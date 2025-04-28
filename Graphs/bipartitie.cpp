#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
    public:
    
        bool isIt(vector<vector<int>>& graph, vector<int> &visited,  vector< int > &colour, int sentNode){
    
            queue<int> q ;
            q.push(sentNode);
    
            colour[sentNode] = 1;
            visited[sentNode] = 1;
    
            while( !q.empty() ){
    
                int temp = q.front();
                q.pop();
                visited[temp] = 1;
                int tempColour = colour[temp];
                int expectedColour = tempColour == 1 ? 0 : 1;
    
    
                for(int i = 0 ; i < graph[temp].size() ; i++){
                    
                    int node = graph[temp][i];
                    
                    if( colour[node] == -1 ){ // not traversed
                        q.push(node);
                        colour[node] = expectedColour;
                        visited[node] = 1;
                    }
                    else if( colour[node] != expectedColour ){
                        return false;
                    } 
                    
                }
    
            }
    
            return true;
        }
    
        bool isBipartite(vector<vector<int>>& graph) {
            
    
            /*
            1 - {2, 3, 4}
            take colour of i = 0 
            2 - {3, 5}
            */
    
            int size = graph.size();
            if(size == 0)
                return true;
    
            vector< int > colour (size , -1);
            vector<int> visited(size, 0);
    
            for(int i = 0 ; i < size ; i++){
    
                if( visited[i] == 0 ){
                    // if( isIt(graph, visited, colour, i) ){
    
                    // }
                    if(dfs(graph, visited, colour, 0 , 0 ))
                    {
    
                    }
                    else return false;
                }
            }
    
            return true;
    
        }
    
    
        bool dfs(vector<vector<int>>& graph, 
        vector<int> &visited, 
        vector< int > &colour, 
        int sentNode, int sentColour ){
    
            int expectedColour = sentColour == 1 ? 0 : 1 ;
            visited[sentNode] = 1;
            for(int i = 0 ; i < graph[sentNode].size() ; i++ ){
                
                if( colour[i] == -1 ){
                    visited[i] = 1;
                    colour[i] = expectedColour;
                    bool ans = dfs(graph, visited, colour, i, expectedColour);
                    if(ans == false)
                        return false;
                }
               else  if( colour[i] == sentColour  && i != sentNode){
                    return false;
                }
                
            }
    
            return true;
        }
    
    };