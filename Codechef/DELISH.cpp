/*
 * =====================================================================================
 *
 *       Filename:  DELISH.cpp
 *
 *    Description: Codechef DELISH problem solution 
 *
 *        Version:  1.0
 *        Created:  08/20/20 09:15:04
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Shubhranshu
 *   Organization:  
 *
 * =====================================================================================
 */

#include<cstdio>
#include<algorithm>
#include<iostream>
#define SIZE 10007
using namespace std;

int main(){
    int t, n, i;
    int D[SIZE];

    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(i = 0; i < n; i++)
            scanf("%d", &D[i]);
        
        /* 
         * left is used to store the minimum and maximum value on the left side of index i
         * right is used to store the minimum and maximum value on the right side of index i 
         */

        int left[n+1][2];
        int right[n+1][2];
        
        left[0][0] = left[0][1] = D[0];
        for(i = 1; i < n; i++){
            left[i][0] = min(left[i-1][0], 0) + D[i]; // storing the minimum value 
            left[i][1] = max(left[i-1][1], 0) + D[i]; // storing the maximum value
        }

        right[n-1][0] = right[n-1][1] = D[n-1];
        for(i = n-2; i >= 0; i--){
            right[i][0] = min(right[i+1][0], 0) + D[i]; // storing the minimum value
            right[i][1] = max(right[i+1][1], 0) + D[i]; // storing the maximum value
        }

        int ans = 0;
        for(i = 0; i < n-1; i++){
            ans = max((int)abs(left[i][0]-right[i+1][1]), ans);
            ans = max((int)abs(left[i][1]-right[i+1][0]), ans);
        }

        printf("%d\n", ans);
    }
    return 0;
}

