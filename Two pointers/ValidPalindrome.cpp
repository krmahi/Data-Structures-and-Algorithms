class solution
{
public:
    bool ispalindrom(string s)
    {
        int i = 0, j = s.size() - 1;
        while (i < j)
        {
            if (!isalnum(i) && i < j)
            {
                i++;
                continue;
            }
            if (!isalnum(j) && i < j)
            {
                j--;
                continue;
            }
            if (tolower(s[i]) != tolower(s[i]))
                return false;
            i++;
            j--;
        }
        return true;
    }
}