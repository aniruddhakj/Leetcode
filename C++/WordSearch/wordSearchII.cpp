// Author : Aniruddha Krishna Jha
// Date : 05/11/2022

/*******************************************************************************
Given an m x n board of characters and a list of strings words, return all words on the board.

Each word must be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. 
The same letter cell may not be used more than once in a word.

Example:

Input: board = [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]], words = ["oath","pea","eat","rain"]
Output: ["eat","oath"]
*******************************************************************************/

// INTUITION: Trie to store prefix for each word in dictionary
// dfs to search through the trie

class Solution {
public:
    
    struct TrieNode {
        string word;
        vector<TrieNode*> child;
        TrieNode(): word(""), child(vector<TrieNode*>(26, nullptr)) {}
    };
    
    
    TrieNode * buildTrie(vector<string>& words) {
        TrieNode * root = new TrieNode();
        for(string &w : words) {
            TrieNode *tmp = root;
            for(char &c: w) {
                int i = c - 'a';
                if (!tmp->child[i]) tmp->child[i] = new TrieNode();
                tmp = tmp->child[i];
            }
            tmp->word = w;
        }
        return root;
    } 

    
    void dfs(vector<vector<char>> &b, int i, int j, TrieNode *root, vector<string> &res) {
        int m = b.size(), n = b[0].size();
        char c = b[i][j];
        if(c == '#' || !root->child[c - 'a']) // no child for this char
            return;
        
        root = root->child[c - 'a'];
        // if a word exists at current, push to res and remove from Trie
        if(root->word != "") {
            res.push_back(root->word);
            root->word = "";
        }
        
        // mark visited and dfs conditioned for each dir
        b[i][j] = '#';
        if (i > 0) dfs(b, i - 1, j, root, res);
        if (j > 0) dfs(b, i, j - 1, root, res);
        if (i < m - 1) dfs(b, i + 1, j, root, res);
        if (j < n - 1) dfs(b, i, j + 1, root, res);

        // assign value back 
        b[i][j] = c;   
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        TrieNode* root = buildTrie(words);
        for(int i = 0; i < board.size(); ++i) {
            for(int j = 0; j < board[0].size(); ++j) 
                dfs(board, i, j, root, res);
        }
        return res;
    }
    
};

