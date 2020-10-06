#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

#define ll long long int
#define pii pair<int,int>
#define FOR(i, st, ed) for(int i = int(st); i < int(ed); i++)
#define divide(l, h, idx) int mid = (l + h)>>1, lc = idx<<1, rc = lc|1;
#define MAX 100007
#define MAX2 (MAX << 2)

using namespace std;


int Q, root, x, y;
char type;

int lca(int u, int v){
    int h1 = (int)log2(u)+1, h2 = (int)log2(v)+1;
    int u_h = h1, v_h = h2;
    if(h1 < h2){
        int tmp = u;
        u = v;
        v = u;
    }

    while(h1 > h2){
        u = u>>1;
        h1 = h1-1;
    }

    int lca_t, lca_h = h1;
    if(u == v) lca_t = u;
    else{
        while(u != v){
            u = u >> 1;
            v = v >> 1;
            lca_h = lca_h-1;
        }
        lca_t = u;
    }


    int lca_color = lca_h&1 ? root : root^1;
    // cout << lca_t << " " << lca_h << " " << u_h << " " << v_h << " " << lca_color << "\n";
    int ans = 0;
    if((type == 'b' && lca_color) || (type == 'r' && !lca_color)){
        ans = (int)ceil((u_h-lca_h+1)/2.0) + (int)ceil((v_h-lca_h+1)/2.0) - 1;
    }
    else{
        ans = (int)floor((u_h-lca_h+1)/2.0) + (int)floor((v_h-lca_h+1)/2.0);
    }

    return ans;
}

int main(){
    scanf("%d", &Q);
    root = 1; // 1 for black and 0 for red;
    while(Q--){
        scanf("\nQ%c", &type);
        if(type == 'i'){
            root = root^1;
            continue;
        }
        scanf("%d %d", &x, &y);
        printf("%d ", lca(x,y));
    }
    printf("\n");
    return 0;
}