class Solution {
public:
    bool judgeSquareSum(int c) {
        long i = 0 , e = sqrt(c);
        while(i<=e)
        {
            long long val = e*e + i*i;
            if(val == c)return true;
            if(val<c)i++;
            else e--;
        }
        return false;
        
    }
};