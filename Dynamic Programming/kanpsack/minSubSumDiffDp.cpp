#include<iostream>
#include<vector>
#include <algorithm>  
using namespace std;

// bool subSum(vector<int> &arr, int sum, int n){
//     if(sum == 0)
//         return true;
//     if(sum < 0 || n <= 0)
//         return false;
    
//     if(sum - arr[n-1] >= 0){
//         return subSum(arr, sum - arr[n-1], n-1) || subSum(arr, sum , n-1);
//     }else
//         return subSum(arr, sum , n-1);
// }


int main(){

    vector<int> v = {1,6,5,11};
    int sum = 0 ;
    for(int i : v)
        sum = sum + i;
    cout<< endl << "sum is : " << sum; 
    int row = v.size()+1;
    int col = sum+1;
    vector<vector<bool>> dp(row, vector<bool>(col));

    for(int i = 0 ; i < col ; i++ )
        dp[0][i] = false;

    for(int i = 0 ; i < row ; i++)
        dp[i][0] = true;
    
    for(int i = 1 ; i < row ; i++){
        for(int j = 1 ; j < col ; j++){
            if(j-v[i-1] >= 0){
                dp[i][j] =  dp[i-1][j-v[i-1]] || dp[i-1][j];
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    int minEle = INT_MAX;

    for(int i = 0 ; i < sum/2 ; i++){
        if(dp[row-1][i] == true){
            minEle = min(minEle, abs(sum - 2*i));
        }
    }

    cout<<endl<<"Min ele : " << minEle;

}