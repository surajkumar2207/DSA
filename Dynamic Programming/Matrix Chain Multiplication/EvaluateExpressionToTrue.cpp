#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>


using namespace std;

unordered_map<string, int> mp;

int mcm(string &s, int i, int j, bool isTrue){

    int boolVal = isTrue ;
    string mapString = to_string(i) + "_" + to_string(j) + "_" + to_string(boolVal);
    
    if(mp.find(mapString)!= mp.end())
        return mp[mapString];

    if( i == j ){
        if(isTrue){
            return  s[i] == 'T';
        }else
            return s[i] == 'F';
    }

    if( i > j ){
        return false;
    }

    int ans = 0;

    for(int k = i+1; k <= j-1 ; k = k+2){

        int lt = mcm(s, i, k-1, true);
        int lf = mcm(s, i, k-1, false);
        int rt = mcm(s, k+1, j, true);
        int rf = mcm(s, k+1, j, false);

        if( s[k]== '&'){
            if(isTrue){ // to make it true;
                ans = ans + lt*rt;
            }else
                ans = ans + lt*rf + lf*rt + lf*rf;

        }else if(s[k] == '|'){

            if(isTrue){ // to make it true
                ans = ans + lt*rf + lf*rt + lt*rt;
            }else
                ans = ans + lf*rf;

        }else if(s[k] == '^'){

            if(isTrue){
                ans = ans + lf*rt + lt*rf;
            }else
                ans = ans + rt*lt + rf*lf;

        } 

    }

    int boolVal1 = isTrue ;
    string mapString1 = to_string(i) + "_" + to_string(j) + "_" + to_string(boolVal1);
    mp[mapString1] = ans;
    return ans;


}

int main(){

    string s = "T^F&T";
    int dim = s.size();

    cout<<mcm(s, 0, s.size()-1, true);
    

    cout<<endl;
    return 0;
}