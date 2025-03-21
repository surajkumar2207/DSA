#include<bits/stdc++.h>
using namespace std;

vector<int> selection(vector<int> &v){
    int n = v.size();
    int min = 0;

    for(int i = 0  ; i < n-1 ; i++){
        min = i;
        for(int j = i ; j < n ; j++){
            if(v[j] < v[min]){
                min = j;
            }
        }

        swap(v[i], v[min]);
        // int temp = v[i];
        // v[i] = v[min];
        // v[min] = temp;
        
    }
    return v;

}

int main(){
    vector<int> v = {13, 46, 24, 52, 20, 9, 1 , 8};
    vector<int> res = selection(v);
    for(auto i: res){
        cout<<i<<" ";
    }
    return 0;
}