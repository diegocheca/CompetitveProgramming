//link -->   https://leetcode.com/problems/rotate-image/
//Level: medium
void rotate(int** matrix, int matrixSize, int* matrixColSize){
    for(int i = 0; i < (matrixSize/2); ++i){
        for(int j = i; j < (matrixSize - 1 - i); ++j){
            int temp1 = matrix[i][j];
            int temp2 = matrix[j][matrixSize-1-i];
            int temp3 = matrix[matrixSize-1-i][matrixSize-1-j];
            int temp4 = matrix[matrixSize-1-j][i];
            
            matrix[i][j] = temp4;
            matrix[j][matrixSize-1-i] = temp1;
            matrix[matrixSize-1-i][matrixSize-1-j] = temp2;
            matrix[matrixSize-1-j][i] = temp3;
        }
    }
}