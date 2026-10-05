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
private:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int>ans;
        while(head){
            ans.push_back(head->val);
            head = head->next;
        }
        stack<int>st;
        for(int i = ans.size()-1 ; i >=0 ; i--)
        {
            int val = ans[i];
            while(!st.empty() && st.top()<=val)
            {
                st.pop();
            }
            if(!st.empty())ans[i]=st.top();
            else ans[i]=0;
            st.push(val);
        }
        return ans;  
    }
public:
    ListNode* removeNodes(ListNode* head) {
        vector<int>nextLarge = nextLargerNodes(head);
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        for(int i= 0 ; i < nextLarge.size() ; i++)
        {
            if(nextLarge[i]==0)
            {
                curr->next = head;
                curr = head;
            }
            head = head->next;
        }
        return dummy->next;
    }
};