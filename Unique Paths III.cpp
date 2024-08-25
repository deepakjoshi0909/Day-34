class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int x, y , remain = 0;
        int m = grid.size();
        int n = grid[0].size();

        for(int i = 0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    x = i;
                    y = j;
                }
                if(grid[i][j] != -1){
                    remain++;
                }
            }
        }

        return dfs(grid,x,y,remain);
    }
    private:
        int dfs(vector<vector<int>>& grid,int x,int y,int remain){
            if(x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == -1){
                return 0;
            }

            if(grid[x][y] == 2){
                return remain == 1 ? 1 : 0;
            }

            int temp = grid[x][y];
            grid[x][y] = -1;
            remain--;

            int path = dfs(grid,x+1,y,remain) + dfs(grid,x-1,y,remain) + dfs(grid,x,y+1,remain) + dfs(grid,x,y-1,remain);

            grid[x][y] = temp;
            remain++;

            return path;
        }
};
