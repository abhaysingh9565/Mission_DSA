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
    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr != NULL) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
    ListNode* add(ListNode* l1, ListNode* l2) {
        int sum = 0 , carry = 0;
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;
        while(l1 || l2)
        {
            if(l1 && l2)
            {
                sum = (l1->val + l2->val+carry)%10;
                carry = (l1->val + l2->val+carry)/10;
                l1=l1->next;
                l2=l2->next;
            }
            else if(l1)
            {
                sum = (l1->val+carry)%10;
                carry = (l1->val+carry)/10;
                l1=l1->next;

            }
            else{
                sum = (l2->val+carry)%10;
                carry = (l2->val+carry)/10;
                l2=l2->next;

            }
            temp->next = new ListNode(sum);
            temp = temp->next;
        }
        if(carry)
        {
            temp->next = new ListNode(carry);
        }
        return dummy->next;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse(l1);
        l2 = reverse(l2);
        return reverse(add(l1,l2));
    }
};