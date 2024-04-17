//
// Created by 大妖怪 on 2023/10/19.
//
/**
 * 编写一种算法，若M × N矩阵中某个元素为0，则将其所在的行与列清零。
*/
void setZeroes(int** matrix, int matrixSize, int* matrixColSize){
    int i, j;
    int row[matrixSize], col[*matrixColSize];
    for(i = 0; i < matrixSize; i ++) {
        for(j = 0; j < matrixSize; j ++) {
            if(matrix[i][j] == 0) {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }

    for(i = 0; i < matrixSize; i ++) {
        for(j = 0; j < *matrixColSize; j ++) {
            if(row[i] || col[j]) {
                matrix[i][j] = 0;
            }
        }
    }
}