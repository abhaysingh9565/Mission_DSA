class Solution {
public:
    bool hasAll(vector<int>&freq)
    {
        for(int i = 0 ; i < 26 ; i++)
        {
            if(freq[i]==0)return false;
        }
        return true;
    }
    bool checkIfPangram(string sentence) {
        if(sentence.size()<26)
        {
            return false;
        }
        vector<int>freq(26,0);
        for(char c : sentence)
        {
            freq[c-'a']++;
            if(hasAll(freq))return true;
        }
        return false;
    }
};