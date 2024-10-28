class Solution {
public:
    bool lemonadeChange(vector<int>& b) {
        int count5=0,count10=0;
        for(int i=0;i<b.size();i++){
            if(b[i]==5) count5++;
            else if(b[i]==10){
                if(count5>0){
                    count10++;
                    count5--;
                }
                else return false;
            }
            else if(b[i]==20){
                //15 return
                if(count10>0 && count5>0){
                    count5--;
                    count10--;
                }
                else if(count10==0 && count5>2){
                    count5=count5-3;
                }
                else return false;
            }
        }
        return true;
    }
};