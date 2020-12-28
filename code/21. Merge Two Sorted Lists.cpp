// https://leetcode.com/problems/merge-two-sorted-lists/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    
    ListNode* getNextNode(ListNode *&l1, ListNode *&l2){
        ListNode* nextNode;
        if(l2==NULL || (l1!=NULL && l1->val <= l2->val)){
            nextNode=l1;
            l1=l1->next;
        } else {
            nextNode=l2;
            l2=l2->next;
        }
        return nextNode;
    }
    
    ListNode* mergeTwoLists(ListNode *l1, ListNode *l2) {
        if(l1==NULL  && l2==NULL) return NULL;
        ListNode *head = getNextNode(l1,l2);
        ListNode *previousNode=head;
        while(l1!=NULL || l2!=NULL){
            previousNode->next=getNextNode(l1,l2);
            previousNode=previousNode->next;
        }
        return head;
    }
};