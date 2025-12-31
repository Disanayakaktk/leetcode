class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> letterCombinations;
        map<char, string> buttons = {
            {'2', "abc"},{'3', "def"},
            {'4', "ghi"},{'5', "jkl"},
            {'6', "mno"},{'7', "pqrs"},
            {'8', "tuv"},{'9', "wxyz"}
        };
        
        int n = digits.size();

        if(n==1) {
            for(char d1 : buttons[digits[0]]){
                letterCombinations.push_back(string(1,d1));
            }
        }else if(n==2) {
            for(char d1 : buttons[digits[0]]){
                for(char d2 : buttons[digits[1]]){
                    string combination ="";
                    combination += d1;
                    combination += d2;
                    letterCombinations.push_back(combination);
                }
            }
        }else if(n==3) {
            for(char d1 : buttons[digits[0]]){
                for(char d2 : buttons[digits[1]]){
                    for(char d3 : buttons[digits[2]]){
                    string combination ="";
                    combination += d1;
                    combination += d2;
                    combination += d3;
                    letterCombinations.push_back(combination);
                    }
                }
            }
        }else if(n==4) {
            for(char d1 : buttons[digits[0]]){
                for(char d2 : buttons[digits[1]]){
                    for(char d3 : buttons[digits[2]]){
                        for(char d4 : buttons[digits[3]]){
                            string combination ="";
                            combination += d1;
                            combination += d2;
                            combination += d3;
                            combination += d4;
                            letterCombinations.push_back(combination);
                        }
                    }
                }
            }
        }  
        return letterCombinations;
    }
};
