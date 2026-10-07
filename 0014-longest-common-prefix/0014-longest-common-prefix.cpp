class TrieNode{
    public:
    TrieNode* children[26];
    bool isEnd;
    TrieNode()
    {
        for(int i =0; i<26; i++)children[i]=nullptr;

        isEnd = false;
    }
};
class Solution {
    void insert(TrieNode* root, string & str)
    {
        TrieNode* curr = root;
        for(char c : str)
        {
            if(curr->children[c-'a']==NULL)
            {
                curr->children[c-'a'] = new TrieNode();
            }
            curr = curr->children[c-'a'];
        }
        curr->isEnd = true;
    }
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        TrieNode* root = new TrieNode();
        for(string & s : strs)
        {
            insert(root,s);
        }
        TrieNode* curr = root;
        while(true) {

            int count = 0;
            int index = -1;

            // Count children
            for(int i = 0; i < 26; i++) {

                if(curr->children[i] != nullptr) {
                    count++;
                    index = i;
                }
            }

            // More than one path => common prefix ends
            if(count != 1)
                break;

            // One word has ended => common prefix ends
            if(curr->isEnd)
                break;

            ans += char('a' + index);

            curr = curr->children[index];
        }
        return ans;
    }
};