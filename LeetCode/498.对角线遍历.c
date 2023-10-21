//
// Created by 大妖怪 on 2023/10/20.
//
/**
* 给你一个大小为 m x n 的矩阵 mat ，请以对角线遍历的顺序，用一个数组返回这个矩阵中的所有元素。
*/
int* findDiagonalOrder(int** mat, int matSize, int* matColSize, int* returnSize){
    *returnSize = matSize * (* matColSize);
    int *ans = (int *)malloc((* returnSize) * sizeof(int));
    // 行列1特殊处理
    if(matSize == 1) {
        return mat[0];
    }else if(*matColSize == 1) {
        for(int i = 0; i < *returnSize; i ++) {
            ans[i] = mat[i][0];
            return ans;
        }
    }
    // i行j列，flag==0从上到下，等于1表示从下到上
    int i = 0, j = 0, k = 0, flag = 1;

    while(k < *returnSize) {
        ans[k ++] = mat[i][j];
        // 边界转置
        if(i == 0 || j == (*matColSize) - 1) {
            flag = 1;
            if(j < (*matColSize) - 1) {
                j ++;
            }else {
                i ++;
            }
            ans[k++] = mat[i][j];
        }else if(i == matSize - 1 || j == 0){
            flag = 0;
            if(i < matSize - 1){
                i ++;
            }else {
                j ++;
            }
            ans[k ++] = mat[i][j];
        }
        // 向下/向上移动
        if(flag) {
            i ++, j --;
        }else {
            i --, j ++;
        }
    }
    return ans;
}