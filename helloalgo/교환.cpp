#include <iostream>

using namespace std;

int arr[100];

int main()
{
    int n, i, j, s, max_idx, tmp;
    
    cin >> n;
    for(i=0; i<n; i++) cin >> arr[i];
    cin >> s;
    
    for(i=0; i<n; i++){
        max_idx = i;
        for(j=i; j<n && j-i<=s; j++){
            if(arr[j] > arr[max_idx]){
                max_idx = j;
            }
        }
        for(j=max_idx; j>i; j--){
            tmp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = tmp;
        }
        
        s -= max_idx-i;
    }
    
    for(i=0; i<n; i++) cout << arr[i] << ' ';
    
    return 0;
}