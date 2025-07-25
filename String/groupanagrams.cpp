const int MAX_CHAR=26;
  string gethash(string &s)
  {
      string hash;
      vector<int>freq(MAX_CHAR,0);
      for(char ch:s)
      freq[ch-'a']+=1;
      
      for(int i=0;i<MAX_CHAR;i++)
      {
          hash.append(to_string(freq[i]));
          hash.append("$");
      }
      return hash;
  }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
      vector<vector<string>>res;
        unordered_map<string,int>mp;
        for(int i=0;i<strs.size();i++)
        {
            string key=gethash(strs[i]);
            if(mp.find(key)==mp.end())
            {
                mp[key]=res.size();
                res.push_back({});
            }
            res[mp[key]].push_back(strs[i]);
        }
        return res;

    }
