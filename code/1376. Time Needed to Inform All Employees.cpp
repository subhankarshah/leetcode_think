// https://leetcode.com/problems/time-needed-to-inform-all-employees/

class Solution {
public:
    
    int timeToKnowInformation(int employeeId, vector<int>& manager, vector<int>& informTime,
                             vector<int> &timeToKnow){
        if(timeToKnow[employeeId]!=-1) return timeToKnow[employeeId];
        return timeToKnow[employeeId] = informTime[manager[employeeId]]+
            timeToKnowInformation(manager[employeeId],manager,informTime,timeToKnow);
    }
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<int> timeToKnow(n,-1);
        timeToKnow[headID]=0;
        int ans=0;
        for(int i=0;i<n;i++) 
            ans = max(ans,timeToKnowInformation(i,manager,informTime,timeToKnow));
        return ans;
    }
};