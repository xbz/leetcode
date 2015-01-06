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
            // if (valid(s))
            //     sret.insert(s);
            sret.insert(s);
            return;
        }

        for (size_t i=pos; i<s.size(); ++i) {
            if (i!=pos && s[i]==s[pos])
                continue;

            if (left_count==0 && s[i]==')')
                continue;

            if (s[pos] == '(')
                left_count++;
            else if (s[pos] == ')')
                left_count--;

            swap(s[i], s[pos]);
            gen_helper(sret, s, pos+1, left_count);
            swap(s[i], s[pos]);

            if (s[pos] == '(')
                left_count--;
            else if (s[pos] == ')')
                left_count++;
        }
    }
    bool valid(const string& s) {
        int left_count = 0;
        for (size_t i=0; i<s.size(); ++i) {
            if (s[i]==')' && left_count==0)
                return false;

            if (s[i] == '(')
                ++left_count;
            if (s[i] == ')')
                --left_count;
        }
        return true;
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

