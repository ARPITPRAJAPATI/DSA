Find square root of a number
Input: n = 36

Output: 6

Explanation: 6 is the square root of 36.

Solution

class Solution {
public:
    int floorSqrt(int n)  {
    int low = 1;
    int right = n/2;
    int ans = 0;
    if(n<2){
        return 1;
    }

    while(low<=right){
        long mid = low+(high-low)/2;
        if(mid*mid <=n){
            ans = int(mid) ;
        }
        else if (mid*mid>n){
            right = int(mid)-1;
        }
        else{
            low = int(mid)+1;
        }
    }
    return ans;
    }
};