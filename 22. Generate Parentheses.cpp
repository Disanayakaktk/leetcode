class Solution {
private:
    vector<string> output;     // final output
    int num;

    // Initialize function which create different ways of n pairs
    void createParenthesis(int start, int end, string parS) {
        if( parS.size() == 2*num ) {
            output.push_back(parS);
            return;
        }
        if( start<num ) {
            createParenthesis(start+1, end, parS+'(');
        } 
        if( start>end ) {
            createParenthesis(start, end+1, parS+')');
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        num = n;
        createParenthesis(0,0,"");      // call the function
        return output;
    }
};
