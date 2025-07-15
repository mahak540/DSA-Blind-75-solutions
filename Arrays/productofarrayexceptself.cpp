vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>pre(n),suf(n),res(n);
        
        pre[0]=1;
        for(int i=1;i<n;i++){
        pre[i]=nums[i-1]*pre[i-1];
        }
        suf[n-1]=1;
        for(int j=n-2;j>=0;j--){
        suf[j]=nums[j+1]*suf[j+1];
        }
        
        for(int i=0;i<n;i++){
        res[i]=pre[i]*suf[i];
        }
        return res;
    }
