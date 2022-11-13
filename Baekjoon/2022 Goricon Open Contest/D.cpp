#include <iostream>
#include <algorithm>

#define MAXN 200000

using namespace std;

struct dxy{
    int d, idx, ans;
    long long x, y;
};

bool cmp_d(const dxy &x, const dxy &y){
    return x.d < y.d;
}
bool cmp_idx(const dxy &x, const dxy &y){
    return x.idx < y.idx;
}

dxy typhoon[MAXN+10], people[MAXN+10];

int main()
{
    int n, k, q, i, j, dd;
    long long r, x, y, dx, dy;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> k >> r >> q;
    for(i=0; i<k; i++){
        cin >> typhoon[i].d >> typhoon[i].x >> typhoon[i].y;
    }
    for(i=0; i<q; i++){
        cin >> people[i].d >> people[i].x >> people[i].y;
        people[i].idx = i;
    }

    sort(people, people+q, cmp_d);

    j = 1;
    typhoon[k].d = n+1;
    for(i=0; i<q; i++){
        while(typhoon[j].d <= people[i].d) j++;
        if(j == k) j--;

        dd = typhoon[j].d - typhoon[j-1].d;
        dx = typhoon[j].x - typhoon[j-1].x; dx /= dd;
        dy = typhoon[j].y - typhoon[j-1].y; dy /= dd;

        x = typhoon[j-1].x + dx*(people[i].d-typhoon[j-1].d);
        y = typhoon[j-1].y + dy*(people[i].d-typhoon[j-1].d);

        if((people[i].x-x)*(people[i].x-x) + (people[i].y-y)*(people[i].y-y) > r*r) people[i].ans = 3;
        else{
            if(dx == 0){
                if(people[i].x == x) people[i].ans = 3;
                else if(dy * (people[i].x-x) < 0) people[i].ans = 1;
                else people[i].ans = 2;
            }
            else{
                if(people[i].y == y) people[i].ans = 3;
                else if(dx * (people[i].y-y) > 0) people[i].ans = 1;
                else people[i].ans = 2;
            }
        }
    }

    sort(people, people+q, cmp_idx);

    for(i=0; i<q; i++){
        if(people[i].ans == 1) cout << "safe\n";
        else if(people[i].ans == 2) cout << "unsafe\n";
        else cout << "gori\n";
    }

    return 0;
}