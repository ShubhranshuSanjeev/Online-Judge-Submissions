#include <cstdio>
#include <cstring>
#include <unordered_map>
#include <map>
#include <set>

#define MOD 1000000007
#define SIZE 500007
using namespace std;

int t, n;
int A[SIZE], ans[SIZE];
unordered_map<int, int> pos;
unordered_map<long long int, int> memo;

void solve(int i, unordered_map<int, int> &freq, long long int seq){

    if(i == n) {
        unordered_map<int, int> :: iterator it;
        int maxEle, maxOcc = 0;
        for(it = freq.begin(); it != freq.end(); it++){
            if(maxOcc < (*it).second) maxOcc = (*it).second, maxEle = (*it).first;
            else if(maxOcc == (*it).second) maxEle = min(maxEle, (*it).first);
        }
        ans[pos[maxEle]] = (int)((long long int)ans+1)%MOD;
        return;
    }

    solve(i+1, freq, seq);

    if(freq.find(A[i]) != freq.end()) freq[A[i]]++;
    else freq[A[i]] = 1;
    solve(i+1, freq, (seq|1<<i));
    freq[A[i]]--;
}

int main(){
    int i;
    scanf("%d", &t);
    while (t--) {
        pos.clear();
        memset(ans, 0, sizeof(ans));

        scanf("%d", &n);
        for (i = 0; i < n; i++) {
            scanf("%d", &A[i]);
            if (pos.find(A[i]) != pos.end()) pos[A[i]] = i;
        }
    }
}