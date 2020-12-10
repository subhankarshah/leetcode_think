// https://leetcode.com/problems/minimum-window-subsequence/

class Solution {
public:
    
    
    int computeDp(int i, int j, vector<vector<int>> &dp, const string &s, const string &t){
        if(i<0) return 0;
        if(j<0) return 1e9;
        if(dp[i][j] != -1) return dp[i][j];
        if(t[i]==s[j]) return dp[i][j] = 1 + computeDp(i-1,j-1,dp,s,t);
        return dp[i][j] = 1 + computeDp(i,j-1,dp,s,t);
    }
    
    
    string minWindow(const string &s, const string &t) {
        int m=s.size(), n=t.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        string ans=s+t;
        for(int j=0;j<m;j++) { 
            int substrLength = computeDp(n-1,j,dp,s,t); 
            if(substrLength>m || substrLength>=ans.size()) continue;
            ans = s.substr(j-substrLength+1,substrLength);
        }
        return ans.size() <= m ? ans : "";
    }
};