// Hashmap //

class solution
{
public:
    vector<int> topkfreqelements(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;

        for (auto i : nums)
            mp[i]++;

        vector<pair<int, int>> vec;
        for (auto i : mp)
            vec.push_back(i);

        sort(vec.begin(), vec.end(), [](auto a, auto b)
             { return a.second > b.second; });

        vector<int> ans;
        for (auto i : vec)
        {
            if (ans.size() >= k)
                break;
            ans.push_back(i.first);
        }
        return ans;
    }
}