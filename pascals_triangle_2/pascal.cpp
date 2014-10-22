#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> getRow(int rowIndex) {
        vector<int> v;
        for (int i=0; i<=rowIndex; i++)
            v = next(v);
        return v;
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

void print_v(const vector<int>& v)
{
    vector<vector<int> >::size_type i;
    for (i=0; i<v.size()-1; i++)
        cout << v[i] << ' ';

    cout << v[i] << endl;
}

// sumbit times for the first accept: 1
int main(int argc, char *argv[])
{
    Solution s;
    vector<int> v = s.getRow(5);
    print_v(v);

    return 0;
}
