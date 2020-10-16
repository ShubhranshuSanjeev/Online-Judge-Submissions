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

int main(){
    int T, a, b, c;
    scanf("%d", &T);
    while(T--){
        scanf("%d %d %d", &a, &b, &c);
        int d = max(a, max(b, c));
        printf("%d\n", d);
    }

    return 0;
}