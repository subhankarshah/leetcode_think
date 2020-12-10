// https://leetcode.com/problems/student-attendance-record-ii/

const int mod = 1e9+7;

class Solution {
public:
    
    int get(vector<vector<int>> &dp, int i, int j){
        if(j<0) return 0;
        return dp[i][j];
    }
    
    int checkRecord(int n) {
        vector<vector<int>> dp(2, vector<int>(n+2,0));
        dp[0][0]=1;
        for(int i=1;i<=n+1;i++){
            dp[0][i] = ((get(dp,0,i-1) + get(dp,0,i-2))%mod + get(dp,0,i-3))%mod;
            dp[1][i] = (dp[0][i] + ((get(dp,1,i-1) + get(dp,1,i-2))%mod + get(dp,1,i-3))%mod)%mod;
        }
        return dp[1][n+1];
    }
};