class Solution {
public:
    string countAndSay(int n) {
        if(n==1)return "1";
        if(n==2)return "11";
        string prev = countAndSay(n-1);
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
};