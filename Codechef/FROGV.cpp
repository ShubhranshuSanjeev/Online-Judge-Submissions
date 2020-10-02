#include <cstdio>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

int main(){
    int N, K, P, a, b, i, j;
    scanf("%d %d %d", &N, &K, &P);
    int A[N];
    vector<int> tmp,tmp2;
    unordered_map<int,int> m;
    for(i = 0; i < N; i++) {
        scanf("%d", &A[i]);
        if(m.find(A[i]) == m.end()){
            m[A[i]] = 1;
            tmp.push_back(A[i]);
        }
    }

    int n = tmp.size();
    sort(tmp.begin(), tmp.end());
    m[tmp.back()] = tmp.back();

    for(i = n-2; i >= 0; i--){
        int x = tmp[i+1]-tmp[i];
        if(x <= K) m[tmp[i]] = m[tmp[i+1]];
        else m[tmp[i]] = tmp[i];
    }

    for(i = 0; i < P; i++){
        scanf("%d %d", &a, &b);
        --a; --b;
        a = A[a], b = A[b];
        if(a > b) swap(a, b);
        if(m[a] >= b) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}