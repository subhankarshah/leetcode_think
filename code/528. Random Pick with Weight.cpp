// https://leetcode.com/problems/random-pick-with-weight/s

class Solution {
    vector<int> cumulativeWeight;
public:
    Solution(vector<int>& w) {
        cumulativeWeight.resize(w.size());
        cumulativeWeight[0] = w[0];
        for(int i=1;i<w.size();i++)
            cumulativeWeight[i]=cumulativeWeight[i-1]+w[i];
    }
    
    int pickIndex() {
        int randomNumber = rand()%cumulativeWeight.back();
        return distance(cumulativeWeight.begin(), upper_bound(cumulativeWeight.begin(),cumulativeWeight.end(),randomNumber));
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */