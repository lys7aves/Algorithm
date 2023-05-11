from selenium import webdriver
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.common.by import By
import time
import logging
import configparser
import sqlite3

CONFIG_FILE_PATH = 'E:/LeeYuseop/Study/Computer/Algorithm/Codeforces/etc/data/config.ini'

# 웹 드라이버 초기화
def initialize_web_driver():
    logging.basicConfig(level=logging.WARNING)
    options = webdriver.ChromeOptions()
    options.add_argument('--headless')  # 무차단 모드 옵션 추가
    driver = webdriver.Chrome(chrome_options=options)  # 웹 드라이버의 경로와 옵션을 설정하여 초기화

    return driver


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


def crawling_contest_name(contest):
    # 관리자페이지에서 특정 검색어로 사용자 검색 (새탭 이용)
    current_handle = driver.current_window_handle
    url = 'https://codeforces.com/contest/' + str(contest)
    driver.execute_script(f"window.open('{url}')")
    driver.switch_to.window(driver.window_handles[-1])
    time.sleep(1)

    roundbox = driver.find_element(By.CSS_SELECTOR, '.roundbox.sidebox.borderTopRound')
    trs = roundbox.find_elements(By.TAG_NAME, 'tr')
    contest_name = trs[0].text

    # 현재 탭 닫고 이전 탭으로 이동
    driver.close()
    driver.switch_to.window(current_handle)
    time.sleep(1)

    return contest_name


def crawling_problemset(conn, cursor):
    page = 0
    end_page = 30
    while True:
        page = page+1
        url = 'https://codeforces.com/problemset/page/' + str(page)
        driver.get(url)
        time.sleep(1)

        #problem table 가져오기
        problem_table = driver.find_element(By.CLASS_NAME, "problems")

        for idx, tr in enumerate(problem_table.find_elements(By.TAG_NAME, 'tr')):
            if idx == 0:
                continue

            tds = tr.find_elements(By.TAG_NAME, 'td')

            problem = tds[0].text
            contest = int(problem[:4])
            number = problem[4:]

            difficulty = tds[3].text
            if difficulty == '':
                difficulty = 0
            else:
                difficulty = int(difficulty)

            contest_name = crawling_contest_name(contest)

            print(contest, contest_name, number, difficulty)

            save_problem(conn, cursor, contest, contest_name, number, difficulty)


        if page == end_page:
            break


def save_problem(conn, cursor, contest, contest_name, number, difficulty):
    cursor.execute("INSERT INTO problems (contest, contest_name, number, difficulty) VALUES (?, ?, ?, ?)", [contest, contest_name, number, difficulty])
    conn.commit()

if __name__ == "__main__":
    driver = initialize_web_driver()

    # 데이터베이스 연결
    conn, cursor = connect_db()

    crawling_problemset(conn, cursor)

    
    # 데이터베이스 연결 종료
    cursor.close()
    conn.close()
    
    # 브라우저 닫기
    driver.quit()