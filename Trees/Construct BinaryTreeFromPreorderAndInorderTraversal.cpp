
class Solution
{
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        int index = 0;
        return build(vector<int> & preorder, index, vector<int> inorder, 0, inorder.size() - 1);
    }

private:
    TreeNode *build(vector<int> &preorder, int &index, vector<int> &inorder, int start, int end)
    {
        if (start > end)
            return NULL;

        TreeNode *root = new TreeNode(preorder[index]);

        // finding index of root in inorder
        int split = 0;
        for (int = 0; i <= end; i++)
        {
            if (inorder[i] == preorder[index])
            {
                split = i;
                break;
            }
        }

        index++;
        root->left = build(preorder, index, inorder, start, split - 1);
        root->right = build(preorder, index, inorder, split + 1, end);
        return root;
    }
};