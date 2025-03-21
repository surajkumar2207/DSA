#include<iostream>
#include<vector>

using namespace std;


class Solution {
    vector<int> myAns ;
    public:

         int cointCount(vector<int> &coins, int sum, int n, int ways){
            if(sum == 0)
                return ways;
            if(sum < 0 || n <= 0)
                return 0;
            int ans = 0;
            if(sum - coins[n-1] >=0){
                int ans =  cointCount(coins, sum-coins[n-1], n, ways+1) +
                            cointCount(coins, sum, n-1, ways) ;
                
                myAns.push_back(ans);
                return ans;
            }
            int  ans1 =  cointCount(coins, sum, n-1, ways );
            myAns.push_back(ans1);
                return ans1;


        }
    
        int coinChange(vector<int>& coins, int amount) {
            return cointCount(coins, amount, coins.size(),0);
        }

        void showSol(){
            for(auto i : myAns){
                cout<<i<<" ";
            }
        }
    };

    int main(){

        Solution mySol = Solution();

        vector<int> coins = {1,2,5};
        int amount  = 11;
        cout<<mySol.coinChange(coins, amount);
        cout<<endl;
        mySol.showSol();
        return 0;
    }