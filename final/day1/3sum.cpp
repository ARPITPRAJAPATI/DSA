 
 i   j            k
-4  -1  -1  0  1  2

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end()); // first we have to sort

        for(int i = 0; i < nums.size(); i++) { // first for loop for i to last

            if(i > 0 && nums[i] == nums[i - 1]) continue; // ths use to skip the repeat shit of main loop

            int l = i + 1; // second pointer is i+1;
            int r = nums.size() - 1; // put at last 

            while(l < r) {
                int sum = nums[i] + nums[l] + nums[r]; // fix the i move l and r

                if(sum == 0) { //if sum =0
                    res.push_back({nums[i], nums[l], nums[r]});
                    l++;  
                    r--;      // push the vector into res

                    // skip duplicates AFTER getting one ans
                    while(l < r && nums[l] == nums[l - 1]) l++;
                    while(l < r && nums[r] == nums[r + 1]) r--;
                }
                // this is core 
                // to reduce sum just move towards neg
                else if(sum > 0) {
                    r--; 
                }
                // to increase the sum move towards pos
                else {
                    l++;
                }
            }
        }
        return res; 
    }
};