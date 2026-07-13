739. Daily Temperatures

Hint
Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.

 

Example 1:

Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]

Example 2:

Input: temperatures = [30,40,50,60]
Output: [1,1,1,0]

solution:

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int>ans(n); // to store ans
        stack<int>st;
        for(int i = n-1;i>=0;i--){ // trans the array from the last 
            while(!st.empty() && temperatures[i]>=temperatures[st.top()]){  // store the index only if temp > temp[top]
                st.pop(); // do pop till end
            }
            if(st.empty()){
                ans[i]=0; // if nothing in stack add zero
            }
            else{
                ans[i] = st.top()-i; // this update val of index in ans
            }
            st.push(i); // push in stack
        }
        return ans;

    }
};