class TrieNode{
    public:
    TrieNode* children[26];
    bool isEnd;
    string word;
    TrieNode()
    {
        for(int i =0 ; i<26 ; i++)children[i]=NULL;

        isEnd = false;
    }
};
class Solution {
    void addWord(TrieNode* root,string &word) {
        TrieNode* curr = root;
        for(char c : word)
        {
            if(!curr->children[c-'a'])
            {
                curr->children[c-'a'] = new TrieNode();
            }
            curr = curr->children[c-'a'];
        }
        curr->isEnd = true;
        curr->word = word;
        
    }
    void solve(TrieNode* root,vector<string>&ans)
    {
        if(ans.size()==3)
        {
            return;
        }
        if(root->isEnd)
            ans.push_back(root->word);

        for(int i =0 ; i < 26 ; i++)
        {
            if(root->children[i])solve(root->children[i],ans);
        }
    }
    void giveSuggestion(TrieNode* root , string &searchWord,vector<string>&ans,int& index)
    {
        TrieNode* curr = root;
        for(int i = 0 ; i<=index; i++)
        {
            char c = searchWord[i];
            if(curr->children[c-'a'])
            {
                curr = curr->children[c-'a'];
            }
            else{
                return;
            }
        }
        solve(curr,ans);
    }
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>>result;
        TrieNode* root = new TrieNode();
        for(string &s : products)
        {
            addWord(root,s);
        }
        for(int i = 0 ; i < searchWord.size(); i++)
        {
            vector<string>temp;
            giveSuggestion(root,searchWord,temp,i);
            result.push_back(temp);
            
        }
        return result;
    }
};