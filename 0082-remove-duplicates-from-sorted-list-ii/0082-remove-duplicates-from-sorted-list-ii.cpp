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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode * ans = new ListNode();
        ListNode* temp = ans;
        while(head)
        {
            if(head->next && head->val == head->next->val)
            {
                int ele = head->val;
                while(head && head->val == ele)
                head = head->next;
            }
            else 
            {
            temp->next = head;
            temp = head;
            head = head->next;
            }
        }
        temp->next = head;
        return ans ->next;
        
    }
};