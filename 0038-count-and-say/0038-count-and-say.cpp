class Solution {
    private:
    string decode(string &prev)
    {
        string curr = "";
        for(int i = 0 ; i<prev.size(); i++)
        {
            int count = 1;
            int index = i;
            while(index<prev.size()-1 && prev[index]==prev[index+1])
            {
                count++;
                index++;
            }
            i = index;
            curr+=to_string(count);
            curr+=prev[i];
        }    
        return curr;
    }
public:
    string countAndSay(int n) {
        if(n==1)return "1";
        string prev =  countAndSay(n-1);
        return decode(prev);
    }
};