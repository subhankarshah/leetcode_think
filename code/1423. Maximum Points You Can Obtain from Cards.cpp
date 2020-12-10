// https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum=0;
        for(int i=0;i<k;i++) sum += cardPoints[i];
        int ans=sum, n=cardPoints.size();
        for(int i=0;i<k;i++) {
            sum += cardPoints[n-1-i]-cardPoints[k-1-i];
            ans = max(ans,sum);
        }
        return ans;
    }
};