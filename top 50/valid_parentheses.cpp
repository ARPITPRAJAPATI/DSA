20. Valid Parentheses


Example 1:

Input: s = "()"

Output: true

Example 2:

Input: s = "()[]{}"

Output: true

Example 3:

Input: s = "(]"

Output: false

Example 4:

Input: s = "([])"

Output: true


solution:

class Solution {
public:
    bool isValid(string s) {
        stack<char>st; //using stack 
        for(auto & x:s){
            if(x == '(' || x=='{' || x== '['){ // add open in stack 
                st.push(x); 
            }
            else{
                if(st.empty()){
                    return false; // if no add on means ans is false 
                }
                if (x == ')' && st.top() != '(') return false;
                if (x == '}' && st.top() != '{') return false;
                if (x == ']' && st.top() != '[') return false;

                st.pop(); // if match pop the thing
            }
        }
        return st.empty();  // if everything match and stack become empty return true
        
    }
};