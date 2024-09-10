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
    int gcd(int a,int b){
        if(a==b) return a;
        if(a>b) return gcd(a-b,b);
        else return gcd(a,b-a);
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head->next==NULL) return head;
        ListNode*temp=head;
        int n=0;
        while(temp){
            n++;
            temp=temp->next;
        }
        temp=head;
        ListNode*ptr=head;
        n--;
        while(n--){
            temp=temp->next;
            int x=gcd(ptr->val,temp->val);
            ListNode*newNode=new ListNode(x);
            ptr->next=newNode;
            newNode->next=temp;
            ptr=temp;
        }
        return head;
    }
};