string findOrder(vector<string> &words) {
        // code here
        vector<vector<int>>graph(26);
        vector<int>indegree(26,0);
        vector<bool>exists(26,false);
        
        for(const string& word:words)
        {
            for(char ch:word)
            {
                exists[ch-'a']=true;
            }
        }
        for(int i=0;i+1<words.size();++i)
        {
            const string& w1=words[i];
            const string& w2=words[i+1];
            
            int len=min(w1.length(),w2.length());
            int j=0;
            
            while(j<len && w1[j]==w2[j])
            ++j;
            
            if(j<len)
            {
                int u=w1[j]-'a';
                int v=w2[j]-'a';
                graph[u].push_back(v);
                indegree[v]++;
                
            }
            else if(w1.size()>w2.size())
            {
                return "";
                
            }
            
        }
        queue<int>q;
        for(int i=0;i<26;++i)
        {
            if(exists[i] && indegree[i]==0 )
            {
                q.push(i);
            }
        }
        string res;
        while(!q.empty())
        {
            int u=q.front();
            q.pop();
            res+=(char)(u+'a');
            
            for(int v:graph[u])
            {
                indegree[v]--;
                
                if(indegree[v]==0)
                {
                    q.push(v);
                }
            }
        }
        for(int i=0;i<26;++i)
        {
            if(exists[i] && indegree[i]!=0){
                return "";
            }
        }
        return res;
        }
