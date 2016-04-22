
class Solution {
public:
    vector<vector<string>> result;
    
    vector<vector<string>> solveNQueens(int n) {
        int *ltCheck = new int[2*n-1];
        int *rtCheck = new int[2*n-1];
        int *verCheck = new int[n];
        int *record = new int[n];
        for (int i = 0; i < 2*n-1; ++i) {
            ltCheck[i] = 0;
            rtCheck[i] = 0;
            if(i < n){
                verCheck[i] = 0;
                record[i] = 0;
            }
        }
        
        solution(ltCheck, rtCheck, verCheck, 0, record, n);
        delete [] ltCheck;
        delete [] rtCheck;
        delete [] verCheck;
        delete [] record;
        
        return result;
    }
    
    void solution(int* ltCheck,int *rtCheck, int *verCheck,int layer,int* record,int n){
        if (layer >= n) {
            return;
        }
        for(int i = 0;i < n;++i){
            if(ltCheck[i-layer+n-1] == 0 && rtCheck[layer+i] == 0 && verCheck[i] == 0){
                ltCheck[i-layer+n-1] = 1;
                rtCheck[layer+i] = 1;
                verCheck[i] = 1;
                record[layer] = i;
                
                solution(ltCheck, rtCheck, verCheck, layer+1, record, n);
                if(layer == n-1){
                    recordResult(this->result,record,n);
                }
                
                ltCheck[i-layer+n-1] = 0;
                rtCheck[layer+i] = 0;
                verCheck[i] = 0;
            }
        }
    }
    
    void recordResult(vector<vector<string>>& result,int* record,int n){
        vector<string> resTemp;
        for(int i = 0;i < n;++i){
            string rowContent;
            rowContent.clear();
            for(int j = 0;j < n;++j){
                if(record[i] == j){
                    rowContent = rowContent + "Q";
                }else{
                    rowContent = rowContent + ".";
                }
            }
            resTemp.push_back(rowContent);
        }
        result.push_back(resTemp);
    }
    
};