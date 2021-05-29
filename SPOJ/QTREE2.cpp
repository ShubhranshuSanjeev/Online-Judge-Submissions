#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

#define root 0
#define N 10007
#define LOGN 14

vector<int> adj[N], costs[N], edgeIndex[N];
int baseArray[N], ptr;
int chainNo, chainHead[N], chainIdx[N], posInBase[N];
int depth[N], pa[LOGN][N], otherEnd[N], subsize[N];
long long int segTree[N<<2], qTree[N<<2];

void buildTree(int idx, int l, int h){
	if(l > h) return;
	if(l == h){
		segTree[idx] = baseArray[l];
		return;
	}
	int mid = (l+h)>>1, ls = idx<<1, rs = ls|1;
	buildTree(ls, l, mid);
	buildTree(rs, mid+1, h);
	segTree[idx] = segTree[ls] + segTree[rs];
}

void queryTree(int idx, int l, int h, int ql, int qh){
	if(l > h || l > qh || h < ql){
		qTree[idx] = 0;
		return;
	}
	if(l >= ql && h <= qh){
		qTree[idx] = segTree[idx];
		return;
	}
	int mid = (l+h)>>1, ls = idx<<1, rs = ls|1;
	queryTree(ls, l, mid, ql, qh);
	queryTree(rs, mid+1, h, ql, qh);
	qTree[idx] = qTree[ls]+qTree[rs];
}

long long int queryUp(int u, int v){
	if(u == v) return 0;
	int uchain, vchain = chainIdx[v];
	long long int ans = 0;

	while(1){
		uchain = chainIdx[u];
		if(uchain == vchain){
			if(u == v) break;
			queryTree(1, 0, ptr, posInBase[v]+1, posInBase[u]);
			ans += qTree[1];
			break;
		}
		queryTree(1, 0, ptr, posInBase[chainHead[uchain]], posInBase[u]);
		ans += qTree[1];
		u = pa[0][chainHead[uchain]];
	}
	return ans;
}

int LCA(int u, int v){
	int log, tmp;
	if(depth[u] < depth[v])
		tmp = u, u = v, v = tmp;

	for(log = 0; (1 << log) <= depth[u]; log++);
	log--;

	for(int i = log; i >= 0; i--)
		if(depth[u]-depth[v] >= 1<<i)
			u = pa[i][u];

	if(u == v) return u;

	for(int i = log; i >= 0; i--)
		if(pa[i][u] != -1 && pa[i][u] != pa[i][v])
			u = pa[i][u], v = pa[i][v];

	return pa[0][u];
}

void query(int u, int v){
	if(u == v) {
        printf("0\n");
        return;
	}
	int lca = LCA(u, v);
	long long int a = queryUp(u,lca);
	long long int b = queryUp(v,lca);
	printf("%lld\n", (a+b));
}

void getKthNode(int u, int v, int k){
	int lca = LCA(u, v), tmp;
	if(u == lca){
		k = depth[v]-depth[u]-k+2;
		tmp = u, u = v, v = tmp; 
	}
	else if(v == lca);
	else{
		int x = depth[u] - depth[lca] + 1;
		int y = depth[v] - depth[lca] + 1;
		if(k > x){
			k = x+y-k;
			u = v;
		}
	}
	k--;
	for(int i = LOGN-1; i >= 0; i--){
		if(k >= (1<<i)){
			u = pa[i][u];
			k -= (1<<i);
		}
	}

	printf("%d\n", u+1);
}

void HLD(int u, int prev, int cost){
	if(chainHead[chainNo] == -1) chainHead[chainNo] = u;
	chainIdx[u] = chainNo;
	posInBase[u] = ptr;
	baseArray[ptr++] = cost;

	int sc = -1, _cost;
	for(int i = 0; i < adj[u].size(); i++)
		if(adj[u][i] != prev)
			if(sc == -1 || subsize[sc] < subsize[adj[u][i]]){
				sc = adj[u][i];
				_cost = costs[u][i];
			}
	if(sc != -1) HLD(sc, u, _cost);

	for(int i = 0; i < adj[u].size(); i++)
		if(adj[u][i] != prev)
			if(adj[u][i] != sc){
				chainNo++;
				HLD(adj[u][i], u, costs[u][i]);
			}
}

void dfs(int u, int prev, int _depth = 0){
	pa[0][u] = prev;
	depth[u] = _depth;
	subsize[u] = 1;

	for(int i = 0; i < adj[u].size(); i++){
		if(adj[u][i] != prev){
			otherEnd[edgeIndex[u][i]] = adj[u][i];
			dfs(adj[u][i], u, _depth+1);
			subsize[u] += subsize[adj[u][i]];
		}
	}
}

int main()
{
	int t;
	scanf("%d", &t);

	while(t--){
		int n;
		scanf("%d", &n);

		for(int i = 0; i < n; i++){
			adj[i].clear();
			costs[i].clear();
			edgeIndex[i].clear();
			chainHead[i] = -1;
			for(int j = 0; j < LOGN; j++) pa[j][i] = -1;
		}
		for(int i = 1; i < n; i++){
			int a,b,c;
			scanf("%d %d %d", &a, &b, &c);
			a--; b--;
			adj[a].push_back(b);
			costs[a].push_back(c);
			edgeIndex[a].push_back(i-1);
			adj[b].push_back(a);
			costs[b].push_back(c);
			edgeIndex[b].push_back(i-1);
		}
		chainNo = 0;
		ptr = 0;
		dfs(root, -1);
		HLD(root, -1, -1);
		ptr--;
		buildTree(1, 0, ptr);

		for(int i = 1; (1 << i) < n; i++)
			for(int j = 0; j < n; j++)
				pa[i][j] = pa[i-1][pa[i-1][j]];

		char type[100];
		while(1){
			scanf("%s", type);
			if(type[1] == 'O') break;

			int a,b,c;
			if(type[0] == 'D'){
				scanf("%d %d", &a, &b);
				query(a-1, b-1);
			}
			else{
				scanf("%d %d %d", &a, &b, &c);
				getKthNode(a-1,b-1,c);
			}
		}
		printf("\n");
	}
	return 0;
}
