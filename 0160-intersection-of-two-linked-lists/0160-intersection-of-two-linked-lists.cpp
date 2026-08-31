/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        set<ListNode*>visited;
        // while(headA && headB)
        // {
        //     if(visited.count(headA))return headA;
        //     visited.insert(headA);
        //     if(visited.count(headB))return headB;
        //     visited.insert(headB);
        //     headA = headA->next;
        //     headB = headB->next;
        // }
        while(headA)
        {
            visited.insert(headA);
            headA = headA->next;
        }
        while(headB)
        {
            if(visited.count(headB))return headB;
            headB = headB->next;
        }
        return NULL;
    }
};