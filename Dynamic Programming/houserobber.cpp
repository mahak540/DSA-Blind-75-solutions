int rob(vector<int>& nums) {
        int prev=0,maxrob=0;
        for(int curr:nums)
        {
            int temp=max(maxrob,prev+curr);
            prev=maxrob;
            maxrob=temp;
        }
        return maxrob;
    }
