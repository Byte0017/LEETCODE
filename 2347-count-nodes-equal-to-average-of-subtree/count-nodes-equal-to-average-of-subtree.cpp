class Solution {
public:
    int size(TreeNode* root) {
        if (root == NULL) return 0;
        return 1 + size(root->left) + size(root->right);
    }

    int solve(TreeNode* root, int& cnt) {
        if (root == NULL) return 0;
        if (root->left == NULL && root->right == NULL) {
            cnt++;
            return root->val;
        }
        int l = solve(root->left, cnt);
        int r = solve(root->right, cnt);

        int n = size(root);
        int avg = (l + r + root->val) / n;
        if (avg == root->val) cnt++;
        return l + r + root->val;
    }

    int averageOfSubtree(TreeNode* root) {
        int cnt = 0;
        solve(root, cnt);
        return cnt;
    }
};