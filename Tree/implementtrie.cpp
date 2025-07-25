class Trie {
public:
Trie *child[26];
bool isend;
    Trie() {
         isend=false;
        for(int i=0;i<26;i++)
        child[i]=NULL;
    }
    
    void insert(string word) {
          Trie *curr=this;
        for(int i=0;i<word.length();i++)
        {
            int index=word[i]-'a';
            if(curr->child[index]==NULL)
            curr->child[index]=new Trie();
            curr=curr->child[index];
        }
        curr->isend=true;
    }
    
    bool search(string word) {
           Trie *curr=this;
        for(int i=0;i<word.length();i++)
        {
            int index=word[i]-'a';
            if(curr->child[index]==NULL)
            return false;
            curr=curr->child[index];
        }
        return curr->isend;
    }
    
    bool startsWith(string prefix) {
         Trie *curr=this;
        for(int i=0;i<prefix.length();i++)
        {
            int index=prefix[i]-'a';
            if(curr->child[index]==NULL)
            return false;
            curr=curr->child[index];
        }
        return true;
    }
};
