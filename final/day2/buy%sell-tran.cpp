714.

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int miny = INT_MAX;
        int maxy = 0;
        for (int i = 0; i < prices.size(); i++) {
            miny = min(miny, prices[i]);
            if ((prices[i] - miny - fee) > 0) {
                maxy = maxy + (prices[i] - miny - fee);
                miny = prices[i]-fee;
            }
        }
        return maxy;
    }
};