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
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > ret;
        vector<int> num;
        for (int i=1; i<=n; ++i)
            num.push_back(i);
        vector<int> path;
        dfs(ret, path, num, static_cast<size_t>(k));
        return ret;
    }

private:
    void dfs(vector<vector<int> > &ret, vector<int> &path, vector<int> &num, size_t k) {
        if (path.size() == k) {
            ret.push_back(path);
            return;
        }

        for (size_t i=0; i!=num.size(); ++i) {
            path.push_back(num[i]);
            vector<int> part(num.begin()+i+1, num.end());
            dfs(ret, path, part, k);
            path.pop_back();
        }
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    int n = 5;
    int k = 2;
    vector<vector<int> > ret = s.combine(n, k);
    cout << "size:" << ret.size() << endl;
    vector<vector<int> >::iterator it;
    for (it=ret.begin(); it!=ret.end(); ++it)
        print(*it);

    return 0;
}

