class Solution {
public:
    string convert(string s, int numRows) {
        int length = s.size();
        if(numRows==1 || length<=numRows){return s;}
        string zigzag;
        for(int i=0;i<numRows;i++){
            int x = (2*numRows)-2;
            int b = 2*i;
            int a = x-b;
            int j = i;
            zigzag.push_back(s[j]);
            if(b==0){
                while(true){
                    j = j+a;
                    if(j<length){
                        zigzag.push_back(s[j]);
                    }else{break;}
                }
            }
            else if(a==0){
                while(true){
                    j = j+b;
                    if(j<length){
                        zigzag.push_back(s[j]);
                    }else{break;}
                }
            }
            else{
                while(true){
                    j = j+a;
                    if(j<length){
                        zigzag.push_back(s[j]);
                    }else{break;}

                    j = j+b;
                    if(j<length){
                        zigzag.push_back(s[j]);
                    }else{break;}
                }
            }   
        }
        return zigzag;
    }
};
