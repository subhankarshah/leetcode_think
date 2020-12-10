// https://leetcode.com/problems/string-transforms-into-another-string/

class Solution {
public:
    bool canConvert(string str1, string str2) {
        if(str1.size() != str2.size()) return false;
        if(str1 == str2) return true;
        map<char,char> graph;
        map<char,int> revGraph;
        for(int i=0;i<str1.size();i++){
            int c1=str1[i], c2=str2[i];
            if(graph.find(c1)==graph.end()) graph[c1]=c2;
            if(graph[c1]!=c2) return false;
            revGraph[c2]=1;
        }
        return revGraph.size()!=26;
    }
};