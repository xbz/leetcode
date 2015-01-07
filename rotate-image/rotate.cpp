#include <vector>
#include <algorithm>
#include <iostream>
#include <iomanip>

using namespace std;

void print(const vector<vector<int> >& v)
{
    vector<vector<int> >::const_iterator it;
    for (it=v.begin(); it!=v.end(); ++it) {
        vector<int>::const_iterator it_j;
        for (it_j=it->begin(); it_j!=it->end(); ++it_j)
            cout << setw(2) << *it_j << " ";
        cout << endl;
    }
    cout << endl;
}

class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        vector<vector<int> > old_mat = matrix;
        matrix.clear();
        for (size_t col=0; col<old_mat.size(); ++col) {
            vector<int> nrow;
            for (size_t r=0; r<old_mat.size(); ++r) {
                size_t row = old_mat.size() - 1 - r;
                nrow.push_back(old_mat[row][col]);
            }
            matrix.push_back(nrow);
        }
    }
};

int main(int argc, char *argv[])
{
    int arr1[] = { 1, 2, 3 };
    vector<int> v1(arr1, arr1+sizeof(arr1)/sizeof(arr1[0]));
    int arr2[] = { 4, 5, 6 };
    vector<int> v2(arr2, arr2+sizeof(arr2)/sizeof(arr2[0]));
    int arr3[] = { 7, 8, 9 };
    vector<int> v3(arr3, arr3+sizeof(arr3)/sizeof(arr3[0]));
    vector<vector<int> > matrix;
    matrix.push_back(v1);
    matrix.push_back(v2);
    matrix.push_back(v3);
    // int arr1[] = { 1, 2, 3, 4 };
    // vector<int> v1(arr1, arr1+sizeof(arr1)/sizeof(arr1[0]));
    // int arr2[] = { 5, 6, 7, 8 };
    // vector<int> v2(arr2, arr2+sizeof(arr2)/sizeof(arr2[0]));
    // int arr3[] = { 9, 10, 11, 12 };
    // vector<int> v3(arr3, arr3+sizeof(arr3)/sizeof(arr3[0]));
    // int arr4[] = { 13, 14, 15, 16 };
    // vector<int> v4(arr4, arr4+sizeof(arr4)/sizeof(arr4[0]));
    // vector<vector<int> > matrix;
    // matrix.push_back(v1);
    // matrix.push_back(v2);
    // matrix.push_back(v3);
    // matrix.push_back(v4);

    Solution s;
    print(matrix);
    s.rotate(matrix);
    print(matrix);

    return 0;
}

