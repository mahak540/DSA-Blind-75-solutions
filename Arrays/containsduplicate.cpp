bool containsDuplicate(vector<int>& nums) {
       unordered_map<int,int>ans;
       for(int num:nums)
       {
        if(ans[num]>=1)
           return true;
        ans[num]++;

       }
       return false;
    }
