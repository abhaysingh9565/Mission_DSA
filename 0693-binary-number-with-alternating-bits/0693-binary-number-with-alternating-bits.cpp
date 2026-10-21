class Solution {
public:
    bool hasAlternatingBits(int n) {
        int prev = -1 , curr = 0;
        while(n!=0)
        {
            curr = n&1;
            if(curr == prev)return false;

            prev = curr;
            n>>=1;
        }
        return true;
        
    }
};