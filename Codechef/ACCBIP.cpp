#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

struct Line{
    int a, b, c;
};

int main(){
    int t, N, C, K, i, a, b, c;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d %d", &N, &C, &K);
        vector<Line> lines(N);
        vector<int> cFreq(C+1, 0);
        vector<int> V(C+1);
        for(i = 0; i < N; i++){
            scanf("%d %d %d", &a, &b, &c);
            lines[i] = (struct Line){a, b, c};
            cFreq[c]++;
        }
        for(i = 1; i <= C; i++){
            scanf("%d", &V[i]);
        }

        int l = K/V[1];
        i = 1;
        while(l > 0 && i <= C){
            if(cFreq[i] > 3) {
                a = min(cFreq[i]-3, l);
                cFreq[i] -= a;
                l -= a;
            }
            i++;
        }
        int ans = 0;
        for(i = 1; i < C; i++){
            ans += (int)((long long int)cFreq[i]*(cFreq[i]-1)*(cFreq[i]-2))/6;
        }
        printf("%d\n", ans);
    }
    return 0;
}