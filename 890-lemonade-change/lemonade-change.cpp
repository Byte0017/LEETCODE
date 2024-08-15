class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int cnt5=0;
        int cnt10=0;
        for(int i=0;i<bills.size();i++){
            if(bills[i]==5) cnt5++;
            else if(bills[i]==10){
                if(cnt5>0){
                    cnt10++;
                    cnt5--;
                }
                else return false;
            }
            else if(bills[i]==20){
                //15 dena hai (10,5) or (5,5,5)
                if(cnt10>0 && cnt5>0){
                    cnt10--,cnt5--;
                }
                else if(cnt10==0 && cnt5>2) cnt5=cnt5-3;
                else return false;
            }
        }
        return true;
    }
};