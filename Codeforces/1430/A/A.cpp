#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_map>
#include <map>

#define ll long long int
#define pii pair<int,int>
#define FOR(i, st, ed) for(int i = int(st); i < int(ed); i++)
#define divide(l, h, idx) int mid = (l + h)>>1, lc = idx<<1, rc = lc|1;
#define MAX 100007
using namespace std;

int T, N, tmp[3], ans[3];
bool found;
int type[] = {3, 5, 7};
void solve(int amt){
    if(amt < 0) return;
    if(amt == 0){
        ans[0] = tmp[0], ans[1] = tmp[1], ans[2] = tmp[2];
        found = true;
        return;
    }
    FOR(i, 0, 3){
        if(found) return;
        tmp[i]++;
        solve(amt-type[i]);
        tmp[i]--;
    }
}

int main(){
    scanf("%d", &T);
    while(T--){
        scanf("%d", &N);
        ans[0]=ans[1]=ans[2]=0;
        tmp[0]=tmp[1]=tmp[2]=0;
        found=false;
        solve(N);
        if(found) printf("%d %d %d\n", ans[0], ans[1], ans[2]);
        else printf("-1\n");
    }
    return 0;
}