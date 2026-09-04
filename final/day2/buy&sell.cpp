lc 121.

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxy = INT_MIN;
        int miny = INT_MAX;
        for(int i=0;i<prices.size();i++){
            miny = min(miny,prices[i]);
            maxy= max(maxy,prices[i]-miny);
        }
        return maxy;
    }
};