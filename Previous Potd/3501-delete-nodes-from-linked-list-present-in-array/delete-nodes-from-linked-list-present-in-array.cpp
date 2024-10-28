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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int>st;
        for(auto i:nums) st.insert(i);

        ListNode* temp=head;
        ListNode* prev=new ListNode(-1);
        prev->next=head;
        
        while(temp){
            if(st.find(temp->val)!=st.end()){
                //delete 
                if(temp==head)  head=head->next;
                ListNode*ptr=temp;
                temp=temp->next;
               
                ptr->next=NULL;
                prev->next=temp;

            }
            else{
                temp=temp->next;
                prev=prev->next;
            }
        }
        return head;
    }
};