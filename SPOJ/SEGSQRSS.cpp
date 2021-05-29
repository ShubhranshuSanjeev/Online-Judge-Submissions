#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define N 100007
using namespace std;

int A[N], lazy[N<<2], segtree[N<<2], qt[N<<2];

void buildTree(int idx, int l, int h){
	if(l > h) return;
	if(l == h){
		segtree[idx] = A[l]*A[l];
		return;
	}
	int mid = (l+h)>>1, ls = idx<<1, rs = ls|1;
	buildTree(ls, l, mid);
	buildTree(rs, mid+1, h);
	segtree[idx] = segtree[ls] + segtree[rs];
}

void propagate(int idx, int l, int h){
	if(lazy[idx]){
		segtree[idx] = (h-l+1)*lazy[idx]*lazy[idx];
		if(l != h) { lazy[idx<<1] = lazy[idx]; lazy[idx<<1|1] = lazy[idx];}
		lazy[idx] = 0;
	}
}

void pointUpdate(int idx, int l, int h, int ql, int qh, int v){
	propagate(idx, l, h);
	if(l > h || l > qh || h < ql) return;
	if(l >= ql && h <= qh && l == h){
		segtree[idx] = (segtree[idx]+v)*(segtree[idx]+v);
		return;
	}
	int mid = (l+h)>>1, ls = idx<<1, rs = ls|1;
	pointUpdate(ls, l, mid, ql, qh, v);
	pointUpdate(rs, mid+1, h, ql, qh, v);
	segtree[idx] = segtree[ls] + segtree[rs];
}

void rangeUpdate(int idx, int l, int h, int ql, int qh, int v){
	propagate(idx, l, h);
	if(l > h || l > qh || h < ql) return;
	if(l >= ql && h <= qh){
		segtree[idx] = (h-l+1)*v*v;
		if(l != h){ lazy[idx<<1] = v; lazy[idx<<1|1] = v;}
		return;
	}
	int mid = (l+h)>>1, ls = idx<<1, rs = ls|1;
	rangeUpdate(ls, l, mid, ql, qh, v);
	rangeUpdate(rs, mid+1, h, ql, qh, v);
	segtree[idx] = segtree[ls] + segtree[rs];
}

void query(int idx, int l, int h, int ql, int qh){
	propagate(idx, l, h);
	if(l > h || l > qh || h < ql){ qt[idx] = 0; return;}
	if(l >= ql && h <= qh){
		qt[idx] = segtree[idx];
		return;
	}
	int mid = (l+h)>>1, ls = idx<<1, rs = ls|1;
	query(ls, l, mid, ql, qh);
	query(rs, mid+1, h, ql, qh);
	qt[idx] = qt[ls] + qt[rs];
}

int main(){
	int t,n,q,m,s,e,x,ti=1;
	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &n, &q);
		for(int i = 0; i < n; i++) scanf("%d", &A[i]);
		buildTree(1, 0, n-1);
		memset(lazy, 0, sizeof(lazy));
		printf("Case %d:\n", ti);
		while(q--){
			scanf("%d", &m);
			if(m == 2){
				scanf("%d %d", &s, &e);
				s--; e--;
				query(1, 0, n-1, s, e);
				printf("%d\n", qt[1]);
			}
			else if(m == 1){
				scanf("%d %d %d", &s, &e, &x);
				s--; e--;
				pointUpdate(1, 0, n-1, s, e, x);
			}
			else{
				scanf("%d %d %d", &s, &e, &x);
				s--; e--;
				rangeUpdate(1, 0, n-1, s, e, x);
			}
		}
		++ti;
	}
	return 0;
}
