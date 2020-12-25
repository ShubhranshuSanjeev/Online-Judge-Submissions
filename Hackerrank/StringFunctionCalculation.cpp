#include <bits/stdc++.h>

using namespace std;

int maxValue(string s) {
    s += '$';
    const int N = s.length();
    const int LOGN = (int)log2(N)+2;
    const int ALPHABET = 256;
    
    vector<int> suffix_array(N);
    vector<vector<int>> classes(LOGN, vector<int> (N));
    vector<int> count_t(max(N, ALPHABET), 0);
    
    for(int i = 0; i < N; i++) count_t[s[i]]++;
    for(int i = 1; i < ALPHABET; i++) count_t[i] += count_t[i-1];
    for(int i = 0; i < N; i++) suffix_array[--count_t[s[i]]] = i;
    
    int class_count = 1;
    classes[0][suffix_array[0]] = 0;
    for(int i = 1; i < N; i++){
        if(s[suffix_array[i]] != s[suffix_array[i-1]])
            class_count++;
        classes[0][suffix_array[i]] = class_count-1;
    }
    
    vector<int> pn(N);
    for(int k = 0; (1 << k) < N; k++){
        for(int i = 0; i < N; i++){
            pn[i] = (suffix_array[i] - (1<<k) + N) % N;
        }
        
        fill(count_t.begin(), count_t.begin()+class_count, 0);
        for(int i = 0; i < N; i++) count_t[classes[k][pn[i]]]++;
        for(int i = 1; i < class_count; i++) count_t[i] += count_t[i-1];
        for(int i = N-1; i > -1; i--) 
            suffix_array[--count_t[classes[k][pn[i]]]] = pn[i];
        
        class_count = 1;
        classes[k+1][suffix_array[0]] = 0;
        for(int i = 1; i < N; i++){
            pair<int, int> a = make_pair(classes[k][suffix_array[i]], classes[k][(suffix_array[i]+(1<<k))%N]);
            pair<int, int> b = make_pair(classes[k][suffix_array[i-1]], classes[k][(suffix_array[i-1]+(1<<k))%N]);
            
            if(a != b)
                class_count++;
            classes[k+1][suffix_array[i]] = class_count-1;
        } 
    }
    
    vector<int> rank(N, 0);
    for(int i = 0; i < N; i++)
        rank[suffix_array[i]] = i;
    
    vector<int> lcp(N+1, 0);
    int k = 0;
    
    for(int i = 0; i < N; i++){
        if(rank[i] == N-1){
            k = 0;
            continue;
        }
        
        int j = suffix_array[rank[i]+1];
        while((i+k) < N && (j+k) < N && s[i+k] == s[j+k])
            k++;
        
        lcp[rank[i]+1] = k;
        if(k) --k;
    }
    
    lcp[N] = 0;
    
    int top = 0;
    vector<int> st(N+2);
    int ans = N-1;
    
    for(int i = 0; i < N+1; i++){
        while(top != 0 && lcp[i] < lcp[st[top-1]]){
            int val = lcp[st[top-1]];
            top--;
            ans = max(ans, val*(top == 0 ? i : i - st[top-1]));
        }
        if(top == 0 || lcp[i] >= lcp[st[top-1]])
            st[top++] = i;
    }
    
    return ans;
}

int main()
{
    string t;
    cin >> t;

    int result = maxValue(t);

    cout << result << "\n";

    return 0;
}
