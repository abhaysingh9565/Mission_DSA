class TrieNode{
    public:
    TrieNode* children[26];
    bool isEnd;
    TrieNode()
    {
        for(int i =0 ; i<26 ; i++)children[i]=NULL;

        isEnd = false;
    }
};
class WordDictionary {
public:
    TrieNode* root;
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
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
        
    }
    bool forDot(TrieNode* root , string word , int index)
    {
        TrieNode* curr = root;
        for(int i = index; i< word.size(); i++)
        {
            char c = word[i];
            if(c=='.'){
                for(int j = 0 ; j < 26 ; j++)
                {
                    if(curr->children[j])
                    {
                        if(forDot(curr->children[j],word,i+1))
                        return true;
                    }
                }
                return false;
            }
            if(curr->children[c-'a'] == nullptr)
            {
                return false;
            }
            curr = curr->children[c-'a'];
        }
        return curr->isEnd;
    }
    bool search(string word) {
        return forDot(root,word,0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */