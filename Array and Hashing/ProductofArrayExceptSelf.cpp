class solution
{
public:
    vector<int> productexceptself(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n);
        vector<int> l_nums(n);
        vector<int> r_nums(n);
        int l_ans = 1;
        int r_ans = 1;

        for (int i = 1; i < n; i++)
        {
            l_ans *= nums[i - 1] l_nums[i] = l_ans;
        }

        for (int i = n - 2; i >= 0; i--)
        {
            r_ans *= nums[i + 1];
            r_nums[i] = r_ans;
        }

        for (int i = 0; i < n; i++)
        {
            ans[i] = l_nums[i] * r_nums[i];
        }
        return ans;
    }
}