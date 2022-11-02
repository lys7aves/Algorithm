#include <iostream>

using namespace std;

int k, ans=-1;
int A[500010], tmp[500010];

void merge(int A[], int p, int q, int r)
{
    int i, j, t;

    i = p; j = q+1; t = 1;
    while(i <= q && j <= r){
        if(A[i] <= A[j]) tmp[t++] = A[i++];
        else tmp[t++] = A[j++];
    }
    while(i <= q) tmp[t++] = A[i++];
    while(j <= r) tmp[t++] = A[j++];

    i = p; t = 1;
    while(i <= r){
        if(--k == 0) ans = tmp[t];
        A[i++] = tmp[t++];
    }
}

void merge_sort(int A[], int p, int r){
    if(p < r){
        int q = (p+r)/2;
        merge_sort(A, p, q);
        merge_sort(A, q+1, r);
        merge(A, p, q, r);
    }
}
int main()
{
    int n, i;

    cin >> n >> k;
    for(i=0; i<n; i++) cin >> A[i];

    merge_sort(A, 0, n-1);

    cout << ans;

    return 0;
}