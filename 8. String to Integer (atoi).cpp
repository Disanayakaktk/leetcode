class Solution {
public:
    int myAtoi(string s) {
        unordered_map<char,int> digitMap = {
            {'0',0},{'1',1},{'2',2},{'3',3},{'4',4},
            {'5',5},{'6',6},{'7',7},{'8',8},{'9',9}
        };
        vector<int> arr;
        bool sign = false;
        bool x = true;
        bool space = true;
        int n = s.size();

        for(int i=0;i<n;i++){
            if(s[i] ==' ' && space){
                continue;
            }
            else if(s[0]==' ' && s[i]==' ' && (!space) && (arr.empty())){
                return 0;
            }
            else if((s[i]==' ' || s[i]=='+' || s[i]=='-') && (!arr.empty())){
                break;
            }
            else if(s[i]=='0' && x){
                space = false;
                continue;
            }
            else if(s[i]=='-'){
                space = false;
                if(i>0 && (s[i-1]=='0' || s[i-1]=='+' || s[i-1]=='-')){
                    return 0;
                }
                else{sign = true;}
            }
            else if(s[i]=='+'){
                space = false;
                if(i>0 && (s[i-1]=='0' || s[i-1]=='+' || s[i-1]=='-')){
                    return 0;
                }
                else{continue;}
            }
            else if(s[i]=='0' || s[i]=='1' || s[i]=='2' || s[i]=='3' || s[i]=='4' || s[i]=='5' || s[i]=='6' || s[i]=='7' || s[i]=='8' || s[i]=='9'){
                space = false;
                x = false;
                arr.push_back(digitMap[s[i]]);
            }
            else {break;}
        } 
        int ans = 0;
        int numLength = arr.size();
        if(sign){
            for(int j=0;j<numLength;j++){
                if( ans>INT_MAX/10 || (ans==INT_MAX/10 && arr[j]>7) ){
                    return INT_MIN;
                }
                ans = ans*10 + arr[j];
            }
            return -ans;
        }
        else{
            for(int j=0;j<numLength;j++){
                if(ans>INT_MAX/10 || (ans==INT_MAX/10 && arr[j]>6)){
                    return INT_MAX;
                }
                ans = ans*10 + arr[j];
            }
            return ans;
        }
    };
};
