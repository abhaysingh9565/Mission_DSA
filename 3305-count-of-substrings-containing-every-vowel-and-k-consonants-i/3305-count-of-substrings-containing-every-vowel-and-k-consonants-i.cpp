class Solution {
private: 
    bool isNotVowel(char c)
    {
        return c!='a'&& c!='e'&& c!='i' && c!='o'&& c!='u';
    }
    bool hasVowels(vector<int>&freq)
    {
        return freq[0]&&freq[4]&&freq[8]&&freq[14]&&freq[20];
    }
public:
    int countOfSubstrings(string word, int k) {
        int cons = 0;
        int j = 0;
        int ans = 0 ;
        vector<int>freq(26,0);
        for(int i = 0 ; i < word.size() && j < word.size(); i++)
        {
            char c = word[i];
            freq[c-'a']++;
            if(isNotVowel(c))
            {
                cons++;
            }
            while(cons>k)
            {
                if(isNotVowel(word[j]))cons--;
                freq[word[j]-'a']--;
                j++;
            }

            if(hasVowels(freq) && cons == k){
                ans++;
                int temp = j ;
                while(temp < i && !isNotVowel(word[temp]) && freq[word[temp]-'a']>1)
                {
                    freq[word[temp++]-'a']--;
                    if(hasVowels(freq))ans++;
                }
                while(temp>j)
                {
                    freq[word[--temp]-'a']++;
                }
            }
        }
        return ans;
        
    }
};

