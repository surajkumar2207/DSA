#include<iostream>
#include<string>

using namespace std;

int main(){


    string x = "axyz";
    string y = "adxcpy";

    int row = x.size() +1;
    int col = y.size() +1;
    vector< vector<int> > dp(row, vector<int>(col,0));

    //if have to initiliaze - then 0th row and col should be 0



    for(int i = 1 ; i < row ; i++){
        for(int j = 1 ; j < col ; j++){
            if(x[i-1] == y[j-1]){
                dp[i][j] = 1 +  dp[i-1][j-1];
                cout<<endl<<"The chars are : " << x[i-1] << " , " << y[j-1]<<endl;
             }else{
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }

    int i = row-1;
    int j = col-1;
    string ans = "";

    while(i>0 || j >0){
        if(x[i-1] == y[j-1]){
           ans = ans + x[i-1];
           i--;
           j--; 
        }else{
            if(dp[i-1][j] > dp[i][j-1]){
                i--;
            }else{
                j--;
            }
        }
    }
    cout<<endl<<"LCS is  : " << ans;

    reverse(ans.begin(), ans.end());

    if(x.size() ==  ans.size())
        cout<<endl<<"True from lcs";
    else
        cout<<endl<<"False from lcs";

    // Second approach - use 2 pointers

    int m = 0;
    int n = 0;

    cout<<endl<<"String x = " << x << " , y = " << y<<endl;

    while( m < x.size() || n < y.size() ){
        if(x[m] == y[n]){
            cout<<endl<<"At x[m] << " << x[m] << " , at y[n] : " << y[n] <<endl;
            m++;
            
        }
        n++;
    }
    cout<< endl<< m<<endl;

    if(m == x.size()){
        cout<<endl<<"True from two pointers";
    }else
        cout<<endl<<"False from two pointers";



    



    cout<<endl;
    return 0;
}