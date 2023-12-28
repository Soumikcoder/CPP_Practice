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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int value=0;
        ListNode* head=NULL;
        ListNode* tmp=NULL;
          while(l1||l2){
              if(l1){
                  value+=l1->val;
                  l1=l1->next;
              }
              if(l2){
                  value+=l2->val;
                  l2=l2->next;
              }
              if(head==NULL){
                  head=new ListNode(value%10);
                  tmp=head;
              }
              else{
                  tmp->next=new ListNode(value%10);
                  tmp=tmp->next;
              }
              value=value/10;
          }
          while(value){
            tmp->next=new ListNode(value%10);
            tmp=tmp->next;
            value=value/10;
          }
          return head;          
    }
};