#include <cstdio>
#define FOR(st, ed) for(int i = st; i < ed; i++)
#define FOR2(st, ed) for(int j = st; j < ed; j++)
using namespace std;

int merge(int arr[], int l, int h, int mid){
    int l1 = mid-l+1, l2 = h-mid;
    int left[l1];
    int right[l2];

    FOR(0, l1){
        left[i] = arr[l+i];
    }
    FOR(0, l2){
        right[i] = arr[mid+1+i];
    }

    int i = 0, j = 0, k = l, inv_count = 0;
    while(i < l1 && j < l2){
        if(left[i] <= right[j]){
            arr[k++] = left[i++];
        }
        else {
            arr[k++] = right[j++];
            inv_count += l1-i;
        }
    }

    while(i < l1) arr[k++] = left[i++];
    while(j < l2) arr[k++] = arr[j++];

    return inv_count;
}

int merge_sort(int arr[], int l, int h){
    int mid, inv_count = 0;
    if(l < h){
        mid = (l+h)>>1;
        inv_count+=merge_sort(arr,l, mid);
        inv_count+=merge_sort(arr,mid+1, h);

        inv_count+=merge(arr, l, h, mid);
    }
    return inv_count;
}

int main(){
    int T, N, K;
    int A[100007];
    scanf("%d", &T);
    FOR2(1, T+1){
        scanf("%d %d", &N, &K);
        FOR(0, N){
            scanf("%d", &A[i]);
        }

        int inv_count = merge_sort(A, 0, N-1);
        printf("Case %d: ", j);
        if(K <= inv_count) printf("%d\n", (inv_count-K));
        else {
            K -= inv_count;
            if(K&1){
                int ans = 1;
                FOR(1, N){
                    if(A[i-1] == A[i]){
                        ans = 0;
                        break;
                    }
                }
                printf("%d\n", ans);
            }
            else printf("0\n");
        }
    }
}