class Solution {
private:
   vector<vector<int>> edges;
   vector<int>visited;
   vector<int>result;
   bool valid=true;
public:
void dfs(int u)
{
    visited[u]=1;
    for(int v:edges[u])
    {
        if(visited[v]==0)
        {
            dfs(v);
            if(!valid)
            return;
        }
        else if(visited[v]==1)
        {
            valid=false;
            return;
        }
    }
    visited[u]=2;
      result.push_back(u);
}
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        edges.resize(numCourses);
        visited.resize(numCourses);
        for(const auto&info: prerequisites)
        edges[info[1]].push_back(info[0]);
        for(int i=0;i<numCourses&&valid;i++)
        {
            if(!visited[i])
            dfs(i);
        }
        if(!valid)return{};
        reverse(result.begin(), result.end());
        return result;
    }
};
