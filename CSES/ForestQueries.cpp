#include <iostream>
#include <vector>

#define FOR(i, st, ed) for(int i = int(st); i < int(ed); i++)
using namespace std;

const int MAX = 1007;
int N, Q;
int forest[MAX][MAX];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    char tree;

    cin >> N >> Q;
    FOR(i, 0, N+1) {
        FOR(j, 0, N+1){
            if(i == 0 || j == 0) {
                forest[i][j] = 0;
                continue;
            }

            cin >> tree; forest[i][j] = tree == '*';
            forest[i][j] -= forest[i-1][j-1];
            forest[i][j] += forest[i-1][j];
            forest[i][j] += forest[i][j-1];
        }
    }

    int a, b, c, d;
    FOR(i, 0, Q){
        cin >> a >> b >> c >> d;
        int tree_count = forest[c][d] - forest[a-1][d] - forest[c][b-1] + forest[a-1][b-1];
        cout << tree_count << "\n";
    }

    return 0;
}