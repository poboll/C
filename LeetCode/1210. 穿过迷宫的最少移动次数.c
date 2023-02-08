int minimumMoves(int** grid, int gridSize, int* gridColSize){
    int n=gridSize,m;
    int MAX=999999;//没有路的步数
    int stph[n][n];//蛇水平步数（horizontal step）
    int stpv[n][n];//蛇竖直步数（vertical step）
    //蛇尾从x,y到n-1,n-2的步数
    int i,j;

    stph[n-1][n-2]=0;//到了
    for(i=n-3;i>=0;i--){
        if(grid[n-1][i]){
            break;
        }
        stph[n-1][i]=stph[n-1][i+1]+1;
    }
    for(;i>=0;i--){
        stph[n-1][i]=MAX;
    }/*
    蛇尾到底端时只能水平，
    如果路上有障碍就不能到达目标。
    */

    for(i=n-1;i>=0;i--){
        stph[i][n-1]=MAX;
        stpv[i][n-1]=MAX;
        stpv[n-1][i]=MAX;
    }/*
    蛇尾到最右端时不能水平，
    蛇尾到最右端时，即使竖直也不能到达目标。
    蛇尾到底端时不能竖直。
    */

    for(i=n-2;i>=0;i--){
        for(j=n-2;j>=0;j--){
            if(grid[i][j]|(grid[i][j+1]&grid[i+1][j])){
                stph[i][j]=MAX;
                stpv[i][j]=MAX;
                continue;
            }//蛇没空间
            if(grid[i][j+1]){
                stph[i][j]=MAX;
                stpv[i][j]=stpv[i+1][j]+1;
                continue;
            }//只能竖直
            if(grid[i+1][j]){
                stpv[i][j]=MAX;
                stph[i][j]=stph[i][j+1]+1;
                continue;
            }//只能水平
            stph[i][j]=(stph[i+1][j]<stph[i][j+1])?stph[i+1][j]+1:stph[i][j+1]+1;
            stpv[i][j]=(stpv[i+1][j]<stpv[i][j+1])?stpv[i+1][j]+1:stpv[i][j+1]+1;
            //既能竖直也能水平
            if(!grid[i+1][j+1]){
                if(stpv[i][j]>stph[i][j]+1)stpv[i][j]=stph[i][j]+1;
                if(stph[i][j]>stpv[i][j]+1)stph[i][j]=stpv[i][j]+1;
            }//可以旋转
        }
    }

    if(stph[0][0]>=MAX)return -1;
    return stph[0][0];
}int minimumMoves(int** grid, int gridSize, int* gridColSize){
    int n=gridSize,m;
    int MAX=999999;//没有路的步数
    int stph[n][n];//蛇水平步数（horizontal step）
    int stpv[n][n];//蛇竖直步数（vertical step）
    //蛇尾从x,y到n-1,n-2的步数
    int i,j;

    stph[n-1][n-2]=0;//到了
    for(i=n-3;i>=0;i--){
        if(grid[n-1][i]){
            break;
        }
        stph[n-1][i]=stph[n-1][i+1]+1;
    }
    for(;i>=0;i--){
        stph[n-1][i]=MAX;
    }/*
    蛇尾到底端时只能水平，
    如果路上有障碍就不能到达目标。
    */

    for(i=n-1;i>=0;i--){
        stph[i][n-1]=MAX;
        stpv[i][n-1]=MAX;
        stpv[n-1][i]=MAX;
    }/*
    蛇尾到最右端时不能水平，
    蛇尾到最右端时，即使竖直也不能到达目标。
    蛇尾到底端时不能竖直。
    */

    for(i=n-2;i>=0;i--){
        for(j=n-2;j>=0;j--){
            if(grid[i][j]|(grid[i][j+1]&grid[i+1][j])){
                stph[i][j]=MAX;
                stpv[i][j]=MAX;
                continue;
            }//蛇没空间
            if(grid[i][j+1]){
                stph[i][j]=MAX;
                stpv[i][j]=stpv[i+1][j]+1;
                continue;
            }//只能竖直
            if(grid[i+1][j]){
                stpv[i][j]=MAX;
                stph[i][j]=stph[i][j+1]+1;
                continue;
            }//只能水平
            stph[i][j]=(stph[i+1][j]<stph[i][j+1])?stph[i+1][j]+1:stph[i][j+1]+1;
            stpv[i][j]=(stpv[i+1][j]<stpv[i][j+1])?stpv[i+1][j]+1:stpv[i][j+1]+1;
            //既能竖直也能水平
            if(!grid[i+1][j+1]){
                if(stpv[i][j]>stph[i][j]+1)stpv[i][j]=stph[i][j]+1;
                if(stph[i][j]>stpv[i][j]+1)stph[i][j]=stpv[i][j]+1;
            }//可以旋转
        }
    }

    if(stph[0][0]>=MAX)return -1;
    return stph[0][0];
}