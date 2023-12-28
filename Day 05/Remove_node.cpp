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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* tmp=head;
        int count=0;
        while(tmp){
            tmp=tmp->next;
            count++;
        }
        tmp=head;
        if(count-n==0){
            return head->next;
        }
        for(int i=0;i<(count-n-1);i++){
            tmp=tmp->next;
        }
        tmp->next=tmp->next->next;
        return head;
    }
};