#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define N 100000025
using namespace std;

char a[N];
int main() {
    for(int i = 2; i * i < N; i ++){
        if(!a[i]){
            for(int j = i * i; j < N; j += i)
                a[j] = 1;
        }
    }
    int ptr = 100;
    for(int i = 2; i < N; i ++){
        if(!a[i]){
            if(ptr == 100){
                printf("%d\n", i);
                ptr = 1;
            }
            else ptr ++;
        }
    }
    
    return 0;
