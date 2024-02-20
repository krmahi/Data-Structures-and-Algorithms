class solution
{
public:
    int lengthoflongestsubstring(string s)
    {
        int l = 0, r, res = 0;
        unordered_set<char> st;

        for (r = 0; r < s.size(); r++)
        {
            if (st.count(s[r]))
            {
                st.erase(s[l]);
                l++;
            }
            st.insert(s[r]);
            res = max(res, r - l + 1);
        }
        return res;
    }
}