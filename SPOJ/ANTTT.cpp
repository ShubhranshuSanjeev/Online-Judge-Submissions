#include <cstdio>
#include <vector>

using namespace std;

struct Point{
    int x, y;
    Point(int a, int b){
        this->x = a;
        this->y = b;
    }
};

struct Stick{
    Point st{0,0}, ed{0,0};
    Stick(Point &a, Point &b){
        this->st.x = a.x, this->st.y = a.y;
        this->ed.x = b.x, this->ed.y = b.y;
    }
};

int onSegment(Point &a, Point &b, Point &c){
    return (b.x <= max(a.x, c.x) && b.x >= min(a.x, c.x) && b.y <= max(a.y, c.y) && b.y >= min(a.y, c.y));
}

int getOrientation(Point &a, Point &b, Point &c){
    int val = (b.y - a.y) * (c.x - b.x) - (b.x - a.x) * (c.y - b.y);
    if (val == 0) return 0;
    return val > 0 ? 1 : 2;
}

int doIntersect(Point &a, Point &b, Point &c, Point &d){
    int o1 = getOrientation(a, b, c);
    int o2 = getOrientation(a, b, d);
    int o3 = getOrientation(c, d, a);
    int o4 = getOrientation(c, d, b);

    if(o1 != o2 && o3 != o4) return 1;
    if (o1 == 0 && onSegment(a, c, b)) return 1;
    if (o2 == 0 && onSegment(a, b, b)) return 1;
    if (o3 == 0 && onSegment(c, a, d)) return 1;
    if (o4 == 0 && onSegment(c, b, d)) return 1;

    return 0;
}

int main(){
    int t, n, a, b, c, d, i, j, m1, m2;
    vector<Stick>sticks(1007);
    vector<int> adj[1007];

    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(i = 0; i < n; i++){
            scanf("%d %d %d %d", &a, &b, &c, &d);
            Point p1 {a,b}, p2 {c,d};

            for(j = 0; j < i; j++){
                if(doIntersect(p1, p2, sticks[j].st, sticks[j].ed)){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
            Stick st1 {p1, p2};
            sticks.push_back(st1);
        }
    }
    return 0;
}