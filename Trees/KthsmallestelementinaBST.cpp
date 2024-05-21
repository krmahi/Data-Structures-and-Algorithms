
// vector , sorting
// time: O(nlogn) | space: O(n)
// worse time and space complexity
class solution
{
public:
    vector<int> ans;
    vector<int> inorder(TreeNode *root)
    {
        if (root == NULL)
            return ans;
        inorder(root->left);
        ans.push_back(root->val);
        inorder(root->right);
        return ans;
    }

    int kthsmallestelementinaBST(TreeNode *root, int k)
    {
        inorder(root);
        // sorting
        sort(ans.begin(), ans.end());
        return ans[k - 1];
    }
};

// optimised sorting
// time: O(nlogn) | space: O(1)

class solution
{
public:
    int inorder(TreeNode *root, int k, int &result)
    {
        if (root == NULL)
            return;
        inorder(root->left, k, result);
        k--;
        if (k == 0)
        {
            result = root->val;
            return;
        }
        inorder(root->right, k, result);
    }
    int kthsmallestelementinaBST(TreeNode *root, int k)
    {
        result = 0;
        inorder(root, k, result);
        return result;
    }
};
