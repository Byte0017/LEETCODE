class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int maxi=0;
        int x=0,y=0;
        bool N=1,S=0,E=0,W=0;
    
        set<pair<int,int>>st;
        for(int i=0;i<obstacles.size();i++){
            pair p=make_pair(obstacles[i][0],obstacles[i][1]);
            st.insert(p);
        }
        for(int i=0;i<commands.size();i++){
            if(commands[i]==-1){
                //take right
                if(N) E=1,N=0;
                else if(S) W=1,S=0;
                else if(E) S=1,E=0;
                else if(W) N=1,W=0;
            }
            else if(commands[i]==-2){
                //take left
                if(N) W=1,N=0;
                else if(S) E=1,S=0;
                else if(E) N=1,E=0;
                else if(W) S=1,W=0;
            }
            else if(N){
               for(int j=1;j<=commands[i];j++){
                  pair p=make_pair(x,y+1);
                  if(st.find(p)!=st.end()) break;
                  else y++;
               }
            }
            else if(S){
                for(int j=1;j<=commands[i];j++){
                  pair p=make_pair(x,y-1);
                  if(st.find(p)!=st.end()) break;
                  else y--;
               }
            }
            else if(E){
                for(int j=1;j<=commands[i];j++){
                  pair p=make_pair(x+1,y);
                  if(st.find(p)!=st.end()) break;
                  else x++;
               }
            }
            else if(W){
                for(int j=1;j<=commands[i];j++){
                  pair p=make_pair(x-1,y);
                  if(st.find(p)!=st.end()) break;
                  else x--;
               }
            }
            maxi=max(maxi,x*x+y*y);
        }
        return maxi;
    }
};