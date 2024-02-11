class solution
{
public:
    string encode(vector<string> &strs)
    {
        string result = "";
        for (char i : strs)
        {
            result += to_string(i.size()) + "#" + i;
        }
        return result;
    }

    vector<string> decode(string &s)
    {
        vector<string> result;
        int i;
        int j;
        int length;
        while (i < s.size())
        {
            j = i;
            while (j != "#")
            {
                j++;
            }
            length = stoi(s.substr(i, j - i));
            result.push_back(s.substr(j + 1, length));
            i = j + 1 + length;
        }
        return result;
    }
}