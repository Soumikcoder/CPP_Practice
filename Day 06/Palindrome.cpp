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
int list_length(ListNode* root){
    if(root==NULL) return 0;
    return list_length(root->next)+1;
}
ListNode* reverselist(ListNode* root){
    ListNode* prev=NULL;
    ListNode* curr=root;
    while(root!=NULL){
        curr=curr->next;
        root->next=prev;
        prev=root;
        root=curr;
    }
    return prev;
}
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        int size=list_length(head);
        if(size!=0){
        ListNode* tmp=head;
        int N=(size&1?(size/2):((size/2)-1));
        for(int i=0;i<N;i++){
            tmp=tmp->next;
        }
        tmp->next=reverselist(tmp->next);
        tmp=tmp->next;
        while(tmp!=NULL){
            if(head->val!=tmp->val)
            return false;
            tmp=tmp->next;
            head=head->next;
        }
        return true;
        }
        return false;
    }
};