#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <algorithm>

bool chk[12];
int p[11], q[11];

using namespace std;

int main()
{
    int i, sum;
    bool flag;

    srand(time(NULL));

    for(i=0; i<11; i++){
        do{
            p[i] = (rand()%11)+1;
        }while(chk[p[i]]);

        chk[p[i]] = true; 
    }

    while(true){
        flag = true;
        for(i=1; i<=11; i++) chk[i] = 0;
        for(i=0; i<11; i++){
            cin >> q[i];
            if(q[i] < 1 || 11 < q[i] || chk[q[i]]){
                flag = false;
                continue;
            }
            chk[q[i]] = true;
        }
        
        if(!flag){
            printf("잘못된 입력입니다. 다시 입력해주세요\n");
            continue;
        }

        sum = 0;
        for(i=0; i<11; i++){
            sum += abs(p[i]-q[i]);
        }
        printf("현재 차이의 합은 %d입니다.\n", sum);
    }

    return 0;
}