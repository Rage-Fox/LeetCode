class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isWord;
    TrieNode(){
        isWord = false;
    }
    void addWord(string &word) {
        TrieNode* cur = this;
        for (char c : word) {
            if (!cur->children.count(c)) {
                cur->children[c] = new TrieNode();
            }
            cur = cur->children[c];
        }
        cur->isWord = true;
    }
};
class Solution {
public:
    unordered_set<string> res;
    vector<vector<bool>> visit;
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (string &word : words) {
            root->addWord(word);
        }
        int rows = board.size(), cols = board[0].size();
        visit.assign(rows, vector<bool>(cols, false));
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                dfs(board, r, c, root, "");
            }
        }
        return vector<string>(res.begin(), res.end());
    }
private:
    void dfs(vector<vector<char>>& board, int r, int c, TrieNode* node, string word) {
        int rows = board.size(), cols = board[0].size();
        if (r < 0 || c < 0 || r >= rows || c >= cols || visit[r][c] || !node->children.count(board[r][c])) {
            return;
        }
        visit[r][c] = true;
        node = node->children[board[r][c]];
        word += board[r][c];
        if (node->isWord) {
            res.insert(word);
        }
        dfs(board, r + 1, c, node, word);
        dfs(board, r - 1, c, node, word);
        dfs(board, r, c + 1, node, word);
        dfs(board, r, c - 1, node, word);
        visit[r][c] = false;
    }
};