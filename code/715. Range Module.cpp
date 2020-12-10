// https://leetcode.com/problems/range-module/

class RangeModule {
    
    map<int,int> rangesTracked;
    
public:
    RangeModule() {
        
    }
    
    void addRange(int left, int right) {
        if(left >= right) return;
        auto it = rangesTracked.upper_bound(right);
        while(rangesTracked.size() && it!=rangesTracked.begin()){
            it--;
            if(it->second < left) break;
            left = min(left, it->first);
            right = max(right, it->second);
            rangesTracked.erase(it);
            it = rangesTracked.upper_bound(right);
        }
        rangesTracked[left]=right;
    }
    
    bool queryRange(int left, int right) {
        if(left>=right) return true;
        auto it = rangesTracked.lower_bound(right);
        if (!rangesTracked.size() || it==rangesTracked.begin())
            return false;
        it--;
        return it->first <= left && right <= it->second;
    }
    
    void removeRange(int left, int right) {
        auto it = rangesTracked.lower_bound(right);
        vector<pair<int,int>> to_insert;
        while(left<right && rangesTracked.size() && it!=rangesTracked.begin()){
            it--;
            if(it->second <= left) break;
            if(it->second > right)
                to_insert.push_back({right,it->second});
            if(it->first < left)
                to_insert.push_back({it->first, left}); 
            rangesTracked.erase(it);
            it = rangesTracked.lower_bound(right);
        }
        for(auto x:to_insert)
            rangesTracked[x.first]=x.second;
    }
};
/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */