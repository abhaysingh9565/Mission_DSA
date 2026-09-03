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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == nullptr)
        {
            return head;
        }
        ListNode* temp = head;
        int sz = 0;
        while(temp)
        {
            sz++;
            temp = temp->next;
        }
        n = sz-n;

        ListNode* prev = NULL;
        temp = head;
        while(temp)
        {
            if(n-- == 0)
            {
                if(prev == NULL)return temp->next;
                prev -> next = temp->next;
            }
            prev = temp;
            temp = temp->next;
        }
        return head;

        
    }
};