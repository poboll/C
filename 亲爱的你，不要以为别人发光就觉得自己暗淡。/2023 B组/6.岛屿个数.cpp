//F 岛屿个数
//题目描述
//小蓝得到了一副大小为 M × N 的格子地图，可以将其视作一个只包含字符‘0’（代表海水）和 ‘1’（代表陆地）的二维数组，地图之外可以视作全部是海水，每个岛屿由在上/下/左/右四个方向上相邻的 ‘1’ 相连接而形成。 在岛屿 A 所占据的格子中，如果可以从中选出 k 个不同的格子，使得他们的坐标能够组成一个这样的排列：(x0, y0),(x1, y1), . . . ,(xk−1, yk−1)，其中(x(i+1)%k , y(i+1)%k) 是由 (xi , yi) 通过上/下/左/右移动一次得来的 (0 ≤ i ≤ k − 1)， 此时这 k 个格子就构成了一个 “环”。如果另一个岛屿 B 所占据的格子全部位于这个 “环” 内部，此时我们将岛屿 B 视作是岛屿 A 的子岛屿。若 B 是 A 的子岛屿，C 又是 B 的子岛屿，那 C 也是 A 的子岛屿。 请问这个地图上共有多少个岛屿？在进行统计时不需要统计子岛屿的数目。
//输入格式
//第一行一个整数 T，表示有 T 组测试数据。 接下来输入 T 组数据。对于每组数据，第一行包含两个用空格分隔的整数M、N 表示地图大小；接下来输入 M 行，每行包含 N 个字符，字符只可能是‘0’ 或 ‘1’。
//输出格式
//对于每组数据，输出一行，包含一个整数表示答案。
//样例输入
//5 5
//01111
//11001
//10101
//10001
//11111
//5 6
//111111
//100001
//010101
//100001
//111111
//样例输出
//1
//3
//题意：找出所有不在环中的岛屿个数
//题解：从第一个点开始遍历，如果它为岛屿，那么找出跟他连通的所有岛屿，判断一下是否在环的内部，即该岛屿连成的岛能不能通过海水接触到边界，如果接触到边界就说明没有岛包围他。通过海水走的时候可以走八个方位。因为能斜着走通的话一样说明没有岛包围

// BFS
//这里采用了nx, ny作为坐标的累加值去实现上线左右移动，nx, ny中的顺序不重要，只要nx[i], ny[i]的组合能覆盖(0, 1),(0, -1),(1, 0),(-1, 0)就可以了。

https://yonagi04.github.io/posts/2024/f2c171f8c68b/index.html
