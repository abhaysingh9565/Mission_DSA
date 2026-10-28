class Solution {
public:
    int binarySearchFirst(vector<int>& nums, int target,int s , int e)
    {
        int ans = -1;
        while(s<=e)
        {
            int mid = s+(e-s)/2;
            if(nums[mid]>=target)
            {
                if(nums[mid]==target)
                ans = mid;
                e = mid-1;
            }
            else s = mid+1;
        }
        return ans;
    }
    int binarySearchSecond(vector<int>& nums, int target,int s , int e)
    {
        int ans = -1;
        while(s<=e)
        {
            int mid = s+(e-s)/2;
            if(nums[mid]<=target)
            {
                if(nums[mid]==target)
                ans = mid;
                s = mid+1;
            }
            else e = mid-1;
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& arr, int target) {
        int n = arr.size();
        // if(n==0)
        // {
        //     return {-1,-1};
        // }
        int f = binarySearchFirst(arr,target , 0 ,n-1);
        if(f==-1)return {-1,-1};
        int l = binarySearchSecond(arr,target,f , n-1);
        return {f,l};
    }
};