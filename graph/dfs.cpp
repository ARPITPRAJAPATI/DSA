class Solution {
  public:
    void helper(int i,vector<vector<int>>& adj,vector<bool>&v,vector<int>&ans){
        v[i]=1;
        ans.push_back(i);
        for(int l=0;l<adj[i].size();l++){
            if(!v[adj[i][l]]){
                helper(adj[i][l],adj,v,ans);
            }
        }
    }
    vector<int> dfs(vector<vector<int>>& adj) {
      int n = adj.size();
      vector<bool>v(n,0);
      vector<int>ans;
      helper(0,adj,v,ans);
      return ans;
    }
    
};