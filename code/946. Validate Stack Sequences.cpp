// https://leetcode.com/problems/validate-stack-sequences/


class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        vector<int> stak;
        int i=0;
        for(auto element:pushed){
            stak.push_back(element);
            while(stak.size() && i<popped.size() && stak.back()==popped[i]){
                stak.pop_back();
                i++;
            }
        }
        return stak.size()==0;
    }
};