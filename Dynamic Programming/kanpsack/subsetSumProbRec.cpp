#include<bits/stdc++.h>

using namespace std;

bool isSubSum(vector<int> &v, int w, int n){
    if(w==0)
        return true;

    if(n==0 || w<0)
        return false;

    if(w - v[n-1] >= 0){

        return isSubSum(v, w - v[n-1], n-1) || isSubSum(v, w, n-1);

    }else
    return isSubSum(v, w, n-1);

}

int main(){
    vector<int> v = {1,3,5,6,8};
    int sum = 12;
    cout<<isSubSum(v, sum, v.size());
    return 0;
}