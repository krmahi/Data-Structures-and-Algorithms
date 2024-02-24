// sliding wondow monotonically decreasing queue (deque)

class solution
{
public:
    vector<int> maxslidingwindow(vector<int> &nums, int k)
    {
        dequeu<int> dq;
        vector<int> result;
        int l = 0, r = 0;
        while (r < nums.size())
        {
            while (!dq.empty() && nums[dq.back()] < nums[r])
                dq.pop_back();
            dq.push_back(r);

            if (l > dq.front())
                dq.pop_front();

            if (r + 1 >= k)
            {
                result.push_back(nums[l]);
                l++;
            }
            r++;
        }
        return result;
    }
}