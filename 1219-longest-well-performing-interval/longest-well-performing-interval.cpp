class Solution {
public:
    int longestWPI(vector<int>& hours) {
       
        // deqeue<int>dq;
        int maxi=0;

        // for(int i=0;i<hours.size();i++){
        //     if(hours[i]>8){
        //         dq.push_back(hours[i]);
        //         x++;
        //     } 
        //     else{
        //         dq.push_back(hours[i]);
        //         y++;
        //     }

        //     //update maximum
        //     if(x>y){
        //         maxi=max(maxi,dq.size());
        //     }
        // }
        // //elliminate extra y
        // while(x<y){
        //     if(x>y) return maxi;

        //     else{

        //     }
        // }


        for(int i=0;i<hours.size();i++){
            int x=0;//greater than 8
            int y=0;//less than 9
            for(int j=i;j<hours.size();j++){
                if(hours[j]>8) x++;
                else y++;
                if(x>y){
                    maxi=max(maxi,x+y);
                }
            }
        }
        return maxi;
    }
};