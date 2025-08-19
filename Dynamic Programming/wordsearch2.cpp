class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isEndOfWord = false;
    
    TrieNode() {}
};
class Trie {
public:
    TrieNode* root;
    
    Trie() {
        root = new TrieNode();
    }
    void insert(const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->children.count(c)) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
        node->isEndOfWord = true;
    }
};
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
        
Trie trie;
        for (const string& word : words) {
            trie.insert(word);
        }
        
        vector<string> result;
        unordered_set<string> foundWords;
        int m = board.size();
        int n = board[0].size();
        
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                dfs(board, trie.root, "", i, j, visited, foundWords);
            }
        }
        
        result.assign(foundWords.begin(), foundWords.end());
        return result;
        
    }
    private:
    void dfs(vector<vector<char>>& board, TrieNode* node, string currentWord, int x, int y, vector<vector<bool>>& visited, unordered_set<string>& foundWords) {
        if (node->isEndOfWord) {
            foundWords.insert(currentWord);
            node->isEndOfWord = false; // Avoid duplicate entries
        }
        
        if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || visited[x][y]) {
            return;
        }
        
        char c = board[x][y];
        if (!node->children.count(c)) {
            return;
        }
         visited[x][y] = true;
        currentWord += c;
        
        // Explore neighbors
        dfs(board, node->children[c], currentWord, x + 1, y, visited, foundWords);
        dfs(board, node->children[c], currentWord, x - 1, y, visited, foundWords);
        dfs(board, node->children[c], currentWord, x, y + 1, visited, foundWords);
        dfs(board, node->children[c], currentWord, x, y - 1, visited, foundWords);
        
        visited[x][y] = false; // Backtrack
    }
};
