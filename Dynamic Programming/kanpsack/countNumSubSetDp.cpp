#include<iostream>
#include<vector>

using namespace std;

int main(){
    vector<int> arr = { 2, 4, 3, 1, 6};
    int sum = 26;


    int row = arr.size() + 1;
    int col = sum+1;

    vector< vector<int> > v (row, vector<int>(col));
    
    for(int i = 0 ; i <col ; i ++ )
        v[0][i] = 0;
    
    for(int i = 0 ; i < row ; i++)
        v[i][0] = 1;

    for(int i = 1 ; i < row ; i++){
        for(int j = 1 ; j < col ; j++){
            if(j-arr[i-1] >= 0){
                v[i][j] = v[i-1][j-arr[i-1]] + v[i-1][j];
            }else
            v[i][j] = v[i-1][j];
        }
    }

    cout<<v[row-1][col-1];


    return 0;

}