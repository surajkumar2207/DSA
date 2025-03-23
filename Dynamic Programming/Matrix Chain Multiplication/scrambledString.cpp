#include<iostream>
#include<vector>
#include<string>

using namespace std;

unordered_map<string, bool> mp;

bool mcm(string a, string b){

    if(a.compare(b) == 0)
        return true;

    if(a.size()!= b.size())
        return false;

    if(a.size() <= 1)
        return false;
    
    string mpString = a + "_" + b;

    if( mp.find(mpString) != mp.end() )
        return mp[mpString];

    
    bool flag = false;

    int n = a.size();
    for(int i = 1 ; i < a.size() ; i++){
        
        bool condition1 = ( mcm(a.substr(0,i), b.substr(n-i, i)) ) && ( mcm( a.substr(i, n-i), b.substr(0, n-i) ) );
        bool conditiin2 = ( mcm(a.substr(0,i), b.substr(0, i)) ) && ( mcm( a.substr(i, n-i), b.substr(i, n-i) ) );

        if(condition1 || conditiin2)
            flag = true;
        if(flag == true)
            break;

    }

    string str = a + "_" + b;
    mp[str] = flag;

    return flag;


}

int main(){

    string a = "great";
    string b = "rgate";

    if(a.size() != b.size())
        cout<<false;
    if(a.size() == 0 && b.size() == 0)
        cout<< true;
    if(a.compare(b) == 0)
        cout<<true;


    cout<<mcm(a,b);

    cout<<endl;

    return 0;

}