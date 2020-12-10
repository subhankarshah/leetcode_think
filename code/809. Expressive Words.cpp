// https://leetcode.com/problems/expressive-words/

class Solution {
public:
    
    int getCount(char c, int &i, string &a){
        int count=0;
        while(i<a.size() and a[i]==c) { 
            i++; 
            count++; 
        }
        return count;
    }
    
    int isStretchyInstance(string &a, string &b){
        if(a.size() < b.size()) return false;
        for(int i=0,j=0;i<a.size();){
            char currentChar=a[i];
            int charCountA=getCount(currentChar,i,a);
            int charCountB=getCount(currentChar,j,b);
            if(charCountB==0 || charCountA<charCountB || (charCountA>charCountB && charCountA<3))
                return false;
        }
        return true;
    }
    
    int expressiveWords(string S, vector<string>& words) {
        int ans=0;
        for(auto word:words)
            ans += isStretchyInstance(S,word);
        return ans;
    }
};