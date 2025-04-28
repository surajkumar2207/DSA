//{ Driver Code Starts
// Initial Template for C++
#include<iostream>
#include<vector>
#include<set>

using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    
    vector< pair<int, int>> visitIsland(vector<vector<int>>& grid, int row, int col,
    int i, int j, vector< vector<int> > &visited ){
        
        int basei = i ; int basej = j;
        queue< pair<int, int>> q;
        q.push({ i , j });
        vector< pair<int, int>> resVector;
        resVector.push_back({abs(basei-i) , abs(basej - j)});
        
        while( !q.empty() ){
            
            pair<int, int> temp = q.front();
            int tempi = temp.first;
            int tempj = temp.second;
            visited[tempi][tempj] = 1;
            q.pop();
            
            cout<<endl<<"Came here 3 ";
            int indexi[4] = {0, -1, 0, 1};
            int indexj[4] = {1, 0, -1, 0};
            
            for(int k = 0 ; k < 4 ; k++){
                
                int resi = tempi + indexi[k];
                int resj = tempj + indexj[k];
                cout<<endl<<"Came here 4 ";
                
                if( resi < row && resi >= 0 && resj < col && resj >= 0 
                && grid[resi][resj] == 1 && visited[resi][resj] == 0){
                  
                    q.push({resi, resj});
                    resVector.push_back({(basei-resi) , (basej - resj)});
                  
                }
                
            }
            
        }

        cout<<endl<<"Came here 5 ";
        
        return resVector;
        
        
        
    }
    
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int row = grid.size();
        int col = grid[0].size();
        set< vector< pair<int, int> > > res;
        
        vector< vector<int> > visited(row, vector<int>(col, 0));
        cout<<endl<<"Came here 1 ";
        
        for(int i = 0 ; i < row ; i++){
            for(int j = 0 ; j < col ; j++){
                
                if(grid[i][j] == 1 && visited[i][j] == 0){
                    cout<<endl<<"Came here 2 ";
                    vector< pair<int, int>> v = visitIsland(grid, row, col, i, j, visited );
                    res.insert(v);
                }
                
            }
        }
        
        return res.size();
        
    }
};



//{ Driver Code Starts.

int main() {

    // int t;
    // cin >> t;
    // while (t--) {
        // int n, m;
        // cin >> n >> m;
        vector<vector<int>> grid = {
            {1, 1, 0, 0, 0},
            {1, 1, 0, 0, 0},
            {0, 0, 0, 1, 1},
            {0, 0, 0, 1, 1}
        };
        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < m; j++) {
        //         cin >> grid[i][j];
        //     }
        // }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    
cout << "~" << "\n";
// }
}
// } Driver Code Ends