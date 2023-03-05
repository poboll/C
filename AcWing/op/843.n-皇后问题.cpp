/*843.n-皇后问题
n−皇后问题是指将 n 个皇后放在 n×n 的国际象棋棋盘上，使得皇后不能相互攻击到，即任意两个皇后都不能处于同一行、同一列或同一斜线上。
现在给定整数 n，请你输出所有的满足条件的棋子摆法。
输入格式：
共一行，包含整数 n。
输出格式：
每个解决方案占 n 行，每行输出一个长度为 n 的字符串，用来表示完整的棋盘状态。
其中 . 表示某一个位置的方格状态为空，Q 表示某一个位置的方格上摆着皇后。
每个方案输出完成后，输出一个空行。
注意：行末不能有多余空格。
输出方案的顺序任意，只要不重复且没有遗漏即可。
数据范围：
1≤n≤9
输入样例：
4
输出样例：
.Q..
...Q
Q...
..Q.

..Q.
Q...
...Q
.Q..
二、算法基本思想
DFS（深度优先搜索）
（搜索顺序一）由于每一行每一列上都只能有一个皇后，我们可以按行枚举，判断皇后应该放在哪一列上。且根据任意两个皇后都不能在同一条对角线上“剪枝”。
（搜索顺序二）我们按照一行一行的顺序，逐个枚举每一个格子。根据限定条件“任意两个皇后都不能处于同一行、同一列或同一斜线上”上判断是否应该放皇后，最后皇后的数量等于n说明我们已经找到了结果，输出即可。
三、步骤
1.首先在所有的棋盘上都填上“ . ”
2.按行开始枚举，判断皇后应该放在哪一列（核心代码）
（1）当算法进行到第n行时，代表n个皇后都已经放置完毕，可以直接呼出结果了
（2）当算法没有进行到第n行时（设为u)，利用for循环从第1列开始遍历，如果第i列没有放皇后，且其所处的正对角线和反对角线也都没有放置皇后，说明该位置可以
放皇后；
    然后标记这个位置所在的列、对角线和反对角线为true，即在同一列、同一对角线和同一反对角线的位置不可以再放皇后；
    接着调用dfs函数，进行到第 u + 1行，重复此操作；
    当dfs函数结束以后，一定要记得恢复上一层的状态（即列、对角线反对角线都恢复为未使用的状态）。这是dfs的回溯操作。
3.输出结果
*/