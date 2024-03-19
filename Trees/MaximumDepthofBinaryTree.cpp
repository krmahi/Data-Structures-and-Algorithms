/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// recursive dfs
// time | space
// O(n) | O(1)

class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);
        return 1 + max(lh, rh);
    }
};

// stack
// time | sapce
// O(n) | O(n)

class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        stack<pair<TreeNode *, int>> st
            st.push({root, 1});
        res = 1;
        while (!st.empty())
        {
            auto [node, depth] = st.top();
            st.pop();
            if (node)
            {
                res = max(res, depth);
                if (node->left)
                    st.push(node->left, 1 + depth);
                if (node->right)
                    st.push(node->right, 1 + depth);
            }
        }
        return res;
    }
};