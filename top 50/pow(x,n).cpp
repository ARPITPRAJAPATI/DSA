50. Pow(x, n)

Implement pow(x, n), which calculates x raised to the power n (i.e., xn)

Example 1:

Input: x = 2.00000, n = 10
Output: 1024.00000


solution

class Solution {
public:
    double solve(double x, long n) {
        if(n==0){
            return 1;
        }
        else if(n<1){
            return solve(1/x,-n); // handle negative power
        }
        else if(n%2==0){
            return solve(x*x,n/2); 
        }
        else{
            return x*solve(x*x,(n-1)/2);
        }
    }
    double myPow(double x, int n) {
        return solve(x,long(n)); // imp for long 
    }
};

tips .. 1 using long to avoid crash of int during neg to pos in 2nd return ,
        2 diving the power by 2 to reduce the time complexity from O(n) to O(logn)
        