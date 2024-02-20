// two pointers

class solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size(), l = 0, r, profit, res = 0;

        for (r = 0; r < n; r++)
        {
            if (prices[l] < prices[r])
            {
                profit = prices[r] - prices[i];
                res = max(res, profit);
                r++;
            }
            else
            {
                l = r;
            }
        }
        return res;
    }
}

// sliding windows

class solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int min = INT_MAX, profit = 0;
        for (auto price : prices)
        {
            if (price < min)
                min = price;
            if (price - min > profit)
                profit = price - min;
        }
        return profit;
    }
}