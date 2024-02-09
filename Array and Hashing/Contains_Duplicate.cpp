
// Brute force //
class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (nums[i] == nums[j])
                    return true;
            }
        }
        return false;
    }
}

// sorting //

class solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++)
        {
            if (nums[i] == nums[i + 1])
                return true;
        }
        return false;
    }
}

// using set //

class solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_set<int> set;
        for (int i : nums)
        {
            if (set.count(i) == 1)
                return true;
            set.insert(i)
        }
    }
}

// using map //

class solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_map<int, int> map;

        for (int i : nums)
        {
            if (map[i] == 1)
                return true;
            map[i]++;
        }
    }
}