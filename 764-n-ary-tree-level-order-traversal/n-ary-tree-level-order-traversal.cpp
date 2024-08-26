/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>>ans;
        if(root==NULL) return ans;
        queue<Node*>q;

        //insert src node in queue
        q.push(root);
        q.push(NULL);
        vector<int>tem;
        tem.push_back(root->val);
        ans.push_back(tem);

        vector<int>temp;
        
        while(!q.empty()){
            if(q.front()!=NULL){
              while(q.front()!=NULL){
                  Node* parent=q.front();
                  q.pop();
                  for(auto child:parent->children){
                      q.push(child);
                      temp.push_back(child->val);
                   }
                }
            }

            else if(q.front()==NULL && q.size()==1){
                return ans;
            } 
            else if(q.front()==NULL){
                q.pop();
                q.push(NULL);
                ans.push_back(temp);
                temp.clear();
            }
        }
        return ans;
    }
};