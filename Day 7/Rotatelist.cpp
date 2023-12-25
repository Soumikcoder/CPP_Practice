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
    int get_size(ListNode* head){
        int count=0;
        while(head){
            head=head->next;
            count++;
        }
        return count;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        int size=get_size(head);
        if(size){
            k=k%size;
            if(k==0) return head;
            ListNode* prev=head;
            ListNode* curr=prev->next;
            for(int i=1;i<(size-k);i++){
                prev=prev->next;
                curr=prev->next;
            }
            prev->next=NULL;
            ListNode* tmp=curr;
            if(tmp){       
            while(tmp->next!=NULL){
                tmp=tmp->next;
            }
            tmp->next=head;
            }
            return curr;
        }
        return NULL;
    }
};