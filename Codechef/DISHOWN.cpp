#include <cstdio>
#define N 10007
using namespace std;

int S[N], parent[N];

void init(int n){
  for (int i = 1; i <= n; i++){
    scanf("%d", &S[i]);
    parent[i] = i;
  }
}

int findset(int u){
  if (parent[u] == u)
    return u;
  return (parent[u] = findset(parent[u]));
}

void unionSet(int u, int v){
  int pu = findset(u);
  int pv = findset(v);
  if(pu == pv) {
    printf("Invalid query!\n");
    return;
  }
  if(S[pu] == S[pv]) return;
  if(S[pu] > S[pv]) parent[pv] = pu;
  else parent[pu] = pv;
}

int main(){
  int t, n, q, type, x, y;  
  scanf("%d", &t);
  while (t--){
    scanf("%d", &n);
    init(n);
    scanf("%d", &q);
    for (int i = 0; i < q; i++){
      scanf("%d %d", &type, &x);
      if (type) printf("%d\n", findset(x));
      else{
        scanf("%d", &y);
        unionSet(x, y);
      }
    }
  }
  return 0;
}

