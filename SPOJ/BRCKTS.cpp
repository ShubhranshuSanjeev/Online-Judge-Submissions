#include <cstdio>
#include <cmath>
#include <cstring>

#define MAX 30007
#define MAX2 (30007<<2)

using namespace std;

char brac[MAX];
struct Node{
	int ope,clo,balanced;
	void createLeaf(char c){
		ope = c == '(' ? 1 : 0;
		clo = c == ')' ? 1 : 0;
		balanced = 0;
	}
	
	void update(){
		ope = ope ? 0 : 1;
		clo = clo ? 0 : 1;
	}
	
	void merge(Node &a, Node &b){
		ope = (a.ope < b.clo ? 0 : (a.ope-b.clo)) + b.ope;
		clo = (b.clo < a.ope ? 0 : (b.clo-a.ope)) + a.clo;
		if(ope == 0 && clo == 0) balanced = 1;
		else balanced = 0; 
	}
};

Node nodes[MAX2];
class Segtree{
private:
	void buildTree(int l, int h, int idx){
		if(l > h) return;
		if(l == h){
			nodes[idx].createLeaf(brac[l]);
			return;
		}
		int mid = (l+h)>>1;
		buildTree(l, mid, idx<<1);
		buildTree(mid+1, h, idx<<1|1);
		nodes[idx].merge(nodes[idx<<1], nodes[idx<<1|1]);
	}
	
	void update(int l, int h, int i, int idx){
		if(l > h || l > i || h < i) return;
		//cout << "Traversing: " << l << " " << h << " " << nodes[idx].ope << " " << nodes[idx].clo << " " << idx << "\n";
		if(l == i && h == i){
			nodes[idx].update();
			//cout << "Updated Leaf: " << i << " " << nodes[idx].ope << " " << nodes[idx].clo << "\n";
			return;
		}
		int mid = (l+h)>>1;
		update(l, mid, i, idx<<1);
		update(mid+1, h, i, idx<<1|1);
		nodes[idx].merge(nodes[idx<<1], nodes[idx<<1|1]);
		//cout << "Updated Internal: " << l << " " << h << " " << nodes[idx].ope << " " << nodes[idx].clo << " " << idx << "\n";
	}
public: 
	int N;
	Segtree(int n){
		N = n;
		buildTree(0, n-1, 1);
	}
	void update(int i){
		update(0, N-1, i, 1);
	}
};

int main() {
	int t = 1,n,i,q,a;
	while(t < 11){
		scanf("%d", &n);
		scanf("%s", brac);
		Segtree tree(n);
		
		printf("Test %d:\n", t);
		scanf("%d", &q);
		for(i = 0; i < q; i++){
			scanf("%d", &a);
			if(a > 0) tree.update(a-1);
			else{
				if(nodes[1].balanced)
					printf("YES\n");
				else
					printf("NO\n");
			}
		}
		t++;
	}
	return 0;
