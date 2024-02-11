// sorting //

class solution
{
public:
    int longestconsecutivesequence(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int count = 0;
        int previous = INT_MIN;
        int longest = 1;
        for (auto i : nums)
        {
            if (i - 1 == previous)
            {
                count++;
                previous = i;
            }
            else if (i != previous)
            {
                count = 1;
                previous = i;
            }
            longest = max(longest, count);
        }
        return longest;
    }
}

// hashset //

class solution
{
public:
    int longestconsecutivesequence(vector<int> &nums)
    {
        int n = nums.size();
        unordered_set<int> st(nums.begin(), nums.end());

        if (n == 0)
            return 0;
        if (n == 1)
            return 1;

        int longest = 1;
        for (auto i : st)
        {
            if (!st.count(i - 1))
            {
                int count = 1;
                while (st.count(i + count))
                    count++;
                longest = max(longest, count);
            }
        }
    }
}