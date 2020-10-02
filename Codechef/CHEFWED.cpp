#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int main(){
    int t, n, k, i, j;
    int F[1007];
    scanf("%d", &t);

    while(t--){
        scanf("%d %d", &n, &k);
        for(i = 0; i < n; i++) scanf("%d", &F[i]);
        multiset<int> :: iterator l, h;

        vector<int> costs(n);
        vector<multiset<int>> poss(n);

        costs[0] = k;
        poss[0].insert(F[0]);
        int tmp;

        for(i = 1; i < n; i++){
            poss[i].insert(F[i]);
            costs[i] = k;
            tmp = INT32_MAX;
            for(j = 0; j < i; j++){
                tmp = min(tmp, costs[j]);
                l = poss[j].find(F[i]);
                if(l != poss[j].end()){
                    h = poss[j].upper_bound(F[i]);
                    int occ = distance(l, h);
                    if(occ == 1) costs[j] += 2;
                    else costs[j] += 1;
                }
                poss[j].insert(F[i]);
            }
            costs[i] += tmp;
        }

        int minCost = INT32_MAX;
        for(i = 0; i < n; i++) minCost = min(minCost, costs[i]);
        printf("%d\n", minCost);
    }
    return 0;
}