#include<cstdio>
#include<cmath>

#define MAX 100007
#define MAX2 (100007<<2)

using namespace std;

long long int arr[MAX];
struct Node{
    long long int sum;
    void createLeaf(long long int val){
        sum = val;
    }
    void merge(Node &a, Node &b){
        sum = a.sum + b.sum;
    }
    void update(){
        sum = (long long int)floor(sqrt(sum));
    }
    int shouldUpdate(int l, int h){
        return (sum > (h-l+1));
    }
};

Node tree[MAX2];

void buildTree(int l, int h, int idx){
    if(l > h) return;
    if(l == h){
        tree[idx].createLeaf(arr[l]);
        return;
    }
    int mid = (l+h)>>1;
    buildTree(l, mid, idx<<1);
    buildTree(mid+1, h, idx<<1|1);
    tree[idx].merge(tree[idx<<1], tree[idx<<1|1]);
}

void update(int l, int h, int ql, int qh, int idx){
    if(l>h || l>qh || h<ql) return;
    if(l>=ql && h<=qh){
        int r = tree[idx].shouldUpdate(l, h);
        if(!r) return;
    }
    if(l == h){
        tree[idx].update();
        return;
    }
    int mid = (l+h)>>1;
    update(l, mid, ql, qh, idx<<1);
    update(mid+1, h, ql, qh, idx<<1|1);
    tree[idx].merge(tree[idx<<1], tree[idx<<1|1]);
}

long long int query(int l, int h, int ql, int qh, int idx){
    if(l>h || l > qh || h < ql) return 0;
    if(l>=ql && h<=qh){
        return tree[idx].sum;
    }
    int mid = (l+h)>>1;
    return (query(l, mid, ql, qh, idx<<1) + query(mid+1, h, ql, qh, idx<<1|1));
}

int main(){
    int n,q,i,a,b,c,t;
    int cnt = 1;
    while(scanf("%d", &n) != EOF){
        for(i = 0; i < n; i++)scanf("%lld", &arr[i]);
        buildTree(0, n-1, 1);
        scanf("%d", &q);
        printf("Case #%d:\n", cnt);
        for(i = 0; i < q; i++){
            scanf("%d %d %d", &a, &b, &c);
            if(b > c){
                t = b;
                b = c;
                c = t;
            }
            if(a){
                long long int ans = query(0, n-1, b-1, c-1, 1);
                printf("%lld\n", ans);
            }else{
                update(0,n-1,b-1,c-1,1);
            }
        }
        printf("\n");
        cnt++;
    }
    return 0;
}
