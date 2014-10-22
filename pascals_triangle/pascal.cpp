#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > ret;
        vector<int> v;
        for (int i=0; i<numRows; i++) {
            v = next(v);
            ret.push_back(v);
        }
        return ret;
    }
private:
    vector<int> next(const vector<int>& v) {
        vector<int> ret;
        if (v.size() == 0) {
            ret.push_back(1);
            return ret;
        }

        ret.push_back(v[0]);
        vector<int>::size_type i;
        for (i=0; i<v.size()-1; i++)
            ret.push_back(v[i]+v[i+1]);

        ret.push_back(v[i]);
        return ret;
    }
};

void print(const vector<vector<int> >& v)
{
    vector<vector<int> >::size_type i;
    vector<int>::size_type j;
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
    vector<vector<int> > v = s.generate(10);
    print(v);

    return 0;
}
