class Solution {
public:
    string countAndSay(int n) {
        string s = "1";

        for(int i=1; i<n; i++) {
            int count = 0;
            char temp = s[0];
            string p;
            for(int j=0; j<s.size(); j++) {
                if(temp==s[j]) { count++; }
                else {
                    p.push_back(count+'0');
                    p.push_back(temp);
                    temp = s[j];
                    count = 1;
                }
            }
            p.push_back(count+'0');
            p.push_back(temp);
            s = p;
        }
        return s;
    }
};
