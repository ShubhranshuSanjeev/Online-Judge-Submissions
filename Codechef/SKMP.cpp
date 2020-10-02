#include <iostream>
#include <set>
#include <string>

using namespace std;

int main(){
    int t, n, m, i;
    string s, p, l, h;
    cin >> t;
    while(t--){
        cin >> s;
        cin >> p;
        n = s.length();
        m = p.length();

        char smallestChar = 'z', largestChar = 'a', firstChar = p[0];

        multiset<char> chr;
        multiset<char> chr2;
        for(i = 0; i < n; i++){
            chr.insert(s[i]);
        }
        for(i = 0; i < m; i++){
            if(smallestChar > p[i]) smallestChar = p[i];
            if(largestChar < p[i]) largestChar = p[i];
            chr.erase(chr.find(p[i]));
        }

        l = "";
        h = "";

        multiset<char> :: iterator it;
        for(it = chr.begin(); it != chr.end(); it++) {
            if (*it <= smallestChar)  l += *it;
            else if (*it > largestChar)  h += *it;
            else {
                if((*it)+p < p+(*it)) l += *it;
                else h += *it;
            }
        }

        cout << l << p << h << "\n";
    }

    return 0;
}