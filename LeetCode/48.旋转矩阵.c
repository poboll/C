//
// Created by 大妖怪 on 2023/10/19.
/**
* 给你一幅由 N × N 矩阵表示的图像，其中每个像素的大小为 4 字节。请你设计一种算法，将图像旋转 90 度。
 * 不占用额外内存空间能否做到？
*/
void rotate(int** matrix, int matrixSize, int* matrixColSize){
    int i, j;
    for(i = 0; i < matrixSize; i ++) {
        for(j = i + 1; j < matrixSize; j ++) {
            // swap(arr[i][j], arr[j][i]);
            // 对角线翻转，沿左上到右下
            matrix[i][j] = matrix[i][j] ^ matrix[j][i];
            matrix[j][i] = matrix[i][j] ^ matrix[j][i];
            matrix[i][j] = matrix[i][j] ^ matrix[j][i];
        }
    }
    for(i = 0; i < matrixSize; i ++) {
        for(j = 0; j < matrixSize / 2; j ++) {
            // swap(matrix[i][j], matrix[j][i]);
            // 水平翻转，沿垂直中心线
            matrix[i][j] = matrix[i][matrixSize - j - 1] ^ matrix[i][j];
            matrix[i][matrixSize - j - 1] = matrix[i][matrixSize - j - 1] ^ matrix[i][j];
            matrix[i][j] = matrix[i][matrixSize - j - 1] ^ matrix[i][j];
        }
    }

}