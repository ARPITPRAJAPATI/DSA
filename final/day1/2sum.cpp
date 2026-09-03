lc 1.

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum = target-nums[i];
            //find the sum in map.
            if(mp.find(sum)!=mp.end()){
                return {mp[sum],i};
            }
            mp[nums[i]]=i;
        }
        return {};
    }
};