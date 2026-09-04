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
    ListNode* reverseList(ListNode* head){
        if(head==nullptr || head->next==nullptr)return head;
        ListNode* curr=head;
        ListNode* prev=NULL;
        while(curr!=NULL )
        {
            ListNode* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;

        }
        return prev;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || k==0 || !head->next)return head;
        head = reverseList(head);
        ListNode* temp = head;
        int s = 0 ;
        ListNode* kth;
        while(temp)
        {
            s++;
            temp = temp->next;
        }
        k %= s;
        if(k == 0) {
            return reverseList(head);
        }
        temp = head;
        while(k--)
        {
            if(k==0)
            {
                kth = temp->next;
                temp->next = NULL;
                break;
            }
            temp=temp->next;

        }
        temp = head;
        head = reverseList(head);
        kth = reverseList(kth);
        temp->next = kth;
        return head;

    }
};