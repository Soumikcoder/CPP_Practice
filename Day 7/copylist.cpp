/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copylist(Node* head){
        if(head==NULL){
            return NULL;
        }
        else{
            Node* newhead=new Node(head->val);
            newhead->next=head->next;
            head->next=newhead;
            newhead->next=copylist(head->next->next);
            if(head->random==NULL){
                newhead->random=NULL;
            }
            else{
                newhead->random=head->random->next;
            }
            return head;
        }
    }
    Node* copyRandomList(Node* head) {
        if(head==NULL) return NULL;
        Node* copy=copylist(head)->next;
        Node* tmp=head;
        while(head!=NULL){
            tmp=tmp->next;
            if(tmp!=NULL){
                head->next=tmp->next;
            }
            else{
                head->next=NULL;
            }
            head=tmp;
        }
        return copy;
    }
};