#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr = {1,3,5,6,8};
    int sum = 23;
    
    int n = arr.size() + 1;
    int w = sum +1;

    vector< vector<bool> > v(n , vector<bool>(w));
    //initialize 
    for(int i = 0 ; i < w ; i++)
        v[0][i] = false;

    for(int i = 0; i < n ; i++)
        v[i][0] = true;

    for(int i = 1 ; i < n ; i++){
        for(int j = 1 ; j < w ; j++){
            if( j-arr[i-1] >= 0){
                v[i][j] = (v[i-1][j- arr[i-1]] || v[i-1][j]);
            }else{
                v[i][j] = v[i-1][j];
            }
        }
    }

    cout<<v[n-1][w-1];

    return 0;
}