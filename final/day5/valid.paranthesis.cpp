lc 20.

class Solution {
public:
    bool isValid(string s) {
        stack<char>st; // take a stack
        for(auto & x:s){
            if(x == '(' || x=='{' || x== '['){ // push the open part
                st.push(x);
            }
            else{
                if(st.empty()){ // if no open mean not valid close 
                    return false;
                } // if the thing on the top doesnot have proper closing
                if (x == ')' && st.top() != '(') return false;
                if (x == '}' && st.top() != '{') return false;
                if (x == ']' && st.top() != '[') return false;

                st.pop();
            }
        }
        return st.empty(); // if stack finish means valid
       
    }
};
