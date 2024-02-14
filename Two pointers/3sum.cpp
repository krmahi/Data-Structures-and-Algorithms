class solution
{
public:
    vector<vector<int>> threesum(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> result;
        unordered_st<string> st;
        int i, j, k;
        if (n < 3)
            return result;
        sort(nums.begin(), nums.end());
        for (i = 0; i < n - 2; i++)
        {
            int sumtofind = o - nums[i];
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            j = i + 1;
            k = n - 1;
            while (i < j)
            {
                sum = nums[j] + nums[k];
                if (sum < sumtofind)
                    j++;
                else if (sum > sumtofind)
                    k--;
                else
                {
                    result.push_back({nums[i], nums[j], nums[k]});
                    // removing duplicates //
                    while (j < k && nums[j] == nums[j + 1])
                        j++;
                    while (k > j && nums[k] == nums[k - 1])
                        k--;
                    j++;
                    k--;
                }
            }
        }
        return result;
    }
}

// using a set // (more space)

class solution
{
public:
    vector<vector<int>> threesum(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> result;
        unordered_st<string> st;
        int i, j, k;
        if (n < 3)
            return result;
        sort(nums.begin(), nums.end());
        for (i = 0; i < n - 2; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            j = i + 1;
            k = n - 1;
            while (i < j)
            {
                sum = nums[i] + nums[j] + nums[k];
                if (sum < target)
                    j++;
                else if (sum > target)
                    k--;
                else
                    vector<int> pattern = {nums[i], nums[j], nums[k]};
                string key = to_string(nums[i]) + ',' + to_string(nums[j]) + ',' + to_string(nums[k]);
                if (!st.count(key))
                {
                    result.push_back(pattern);
                    st.insert(key);
                }
                pattern.clear();
                j++;
                k--;
            }
        }
        return result;
    }
}