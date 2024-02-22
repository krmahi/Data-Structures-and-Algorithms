class solution
{
public:
    string minWindow(string s, string t)
    {
        int n = t.size(), m = s.size(), l = 0, r = 0, counter = n, shortstr = INT_MAX, startindex;
        unordered_map<char, int> mp;

        for (auto ch : t)
            mp[ch]++;

        while (r < m)
        {
            if (mp[s[r]])
                > 0 counter++;
            mp[s[r]]--;
            r++;

            while (counter == n)
            {
                if (r - l < shortstr)
                {
                    shortstr = r - l;
                    startindex = l;
                }
                mp[s[l]]++;
                if (mp[s[l]] > 0)
                    counter--;
                l++;
            }
        }
        if (shortstr != INT_MAX)
            return s.substr(startindex, shortstr);
        return "";
    }
};