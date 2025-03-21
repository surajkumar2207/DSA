#include<bits/stdc++.h>

using namespace std;

int minSubSum(vector<int> &v, int n, int minEle){
    if(n ==  0)
        return v[n];
    if(n < 0)
        return 0;
    
    return min(INT_MAX, abs((minSubSum(v, n-1, minEle) + v[n-1] ) - (minSubSum(v, n-1, minEle))) );

}


int main(){

    vector<int> v = {1,6,5,11};
    int n = v.size();

    cout<< minSubSum(v, n, INT_MAX);


}