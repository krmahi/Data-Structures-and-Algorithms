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
// time | space
// O(n) | O(n)
class Solution
{
public:
    vector<int> ans;
    vector<int> postorderTraversal(TreeNode *root)
    {
        if (root == NULL)
            return {};
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        ans.push_back(root->val);
        return ans;
    }
};

// iterative
// time | space
// O(n) | O(n)

class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        if (root == NULL)
            return {};
        vector<int> ans;
        stack<TreeNode *> st1;
        stack<TreeNode *> st2;
        st1.push(root);
        while (!st1.empty())
        {
            auto node = st1.top();
            st1.pop();
            if (node)
            {
                st2.push(node);
                st1.push(node->left);
                st1.push(node->right);
            }
        }

        while (!st2.empty())
        {
            ans.push_back(st2.top()->val);
            st2.pop();
        }
        return ans;
    }
};