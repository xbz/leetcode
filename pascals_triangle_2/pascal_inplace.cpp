#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> getRow(int rowIndex) {
        vector<int> v(rowIndex+1);
        for (int i=0; i<rowIndex+1; ++i) {
            v[0] = 1;
            v[i] = 1;
            for (int j=i-1; j>0; j--)
                v[j] += v[j-1];
        }
        return v;
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
    int rowNum = atoi(argv[1]);
    Solution s;
    vector<int> v = s.getRow(rowNum);
    print_v(v);

    return 0;
}
