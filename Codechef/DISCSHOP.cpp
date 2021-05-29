#include <iostream>
#include <cmath>
using namespace std;

int countDigits(int n){
    int dig = 0;
    while(n){
        n=n/10;
        dig++;
    }
    return dig;
}

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int len = countDigits(n);
        int m = 10000000000;
        for(int i = 0; i < len; i++){
            int p = pow(10,i); 
            int num = (p * (n/(p*10))) + n%p;
            if(m > num) m = num;
        }
        cout << m <<"\n";
    }
}
