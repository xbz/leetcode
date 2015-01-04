#include <iostream>
#include <stack>

using namespace std;

enum {
    OPEN,
    CLOSE,
    INVALID,
};

class Solution {
public:
    bool isValid(string s) {
        stack<char> paren_s;
        for (size_t i=0; i!=s.size(); ++i) {
            if (get_type(s[i]) == OPEN)
                paren_s.push(s[i]);
            else if (get_type(s[i]) == CLOSE) {
                if (paren_s.empty())
                    return false;
                char cur = paren_s.top();
                paren_s.pop();
                if (!is_pair(cur, s[i]))
                    return false;
            }
        }
        return paren_s.empty();
    }

private:
    int get_type(char ch) {
        if (ch == '(' || ch == '[' || ch == '{')
            return OPEN;
        if (ch == ')' || ch == ']' || ch == '}')
            return CLOSE;
        return INVALID;
    }

    int is_pair(char open, char close) {
        if (close == ']')
            return open == '[';
        if (close == '}')
            return open == '{';
        if (close == ')')
            return open == '(';
        return false;
    }
};

int main(int argc, char* argv[]) {
    Solution s;
    string str = "(()[]{}";
    bool bValid = s.isValid(str);
    cout << "isValid:" << bValid << endl;

    return 0;
}
