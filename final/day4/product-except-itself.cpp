lc 238 

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>result(nums.size());
        result[0]=1;
        
        for(int i=1;i<nums.size();i++){
               int left = result[i-1];
               result[i]=left*nums[i-1];
        }
        int back = 1;
        for(int i=nums.size()-1;i>=0;i--){
            result[i] = back*result[i];
            back = back*nums[i];
        }
        return result;
    }
};