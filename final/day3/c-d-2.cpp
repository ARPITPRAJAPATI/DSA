lc 219

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            
            if(mp.find(nums[i])!=mp.end()){
                if(abs(mp[nums[i]]-i)<=k){
                    return true;
                }
            }
            mp[nums[i]]=i;
        }
        return false;
    }
};

// here store the first index val of nums[i] and match with second value 