#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void print(const vector<int>& v)
{
    vector<int>::const_iterator it;
    for (it=v.begin(); it!=v.end(); ++it)
        cout << *it;
    cout << endl;
}

class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<vector<int> > ret;
        vector<int> path;

        sort(S.begin(), S.end());
        dfs(S, path, ret, 0);

        return ret;
    }

private:
    void dfs(vector<int>& S, vector<int>& path, vector<vector<int> >& ret, size_t pos) {
        ret.push_back(path);

        for (size_t i=pos; i<S.size(); ++i) {
            if (i>pos && S[i]==S[i-1])
                continue;

            path.push_back(S[i]);
            dfs(S, path, ret, i+1);
            path.pop_back();
        }
    }
};

class Solution_Orig {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        sort(S.begin(), S.end());
        vector<vector<int> > ret;
        for (size_t i=0; i<=S.size(); ++i) {
            vector<int> path;
            dfs(ret, S, path, i);
        }
        return ret;
    }

private:
    void dfs(vector<vector<int> > &ret, vector<int> &num, vector<int> &path, size_t n) {
        if (path.size() == n) {
            ret.push_back(path);
            return;
        }

        for (size_t i=0; i<num.size(); i++) {
            if (i > 0 && num[i]==num[i-1])
                continue;

            path.push_back(num[i]);
            vector<int> sub(num.begin()+i+1, num.end());
            dfs(ret, sub, path, n);
            path.pop_back();
        }
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    // v.push_back(4);
    v.push_back(2);
    //v.push_back(5);
    vector<vector<int> > ret = s.subsetsWithDup(v);
    cout << "size:" << ret.size() << endl;
    vector<vector<int> >::iterator it;
    for (it=ret.begin(); it!=ret.end(); ++it)
        print(*it);

    return 0;
}

