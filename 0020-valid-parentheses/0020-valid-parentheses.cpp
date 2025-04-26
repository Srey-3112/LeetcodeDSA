class Solution {
public:
    int typeOfBracket(char bracket) {
        if (bracket == '(' || bracket == ')') // first type of bracket 
            return 1;
        else if (bracket == '{' || bracket == '}')// second type of bracket 
            return 2;
        else
            return 3; // third type of bracket 

        return -1;
    }

    bool isValid(string s) {
        string openBrackets = "";

        for (int i = 0; i < s.size(); i++) {
            // if we found open bracket store them in openBrackets
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                openBrackets += s[i];
            } else {
                // if we found a close bracket , we will check if the type of
                // this bracket and last open bracket is same

                if (openBrackets.size() == 0)
                    return false; // edge case if we found close bracket when do
                                  // don't have any open bracket return false
                if (typeOfBracket(s[i]) !=
                    typeOfBracket(openBrackets.at(openBrackets.size() - 1)))
                    return false;
                else
                    openBrackets.pop_back();
            }
        }

        // if we still have any brackets open return false
        if (openBrackets.size() != 0)
            return false;

        return true;
    }
};