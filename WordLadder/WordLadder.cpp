class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
//        int min = wordList.size()+3;
//        bool* visited = new bool[wordList.size()];
//        for (int i = 0; i < wordList.size(); ++i) {
//            visited[i] = false;
//        }
//        unordered_set<string>::iterator it;
//        
//        recusiveSearch(beginWord,endWord,wordList,visited,0,2,min);
//        delete visited;
//        return ((min == wordList.size()+3)?0:min);
        
        int min = 2;
        bool* visited = new bool[wordList.size()];
        for (int i = 0; i < wordList.size(); ++i) {
            visited[i] = false;
        }
        queue<string> searchQue;
        string curr = beginWord;
        searchQue.push(beginWord);
        unordered_set<string>::iterator it;
        
        int layer = 1;
        int layerRec = 1;
        int visitCount = 0;
        while (searchQue.size() != 0){

            while (visitCount < layerRec) {
                
                string word = searchQue.front();
                searchQue.pop();
                ++visitCount;
                if (isValidTrans(word, endWord)) {
                    return min;
                }
                
                for (int p = 0; p < (int)word.length(); p++) {
                    char letter = word[p];
                    for (int k = 0; k < 26; k++) {
                        word[p] = 'a' + k;
                        if (letter != word[p] && wordList.find(word) != wordList.end()) {
                            searchQue.push(word);
                            wordList.erase(word);
                            ++layer;
                        }
                    }
                    word[p] = letter;
                }
            }
            layerRec = layer;
            ++min;
        }
    
        
        return 0;
    }
    
    bool isValidTrans(string s1, string s2){
        if(s1.size() != s2.size()){
            return false;
        }
        int cout = 0;
        for(int i = 0;i < s1.size();++i){
            if(s1[i] != s2[i]){
                ++cout;
            }
        }
        
        return ((cout == 1)? true:false);
    }
};