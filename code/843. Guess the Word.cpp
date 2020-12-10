// https://leetcode.com/problems/guess-the-word/



/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */

const int wordlen=6;
const int maxWords=100;

class Solution {
public:
    
    int getMatches(string &a, string &b){
        int matches=0;
        for(int i=0;i<wordlen;i++) if(a[i] == b[i]) matches++;
        return matches;
    }
    
    int getSplit(string &guessCandidate, set<string> &searchSpace){
        vector<int> matchCount(wordlen+1,0);
        for(string word:searchSpace)
            matchCount[getMatches(guessCandidate, word)]++;
        return *max_element(matchCount.begin(),matchCount.end());
    }
    
    string getBestGuess(set<string> &searchSpace){
        int minSplit = maxWords;
        string bestGuess;
        for(string word:searchSpace){
            int split = getSplit(word, searchSpace);
            if(split >= minSplit) continue;
            minSplit=split;
            bestGuess=word;
        }
        return bestGuess;
    }
    
    void trimSearchSpace(string &chosenWord, int score, set<string> &searchSpace){
        set<string> discardedWords;
        for(string word: searchSpace)
            if(getMatches(chosenWord, word) != score)
                discardedWords.insert(word);
        for(string word: discardedWords)
            searchSpace.erase(searchSpace.find(word));
    }
    
    
    void findSecretWord(vector<string>& wordlist, Master& master) {
        set<string> searchSpace(wordlist.begin(), wordlist.end());
        for(int i=0; i<10 && searchSpace.size(); i++){
            string guess = getBestGuess(searchSpace);
            searchSpace.erase(searchSpace.find(guess));
            int score=master.guess(guess);
            trimSearchSpace(guess, score, searchSpace);
        }
        assert(searchSpace.size()==0);
    }
};