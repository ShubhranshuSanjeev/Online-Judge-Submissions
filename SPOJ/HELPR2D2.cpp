#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define MAX (1000007<<2)
using namespace std;

struct Node{
	int maxS,wasted,used;
	void createLeaf(int v){
		maxS = v;
		wasted=used=0;
	}
	void update(int v){
		if(used){
			wasted -= v;
		}
		else{
			wasted = maxS-v;
			used = 1;
		}
		maxS-=v;
	}
	void merge(Node &a, Node &b){
		maxS = max(a.maxS, b.maxS);
		wasted = a.wasted+b.wasted;
		used = a.used+b.used;
	}
};
Node tree[MAX];
void buildTree(int idx, int l, int h, int c){
	if(l > h) return;
	if(l == h){
		tree[idx].createLeaf(c);
		return;
	}
	int mid = (l+h)>>1;
	buildTree(idx<<1, l, mid, c);
	buildTree(idx<<1|1, mid+1, h, c);
	tree[idx].merge(tree[idx<<1], tree[idx<<1|1]);
}

void update(int idx, int l, int h, int c){
	if(l > h || tree[idx].maxS < c) return;
	if(l == h){
		tree[idx].update(c);
		return;
	}
	int mid = (l+h)>>1;
	if(tree[idx<<1].maxS >= c)update(idx<<1, l, mid, c);
	else update(idx<<1|1, mid+1, h, c);
	tree[idx].merge(tree[idx<<1], tree[idx<<1|1]);
}

int main() {
	int t,k,n;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &k);
		scanf("%d", &n);
		buildTree(1, 0, n-1, k);
		int i = 0, c, v;
		char a[4];
		while(i < n){
			scanf("%s", a);
			if(strcmp(a, "b") == 0){
				scanf("%d %d", &c, &v);
				for(int j = 0; j < c; j++){
					update(1, 0, n-1, v);
					i++;
				}
			}
			else{
				v = atoi(a);
				update(1, 0, n-1, v);
				i++;
			}
		}
		printf("%d %d\n", tree[1].used, tree[1].wasted);
	}
	return 0;
