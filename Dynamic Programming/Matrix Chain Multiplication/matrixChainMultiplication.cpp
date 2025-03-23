#include<iostream>
#include<string>
#include<vector>

using namespace std;

int mcm(vector<int> &arr, int i, int j, vector<vector<int>> &dp){

    // if(dp[i][j] != -1)
        // return dp[i][j];
    
    if( i >= j )
        return 0;

    int minEle = INT_MAX;

    for(int k = i ; k <= j-1 ; k++){

        cout<<endl<<"i = " << i << " , k = " << k << " , j = " << j << ", function calls : mcm(i = " << i << " , k = " << k << " , mcm( k+1 = " 
        << k+1 << " , j = " << j ; 

        int tempAns = mcm(arr, i , k,dp) +  mcm(arr, k+1, j,dp) + ( arr[i-1] * arr[k] * arr[j] ); 
        cout<<endl<<"tempAns : " << tempAns << endl;
        if(tempAns < minEle)
            minEle = tempAns;
    }
    // dp[i][j] = minEle;
    return minEle;

}

int main(){

    vector<int> v = {40, 20, 30, 10, 30};
    int row = v.size()+1;
    int col = row;
    vector< vector<int> > dp (row, vector<int>(col, -1));

    cout<<endl<<"The answer is  : ";
    cout<< mcm(v, 1, v.size()-1, dp);

    cout<<endl;
    return 0;
}