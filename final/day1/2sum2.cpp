lc 167

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int,int>mp;
        int sum=0;
        
        for(int i=0;i<numbers.size();i++){
            sum = target-numbers[i];
            if(mp.find(sum)!=mp.end()){
                // return the ans in sorted order and inc by 1
                 if(i>mp[sum]){ 
                    return {mp[sum]+1,i+1};
                 }
                 else{
                    return {i+1,mp[sum]+1};
                 }
            }
            mp[numbers[i]]=i;
        }
        return {};
    }
};