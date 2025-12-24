class Solution {
public:
    string intToRoman(int num) {
        // Roman number set as characters
        map<int, char> Roman {
        {1, 'I'}, {5, 'V'}, 
        {10, 'X'}, {50, 'L'},
        {100, 'C'}, {500, 'D'},
        {1000, 'M'}
        };
        string result;  // output

        // Find maximum divider
        int mod = 1; 
        while(num / mod >= 10) {
            mod *= 10;
        }

        for( int divider=mod;divider>=1;divider/=10 ){
            mod = num / divider;   // calculate the module & asign as mod
            num = num % divider;   // calculate the remainder & asign as num

            // If the mod is 4 or 9 use the subtractive form
            if(mod==4 || mod==9) {
                result.push_back(Roman[divider]);
                result.push_back(Roman[divider*(mod+1)]);
            }
            // If the mod=>5 & !=9
            else if(mod>=5) {
                result.push_back(Roman[divider*5]);
                for(int j=0;j<mod-5;j++) {
                    result.push_back(Roman[divider]);
                }
            }
            // If the 4>mod>0
            else if(mod>0){
                for(int j=0;j<mod;j++) {
                    result.push_back(Roman[divider]);
                }
            }
        }
        return result; // return final output as a string
    }
};
