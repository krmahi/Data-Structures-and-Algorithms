// sorting //

class solution
{
public:
    bool validAnagrams(string s, string t)
    {
        // check length //
        if (s.length() != t.length())
            return false :

                sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        return s == t;
    }
}

// using map //

class solution
{
public:
    bool validAnagrams(string s, string t)
    {

        unordered_map<auto, int> map;

        for (auto x : s)
            map[x]++;

        for (auto x : t)
            map[x]--;

        for (auto x : map)
            if (x != 0)
                return false;
        return true;
    }
}
