lc 238.

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProd = nums[0]; // take first element for maxy
        int minProd = nums[0]; // take first element for miny
        int result = nums[0]; // take first element for final
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < 0)
                swap(maxProd, minProd); //  Agar current number negative hai:
                                        //   max → min ban jayega
                                        //  min → max ban jayega
            
            maxProd = max(nums[i], maxProd * nums[i]); //👉 Either:
                                                       //  naya start karo (nums[i])
                                                       // else extend karo (previous max × nums[i])
            minProd = min(nums[i], minProd * nums[i]); // same for min
            
            result = max(result, maxProd); //return
        }
        
        return result;
    }
};