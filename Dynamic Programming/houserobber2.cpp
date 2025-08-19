class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1)
        return nums[0];

        return max(getMax(nums,0,nums.size()-2),getMax(nums,1,nums.size()-1));
    }
    private:
    int getMax(vector<int>& nums,int s,int e)
    {
        int prev=0,maxrob=0;
        for(int i=s;i<=e;i++)
        {
            int temp=max(maxrob,prev+nums[i]);
            prev=maxrob;
            maxrob=temp;
        }
        return maxrob;
    }
};
