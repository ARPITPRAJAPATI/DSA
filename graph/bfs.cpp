class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        int n = adj.size();
        queue<int>q;
        vector<bool>v(n,0);
        vector<int>ans;
        q.push(0);
        v[0]=1;
        while(!q.empty()){
            int val =q.front();
            q.pop();
            for(int i=0;i<adj[val].size();i++){
                if(!v[adj[val][i]]){
                    v[adj[val][i]]=1;
                    q.push(adj[val][i]);
                }
            }
            ans.push_back(val);
        }
        return ans;
    }
};