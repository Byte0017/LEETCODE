class Solution {
public:
    pair<int, int> solve(TreeNode* root, int& cnt) {
        if (root == NULL) return {0,0};
       
        pair<int,int> l = solve(root->left, cnt);
        pair<int,int> r = solve(root->right, cnt);

        int sum = l.first + r.first + root->val;
        int size = l.second + r.second + 1;
        if(sum/size==root->val) cnt++;
        return {sum,size};
    }

    int averageOfSubtree(TreeNode* root) {
        int cnt = 0;
        solve(root, cnt);
        return cnt;
    }
};