#include <vector>
#include <set>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

void print(const vector<int>& v)
{
    vector<int>::const_iterator it;
    for (it=v.begin(); it!=v.end(); ++it)
        cout << *it << " ";
    cout << endl;
}

class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        for (int line=0; line<9; ++line) {
            if (duplicate(board[line]))
                return false;
        }
        for (int col=0; col<9; ++col) {
            if (duplicate(get_column(board, col)))
                return false;
        }

        for (int i=0; i<9; i+=3) {
            for (int j=0; j<9; j+=3) {
                if (duplicate(get_square(board, i, j)))
                    return false;
            }
        }
        return true;
    }

private:
    bool duplicate(const vector<char>& v) {
        set<char> s;
        for (size_t i=0; i!=v.size(); ++i) {
            if (v[i] == '.')
                continue;

            if (s.find(v[i]) != s.end())
                return true;
            else
                s.insert(v[i]);
        }
        return false;
    }

    vector<char> get_column(const vector<vector<char> >& board,
                            int column_num) {
        vector<char> ret;
        for (size_t i=0; i!=board.size(); ++i)
            ret.push_back(board[i][column_num]);

        return ret;
    }

    vector<char> get_square(const vector<vector<char> >& board, int i, int j) {
        vector<char> ret;
        for (int line=i; line!=i+3; ++line) {
            for (int col=j; col!=j+3; ++col)
                ret.push_back(board[line][col]);
        }
        return ret;
    }
};

int main(int argc, char *argv[])
{
    char arr[] = { '3', '4', '2', '9', '1', '6', '5', '8', '7' };
    vector<char> v(arr, arr+sizeof(arr)/sizeof(arr[0]));
    vector<vector<char> > board;
    board.push_back(v);
    board.push_back(v);
    board.push_back(v);
    board.push_back(v);
    board.push_back(v);
    board.push_back(v);
    board.push_back(v);
    board.push_back(v);
    board.push_back(v);
    Solution s;
    bool b = s.isValidSudoku(board);
    cout << "valid:" << b << endl;

    return 0;
}

