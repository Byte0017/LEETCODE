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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL) return NULL;
        if(head->next==NULL) return head;

        ListNode*odd=head;
        ListNode*even=head->next;
        ListNode*ptr=even;
        while(odd->next && ptr->next){
            if(ptr->next){
                odd->next=ptr->next;
                odd=ptr->next;
                if(odd->next){
                   ptr->next=odd->next;
                   ptr=odd->next;
                } 
            }
        }
        odd->next=even;
        ptr->next=NULL;
        return head;
    }
};