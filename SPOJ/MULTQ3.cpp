#include <iostream>
#include <cstdio>
#define MAX 100007
#define MAX2 (MAX << 2)
using namespace std;

struct Node{
	int zero,one,two;
	void createLeaf(){
		zero = 1;
		one = two = 0;
	}
	void update(){
		int a,b;
		a = zero;
		b = one;
		zero = two;
		one = a;
		two = b;
	}
	void merge(Node &a, Node &b){
		zero = a.zero + b.zero;
		one = a.one + b.one;
		two = a.two + b.two;
	}
};

Node tree[MAX2];
int lazy[MAX2];

void buildTree(int idx, int l, int h){
	if(l > h) return;
	if(l == h){
		tree[idx].createLeaf();
		lazy[idx] = 0;
		return;
	}
	int mid = (l+h)>>1;
	buildTree(idx<<1, l, mid);
	buildTree(idx<<1|1, mid+1, h);
	tree[idx].merge(tree[idx<<1], tree[idx<<1|1]);
}

void propagate(int idx, int l, int h){
	if(lazy[idx]){
		int n = lazy[idx]%3;
		for(int i = 0; i < n; i++) tree[idx].update();
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
		//cout << "Node updating: " << l << " " << h << " " << ql << " " << qh << " " << tree[idx].zero << " " << tree[idx].one << " " << tree[idx].two << "\n";
		tree[idx].update();
		//cout << "Node updated: " << l << " " << h << " " << ql << " " << qh << " " << tree[idx].zero << " " << tree[idx].one << " " << tree[idx].two << "\n"; 
		if(l != h){
			lazy[idx<<1] += 1;
			lazy[idx<<1|1] += 1;
		}
		return;
	}
	int mid = (l+h)>>1;
	update(idx<<1, l, mid, ql, qh);
	update(idx<<1|1, mid+1, h, ql, qh);
	tree[idx].merge(tree[idx<<1], tree[idx<<1|1]);
}

int query(int idx, int l, int h, int ql, int qh){
	propagate(idx, l, h);
	if(l > h || l > qh || h < ql) return 0;
	if(l >= ql && h <= qh) return tree[idx].zero;
	int mid = (l+h)>>1;
	return ( query(idx<<1, l, mid, ql, qh) + query(idx<<1|1, mid+1, h, ql, qh) );
}

int main() {
	int n,q,m,a,b,i;
	scanf("%d %d", &n, &q);
	buildTree(1, 0, n-1);
	for(i = 0; i < q; i++){
		scanf("%d %d %d", &m, &a, &b);
		if(m){
			int ans = query(1, 0, n-1, a, b);
			printf("%d\n", ans);
		}
		else{
			update(1, 0, n-1, a, b);
		}
	}
	return 0;
