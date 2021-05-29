#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

#define root 0
#define N 10007
#define LOGN 14

vector<int> adj[N], costs[N], edgeIndex[N];
int baseArray[N], ptr;
int chainNo, chainHead[N], chainIdx[N], posInBase[N];
int depth[N], pa[LOGN][N], otherEnd[N], subsize[N];
int segTree[N<<2], qTree[N<<2];

void buildTree(int idx, int l, int h){
	if(l >= h) return;
	if(l == h-1){
		segTree[idx] = baseArray[l];
		return;
	}
	int mid = (l+h)>>1, lef = idx << 1, rig = lef|1;
	buildTree(lef, l, mid);
	buildTree(rig, mid, h);
	segTree[idx] = segTree[lef] > segTree[rig] ? segTree[lef] : segTree[rig];
}

void updateTree(int idx, int l, int h, int i, int val){
	if(l >= h || l > i || h-1 < i) return;
	if(l == h-1 && l == i){
		segTree[idx] = val;
		return;
	}
	int mid = (l+h)>>1, lef = idx << 1, rig = lef|1;
	updateTree(lef, l, mid, i, val);
	updateTree(rig, mid, h, i, val);
	segTree[idx] = segTree[lef] > segTree[rig] ? segTree[lef] : segTree[rig];
} 

void queryTree(int idx, int l, int h, int ql, int qh){
	if(l >= h || h <= ql || l >= qh){
		qTree[idx] = -1;
		return;
	}
	if(l >= ql && h <= qh){
		qTree[idx] = segTree[idx];
		return;
	}
	int mid = (l+h)>>1, lef = idx << 1, rig = lef|1;
	queryTree(lef, l, mid, ql, qh);
	queryTree(rig, mid, h, ql, qh);
	qTree[idx] = qTree[lef] > qTree[rig] ? qTree[lef] : qTree[rig];
}

int queryUp(int u, int v){
	if(u == v) return 0;
	int uChain, vChain = chainIdx[v], ans = -1;
	while(1){
		uChain = chainIdx[u];
		if(uChain == vChain){
			if(u == v) break;
			queryTree(1, 0, ptr, posInBase[v]+1, posInBase[u]+1);
			if(qTree[1] > ans) ans = qTree[1];
			break;
		}
		int tmp = chainHead[uChain];
		queryTree(1, 0, ptr, posInBase[tmp], posInBase[u]+1);
		if(qTree[1] > ans) ans = qTree[1];
		u = chainHead[uChain];
		u = pa[0][u];
	}
	return ans;
}

int LCA(int u, int v){
	int tmp, log;
	if(depth[u] < depth[v])
		tmp = u, u = v, v = tmp;

	for(log = 1; (1 << log) <= depth[u]; log++);
	log--;

	for(int i = log; i >= 0; i--)
		if(depth[u]-depth[v] >= (1 << i))
			u = pa[i][u];

	if(u == v) return u;
	for(int i = log; i >= 0; i--)
		if(pa[i][u] != -1 && pa[i][u] != pa[i][v])
			u = pa[i][u], v = pa[i][v]; 

	return pa[0][u];
}

void query(int u, int v){
	int lca = LCA(u,v);
	int a = queryUp(u, lca);
	int b = queryUp(v, lca);
	if(b > a) a = b;
	printf("%d\n", a);
}

void change(int i, int val){
	int u = otherEnd[i];
	updateTree(1, 0, ptr, posInBase[u], val);
}

void HLD(int curr, int cost, int prev){
	if(chainHead[chainNo] == -1)
		chainHead[chainNo] = curr;

	chainIdx[curr] = chainNo;
	posInBase[curr] = ptr;
	baseArray[ptr++] = cost;

	int sc=-1, _cost;
	for(int i = 0; i < adj[curr].size(); i++)
		if(adj[curr][i] != prev)
			if(sc == -1 || subsize[sc] < subsize[adj[curr][i]]){
				sc = adj[curr][i];
				_cost = costs[curr][i];
			}

	if(sc != -1)
		HLD(sc, _cost, curr);

	for(int i = 0; i < adj[curr].size(); i++)
		if(adj[curr][i] != prev)
			if(adj[curr][i] != sc){
				chainNo++;
				HLD(adj[curr][i], costs[curr][i], curr);
			}
}

void dfs(int curr, int prev, int _depth = 0){
	pa[0][curr] = prev;
	depth[curr] = _depth;
	subsize[curr] = 1; 
	for(int i = 0; i < adj[curr].size(); i++)
		if(adj[curr][i] != prev){
			otherEnd[edgeIndex[curr][i]] = adj[curr][i];
			dfs(adj[curr][i], curr, _depth+1);
			subsize[curr] += subsize[adj[curr][i]];
		}
}

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		ptr = 0;
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
		dfs(root, -1);
		HLD(root, -1, -1);
		buildTree(1, 0, ptr);

		for(int i = 1; 1 << i < n; i++)
			for(int j = 0; j < n; j++)
				pa[i][j] = pa[i-1][pa[i-1][j]];

		while(1){
			char type[100];
			scanf("%s", type);
			if(type[0] == 'D') break;

			int a,b;
			scanf("%d %d", &a, &b);
			if(type[0] == 'Q')
				query(a-1, b-1);
			else
				change(a-1, b);
		}
	}
	return 0;
