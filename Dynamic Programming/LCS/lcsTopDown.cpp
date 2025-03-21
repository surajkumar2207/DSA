#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int lcs(string x, string y, int n, int m){
    if(n == 0 || m == 0)
        return 0;
    if(x[n-1] == y[m-1] ){
        return 1 + lcs(x, y, n-1, m-1);
    }
    else
        return max( lcs(x, y, n-1, m), lcs(x, y, n, m-1));
}

int main(){
    string x = "abckpoiuypou";
    string y = "abmklpioyoyo";
    int row = x.size()+1;
    int col = y.size()+1;

    vector< vector<int> > dp(row, vector<int> (col));

    for(int i = 0 ; i < row ; i++)
        dp[i][0] = 0;
    for(int i = 0 ; i < col ; i++)
        dp[0][i] = 0;

    for(int i = 1 ; i < row ; i++){
        for(int j = 1 ; j < col ; j++){
            if(x[i-1] == y[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }else{
                dp[i][j] =  max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    cout<<lcs(x, y, x.size(), y.size());
    cout<<endl;
    cout<<dp[row-1][col-1];

    return 0;

}

// To be loved, to be loved unconditionally feels like a dream.
// To be loved unconditionally almost feels unreal, not true. 
// Unconditional love almost feels like a lie to me unless I see you, Maa.
