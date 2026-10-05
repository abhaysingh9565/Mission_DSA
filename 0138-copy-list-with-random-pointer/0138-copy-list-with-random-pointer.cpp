/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* ans = new Node(0);
        Node* curr = ans;
        Node* head1 = head;
        unordered_map<Node*,Node*>mp;
        while(head)
        {
            Node* node= new Node(head->val);
            node->next = head->next;
            mp[head]=node;
            curr->next = node;
            curr = node;
            head = head->next;
        }
        Node* temp = ans->next;
        while(temp)
        {
            if(head1->random)
            temp->random = mp[head1->random];
            else temp->random = nullptr;
            head1  = head1->next;
            temp= temp->next;
        }
        return ans->next;
    }
};