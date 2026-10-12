class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int word = 1;
        int j = 0;
        for(int i = 0 ; i< sentence.size() ; i++)
        {
            if(sentence[i]==' ')
            {
                string s = sentence.substr(j,i-j);
                if(s.find(searchWord)==0)return word;

                word++;
                j=i+1;
            }
        }
        string s = sentence.substr(j,sentence.size()-j);
        if(s.find(searchWord)==0)return word;

        return -1;
    }
};