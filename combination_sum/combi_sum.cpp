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
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int> > ret;
        vector<int> path;
        dfs(ret, candidates, path, target);
        return ret;
    }

private:
    void dfs(vector<vector<int> > &ret, vector<int> &v, vector<int> &path,
             int target) {
        if (target == 0) {
            if (path.size()>0)
                ret.push_back(path);
            return;
        }

        for (size_t i=0; i!=v.size(); ++i) {
            if (v[i] > target)
                continue;

            path.push_back(v[i]);
            vector<int> part(v.begin()+i, v.end());
            dfs(ret, part, path, target-v[i]);
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
    v.push_back(6);
    v.push_back(3);
    //v.push_back(5);

    int target = 5;
    vector<vector<int> > ret = s.combinationSum(v, target);
    cout << "size:" << ret.size() << endl;
    vector<vector<int> >::iterator it;
    for (it=ret.begin(); it!=ret.end(); ++it)
        print(*it);

    return 0;
}

