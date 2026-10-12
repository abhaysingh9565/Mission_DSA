class Solution {
public:
    bool checkPrefix(string &a , string &b)
    {
        if(b.size()>a.size())return false;

        for(int i= 0 ; i < b.size();i++)
        {
            if(a[i]!=b[i])return false;
        }
        return true;

    }
    int isPrefixOfWord(string sentence, string searchWord) {
        int word = 1;
        int j = 0;
        for(int i = 0 ; i< sentence.size() ; i++)
        {
            if(sentence[i]==' ')
            {
                string s = sentence.substr(j,i-j);
                if(checkPrefix(s,searchWord))return word;

                word++;
                j=i+1;
            }
        }
        string s = sentence.substr(j,sentence.size()-j);
        if(checkPrefix(s,searchWord))return word;

        return -1;
    }
};