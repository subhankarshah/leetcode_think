// https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<pair<int,int>> currentSubarray;
        int ans = 0;
        for(int i=0,j=0; j<nums.size(); j++){
            int maxIdx = i-1;
            for( auto it=currentSubarray.begin(); 
                it!=currentSubarray.end() && abs(it->first - nums[j]) > limit; 
                maxIdx=max(maxIdx, it->second), it++ );
            for( auto it=currentSubarray.rbegin(); 
                it!=currentSubarray.rend() && abs(it->first - nums[j]) > limit; 
                maxIdx=max(maxIdx, it->second), it++ );
            while(i<=maxIdx) { 
                currentSubarray.erase(currentSubarray.find({nums[i],i})); 
                i++; 
            }
            currentSubarray.insert({nums[j],j});
            ans = max(ans, int(currentSubarray.size()));
        }
        return ans;
    }
};