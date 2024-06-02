class codec
{
public:
    serialize(TreeNode *root)
    {
        ostringstream out;
        encode(root, out);
        return out.str();
    }
    deserialize(string data)
    {
        istringstream in(data);
        return decode(in);
    }

private:
    void encode(TreeNode *root, ostringstream &out)
    {
        if (root == NULL)
        {
            out << "null ";
            return;
        }

        out << root->val << " ";

        encode(root->left, out);
        encode(root->right, out);
    }

    TreeNode *decode(istringstream in)
    {
        string data = "";
        in >> data;

        if (data == "null")
            return NULL;

        TreeNode *root = new TreeNode(stoi(data));

        root->left = decode(in);
        root->right = decode(in);

        return root;
    }
};