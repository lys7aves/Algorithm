#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> marks, vector<int> answers) {
    int answer = 0;
    int i, j, cnt;

    answers.push_back(0);
    for(i=0; i<=marks.size(); i++){
        cnt = 0;
        for(j=0; j<marks.size(); j++){
            if(j < i) cnt += marks[j] == answers[j];
            else cnt += marks[j] == answers[j+1];
        }

		printf("%d %d\n", i, cnt); 
        answer = max(answer, cnt);
    }

    return answer;
}

int main()
{
	vector<int> marks;
	vector<int> answers;
	
	int n, i, x;
	
	scanf("%d", &n);
	for(i=0; i<n; i++){
		scanf("%d", &x);
		marks.push_back(x);
	}
	for(i=0; i<n; i++){
		scanf("%d", &x);
		answers.push_back(x);
	}
	
	printf("%d", solution(marks, answers));
	
	return 0;
}
