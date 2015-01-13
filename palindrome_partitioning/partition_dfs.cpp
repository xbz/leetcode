#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string> > ret;
        vector<string> path;
        dfs(s, 0, path, ret);
        return ret;
    }

private:
    void dfs(const string& s, int index, vector<string>& path, \
        vector<vector<string> >& ret) {
        int len = static_cast<int>(s.size());
        if (index == len) {
            ret.push_back(path);
            return;
        }

        for (int i=index; i<len; ++i) {
            string sub = s.substr(index, i-index+1);
            if (!is_palindrome(sub))
                continue;

            path.push_back(sub);
            dfs(s, i+1, path, ret);
            path.pop_back();
        }
    }

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
