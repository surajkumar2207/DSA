#include<iostream>
#include<vector>
using namespace std;

vector<int> removeDuplicates(vector<int> &v){
    int i = 0;
    int j = 1;
    while(j < v.size()){
    
        if(v[i] !=v[j]){
            int temp = v[i+1];
            v[i+1] = v[j];
            v[j] = temp;
            j++; i++;
        }else if(v[i] == v[j]){
            j++;
        }
    }
      v[i+2] = '\0';
      return v;
}

int main(){
    vector<int> v = {1,3,4,5,5,7,7,7,8,8,9};
    vector<int> ans = removeDuplicates(v);
    for(auto i : v){
        cout<<i<<" ";
    }

    return 0;

}