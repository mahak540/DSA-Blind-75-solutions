 bool isPalindrome(string s) {
       
        string res;
        for(char c : s){

            if(isalnum(c))
            {
                res +=tolower(c);
            }
        }
        int l=0,r=res.length()-1;
       while(l<=r){
        if(res[l]!=res[r])
        {
            return false;
        }
            l++;
            r--;
        
       }
       return true;
    }
