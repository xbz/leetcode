#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void print(const vector<int>& v)
{
    vector<int>::size_type i;
    for (i=0; i<v.size()-1; i++)
        cout << v[i] << ' ';
    cout << v[i] << endl;
}

void print(const vector<vector<int> >& v)
{
    vector<vector<int> >::size_type i;
    for (i=0; i<v.size(); i++) {
        vector<vector<int> >::size_type j;
        for (j=0; j<v[i].size(); j++)
            cout << v[i][j] << ' ';
        cout << endl;
    }
}

class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int sum = 0;
        typedef vector<vector<int> > VecVec;
        for (VecVec::const_iterator it=triangle.begin(); \
            it!=triangle.end(); ++it)
            sum += minv(*it);
        return sum;
    }
private:
    int minv(const vector<int>& v) {
        int min_value = INT_MAX;
        for (vector<int>::const_iterator it=v.begin(); it!=v.end(); ++it)
            min_value = min(min_value, *it);
        return min_value;
    }
};

int main(int argc, char *argv[])
{
    Solution s;

    vector<vector<int> > v;
    vector<int> v1;
    v1.push_back(2);
    vector<int> v2;
    v2.push_back(3);
    v2.push_back(4);
    vector<int> v3;
    v3.push_back(6);
    v3.push_back(5);
    v3.push_back(7);
    vector<int> v4;
    v4.push_back(4);
    v4.push_back(1);
    v4.push_back(8);
    v4.push_back(3);
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    v.push_back(v4);

    int min_value = s.minimumTotal(v);
    cout << "min value:" << min_value << endl;

    return 0;
}
