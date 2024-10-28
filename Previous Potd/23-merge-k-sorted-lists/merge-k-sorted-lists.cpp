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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int>arr;
        for(auto head: lists){
           while(head!=NULL){
              arr.push_back(head->val);
              head=head->next;
           }
        }
        sort(arr.begin(),arr.end());
        ListNode*first=new ListNode(-1);
        ListNode*head=first;

        for(int i=0;i<arr.size();i++){
            ListNode* temp=new ListNode(arr[i]);
            first->next=temp;
            first=temp;
        }
        return head->next;
    }
};