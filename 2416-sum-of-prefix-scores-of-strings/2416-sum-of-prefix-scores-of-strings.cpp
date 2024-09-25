class Solution {
public:
    struct TrieNode{
        unordered_map<char,TrieNode*> children;
        int prefixCount=0;
    };
    TrieNode* buildTrie(vector<string>& words){
        TrieNode* root=new TrieNode();
        for(string word:words){
            TrieNode* node=root;
            for(char ch:word){
                if(!node->children[ch]){
                    TrieNode* newnode=new TrieNode();
                    node->children[ch]=newnode;
                }
                node=node->children[ch];
                node->prefixCount++;
            }
        }
        return root;
    }
    vector<int> calculatePrefixScores(TrieNode* trie,vector<string>& words){
        vector<int> scores;
        for(string word:words){
            TrieNode* node=trie;
            int totalScore=0;
            for(char ch:word){
                node=node->children[ch];
                totalScore+=(node->prefixCount);
            }
            scores.push_back(totalScore);
        }
        return scores;
    }
    vector<int> sumPrefixScores(vector<string>& words) {
        TrieNode* trie=buildTrie(words);
        return calculatePrefixScores(trie,words);
    }
};