#include <iostream>
#include <vector>
#include <string>
#include <climits>

using namespace std;

class Solution {
public:
    int minCut(string s) {
        vector<string> path;
        int min_sol = INT_MAX;
        dfs(s, 0, path, min_sol);
        return min_sol;
    }

private:
    void dfs(const string& s, int index, vector<string>& path, int& min_sol) {
        int len = static_cast<int>(s.size());
        if (index == len) {
            int path_len = static_cast<int>(path.size());
            min_sol = min(path_len, min_sol);
            return;
        }

        for (int i=index; i<len; ++i) {
            string sub = s.substr(index, i-index+1);
            if (!is_palindrome(sub))
                continue;

            path.push_back(sub);
            dfs(s, i+1, path, min_sol);
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
    int min_cut_times = s.minCut(str);
    cout << "min_cut:" << min_cut_times << endl;

    return 0;
}
