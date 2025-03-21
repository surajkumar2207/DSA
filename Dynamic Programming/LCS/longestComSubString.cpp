#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;
int maxCount = 0;
int lcs(string &x, string &y, int n, int m){
    if(n==0 || m==0)return 0;
        if(x[n-1] == y[m-1]){
            int ans = lcs(x,y, n-1, m-1);
            ans = ans+1;
            maxCount = max(maxCount, ans);
            return ans;
        }else{
            int ans1 = lcs(x, y, n-1, m);
            int ans2 = lcs(x, y, n, m-1);
            return 0;
        }
        
    }

int main(){
    string x = "abmkghioqwerty";
    string y = "abqakghilqwerty";


    lcs(x, y, x.size(), y.size());
    cout<<maxCount;


    return 0;

}