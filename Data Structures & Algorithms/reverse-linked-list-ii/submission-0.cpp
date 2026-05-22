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
    ListNode* reverseList(ListNode* head,int count,int right) {
        ListNode* prev=nullptr;
        ListNode* curr=head;
        while(curr!=nullptr && count<=right){
          ListNode* next = curr->next;
           curr->next=prev;
           prev = curr;
           curr = next;
           count++;
        }
        head -> next =curr;
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
    if (!head || left == right) return head;
      int count =0;
      ListNode* temp = new ListNode(0);
      temp->next=head;
      ListNode* prev = temp;
      for(int i=1;i<left;i++)
        prev=prev->next;

      prev->next = reverseList(prev->next,left,right);
      return temp->next;
    }
};