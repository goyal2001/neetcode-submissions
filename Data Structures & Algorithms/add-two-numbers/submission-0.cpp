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
      ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* root1 = l1;
        ListNode* root2 = l2;
        
        ListNode * head = new ListNode(0);
        ListNode * temp = head;
         int carry = 0;
        while(root1!=NULL && root2!=NULL){
        int sum = root1->val + root2->val + carry;
        carry = sum/10;
        ListNode* newNode = new ListNode(sum%10);
        temp->next=newNode; temp=temp->next;
        root1=root1->next;
        root2=root2->next;
        }

        while(root1!=NULL){
        int sum = root1->val + carry;
            carry = sum/10;
        ListNode* newNode = new ListNode(sum%10);
        temp->next=newNode; temp=temp->next;
        root1=root1->next;
        }

        while(root2!=NULL){
        int sum = root2->val + carry;
            carry = sum/10;
        ListNode* newNode = new ListNode(sum%10);
        temp->next=newNode; temp=temp->next;
        root2=root2->next;
        }
        
        if(carry>0){
            ListNode* newNode = new ListNode(carry);
            temp->next=newNode;
        }
       return head->next;
    }  
    
};
