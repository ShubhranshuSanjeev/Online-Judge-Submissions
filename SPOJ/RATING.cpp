#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

#define MAX 100007<<2

using namespace std;

struct Node{
    long long int num;
    void createLeaf(){
        num = 0;
    }
    void merge(Node &a, Node &b){
        num = a.num + b.num;
    }
};

class Segtree{
public:
    Node nodes[MAX];
    int N;

    Segtree(int n){
        N = n;
        buildTree(0, n-1, 1);
    }

    void buildTree(int l, int h, int idx){
        if(l > h) return;
        if(l == h){
            //cout << "Creating Leaf: " << l << " " << h << "\n";
            nodes[idx].createLeaf();
            return;
        }
        int mid = (l+h)>>1;
        buildTree(l, mid, idx<<1);
        buildTree(mid+1, h, idx<<1|1);
        nodes[idx].merge(nodes[idx<<1], nodes[idx<<1|1]);
    }

    void update(int l, int h, int i, int idx){
        if(l > h || l > i || h < i) return;
        if(l == i && h == i){
            nodes[idx].num += 1;
            return;
        }
        int mid = (l+h)>>1;
        if(mid >= i) update(l, mid, i, idx<<1);
        else update(mid+1, h, i, idx<<1|1);
        nodes[idx].merge(nodes[idx<<1], nodes[idx<<1|1]);
    }

    long long int query(int l, int h, int ql, int qh, int idx){
        if(l > h || l > qh || h < ql) return 0;
        if(l >= ql && h <= qh){
            return nodes[idx].num;
        }
        int mid = (l+h)>>1;
        return ( query(l, mid, ql, qh, idx<<1) + query(mid+1, h, ql, qh, idx<<1|1) );
    }
};

int main() {
	int n,a,b,mo,mh,i;
	scanf("%d", &n);
	vector<pair<pair<int,int>, int>> ratings(n);
	for(i = 0;i < n;i++){
		scanf("%d %d", &a, &b);
		ratings[i].first.first = a;
		ratings[i].first.second = b;
		ratings[i].second = i;
		if(mo < a) mo = a;
		if(mh < b) mh = b;
	}
	sort(ratings.begin(), ratings.end());
	Segtree openTree(mo+1);
	Segtree highTree(mh+1);
	int eqCount = 0;
	long long int x,y,ans;
	long long int res[n];
	for(i = 0; i < n; i++){
		a = ratings[i].first.first;
		b = ratings[i].first.second;
		x = openTree.query(0, mo, 0, a, 1);
		y = highTree.query(0, mh, 0, b, 1);
		openTree.update(0, mo, a, 1);
		highTree.update(0, mh, b, 1);
		if(i > 0){
			if(ratings[i-1].first.first == a && ratings[i-1].first.second == b)
				eqCount++;
			else
				eqCount = 0;
		}
		if(x > y) ans = y;
		else ans = x;
		ans -= eqCount;
		res[ratings[i].second] = ans;
	}
	for(i = 0; i < n; i++) printf("%lld\n", res[i]);
	return 0;
