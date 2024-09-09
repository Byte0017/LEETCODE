class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        ListNode*temp=head;
        
        vector<vector<int>>ans(m,vector<int>(n,-1));
        int startRow=0;
        int endCol=n-1;
        int endRow=m-1;
        int startCol=0;

        while(temp){
            
          for(int i=startCol;i<=endCol;i++){
               if(temp){
                  ans[startRow][i]=temp->val;
                  temp=temp->next;
                }   
          }
          startRow++;
    
          for(int i=startRow;i<=endRow;i++){
              if(temp){
                ans[i][endCol]=temp->val;
                temp=temp->next;
              } 
           }
           endCol--;
      
           for(int i=endCol;i>=startCol;i--){
              if(temp){
                ans[endRow][i]=temp->val;
                temp=temp->next;
              }  
            }
            endRow--;
      
           for(int i=endRow;i>=startRow ;i--){
               if(temp){
                  ans[i][startCol]=temp->val;
                  temp=temp->next;
                }
            }
            startCol++;
        }
        return ans;
    }
};