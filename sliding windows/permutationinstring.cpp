// sliding window

class solution
{
public:
    bool checkinclusion(string s1, string s2)
    {
        int n = s1.size(), m = s2.size(), l = 0, r, count = n;
        unordered_map<char, int> mp;

        if (n > m)
            return false;

        for (auto ch : s1)
            mp[ch]++;

        while (r < m)
        {
            if (mp[s2[r]] > 0)
                count--;
            mp[s2[r]]--;
            r++;

            if (count == 0)
                return true;

            if (r - l == n)
            {
                if (mp[s2[left]] >= 0)
                    count++;
                mp[s2[l]]++;
                i++
            }
        }
        return false;
    }
}

// neetcode sliding window

class solution
{
public:
    bool checkinclusion(string s1, string s2)
    {
        int n = s1.size(), m = s2.size(), i, r;

        unordered_map<char, int> mp;

        for (i = 0; i < n; i++)
        {
            mp[s1[i]]++;
            mp[s2[i]]--;
        }

        if (ispermutation(mp))
            return true;

        for (i = n; i < m; i++)
        {
            mp[s2[i]]--;
            mp[s2[i - n]]--;
            if (ispermutation(mp))
                return true;
        }
        return false;
    }

private:
    bool ispermutation(unordered_map<char, int> &mp)
    {
        for (auto ch : mp)
        {
            if (ch.second != 0)
                return false;
            return true;
        }
    }
}