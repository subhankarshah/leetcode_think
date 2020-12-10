// https://leetcode.com/problems/find-two-non-overlapping-sub-arrays-each-with-target-sum/

class Solution {
public:
    
    vector<int> getMinSubArray(vector<int>& arr, int target) {
        int n=arr.size();
        vector<int> cumulativeSum(1,0);
        vector<int> minSubArray(n+1,1e9);
        for(int i=0;i<n;i++){
            cumulativeSum.push_back(cumulativeSum.back()+arr[i]);
            auto it = lower_bound(cumulativeSum.begin(), cumulativeSum.end(),  cumulativeSum.back()-target);
            if(*it != cumulativeSum.back()-target)
                minSubArray[i+1] = minSubArray[i];
            else 
                minSubArray[i+1] = min(minSubArray[i], int(distance(it, cumulativeSum.end()))-1);
        }
        return minSubArray;
    }
    
    void display(vector<int>& arr){
        for(auto x: arr) cout << x << ' ';
        cout << '\n';
    }
    
    int minSumOfLengths(vector<int>& arr, int target) {
        vector<int> leftToRight = getMinSubArray(arr, target);
        reverse(arr.begin(), arr.end());
        vector<int> rightToLeft = getMinSubArray(arr, target);
        reverse(rightToLeft.begin(), rightToLeft.end());
        int ans = 1e9, n=arr.size();
        // display(leftToRight);
        // display(rightToLeft);
        for(int i=0;i<=n;i++)
            ans = min(ans, leftToRight[i]+rightToLeft[i]);
        return ans <= n ? ans : -1;
    }
};