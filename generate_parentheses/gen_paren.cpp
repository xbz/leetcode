#include <iostream>
#include <vector>
#include <set>

using namespace std;

void print(const vector<string>& v)
{
    vector<string>::const_iterator it;
    for (it=v.begin(); it!=v.end(); ++it)
        cout << *it << endl;
}

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        string s = "";
        helper(ret, s, n, n);
        return ret;
    }

private:
    void helper(vector<string>& ret, string s, int left, int right) {
        if (left > right)
            return;

        if (left==0 && right==0) {
            ret.push_back(s);
            return;
        }

        if (left > 0)
            helper(ret, s+'(', left-1, right);
        if (right > 0)
            helper(ret, s+')', left, right-1);
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    int n = 8;
    if (argc == 2)
        n = atoi(argv[1]);
    vector<string> ret = s.generateParenthesis(n);
    cout << "size:" << ret.size() << endl;
    print(ret);

    return 0;
}

