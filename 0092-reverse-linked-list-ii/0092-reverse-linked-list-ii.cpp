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
    void reverseList(ListNode* head){
        ListNode* curr=head;
        ListNode* prev=NULL;
        while(curr!=NULL )
        {
            ListNode* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        if(!head || !head->next)return head;
        if(left==right)return head;
        ListNode* temp = head;
        ListNode* leftNode, *prevLeft,*prev=NULL,*rightNext,*rightNode;
        int pos = 1;
        while(temp)
        {
            if(left==pos)
            {
                leftNode = temp;
                prevLeft = prev;
            }
            else if(pos == right)
            {
                rightNode = temp;
                rightNext=temp->next;
                break;
            }
            prev= temp;
            temp = temp->next;
            pos++;
        }
        rightNode->next = nullptr;
        if(prevLeft)
        prevLeft->next = NULL;
        reverseList(leftNode);
        leftNode->next = rightNext;
        if(prevLeft)
        prevLeft->next = rightNode;
        else return rightNode;
        return head;
    }
};