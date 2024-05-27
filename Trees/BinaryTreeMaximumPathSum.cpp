
// time complexity: O(nlogn)
class solution
{
public:
    int maxSumPath(TreeNode *root)
    {
        int maxsum = INT_MIN;
        maxPath(root, maxsum);
        return maxsum;
    }

private:
    int maxPath(TreeNode *root, int &maxsum)
    {
        if (root == NULL)
            return 0;
        int leftsum = max(0, maxPath(root->left, maxsum));
        int rightsum = max(0, maxPath(root->right, maxsum));
        maxsum = max(maxsum, root->val + leftsum + rightsum);
        return root->val + max(leftsum, rightsum);
    }
};