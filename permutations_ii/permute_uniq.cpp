#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

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
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int> > ret;
        permute_helper(ret, num, 0);
        return ret;
    }

private:
    void permute_helper(vector<vector<int> > &ret, vector<int> num, size_t pos) {
        if (pos == num.size()-1) {
            ret.push_back(num);
            return;
        }

        set<int> used;
        for (size_t i=pos; i<num.size(); i++) {
            if (used.find(num[i]) != used.end())
                continue;
            used.insert(num[i]);

            swap(num[pos], num[i]);
            permute_helper(ret, num, pos+1);
            swap(num[pos], num[i]);
        }
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    vector<int> v;
    v.push_back(3);
    v.push_back(3);
    v.push_back(0);
    v.push_back(3);

    // v.push_back(1);
    // v.push_back(1);
    // v.push_back(3);
    // v.push_back(2);
    // v.push_back(4);
    // v.push_back(5);
    vector<vector<int> > ret = s.permuteUnique(v);
    cout << "size:" << ret.size() << endl;
    vector<vector<int> >::iterator it;
    for (it=ret.begin(); it!=ret.end(); ++it)
        print(*it);

    return 0;
}

