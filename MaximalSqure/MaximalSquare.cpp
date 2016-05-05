class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size() == 0){
            return 0;
        }
        vector<vector<int>> assist;
        for(int i = 0;i < matrix.size();++i){
            vector<int> inner;
            assist.push_back(inner);
            for(int j = 0;j < matrix[i].size();++j){
                if(i == 0){
                    assist[i].push_back( (matrix[i][j] == '0')?0:1 );
                }else{
                    if(j == 0){
                        assist[i].push_back( (matrix[i][j] == '0')?0:1 );
                    }else{
                        if(matrix[i][j] != '0' ){
                            int tempMin = assist[i-1][j-1];
                            if(tempMin > assist[i-1][j]){
                                tempMin = assist[i-1][j];
                            }
                            if(tempMin > assist[i][j-1]){
                                tempMin = assist[i][j-1];
                            }
                            assist[i].push_back( tempMin+1 );
                        }else{
                            assist[i].push_back( 0 );
                        }
                    }
                }
            }
        }
        int maxSquare = assist[0][0];
        for(int i = 0;i < assist.size();++i){
            for(int j = 0;j < assist[i].size();++j){
                if(maxSquare < assist[i][j]){
                    maxSquare = assist[i][j];
                }
            }
        }
        return maxSquare*maxSquare;
    }
};