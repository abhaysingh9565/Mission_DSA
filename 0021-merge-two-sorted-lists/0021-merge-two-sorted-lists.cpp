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
    ListNode * ans = new ListNode(0);
    ListNode* result = ans;
    void merge(ListNode* list1, ListNode* list2)
    {
        if(!list1)
        {
            ans->next = list2;
            return ;
        }
        if(!list2)
        {
            ans->next = list1;
            return ;
        }
        if(list1->val < list2->val)
        {
            ans->next = list1;
            ans= ans->next;
            merge(list1->next,list2);
            return ;
        }
        else {
            ans->next = list2;
            ans= ans->next;
            merge(list1,list2->next);
            return ;
        }

    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        merge(list1,list2);
        return result->next;
        
    }
};