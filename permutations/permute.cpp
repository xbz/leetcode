#include <iostream>
#include <vector>
#include <algorithm>

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
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > ret;
        dfs(ret, num, 0);
        return ret;
    }

private:
    void dfs(vector<vector<int> > &ret, vector<int> path, size_t pos) {
        if (pos == path.size()-1) {
            ret.push_back(path);
            return;
        }

        for (size_t i=pos; i<path.size(); i++) {
            swap(path[pos], path[i]);
            dfs(ret, path, pos+1);
            swap(path[pos], path[i]);
        }
    }
};

class Solution_template {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > ret;
        vector<int> path;

        dfs(num, path, ret);
        return ret;
    }

private:
    void dfs(vector<int>& num, vector<int>& path, vector<vector<int> >& ret) {
        if (path.size() == num.size()) {
            ret.push_back(path);
            return;
        }

        for (size_t i=0; i<num.size(); ++i) {
            if (find(path.begin(), path.end(), num[i]) != path.end())
                continue;

            path.push_back(num[i]);
            dfs(num, path, ret);
            path.pop_back();
        }
    }
};

class Solution_Dfs {
public:
    void dfs(vector<vector<int> > &ret, vector<int> &num, vector<int> &path) {
        if (path.size() == num.size()) {
            ret.push_back(path);
            return;
        }

        for (size_t i=0; i<num.size(); i++) {
            // high algorithm complexity, guess O(n!)
            vector<int>::iterator it = find(path.begin(), path.end(), num[i]);
            cout << "call find" << endl;
            if (it != path.end())
                continue;

            path.push_back(num[i]);
            dfs(ret, num, path);
            path.pop_back();
        }
    }

    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > ret;
        vector<int> path;
        dfs(ret, num, path);
        return ret;
    }
};

class Solution_Dfs_fast {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > ret;
        vector<int> path;
        dfs(ret, num, path, num.size());
        return ret;
    }

private:
    void dfs(vector<vector<int> > &ret, vector<int> &num, vector<int> &path, size_t n) {
        if (path.size() == n) {
            ret.push_back(path);
            return;
        }

        for (size_t i=0; i<num.size(); i++) {
            swap(num[0], num[i]);
            vector<int> sub(num.begin()+1, num.end());
            path.push_back(num[0]);
            dfs(ret, sub, path, n);
            path.pop_back();
            swap(num[0], num[i]);
        }
    }
};

class Solution_Orig {
public:
    vector<vector<int> > permute(vector<int> &num) {
        if (num.size() == 1) {
            vector<vector<int> > v(1, num);
            return v;
        }

        vector<vector<int> > ret;
        for (size_t i=0; i<num.size(); i++) {
            swap(num[0], num[i]);
            vector<int> sub(num.begin()+1, num.end());
            vector<vector<int> > subret = permute(sub);
            for (size_t j=0; j<subret.size(); j++) {
                subret[j].push_back(num[0]);
                ret.push_back(subret[j]);
            }
        }
        return ret;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    vector<vector<int> > ret = s.permute(v);
    cout << "size:" << ret.size() << endl;
    vector<vector<int> >::iterator it;
    for (it=ret.begin(); it!=ret.end(); ++it)
        print(*it);

    return 0;
}

