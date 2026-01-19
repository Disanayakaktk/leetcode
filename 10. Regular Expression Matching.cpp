class Solution {
private:
    vector<vector<int>> memo;
    
    bool match(string s, string p, int i, int j) {
        if(memo[i][j] != -1) {
            return memo[i][j];
        }

        if(i==s.size() && j==p.size()) {
            return memo[i][j] = 1;
        }
        if(j==p.size()) {
            return memo[i][j] = 0;
        }

        char current_char = p[j];
        bool has_star = (j+1<p.size() && p[j+1]=='*');

        if(has_star) {
            if(match(s, p, i, j+2)) {
                return memo[i][j] = 1;
            }
            int sIndex = i;
            while(sIndex<s.size() && (current_char=='.' || s[sIndex]==current_char)) {
                if(match(s, p, sIndex+1, j+2)) {
                    return memo[i][j] = 1;
                }
                sIndex++;
            }
            return memo[i][j] = 0;
        }
        else {
            if(i<s.size() && (current_char=='.' || s[i]==current_char)) {
                return memo[i][j] = match(s, p, i+1, j+1);
            }
            return memo[i][j] = 0;
        }
    }
public:
    bool isMatch(string s, string p) {
        memo = vector<vector<int>>(s.size()+1, vector<int>(p.size()+1, -1));
        return match(s, p, 0, 0);
    }
};
