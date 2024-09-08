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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode*temp=head;
        int n=0;
        while(temp){
            n++;
            temp=temp->next;
        }
        vector<ListNode*>ans;
        if(k>=n){
            int x=n;
            while(x--){
                ListNode* ptr=head;
                head=head->next;
                ptr->next=NULL;
                ans.push_back(ptr);
            }
            int y=k-n;
            while(y--){
                ans.push_back(NULL);
            }
            return ans;
        }

        //if(k<n)
        int p=n/k;
        int r=n%k;
        temp=head;
        while(temp){
            int x=p;
            ListNode* ptr=head;
            ListNode*prev=new ListNode(-1);
            prev->next=head;
            while(x--){
                prev=head;
                head=head->next;
                temp=temp->next;
            }
            if(r>0){
                r--;
                prev=prev->next;
                head=head->next;
                temp=temp->next;
            }
            prev->next=NULL;
            ans.push_back(ptr);
        }
        return ans;
        
    }
};