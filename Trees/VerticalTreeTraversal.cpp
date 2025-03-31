#include<iostream>
#include<vector>
#include<map>
#include <sstream>

using namespace std;

class Node {
    public:
      int data;
      Node* left;
      Node* right;
  
      // Constructor to initialize a new node
      Node(int val) {
          data = val;
          left = NULL;
          right = NULL;
      }
  };

  // Function for Inorder Traversal
void printInorder(Node* root) {
    if (!root)
        return;

    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}


Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node* root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


vector<int> topView(Node *root) {
    // code here
    
    vector<int> ans;
    if(root == NULL)    
        return ans;
    
    map < int , map < int, vector<Node*> > > nodes;
    queue < pair < Node* , pair<int, int> > > q;
    q.push(make_pair(root, make_pair(0,0)));
    while (!q.empty()){
        
        pair < Node* , pair<int, int> > temp = q.front();
        q.pop();
        
        Node *firstNode = temp.first;
        int hD = temp.second.first;
        int level = temp.second.second;
        
        // if( nodes.find(hD) == nodes.end())  ->put this condition to find top view.
            nodes[hD][level].push_back(firstNode);
        
        if(firstNode->left != NULL)
            q.push(make_pair(firstNode->left, make_pair(hD-1, level+1)));
        
        if(firstNode->right != NULL)
            q.push(make_pair(firstNode->right, make_pair(hD+1, level+1)));
        
    }
    
    for(auto i : nodes)
        for (auto j : i.second)
            for (auto k : j.second)
                ans.push_back(k->data);
    
    return ans;
    
}


int main(){

    string input = "1 2 3 4 5 6 7 N N N N N 8 N 9";
    
    Node *root = buildTree(input);
    vector<int> ans;

    ans = topView(root);

    cout<<endl<<"Printing Inorder : " ;
    printInorder(root);

    cout<<endl<<"Now Printing top view : ";
    for(auto i : ans){
        cout<<i<<" ";
    }

    cout<<endl;
    return 0;

}

