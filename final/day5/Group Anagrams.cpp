lc 49

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mp; // mp with string
        vector<vector<string>>ans;
        for(int i=0;i<strs.size();i++){
            string s = strs[i]; // take element
            sort(s.begin(),s.end()); // sort that element
            mp[s].push_back(strs[i]); // if present in the mp push ito the map vector
        }
        for(auto &s:mp){
            ans.push_back(s.second);
        } // insert into main ans
        return ans; // return ans
    }
};