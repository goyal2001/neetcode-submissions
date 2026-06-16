class Solution {
public:
    
    int solve(int i,int j,int r, int c,vector<vector<int>>& grid){
        if(i<0 || j<0 || i>=r || j>=c) return 1;
        if(grid[i][j]==0) return 1;

        if (grid[i][j]==-1)
            return 0;

        grid[i][j] = -1;
        int peri = 0;
        int dirx[] = {0,0,1,-1};
    int diry[] = {1,-1,0,0};
        for(int k=0;k<4;k++){
           peri += solve(i+dirx[k],j+diry[k],r,c,grid);
        }
        return peri;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans = 0;
        int r = grid.size();
        int c = grid[0].size();
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
               if(grid[i][j]==1){
                return solve(i,j,r,c,grid);
               }
            }
        }
        return ans;
    }
};