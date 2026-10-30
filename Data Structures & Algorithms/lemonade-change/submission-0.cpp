class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();

        int index = 0;
        int five = 0;
        int ten = 0;

        while(index < n){
            if(bills[index] == 5){
                five++;
            }

            else if(bills[index] == 10){
                if(five){
                    five--;
                    ten++;
                }
                else{
                    return false;
                }
            }

            else{
                if(five && ten){
                    ten--;
                    five--;
                }

                else if(five >= 3){
                    five = five -3;
                }

                else{
                    return false;
                }
            }
            index++;
        }

        return true;
    }
};