#include <bits/stdc++.h>

#define ll long long int
#define pii pair<int,int>
#define pll pair<ll, ll>

#define vec1d(x) vector<x>
#define vec2d(x) vector<vec1d(x)>

#define FOR(i, st, ed) for(int i = int(st); i < int(ed); i++)
using namespace std;

vec1d(string) findStrings(vec1d(string) w, vec1d(int) queries) {
    string s = "";
    vec1d(int) str_cumm_len(1000007, -1);
    vec1d(int) str_idx(1000007, -1);
    FOR(i, 0, w.size()){
        str_cumm_len[s.length()] = s.length();
        str_idx[s.length()] = i;
        s += w[i] + (char)(i+1);
    }
    
    int N = s.length();
    int curr_str_len, curr_str_idx;
    FOR(i, 0, N){
        if(str_cumm_len[i] != -1){
            curr_str_len = str_cumm_len[i];
            curr_str_idx = str_idx[i];
        }
        str_cumm_len[i] = curr_str_len;
        str_idx[i] = curr_str_idx;
    }
    
    int alphabet = 256;

    vec1d(int) p(N);
    vec1d(int) c(N);

    vec1d(int) cnt(max(N, alphabet), 0);
    
    FOR(i, 0, N) cnt[s[i]]++;
    FOR(i, 1, alphabet) cnt[i] += cnt[i-1];
    FOR(i, 0, N) p[--cnt[s[i]]] = i;
        
    c[p[0]] = 0;
    int classes = 1;
    FOR(i, 1, N){
        if(s[p[i]] != s[p[i-1]])
            classes++;
        c[p[i]] = classes-1;
    }

    vec1d(int) pn(N), cn(N);
    for(int k = 0; (1 << k) < N; ++k){
        FOR(i, 0, N){
            pn[i] = (p[i] - (1 << k) + N) % N;
        }

        fill(cnt.begin(), cnt.begin()+classes, 0);
        FOR(i, 0, N) cnt[c[pn[i]]]++;
        FOR(i, 1, classes) cnt[i] += cnt[i-1];
        for(int i = N-1; i > -1; i--){
            p[--cnt[c[pn[i]]]] = pn[i];
        }

        cn[p[0]] = 0;
        classes = 1;
        FOR(i, 1, N){
            pii curr = make_pair(c[p[i]], c[(p[i]+(1 << k)) % N]); 
            pii prev = make_pair(c[p[i-1]], c[(p[i-1]+(1 << k)) % N]);
            if(prev != curr)
                classes++;
            cn[p[i]] = classes-1;
        }

        c.swap(cn);
    }

    vec1d(int) rank(N, 0);
    FOR(i, 0, N) rank[p[i]] = i;

    vec1d(int) lcp(N, 0);
    int k = 0;

    FOR(i, 0, N){
        if(rank[i] == N-1){
            k = 0;
            continue;
        }

        int j = p[rank[i] + 1];
        while(i+k < N && j+k < N && s[i+k] == s[j+k])
            k++;

        lcp[rank[i]+1] = k;
        if(k) --k;
    }
    
    int st = w.size();
    vec1d(string) v;
    FOR(j, 0, queries.size()){
        int q = queries[j];
        bool not_found = true;
        FOR(i, st, N){
            curr_str_len = str_cumm_len[p[i]];
            curr_str_idx = str_idx[p[i]];
            int substr_count = w[curr_str_idx].length() - (p[i]-curr_str_len) - lcp[i];
            if(q > substr_count){
                q -= substr_count;
                continue;
            }
            v.push_back(s.substr(p[i], q+lcp[i]));
            not_found = false;
            break;
        }
        if(not_found) v.push_back("INVALID");
    }
    
    return v;
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n; cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    vec1d(string) w(n);
    FOR(i, 0, n) cin >> w[i];
    
    int q; cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    vec1d(int) queries(q);
    FOR(i, 0, q){ 
        cin >> queries[i];
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    
    vec1d(string) result = findStrings(w, queries);
    for(string s: result){
        cout << s << "\n";
    }
    return 0;
}
