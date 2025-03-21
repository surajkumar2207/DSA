#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>


using namespace std;

// int maxCount = 0;
// string myStr = "";
// map<int, string> mp;
// int lcs(string &x, string &y, int n, int m){
//     if(n==0 || m==0)return 0;
//         if(x[n-1] == y[m-1]){
            
//             int ans = lcs(x,y, n-1, m-1);
//             ans = ans+1;
//             maxCount = max(maxCount, ans);
//             if(ans!=0)
//                 myStr = myStr + x[n-1];
//             if(myStr.length() >=4)
//                 cout<<endl<<"My String : " << myStr;
//             return ans;
//         }else{
//             string tempString = "";
//             for(auto i : myStr)
//                 tempString = tempString + i;
//             myStr.clear();
//             mp[maxCount] = tempString;
//             int ans1 = lcs(x, y, n-1, m);
//             int ans2 = lcs(x, y, n, m-1);
            
//             return 0;
//         }
        
//     }

int main(){
    // string x = "abmkghioqwerty";
    // string y = "abqakghilqwerty";
    string x = "ahc";
    string y = "abh";


    // lcs(x, y, x.size(), y.size());
    // cout<<maxCount;
    // cout<<endl<< mp[maxCount];

    // for (const auto& pair : mp) {
    //     std::cout << pair.first << " => " << pair.second << std::endl;
    // }
    int row = x.size() +1;
    int col = y.size() +1;
    vector< vector<int> > dp(row, vector<int>(col,0));

    //if have to initiliaze - then 0th row and col should be 0

    for(int i = 1 ; i < row ; i++){
        for(int j = 1 ; j < col ; j++){
            if(x[i-1] == y[j-1]){
                dp[i][j] = 1 +  dp[i-1][j-1];
            }else{
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }

    for(int i = 0 ; i < row ; i ++)
    {
        for(int j = 0 ; j < col ; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<dp[row-1][col-1]<<endl;
    // To get the longest common subsequnce as a string

    string ans = "";
    
    int i = row-1;
    int j = col-1;
     x = "ahc";
     y = "abh";


    cout<<endl<<"Initially \n i : " << i << " , j : " << j<<endl;
    while(i>0 || j>0){
        if(x[i-1] == y[j-1]){
            ans.push_back(x[i-1]) ;
            cout<<endl<<"Common char found to be : " << x[i-1];
            i--;
            j--;
        }else if(dp[i-1][j] > dp[i][j-1]){
            i--;
        }else{
            j--;
        }

        cout<<endl<<"i : " << i << " , j : " << j<<endl;
    }
    reverse(ans.begin(), ans.end());
    cout<<endl<<"Common subsequence is : " << ans<<endl;

    return 0;

}