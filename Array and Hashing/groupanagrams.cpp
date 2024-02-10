// hashmap //

class solution
{
public:
    vector<vector<string>> groupanagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> mp;
        for (auto i : strs)
        {
            string temp = i;
            sort(temp.begin(), temp.end());

            if (mp.find(temp != mp.end()))
                mp(temp).push_back(i);
            else
                mp[temp] = {i};
        }

        vector<vector<string>> result;
        for (auto i : mp)
            result.push_back(mp[i.second]);

        return result;
    }