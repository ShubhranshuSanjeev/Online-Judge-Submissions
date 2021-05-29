#include <iostream>
#include <unordered_map>
#include <vector>
#include <iterator>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        unordered_map<string, vector<int>> trainSet;
        for(int i = 0; i < n; i++){
            string w; int b;
            cin >> w >> b;
            if (trainSet.find(w) == trainSet.end()){
                vector<int> v; v.push_back(b);
                trainSet[w] = v;
            }
            else{
                trainSet[w].push_back(b);
            }
        }
        unordered_map<string, vector<int>> :: iterator it;
        int total = 0;
        for(it = trainSet.begin(); it != trainSet.end(); it++){
            int size = it->second.size();
            int c0 = 0, c1 = 0;
            for(int i = 0; i < size; i++){
                if(it->second[i] == 0) c0+=1;
                else c1+=1;
            }
            total+= c1 >= c0 ? c1 : c0;
        }
        cout << total << "\n";
    }
    return 0;
}

