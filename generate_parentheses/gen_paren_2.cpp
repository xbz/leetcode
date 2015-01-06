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
        string s = string(n, '(') + string(n, ')');
        set<string> sret;
        gen_helper(sret, s, 0, 0);
        for (set<string>::iterator it=sret.begin(); it!=sret.end(); ++it)
            ret.push_back(*it);
        return ret;
    }

private:
    void gen_helper(set<string>& sret, string s, size_t pos, int left_count) {
        if (pos == s.size() - 1) {
            sret.insert(s);
            return;
        }

        bool swaped = false;
        for (size_t i=pos; i<s.size(); ++i) {
            if (swaped)
                break;
            if (i!=pos && s[i]==s[pos])
                continue;
            if (left_count==0 && s[i]==')')
                continue;

            if (s[i] == '(')
                left_count++;
            else if (s[i] == ')')
                left_count--;

            swap(s[i], s[pos]);
            if (i!=pos)
                swaped = true;
            gen_helper(sret, s, pos+1, left_count);
            swap(s[i], s[pos]);

            if (s[i] == '(')
                left_count--;
            else if (s[i] == ')')
                left_count++;
        }
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

