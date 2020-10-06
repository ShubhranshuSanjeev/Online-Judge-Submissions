#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

#define ll long long int
#define pii pair<int,int>
#define FOR(i, st, ed) for(int i = int(st); i < int(ed); i++)
#define divide(l, h, idx) int mid = (l + h)>>1, lc = idx<<1, rc = lc|1;
#define MAX 500007
#define MAX2 (MAX << 2)

using namespace std;

int N, Q, pos;
vector<int> adj[MAX];
int first[MAX], last[MAX], A[MAX];
int seg_tree[MAX << 2], lazy[MAX << 2];



int main(){
    int x, y;
    char a;

    scanf("%d %d", &N, &Q);
    FOR(i,0, N-1){
        scanf("%d %d", &x, &y);
        --x; --y;
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
    }
    FOR(i, 0, N){
        scanf("%d", &A[i]);
    }



    }
    return 0;
}