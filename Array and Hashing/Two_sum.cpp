// brute force //

class solution
{
public:
    vector<int> twosum(vector<int> &nums, int target)
    {
        int n = nums.size();
        // vector<int> sum;
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    // sum.push_back(i);
                    // sum.push_back(j);
                    // or
                    return { i, j }
                    // break;
                }
            }
        }
        // return sum;
        throw;
    }
}

// hashmap using count //

class solution
{
public:
    vector<int> twosum(vector<int> &nums, int target)
    {
        unordered_map<int> mp;

        for (int i = 0; i < nums.size(); i++)
        {
            int count = target - nums[i];
            if (mp.count(count))
                return {mp[count], i};
            mp[nums[i]] = i;
        }
        throw;
    }
}

// hashmap using find //

class solution
{
public:
    vector<int> twosum(vector<int> &nums, int target)
    {
        unordered_map<int> mp;

        for (int i; i < nums.size(); i++)
        {
            int count = target - nums[i];
            if (mp.find(count) != mp.end())
                return {mp[count], i};
            mp[nums[i]] = i;
        }
        throw;
    }
}