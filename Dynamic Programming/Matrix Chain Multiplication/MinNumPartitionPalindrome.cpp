#include<iostream>
#include<string>

using namespace std;

bool isPalindrome(string s, int i , int j){

    if(i==j)
        return true;
    else{
        while(i<j){
            if(s[i]!=s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
}

int mcm(string s, int i, int j, vector<vector<int>> &dp){

    if(dp[i][j] != -1)
        return dp[i][j];

    if(i>=j)
        return 0;
    if(isPalindrome(s, i, j) == true)
        return 0;
    
    int minEle = INT_MAX;
    for(int k  = i ; k <= j-1 ; k++){

        int tempAns = mcm(s, i, k, dp) + mcm(s, k+1, j, dp) + 1;
        
        if(tempAns < minEle)
            minEle = tempAns;

    }

    dp[i][j] = minEle;

    return minEle;

    

}

int main(){

    string s = "acbcbd";
    int dim = s.size()+1;
    vector< vector<int>> dp(dim, vector<int> (dim, -1));

    cout<<mcm(s, 0, s.size()-1, dp);

    // cout<<endl<<"Is Palindrome : " << isPalindrome("nitin", 0 , 5-1);

    cout<< endl;
    return 0;
}