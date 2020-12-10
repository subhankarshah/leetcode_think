// https://leetcode.com/problems/missing-element-in-sorted-array/

class Solution {
public:
    
    int get_missing_elements(vector<int>& nums, int i){
        return (nums[i]-nums[0]-1)-(i-1);
    }
    
    int missingElement(vector<int>& nums, int k) {
        int n=nums.size();
        int f=0,l=n,mid;
        while((l-f)>1){
            mid=(f+l)/2;
            if(get_missing_elements(nums,mid)<k)
                f=mid;
            else
                l=mid;
        }
        return nums[f]+k-get_missing_elements(nums,f);
    }
};