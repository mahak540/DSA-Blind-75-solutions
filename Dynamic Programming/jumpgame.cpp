bool canJump(vector<int>& nums) {
        int i=0,j=nums.size()-1;
        int jump=nums.size()-1;
        while(jump>=0)
        {
            if(jump+nums[jump]>=j)
            j=jump;
            jump--;
        }
        return j==0;

    }
