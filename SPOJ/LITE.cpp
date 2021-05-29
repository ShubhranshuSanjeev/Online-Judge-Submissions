#include <iostream>
#include <cstdio>
#include <cstring>

#define MAX 100007
#define MAX2 (MAX<<2)

using namespace std;

int tree[MAX2];
int lazy[MAX2];

void propagate(int idx, int l, int h){
	if(lazy[idx]){
		if(lazy[idx]%2){
			tree[idx] = (h-l+1) - tree[idx];
		}
		if(l != h){
			lazy[idx<<1] += lazy[idx];
			lazy[idx<<1|1] += lazy[idx];
		}
		lazy[idx] = 0;
	}
}
void update(int idx, int l, int h, int ql, int qh){
	propagate(idx, l, h);
	if(l > h || l > qh || h < ql) return;
	if(l >= ql && h <= qh){
		tree[idx] = (h-l+1) - tree[idx];
		if(l != h){
			lazy[idx<<1] += 1;
			lazy[idx<<1|1] += 1;
		}
		return;
	}
	int mid = (l+h)>>1;
	update(idx<<1, l, mid, ql, qh);
	update(idx<<1|1, mid+1, h, ql, qh);
	tree[idx] = tree[idx<<1]+tree[idx<<1|1];
}

int query(int idx, int l, int h, int ql, int qh){
	propagate(idx, l, h);
	if(l > h || l > qh || h < ql) return 0;
	if(l >= ql && h <= qh) return tree[idx];
	int mid = (l+h)>>1;
	return (query(idx<<1, l, mid, ql, qh) + query(idx<<1|1, mid+1, h, ql, qh));
}

int main() {
	int n, q, i, m, a, b;
	memset(tree, 0, MAX2);
	memset(lazy, 0, MAX2);
	scanf("%d %d", &n, &q);
	for(i = 0; i < q; i++){
		scanf("%d %d %d", &m, &a, &b);
		if(m){
			int ans =  query(1, 0, n-1, a-1, b-1);
			printf("%d\n", ans);
		}
		else{
			update(1,0,n-1,a-1,b-1);
		}
	}
	return 0;
