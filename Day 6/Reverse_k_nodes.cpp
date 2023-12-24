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
    int list_length(ListNode* root,int k){
        if(root==NULL &&(k>0)) return 1;
        else if(k==0) return 0;
        return list_length(root->next,k-1);
    }
    ListNode* reverselist(ListNode* root,int k){
        ListNode* prev=NULL;
        ListNode* curr=root;
        ListNode* tmp=root;
        while(k!=0){
            curr=curr->next;
            root->next=prev;
            prev=root;
            root=curr;
            k--;
        }
        tmp->next=root;
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(list_length(head,k)) return head;
        else{
            ListNode* tmp=head;
            head=reverselist(head,k);
            if(tmp!=head){
                tmp->next=reverseKGroup(tmp->next,k);
            }
            return head;
        }
    }
};