#include <cstdio>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

#define MAX 200007
#define MAX2 (MAX << 3)
using namespace std;

int arr[MAX], temp[MAX];
char operations[MAX];
struct Node{
    int num;
    void assignLeaf(){
        num = 0;
    }
    void merge(Node &a, Node &b){
        num =  a.num + b.num;
    }
    int getValue(){
        return num;
    }
};

Node nodes[MAX2];
class Segtree{
public:
    int N;
    Segtree(int n){
        N = n;
        buildTree(0, n-1, 1);
    }
    void buildTree(int l, int h, int idx){
        if(l == h){
            nodes[idx].assignLeaf();
            return;
        }
        int mid = (l+h)>>1;
        buildTree(l, mid, idx<<1);
        buildTree(mid+1, h, (idx<<1|1));
        nodes[idx].merge(nodes[idx<<1], nodes[idx<<1|1]);
    }
    void update(int ql, int qh, int val){
        updateTree(0, N-1, ql, qh, val, 1);
    }
    void updateTree(int l, int h, int ql, int qh, int val, int idx){
        if(l>qh || h<ql || l > h)return;
        if(l>=ql && h<=qh){
            nodes[idx].num = val;
            return;
        }
        int mid = (l+h)>>1;
        updateTree(l, mid, ql, qh, val, (idx<<1));
        updateTree(mid+1, h, ql, qh, val, (idx<<1|1));
        nodes[idx].merge(nodes[idx<<1], nodes[idx<<1|1]);
    }
    int search(int l, int h, int k, int idx){
        if(nodes[idx].num < k) return -1;
        if((h-l+1)== k) return h;

        int mid = (l+h)>>1;
        int left = nodes[idx<<1].num;

        if(left >= k) return search(l, mid, k, idx<<1);
        else return search(mid+1, h, k-left, idx<<1|1);
    }

    Node query(int l, int h, int ql, int qh, int idx){
        if(l > h || l > qh || h < ql) return ((Node){0});
        if(l>=ql && h<=qh) return nodes[idx];
        int mid = (l+h)>>1;
        Node left = query(l, mid, ql, qh, idx<<1);
        Node right = query(mid+1, h, ql, qh, idx<<1|1);
        Node result;
        result.merge(left, right);
        return result;
    }
};
int main(){
    int q,i;
    scanf("%lld", &q);
    unordered_map<int,int> numbers;
    unordered_map<int,int> snum;
    for(i = 0; i < q; i++){
        scanf(" %c", &operations[i]);
        scanf("%d", &arr[i]);
        temp[i]=arr[i];
    }
    sort(temp, temp+q);
    Segtree tree(q);
    for(i = 0; i < q; i++){
        numbers[temp[i]] = i;
    }
    for(i = 0; i < q; i++){
        int idx = numbers[arr[i]];
        switch(operations[i]){
            case 'I':
                if(snum.find(idx) == snum.end() || !snum[idx]){
                    tree.update(idx,idx,1);
                    snum[idx] = 1;
                }
                break;
            case 'D':
                if(snum.find(idx) != snum.end() && snum[idx]){
                    tree.update(idx,idx,0);
                    snum[idx] = 0;
                }
                break;
            case 'K':
                if(arr[i] < 1 || arr[i] > nodes[1].num){
                    printf("invalid\n");
                }
                else{
                    int ans = temp[tree.search(0, q-1, arr[i], 1)];
                    if(ans == -1) printf("invalid\n");
                    else printf("%d\n", ans);
                }
                break;
            case 'C':
                if(idx == 0) printf("0/n");
                else printf("%d\n", tree.query(0, q-1, 0, idx-1, 1).num);
                break;
        }
    }
    return 0;
}
