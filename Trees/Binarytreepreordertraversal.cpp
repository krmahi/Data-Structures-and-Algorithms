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

// recursion
//  time | space
//  O(n) | O(n)
class Solution
{
public:
    vector<int> ans;
    vector<int> preorderTraversal(TreeNode *root)
    {
        if (root == NULL)
            return {};
        ans.push_back(root->val);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
        return ans;
    }
};

// iterative
// time | space
// O(n) | O(n)

class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        stack<TreeNode *> st;
        st.push(root);
        while (!st.empty())
        {
            auto node = st.top();
            st.pop();
            if (node)
            {
                st.push(node->right);
                st.push(node->left);
            }
            ans.push_back(node->val);
        }
        return ans;
    }
};