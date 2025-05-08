class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

        int id=digits.size()-1;

        while(id>=0){
            if(digits[id]==9){
                digits[id]=0;
                id--;
            }else{
                digits[id]+=1;
                return digits;
            }
        }

        digits.insert(digits.begin(),1);

        return digits;
        
    }
};