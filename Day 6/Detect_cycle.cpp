/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
    if(head && head->next){
        ListNode *slow=head->next;
        ListNode *fast=head->next->next;
        while(slow!=fast){
            if(fast==NULL||slow==NULL||fast->next==NULL)
                return false;
            else{
                slow=slow->next;
                fast=fast->next->next;
            }
        }
        return true;
    }
        else
            return false;
        
    }
};