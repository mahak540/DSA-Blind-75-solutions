bool isAnagram(string s, string t) {
        if(s.length()!=t.length())
        return false;
        int cnt[26]={0};
        for(int i=0;i<s.length();i++){
            cnt[s[i]-'a']++;
            cnt[t[i]-'a']--;
        }
        for(int i=0;i<26;i++){
            if(cnt[i])

            return false;
        }
        return true;
    }
