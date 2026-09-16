class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int>fq(26,0);
        for(auto i : magazine)
        fq[i-'a']++;

        for(auto i: ransomNote)
        {
            if(--fq[i-'a']<0)
            return false;
        }
        return true;
        
    }
};