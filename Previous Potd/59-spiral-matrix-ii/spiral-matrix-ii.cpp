class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {

      vector<vector<int>>ans(n,vector<int>(n,0));
      int colStart=0,colEnd=n-1;
      int rowStart=0,rowEnd=n-1;
      int count=0;
      while(count<n*n){
       //1.Right to move
        for(int i=colStart;i<=colEnd;i++){
            ans[rowStart][i]=count+1;
            count++;
        }
        rowStart++;
        //2.Down to move
        for(int i=rowStart;i<=rowEnd;i++){
            ans[i][colEnd]=count+1;
            count++;
        }
        colEnd--;
        //3.Left to move
        for(int i=colEnd;i>=colStart;i--){
            ans[rowEnd][i]=count+1;
            count++;
        }
        rowEnd--;
        //4.Upside to move
        for(int i=rowEnd;i>=rowStart;i--){
            ans[i][colStart]=count+1;
            count++;
        }
        colStart++;
      }   
      return ans;
    }
};