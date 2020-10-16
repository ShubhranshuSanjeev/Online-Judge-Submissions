#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_map>
#include <map>
#include <tuple>

#define ll long long int
#define pii pair<int,int>
#define pll pair<ll, ll>
#define all(x) (x).begin(), (x).end()
#define FOR(i, st, ed) for(int i = int(st); i < int(ed); i++)
#define divide(l, h, idx) int mid = (l + h)>>1, lc = idx<<1, rc = lc|1;
#define MAX 1000000000
using namespace std;

int main(){
    int N, M, sx, sy, fx, fy;
    int ux, uy, vx, vy, u, v;
    ll ti;

    scanf("%d %d", &N, &M);
    scanf("%d %d %d %d", &sx, &sy, &fx, &fy);

    vector<pii> sp_cells(M);
    vector<tuple<int,int,int>> sp_r(M), sp_c(M);
    vector<vector<pii>> edges(M);
    vector<ll> dist(M);
    priority_queue<pair<ll, int>> q;

    FOR(i, 0, M){
        scanf("%d %d", &ux, &uy);

        sp_cells[i] = make_pair(ux, uy);
        sp_r[i] = make_tuple(ux, uy, i);
        sp_c[i] = make_tuple(uy, ux, i);
    }
    sort(all(sp_r));
    sort(all(sp_c));

    FOR(i, 1, M){
        ux = get<0>(sp_r[i-1]), uy = get<1>(sp_r[i-1]), u = get<2>(sp_r[i-1]);
        vx = get<0>(sp_r[i]), vy = get<1>(sp_r[i]), v = get<2>(sp_r[i]);

        ll d = min(abs(ux-vx), abs(uy-vy));
        edges[u].emplace_back(v, d);
        edges[v].emplace_back(u, d);
    }

    FOR(i, 1, M){
        ux = get<0>(sp_c[i-1]), uy = get<1>(sp_c[i-1]), u = get<2>(sp_c[i-1]);
        vx = get<0>(sp_c[i]), vy = get<1>(sp_c[i]), v = get<2>(sp_c[i]);

        ll d = min(abs(ux-vx), abs(uy-vy));
        edges[u].emplace_back(v, d);
        edges[v].emplace_back(u, d);
    }

    FOR(i, 0, M){
        dist[i] = min(abs(sx-sp_cells[i].first), abs(sy-sp_cells[i].second));
        q.push(make_pair(-dist[i], i));
    }

    while(!q.empty()){
        u = q.top().second;
        ti = -(q.top().first);
        q.pop();
        if(dist[u] != ti) continue;
        for(auto& to : edges[u]){
            if(dist[to.first] > ti+to.second){
                dist[to.first] = ti+to.second;
                q.push(make_pair(-dist[to.first], to.first));
            }
        }
    }

    ll ans = abs(sx-fx) + abs(sy-fy);
    FOR(i, 0, M){
        ans = min(ans, dist[i]+abs(fx-sp_cells[i].first)+abs(fy-sp_cells[i].second));
    }

    printf("%lld", ans);
    return 0;
}

//    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> q;
//    unordered_map<ll, ll> visited;
////    vector<vector<ll>> visited(N+1, vector<ll>(N+1, -1));
//
//    q.push(make_pair(0, sx*MAX+sy));
//    visited[sx*MAX+sy] = 0;
//    while(!q.empty()){
//        ti = q.top().first;
//        u = q.top().second;
//        ux = u/MAX;
//        uy = u%MAX;
////        cout << u << " " << ux << " " << uy << " " << ti << "\n";
//        q.pop();
//
//        if(fx == ux && fy == uy) break;
//        if(visited[u] != ti) continue;
//        FOR(i, 0, 4){
//            vx = ux + moves[i][0];
//            vy = uy + moves[i][1];
//            if(vx > 0 && vx <= N && vy > 0 && vy <= N){
//                v = vx*MAX+vy;
//                if(visited.find(v) == visited.end() || (ti+1) < visited[v]) {
//                    q.push(make_pair(ti + 1, v));
//                    visited[v] = ti + 1;
//                }
//            }
//        }
//        for(pii to : sp_cells_r[ux]){
//            vx = to.first, vy = to.second;
//            v = vx*MAX+vy;
//            if(visited.find(v) == visited.end() || ti < visited[v]) {
//                q.push(make_pair(ti, v));
//                visited[v] = ti;
//            }
//        }
//        for(pii to : sp_cells_c[uy]){
//            vx = to.first, vy = to.second;
//            v = vx*MAX+vy;
//            if(visited.find(v) == visited.end() || ti < visited[v]) {
//                q.push(make_pair(ti, v));
//                visited[v] = ti;
//            }
//        }
//    }
//    printf("%lld\n", visited[fx*MAX+fy]);