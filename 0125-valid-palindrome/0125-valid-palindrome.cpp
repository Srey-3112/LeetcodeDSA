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
        int left=0;
        int right=s.size()-1;

        while(left<right){
            while(left<right && !valid(s[left])) left++;
            while(left<right && !valid(s[right])) right --;

            if(toLowerCase(s[left]) != toLowerCase(s[right])){
                return false;
            }

            left++;
            right--;
        } 
        return true;
















        
    }
};