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
        int n = triangle.size();
        int f[n];
        for (int i=0; i<n; i++)
            f[i] = triangle[n-1][i];

        for (int i=n-2; i>=0; i--) {
            for (int j=0; j<triangle[i].size(); ++j)
                f[j] = min(f[j], f[j+1]) + triangle[i][j];
		}
        return f[0];
    }

    int minimumTotal_bottomup(vector<vector<int> > &triangle) {
        int n = triangle.size();
        int f[n][n];
        for (int i=0; i<n; i++)
            f[n-1][i] = triangle[n-1][i];

        for (int i=n-2; i>=0; i--) {
            for (int j=0; j<triangle[i].size(); ++j)
                f[i][j] = min(f[i+1][j], f[i+1][j+1]) + triangle[i][j];
		}
        return f[0][0];
    }

    int minimumTotal_topdown(vector<vector<int> > &triangle) {
		if (triangle.size() == 1)
			return triangle[0][0];

		size_t n = triangle.size();
		int f[n][n];
		f[0][0] = triangle[0][0];
		int min_total = INT_MAX;
		for (size_t i=1; i<n; ++i) {
			for (size_t j=0; j<triangle[i].size(); ++j) {
				if (j == 0)
					f[i][j] = f[i-1][j] + triangle[i][j];
				else if (j == i)
					f[i][j] = f[i-1][j-1] + triangle[i][j];
				else
					f[i][j] = min(f[i-1][j-1], f[i-1][j]) + triangle[i][j];
				if (i+1==n && f[i][j]<min_total)
					min_total = f[i][j];
			}
		}
		return min_total;
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
