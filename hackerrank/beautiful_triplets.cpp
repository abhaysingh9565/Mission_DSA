int beautifulTriplets(int d, vector<int> nums) {
  unordered_map<int,int> mp;
  int n = nums.size();
  for(int i = 0 ; i< n ; i++)mp[nums[i]]=i;
  
  int ans= 0 ; 
  for(int i = 0 ; i<n ; i++)
  {
      int num1 = nums[i]+d;
      int num2 = nums[i]+2*d;
      if(mp.count(num1) && mp.count(num2) )
      {
          if(i<mp[num1] && mp[num1]<mp[num2])ans++;
      }
      
  }
  return ans;
}