class Solution {

private:
    bool valid(char c){
        if((c>='a' && c<='z')||(c>='A' && c<='Z')||(c>='0' && c<='9')){
            return true;
        }
        return false;
    }

    char toLowerCase(char c){
        if((c>='a' && c<='z')||(c>='0' && c<='9')){
            return c;
        }
        else{
            char temp= c+'a'-'A';
            return temp;
        }
    }
public:
    bool isPalindrome(string s) {
        string temp="";
        for(int j=0;j<s.size();j++){
            if(valid(s[j])){
                temp.push_back(s[j]);
            }
        }
        for(int j=0;j<temp.size();j++){
            temp[j]= toLowerCase(temp[j]);
        }
        
        int left=0;
        int right=temp.size()-1;

        while(left<=right){
            if(temp[left]!=temp[right]){
                return false;
            }
            else{
                left++;
                right--;
            }
        } 
        return true;
















        
    }
};