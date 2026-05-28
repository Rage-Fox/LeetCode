class Solution {
public:
    struct TrieNode {
        int child[26];
        int shortestLen;
        int shortestIdx;
        TrieNode() {
            memset(child, -1, sizeof(child));
            shortestLen = INT_MAX;
            shortestIdx = INT_MAX;
        }
    };
    vector<TrieNode> trie;
    Solution() {
        trie.push_back(TrieNode()); // root
    }
    void insertWord(const string& word, int idx) {
        int node = 0;
        int len = word.size();
        // update root
        if (len < trie[node].shortestLen) {
            trie[node].shortestLen = len;
            trie[node].shortestIdx = idx;
        }
        for (int i = len - 1; i >= 0; --i) {
            int c = word[i] - 'a';
            if (trie[node].child[c] == -1) {
                trie[node].child[c] = trie.size();
                trie.push_back(TrieNode());
            }
            node = trie[node].child[c];
            if (len < trie[node].shortestLen) {
                trie[node].shortestLen = len;
                trie[node].shortestIdx = idx;
            }
        }
    }
    int searchWord(const string& word) {
        int node = 0;
        for (int i = word.size() - 1; i >= 0; i--) {
            char ch = word[i]-'a';
            if (trie[node].child[ch] == -1)
                break;
            node = trie[node].child[ch];
        }
        return trie[node].shortestIdx;
    }
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        // TRIE APPROACH
        for (int i = 0; i < wordsContainer.size(); i++) {
            insertWord(wordsContainer[i], i);
        }
        vector<int> ans;
        for (auto& q : wordsQuery) {
            ans.push_back(searchWord(q));
        }
        return ans;
    }
};