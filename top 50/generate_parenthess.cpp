22. Generate Parentheses

Given n pairs of parentheses, 
write a function to generate all combinations of well-formed parentheses.

 

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]



solution: 

class Solution {
public:
    void helper(int close,int open,vector<string>&result,int n,string s){
        if(s.size()==2*n){  // if both open and close are equal we get the answer
            result.push_back(s);
            return;
        }
        if(open<n){  // this increase open but valid manner 
            
            helper(close,open+1,result,n,s + "(");
        }
        if(close<open){ //this avoid adding invalid closes ,
           
            helper(close+1,open,result,n,s + ")");
        }
    }
    
    vector<string> generateParenthesis(int n) {
        int close = 0; // for close count 
        int open =0; // for open count
        vector<string>result; //main 
        string s = ""; //temp 
        helper(close,open,result,n,s); // this will get the updated result 
        return result;
    }
};


tips..  1. Understand the logic first,
        2. make a tree for vaild parentheses   "")())("" this is invalid

        3. to avoid this prioties the open one   ""("" 
        4. but not over n 
        5. make a helper 
        6. base condition same as equal no of open and equal no of close if eqaul to string size we get the ans 
        7. push in result