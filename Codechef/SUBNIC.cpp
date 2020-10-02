/*
 * =====================================================================================
 *
 *       Filename:  SUBNIC.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/22/20 10:01:31
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */


#include <cstdio>
#include <iostream>
#define MAX_SIZE 100007

using namespace std;

int T,N;
int A[MAX_SIZE];

int main(){
    scanf("%d", &T);
    while(T--){
        scanf("%d", &N);
        int i, l = 0;
        long long int ans = 0;
        for(i = 0; i < N; i++){
            scanf("%d", &A[i]);
            if(A[i] >= A[i-1]) l += 1;
            else l = 1;
            ans += l;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
