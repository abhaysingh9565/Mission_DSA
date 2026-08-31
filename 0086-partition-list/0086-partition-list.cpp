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
    ListNode* partition(ListNode* head, int x) {
        ListNode* small = new ListNode();
        ListNode* greater = new ListNode();
        ListNode* temp1 = small;
        ListNode* temp2 = greater;
        ListNode* temp = head;
        while(temp)
        {
            if(temp->val < x)
            {
                temp1->next = temp;
                temp1 = temp;
            }
            else{
                temp2->next = temp;
                temp2= temp;
            }
            temp = temp->next;
        }
        temp2->next = NULL;
        while(greater->next)
        {
            temp1->next = greater -> next;
            greater ->next = greater->next->next;
            temp1 = temp1->next;
        }
        return small->next;

        
    }
};