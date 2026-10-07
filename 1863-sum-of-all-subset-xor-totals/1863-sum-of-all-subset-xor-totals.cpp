class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int OR = 0;

        for(int num : nums) {
            OR |= num;
        }

        return OR * (1 << (nums.size() - 1));
    }
};