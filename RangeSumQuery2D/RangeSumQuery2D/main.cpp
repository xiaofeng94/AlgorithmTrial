//
//  main.cpp
//  RangeSumQuery2D
//
//  Created by zsy on 16/4/19.
//  Copyright © 2016年 zsy. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class NumMatrix {
    vector<int*> matrixRec;
public:
    NumMatrix(vector<vector<int>> &matrix) {
        for (int i = 0; i < matrix.size(); ++i) {
            int* p = new int[matrix[0].size()];
            matrixRec.push_back(p);
        }
        
        for(int i = 0;i < matrix.size();++i){
            for(int j = 0;j < matrix[i].size();++j){
                if(i == 0){
                    if(j == 0){
                        matrixRec[i][j] = matrix[i][j];
                    }else{
                        matrixRec[i][j] = matrixRec[i][j-1]+matrix[i][j];
                    }
                }else{
                    if(j == 0){
                        matrixRec[i][j] = matrixRec[i-1][j]+matrix[i][j];
                    }else{
                        matrixRec[i][j] = matrixRec[i-1][j]+matrixRec[i][j-1]-matrixRec[i-1][j-1]+matrix[i][j];
                    }
                }
            }
        }
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if(row1 == 0){
            if(col1 == 0){
                return matrixRec[row2][col2];
            }else{
                return matrixRec[row2][col2]-matrixRec[row2][col1-1];
            }
        }else{
            if(col1 == 0){
                return matrixRec[row2][col2]-matrixRec[row1-1][col2];
            }else{
                return matrixRec[row2][col2]-matrixRec[row1-1][col2]-matrixRec[row2][col1-1]+matrixRec[row1-1][col1-1];
            }
        }
    }
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<vector<int>> matrix;
    vector<int> r0;
    vector<int> r1;
    vector<int> r2;
    vector<int> r3;
    vector<int> r4;
    r0.push_back(3);
    r0.push_back(0);
    r0.push_back(1);
    r0.push_back(4);
    r0.push_back(2);
    
    r1.push_back(5);
    r1.push_back(6);
    r1.push_back(3);
    r1.push_back(2);
    r1.push_back(1);
    
    r2.push_back(1);
    r2.push_back(2);
    r2.push_back(0);
    r2.push_back(1);
    r2.push_back(5);
    
    r3.push_back(4);
    r3.push_back(1);
    r3.push_back(0);
    r3.push_back(1);
    r3.push_back(7);
    
    r4.push_back(1);
    r4.push_back(0);
    r4.push_back(3);
    r4.push_back(0);
    r4.push_back(5);
    matrix.push_back(r0);
    matrix.push_back(r1);
    matrix.push_back(r2);
    matrix.push_back(r3);
    matrix.push_back(r4);
    
    NumMatrix numMatrix(matrix);
    
    cout << numMatrix.sumRegion(2, 1, 4, 3) << endl;// -> 8
    cout << numMatrix.sumRegion(1, 1, 2, 2) << endl;// -> 11
    cout << numMatrix.sumRegion(1, 2, 2, 4) << endl;// -> 12
}









