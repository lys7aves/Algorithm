from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.common.by import By
import configparser
import sqlite3
from collections import Counter

CONFIG_FILE_PATH = 'E:/LeeYuseop/Study/Computer/Algorithm/Codeforces/etc/data/config.ini'


# config 파일 가져오기 (cp949 오류 해결)
def get_config(config_file_path):
    config = configparser.ConfigParser()
    with open(config_file_path, 'rb') as f:
        config.read_string(f.read().decode('utf-8'))

    return config


# DB 연결하기
def connect_db():
    # config 파일에서 db 파일 경로 가져오기
    config = get_config(CONFIG_FILE_PATH)
    db_path = config['database']['db_filepath']

    # 데이터베이스 연결
    conn = sqlite3.connect(db_path)
    cursor = conn.cursor()

    return conn, cursor



if __name__ == "__main__":
    # 데이터베이스 연결
    conn, cursor = connect_db()

    for div in range(1, 5):
        div_name = "%(Div. " + str(div) + ")%"

        for char in range(ord('A'), ord('L')+1):
            number = chr(char)

            cursor.execute("SELECT difficulty FROM problems WHERE contest_name LIKE ? AND number = ? ORDER BY difficulty", [div_name, number])
            res = cursor.fetchall()

            difficulties = [_[0] for _ in res]
            counted = Counter(difficulties)

            print("# Div.", div, number)
            print("sum: ", len(difficulties))
            for element, count in counted.items():
                print(element, count)

            print(div, number, res)

    
    # 데이터베이스 연결 종료
    cursor.close()
    conn.close()