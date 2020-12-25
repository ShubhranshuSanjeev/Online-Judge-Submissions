#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

#define FOR(i, st, ed) for(int i = int(st); i < int(ed); i++)
using namespace std;

struct Color{
    int r, g, b;

    Color(int x, int y, int z): r(x), g(y), b(z) {}
    bool operator <(const Color& other) const {
        if (r < other.r) return true;
        if (g < other.g) return true;
        if (b < other.b) return true;

        return false;
    }
};

bool compareInterval(Color c1, Color c2)
{
    if (c1.g != c2.g) return c1.g < c2.g;
    if (c1.r != c2.r) return c1.r < c2.r;
    return b < other.b;

    return false;
}

int N,Q;
vector<Color> colors;


//int search(Color query){
//    int l = 0, h = colors.size()-1;
//    int mid;
//    bool found = false;
//    while(l <= h){
//        mid = (l+h)>>1;
//        if(query.r <= colors[mid].r){
//            h = mid;
//            if(!found && (query.r == colors[mid].r)) found = true;
//        }
//        else l = mid+1;
//    }
//}

int main(){
    int x,y,z;
    scanf("%d %d", &N, &Q);
    FOR(i, 0, N){
        scanf("%d %d %d", &x, &y, &z);
        colors.push_back((Color){x, y, z});
    }

    sort(colors.begin(), colors.end());
    vector<string> ans;
    FOR(i, 0, Q){
        scanf("%d %d %d", &x, &y, &z);
        Color tmp = (Color){x, y, z};
        auto lb_x = lower_bound(colors.begin(), colors.end(), tmp);
        auto ub_x = upper_bound(colors.begin(), colors.end(), tmp);
        --ub_x;
        if(lb_x->r != x) {
            ans.push_back("NO");
            continue;
        }

        auto lb_y = lower_bound(lb_x, ub_x, tmp);
        auto ub_y = upper_bound(lb_x, ub_x, tmp);
        --ub_y;
        if(lb_y->g != y) {
            ans.push_back("NO");
            continue;
        }

        auto lb_z = lower_bound(lb_y, ub_y, tmp);
        if(lb_z->b != z) {
            ans.push_back("NO");
            continue;
        }

        ans.push_back("YES");
    }

    for(const string& s: ans){
        cout << s << "\n";
    }
}