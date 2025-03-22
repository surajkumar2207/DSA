#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

/*

*/

int main(){

    string x = "abs";
    string y = "acb";
    int row = x.size()+1;
    int col = y.size()+1;


    vector< vector <int> > dp (row, vector<int>(col,0));

    for(int i = 1 ; i < row ; i++){
        for(int j = 1 ; j < col ; j++){
            if(x[i-1] == y[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    cout << endl << "lcs of x = " << x << " , and y = " << y << " = " << dp[row-1][col-1] << endl;
    // size = 3 , row = 4.  row = 3. 3-1 = 2 => for string
    //

    int i = row-1;
    int j = col-1;
    string ans = " ";

    while(i>0 || j >0){
        if(x[i-1] == y[j-1]){
           ans = ans + x[i-1];
           i--;
           j--; 
        }else{
            if(dp[i-1][j] > dp[i][j-1]){
                ans = ans + x[i-1];
                i--;
            }else{
                ans = ans + y[j-1];
                j--;
            }
        }
    }

    while(i> 0){
        ans = ans + x[i-1];
    }

    while(j>0){
        ans = ans + y[j-1];
    }
    reverse(ans.begin(), ans.end());
    cout<<endl<<"Common super subsequnce is : " << ans << endl;




    return 0;

}