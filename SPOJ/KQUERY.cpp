#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>

#define MAX 30007
#define MAX2 (MAX<<2)

using namespace std;
long long int arr[MAX];
struct Node{
    vector<long long int> v;
    void createLeaf(long long int val){
        v.push_back(val);
    }
    void merge(Node &a, Node &b){
        long long int k,i = 0,j = 0;
        while(i<a.v.size() && j<b.v.size()){
            if(a.v[i] <= b.v[j]){
                v.push_back(a.v[i]);
                i++;
            }
            else{
                v.push_back(b.v[j]);
                j++;
            }
        }
        for(k = i; k < a.v.size(); k++) v.push_back(a.v[k]);
        for(k = j; k < b.v.size(); k++) v.push_back(b.v[k]);
    }
};

Node nodes[MAX2];
class Segtree{
public:
    int N;
    Segtree(int n){
        N=n;
        buildTree(0,n-1,1);
    }
    void buildTree(int l, int h, int idx){
        if(l>h) return;
        if(l == h){
            nodes[idx].createLeaf(arr[l]);
            return;
        }
        int mid = (l+h)/2;
        buildTree(l, mid, idx<<1);
        buildTree(mid+1, h, idx<<1|1);
        nodes[idx].merge(nodes[idx<<1], nodes[idx<<1|1]);
    }
    long long int query(long long int l, long long int h, long long int ql, long long int qh, long long int idx, long long int val){
        if(l>qh || h < ql || l > h) return 0;
        if(l>=ql && h<=qh){
            return ( nodes[idx].v.end() - upper_bound(nodes[idx].v.begin(), nodes[idx].v.end(), val));
        }
        int mid = (l+h)/2;
        return ( query(l, mid, ql, qh, idx<<1, val) + query(mid+1, h, ql, qh, idx<<1|1, val) );
    }
};

int main(){
    long long int n,q,i,x,y,z;
    scanf("%lld", &n);

    for(i = 0; i < n; i++){
        scanf("%lld", &arr[i]);
    }
    Segtree tree(n);
    long long int res;
    scanf("%lld", &q);
    for(i = 0; i < q; i++){
        scanf("%lld %lld %lld", &x, &y, &z);
        res = tree.query(0, n-1, x-1, y-1, 1, z);
        printf("%lld\n", res);
    }
    return 0;
}
