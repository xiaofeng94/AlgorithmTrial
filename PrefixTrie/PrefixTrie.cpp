class TrieNode {
public:
    bool isEnd;
    char val;
    TrieNode* ftChild;
    TrieNode* ntBrother;
    // Initialize your data structure here.
    TrieNode() {
        this->val = '\0';
        ftChild = NULL;
        ntBrother = NULL;
        isEnd = false;
    }
    
    TrieNode(char val) {
        this->val = val;
        ftChild = NULL;
        ntBrother = NULL;
        isEnd = false;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }
    
    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode* lastNode = this->root;
        TrieNode* curr = this->root->ftChild;

        int i = 0;
        while (curr != NULL) {
            if (curr->val == word[i]) {
                lastNode = curr;
                curr = lastNode->ftChild;
                ++i;
                if (i == word.size()) {
                    lastNode->isEnd = true;
                }
                if(i >= word.size()){
                    return;
                }
                continue;
            }
            
            if (curr->val > word[i]) {
                TrieNode* tempNode = new TrieNode(word[i++]);
                if (lastNode->ftChild == curr) {
                    tempNode->ntBrother = lastNode->ftChild;
                    lastNode->ftChild = tempNode;
                }else{
                    tempNode->ntBrother = lastNode->ntBrother;
                    lastNode->ntBrother = tempNode;
                }
                lastNode = tempNode;
                curr = lastNode->ftChild;
                if (i == word.size()) {
                    lastNode->isEnd = true;
                }
                break;
            }
            
            lastNode = curr;
            curr = lastNode->ntBrother;
            if (curr == NULL) {
                TrieNode* tempNode = new TrieNode(word[i++]);
                lastNode->ntBrother = tempNode;
                lastNode = tempNode;
                curr = lastNode->ftChild;
                if (i == word.size()) {
                    lastNode->isEnd = true;
                }
                break;
            }
        }
        
        if(curr == NULL){
            while (i < word.size()) {
                TrieNode* tempNode = new TrieNode(word[i++]);
                
                lastNode->ftChild = tempNode;
                lastNode = tempNode;
                curr = lastNode->ftChild;
                if (i == word.size()) {
                    tempNode->isEnd = true;
                }
            }
        }
    }
    
    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode* curr = this->root->ftChild;
        
        int indx = 0;
        while(curr != NULL){
            if(curr->val == word[indx]){
                ++indx;
                if(indx >= word.size() && curr->isEnd == true){
                    return true;
                }
                curr = curr->ftChild;
                if(curr == NULL){
                    return false;
                }
                continue;
            }
            curr = curr->ntBrother;
        }
        return false;
    }
    
    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* curr = this->root->ftChild;
        
        int indx = 0;
        while(curr != NULL){
            if(curr->val == prefix[indx]){
                curr = curr->ftChild;
                ++indx;
                if(indx >= prefix.size()){
                    return true;
                }
                continue;
            }
            curr = curr->ntBrother;
        }
        return false;
    }
    
private:
    TrieNode* root;
};
