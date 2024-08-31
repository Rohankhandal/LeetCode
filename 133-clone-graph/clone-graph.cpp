/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void solve(unordered_map<Node*,Node*>&mapping,Node*&newNode,Node*node)
    {
        for(Node*temp:node->neighbors)
        {
            if(mapping.find(temp)!=mapping.end())
            {
                newNode->neighbors.push_back(mapping[temp]);
                // solve(mapping,mapping[temp],temp);
            }
            else
            {   
                Node* newtemp=new Node(temp->val);
                newNode->neighbors.push_back(newtemp);
                mapping[temp]=newtemp;
                solve(mapping,newtemp,temp);
            }
            
            
        }

    }
    Node* cloneGraph(Node* node) {
        if(node==NULL) return NULL;
        unordered_map<Node*,Node*>mapping;
        Node* newNode=new Node(node->val);
        mapping[node]=newNode;
        solve(mapping,newNode,node);
        return newNode;
    }
};