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
    ListNode* rev(ListNode* head)
    {
        if(head==NULL  || head-> next==NULL)
    {
        return head;
    }
     ListNode* shead=rev(head->next);
     head->next->next=head;
     head->next=NULL;
     return shead;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast ->next->next;
        }
        slow = rev(slow);
        while(slow)
        {
            if(slow->val != head->val)
            {
                return false;
            }
            slow= slow->next;
            head = head->next;

        }
        return true;
        
    }
};