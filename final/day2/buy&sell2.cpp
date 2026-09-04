lc 122

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int miny = INT_MAX; // for the min value of stock buy
        int maxy =0; //total sum
        for(int i=0;i<prices.size();i++){ // till n
            miny = min(miny,prices[i]); //find min at every index as well as last buy
            if((prices[i]-miny)>0){ // if selling is just more than last buy 
                maxy = maxy + ( prices[i] - miny );
                miny = prices[i]; //last selling price is our new buying price if we get the profit
            }
        }
        return maxy;
    }
};

in this question we have to find out the max value .
we can buy and sell more than 1. and add the for max profit