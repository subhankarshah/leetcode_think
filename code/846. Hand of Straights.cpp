// https://leetcode.com/problems/hand-of-straights/

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        map<int,int> cardCount;
        for(int card:hand) cardCount[card]++;
        deque<int> runningHands;
        int cardsRequired=0;
        int previousCard;
        for(auto card:cardCount){
            int currentCard=card.first;
            int cardFreq=card.second;
            if(cardsRequired && (currentCard != previousCard+1 || cardFreq<cardsRequired))
                return false;
            runningHands.push_front(cardFreq-cardsRequired);
            cardsRequired+=runningHands.front();
            if(runningHands.size()==W){
                cardsRequired-=runningHands.back();
                runningHands.pop_back();
            }
            previousCard=currentCard;
        }
        return cardsRequired==0;
    }
};