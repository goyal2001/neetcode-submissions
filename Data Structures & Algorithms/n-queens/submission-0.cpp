class Solution {
public:
    bool check(int i, int j, int n,vector<string>& grid)
    {
        //Col
        for(int y=0;y<n;y++)
        {
            if(grid[i][y]=='Q')
                return false;
        }
        
        //Row
        for(int x=0;x<n;x++)
        {
            if(grid[x][j]=='Q')
                return false;
        }
        
        //Diagonals
        
        int x = i, y = j;
        while(x >= 0 && y >= 0) {
            if(grid[x--][y--] == 'Q') return false;
        }
       
        x = i-1, y = j+1;
        while(x >= 0 && y < n) {
            if(grid[x--][y++] == 'Q') return false;
        }
        
        return true;
        
    }
    
    
    
    
    void solve(int i, int j, int n,vector<string>& grid, int q,vector<vector<string>>& ans)
    {
        if(q==0){
            ans.push_back(grid);
            return;}
        
        if(i==n || j==n) return;
        
       
        if(check(i,j,n,grid))
        {
            grid[i][j]='Q'; 
            solve(i+1,0,n,grid,q-1,ans); 
            grid[i][j]='.'; 
        }
        
        solve(i,j+1,n,grid,q,ans);
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> grid(n,string(n,'.'));
        
        int q=n; //total queens
        
        solve(0,0,n,grid,q,ans); //(i,j,size,grid,queens)
        
        return ans;
        
    }
};
