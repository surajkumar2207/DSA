#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main(){

    string x = "aabebcdd";
    string y = "aabebcdd";

    int row = x.size() +1;
    int col = y.size() +1;
    vector< vector<int> > dp(row, vector<int>(col,0));

    //if have to initiliaze - then 0th row and col should be 0



    for(int i = 1 ; i < row ; i++){
        for(int j = 1 ; j < col ; j++){
            if(x[i-1] == y[j-1] && i!= j){
                dp[i][j] = 1 +  dp[i-1][j-1];
                cout<<endl<<"The chars are : " << x[i-1] << " , " << y[j-1]<<endl;
             }else{
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }

    int i = row-1;
    int j = col-1;

    string ans =  "";

    while(i>0 || j >0){
        if(x[i-1] == y[j-1] && i!=j){
            ans = ans + x[i-1];
            i--;
            j--;
        }else{

            if(dp[i-1][j] > dp[i][j-1]){
                i--;
            }
            else    
                j--;

        }

    }
    
    reverse(ans.begin(), ans.end());
    cout<<endl<<"Largest Repeating Subsequence : "<<ans;


    cout<<endl;
    return 0;

}