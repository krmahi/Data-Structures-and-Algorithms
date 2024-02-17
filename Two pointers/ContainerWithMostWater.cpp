// two pointer soluiton

class solution
{
public:
    int maxArea(vector<int> &height)
    {
        int i = 0, j = height.size(), maxarea = INT_MIN;
        if (n == 1)
            return 0;
        if (n == 2)
            return min(height[0], height[1]);
        while (i < j)
        {
            int currarea = (j - i) * min(height[i], height[j]);
            maxarea = max(maxarea, currarea);
            if (height[i] <= height[j])
                i++;
            else
                j--;
        }
        return maxarea;
    }
}