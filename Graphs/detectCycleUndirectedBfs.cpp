#include<iostream>
#include<queue>
#include<vector>

using namespace std;

// bool isCycle(vector<vector<int>>& grid){
//     int size = grid.size();
//     vector<int> visited(size, 0);
//     queue< pair<int,int> > q;
//     int node = grid[0][0];
//     q.push({node, -1});
//     while( !q.empty()){
//         pair<int, int> temp = q.front();
//         int node = temp.first;
//         int parent = temp.second;
//         for(auto i : grid[temp.first]){
//             if(visited[i] == 0){
                
//                 q.push({i, temp.first});
//                 visited[i] = 1;
//             }else if(parent != i){ // Means it is visited; hence there is the 
//                 return true; //either it is going to be the node coming from the same or the loop one.
//                 cout<<endl<<"Cycle detected ";
//             }
//         }
//     }

// }

bool isCycle(vector<int> grid[], int size){ // By bfs
    vector<int> visited(size, 0);
    queue< pair<int,int> > q;
    int node = 0;
    q.push({node, -1});
    
    visited[node] = 1;
    while( !q.empty()){

        pair<int, int> temp = q.front();
        int node = temp.first;
        int parent = temp.second;
        cout<<endl<<"Printing pairs";
        cout<<endl<<"( " << node<<" , " << parent << " )";
        q.pop();
        for(auto i : grid[node]){
            
            if(visited[i] == 0 ){

                cout<<endl<<"Pushed : " <<endl<<"( " << node<<" , " << parent << " )";
                q.push({i, temp.first});
                visited[node] = 1;

            }else if(parent != i){ // Means it is visited; hence there is the 
                // return true; //either it is going to be the node coming from the same or the loop one.
                return true;
                cout<<endl<<"Cycle detected ";
            }
        }
    }
    return false;

}

bool dfs(vector<int> v[], int node, int parent, vector<int> &visited){
    bool result = false;
    for(auto i : v[node]){
        if(visited[i] == 0){
            visited[i] = 1;
            cout<<endl<<"Came here, i =  " << i << " , node = " << node << " , parent = " << parent;
            result = dfs(v, i, node, visited);
        }else if(node != parent){
            cout<<endl<<"Came here true, i =  " << i << " , node = " << node << " , parent = " << parent;
            return true;
        }
        
    }

    return result;

}

int main(){

    vector<int> v[6];
    vector< vector<int>> matrix = {
        {0 , 1 , 1 , 0 , 0, 0},
        {1, 0, 0, 1, 0, 0},
        {1, 0 , 0 , 1, 0 , 0},
        {0, 1, 1, 0, 0, 0},
        {0, 0, 1, 0, 0, 1},
        {0, 0, 0, 0, 1, 0}
    };

    for(int i = 0 ; i < 6 ; i++){
        for(int j = 0 ; j < 6 ; j++){
            if(matrix[i][j]==1)
                v[i].push_back(j);
        }
    }

    for(int i = 0 ; i < 6 ; i++){
        cout<<endl<<i<<" : ->  " ;
        for(auto j : v[i]){
            cout<< j << " ";
        }
    }
    
    cout<<endl<< "By BFS : " << endl;
    
    if(isCycle(v,6))
        cout<<endl<<"there is a cycle";
    else
        cout<<endl<<"No cycle";

    cout<<endl<< "By DFS : " << endl;
    vector<int> visited(6, 0);
    if(dfs(v,0, -1, visited))
        cout<<endl<<"there is a cycle";
    else
        cout<<endl<<"No cycle";
    
    cout<<endl;
    
    return 0;


}