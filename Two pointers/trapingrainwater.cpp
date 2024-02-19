// using left and right vectors
// time = O(n) | space = O(n)

class solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size(), maxel = 0, minel, i, res = 0;
        vector<int> maxleft(n);
        vector<int> maxright(n);
        vector<int> minlr(n);

        // maxleft
        for (i = 0; i < n; i++)
        {
            maxleft[i] = maxel;
            maxel = max(maxel, height[i]);
        }

        // maxright
        maxel = 0;
        for (i = n - 1; i >= 0; i--)
        {
            maxright = maxel;
            maxel = max(maxel, maxright);
        }

        // minlr
        for (i = 0; i < n; i++)
        {
            minel = min(maxleft[i], maxright[i]);
            minlr[i] = minel;
        }

        for (i = 0; i < n; i++)
        {
            if (minlr[i] > height[i])
                res += (minlr[i] - height[i]);
        }
        return res;
    }
}

// using two pointer
// time = O(n) | space = O(1)

class solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size(), i = 0, j = n - 1, maxleft = height[i], maxright = height[j], res = 0;

        while (i < j)
        {
            if (maxleft <= maxright)
            {
                i++;
                maxleft = max(maxleft, height[i]);
                res += (maxleft - height[i]);
            }
            else
            {
                j--;
                maxright = max(maxright, height[j]);
                res += (maxright - height[j]);
            }
        }
        return res;
    }
}