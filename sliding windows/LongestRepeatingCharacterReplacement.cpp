class solution
{
public:
    int characterReplacement(string s, int k)
    {
        unordered_map<char, int> mp;
        int n = s.size(), l = 0, r, res = 0;

        for (r = 0; r < n; r++)
        {
            mp[s[r]]++;
            maxf = max(maxf, mp[s[r]]);
            while ((r - l + 1) - maxf > k)
            {
                mp[s[l]]--;
                l++;
            }
            res = max(res, r - l + 1)
        }
        return res;
    }
}