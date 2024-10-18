class Solution {
public:
    int lengthOfLastWord(string s) {
        // Remove trailing spaces (manual trimming)
        int i = s.length() - 1;
        while (i >= 0 && s[i] == ' ') {
            i--;
        }

        int len = 0;
        // Now, count the length of the last word
        while (i >= 0 && s[i] != ' ') {
            len++;
            i--;
        }

        return len;
    }
};
