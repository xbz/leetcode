#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string> > ret;
        for (size_t i=0; i<s.size(); ++i) {
            string s1 = s.substr(0, i+1);
            if (!is_palindrome(s1))
                continue;

            string s2 = s.substr(i+1);
            if (s2.size() == 0) {
                vector<string> tmp(1, s1);
                ret.push_back(tmp);
                continue;
            }

            vector<vector<string> > sol = partition(s2);
            if (sol.size()==0)
                continue;

            for (size_t j=0; j<sol.size(); ++j) {
                vector<string> tmp;
                tmp.push_back(s1);
                for (size_t k=0; k<sol[j].size(); ++k)
                    tmp.push_back(sol[j][k]);
                ret.push_back(tmp);
            }
        }
        return ret;
    }

private:
    bool is_palindrome(const string& s) {
        for (size_t i=0,j=s.size()-1; i<j; ++i,--j) {
            if (s[i] != s[j])
                return false;
        }
        return true;
    }
};

void print(const vector<vector<string> >& v)
{
    vector<vector<string> >::size_type i;
    vector<string>::size_type j;
    for (i=0; i<v.size(); i++) {
        for (j=0; j<v[i].size()-1; j++)
            cout << v[i][j] << ' ';
        cout << v[i][j] << endl;
    }
}

// sumbit times(for the first accept): 3
int main(int argc, char *argv[])
{
    Solution s;
    string str = "aabcbaadd";
    if (argc > 1)
        str = argv[1];
    vector<vector<string> > v = s.partition(str);
    print(v);

    return 0;
}
