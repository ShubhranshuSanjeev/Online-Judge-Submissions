#include <cstdio>
#include <vector>
#include <algorithm>

int main(){
    int t,n,arr[100007];
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);

        for(int i = 0; i < n; i++){
            scanf("%d", &arr[i]);
        }

        std::vector<int> stacks;
        for(int i = 0; i < n; i++){
            if(i == 0) stacks.push_back(arr[0]);
            else {
                int pos = upper_bound(stacks.begin(), stacks.end(), arr[i]) - stacks.begin();
                if(pos == stacks.size()) stacks.push_back(arr[i]);
                else stacks[pos] = arr[i];
            }
        }
        printf("%d ", stacks.size());
        for(auto i = stacks.begin(); i != stacks.end(); i++){
            printf("%d ", *i);
        }
        printf("\n");
    }
    return 0;
}