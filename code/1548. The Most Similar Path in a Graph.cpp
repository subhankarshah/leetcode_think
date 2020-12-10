// https://leetcode.com/problems/the-most-similar-path-in-a-graph/

class Solution {
    // f(i,j) -> min edit distance of path lenght i ending on node j
    // f(i,j) = +1 if j is ith in targetPath else +0 + min( f(i-1,k) for all k with edge to j)
    // return min(for all j f(targetPathLength,j))
    
    int getEditDistance(int pathLength, int node, vector<string>& targetPath, vector<string>& names, vector<vector<int>>& graph, vector<vector<int>> &dp) {
        if(pathLength==0) return 0;
        if(dp[pathLength][node]!=-1) return dp[pathLength][node];
        dp[pathLength][node] = pathLength+1;
        for(auto neighbour: graph[node])
            dp[pathLength][node] = min( dp[pathLength][node], 
            getEditDistance(pathLength-1, neighbour, targetPath, names, graph, dp) );
        dp[pathLength][node] += targetPath[pathLength-1] == names[node] ? 0 : 1;
        return dp[pathLength][node];
    }
    
    vector<int> backtrack(int minEditDistance, int pathLength, vector<string>& targetPath, vector<string>& names, vector<vector<int>>& graph, vector<vector<int>> &dp){
        vector<int> path;
        int curNode = distance(dp[pathLength].begin(),
            find(dp[pathLength].begin(),dp[pathLength].end(),minEditDistance));
        minEditDistance -= targetPath[pathLength-1] == names[curNode] ? 0 : 1;
        path.push_back(curNode);
        for(int i=pathLength-1;i>=1;i--){
            for(int neighbour:graph[curNode]){
                if(dp[i][neighbour]==minEditDistance){
                    curNode = neighbour;
                    minEditDistance -= targetPath[i-1] == names[curNode] ? 0 : 1;
                    path.push_back(curNode);
                    break;
                }
            }
        }
        reverse(path.begin(), path.end());
        return path;
    }
    
public:
    vector<int> mostSimilar(int n, vector<vector<int>>& roads, vector<string>& names, vector<string>& targetPath) {
        vector<vector<int>> graph(n);
        for(auto road:roads){
            graph[road[0]].push_back(road[1]);
            graph[road[1]].push_back(road[0]);
        }
        int pathLength = targetPath.size();
        vector<vector<int>> dp(pathLength+1,vector<int>(n,-1));
        int minEditDistance = pathLength+1;
        for(int i=0;i<n;i++) 
            minEditDistance = min(minEditDistance,
                getEditDistance(pathLength,i,targetPath,names,graph,dp));
        return backtrack(minEditDistance,pathLength,targetPath,names,graph,dp);
    }
};