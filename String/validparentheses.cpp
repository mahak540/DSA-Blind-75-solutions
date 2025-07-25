 bool check(char c1, char c2)
  {
      if(c1=='(' && c2==')')
      return true;
      if(c1=='[' && c2==']')
      return true;
      if(c1=='{' && c2=='}')
      return true;
      
      return false;
  }
    bool isValid(string s) {
        int top=-1;
        for(int i=0;i<s.length();++i){
            if(top<0 || !check(s[top],s[i]))
            {
                ++top;
                s[top]=s[i];
                
                
            }
            else
            {
                --top;
            }
        }
        return top==-1;
    }
