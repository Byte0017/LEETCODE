class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        if(m<3 || n<3) return 0;
        int count=0;

        for(int i=0;i<=m-3;i++){
            for(int j=0;j<=n-3;j++){
                if(isValid(grid,i,j)) count++;
            }
        }
        return count;
    }
    private:
    bool isValid(vector<vector<int>>& grid,int i,int j){
        //check diagonal sum
        if(grid[i][j]+grid[i+1][j+1]+grid[i+2][j+2]!=15) return false;
        if(grid[i][j+2]+grid[i+1][j+1]+grid[i+2][j]!=15) return false;
        
        //check row sum
        if(grid[i][j]+grid[i][j+1]+grid[i][j+2]!=15) return false;
        if(grid[i+1][j]+grid[i+1][j+1]+grid[i+1][j+2]!=15) return false;
        if(grid[i+2][j]+grid[i+2][j+1]+grid[i+2][j+2]!=15) return false;

        //check col sum
        if(grid[i][j]+grid[i+1][j]+grid[i+2][j]!=15) return false;
        if(grid[i][j+1]+grid[i+1][j+1]+grid[i+2][j+1]!=15) return false;
        if(grid[i][j+2]+grid[i+1][j+2]+grid[i+2][j+2]!=15) return false;

        //check distinct number
        int hash[16];
        for(int a=i;a<i+3;a++){
            for(int b=j;b<j+3;b++){
               hash[grid[a][b]]++;
            }
        }
        for(int i=1;i<10;i++){
            if(hash[i]!=1) return false;
        }
        return true;
    }
};