#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > ret;
        for (int i=0; i<numRows; i++) {
            vector<int> v;
            for (int j=0; j<i+1; j++) {
                if (j==0 || j==i)
                    v.push_back(1);
                else {
                    int sum = ret[i-1][j-1] + ret[i-1][j];
                    v.push_back(sum);
                }
            }
            ret.push_back(v);
        }
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
