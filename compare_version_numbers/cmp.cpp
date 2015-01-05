#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> v1 = split(version1);
        vector<int> v2 = split(version2);
        size_t i = 0;
        while (i<v1.size() && i<v2.size()) {
            if (v1[i] > v2[i])
                return 1;
            else if (v1[i] < v2[i])
                return -1;

            i++;
        }
        if (i < v1.size())
            return 1;
        if (i < v2.size())
            return -1;
        return 0;
    }

private:
    vector<int> split(const string& v) {
        vector<int> ret;
		string::const_iterator it = v.begin();
        while (it != v.end()) {
            string::const_iterator it_right = find(it, v.end(), '.');
            string s(it, it_right);
            istringstream iss(s);
            int n;
            iss >> n;
            ret.push_back(n);
            if (it_right == v.end())
                it = it_right;
            else
                it = it_right + 1;
        }
        for (size_t i=ret.size()-1; i>0; i--) {
            if (ret[i] == 0)
                ret.pop_back();
            else
                break;
        }

        return ret;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    string v1 = "11.0.4.10";
    string v2 = "11.0.4.2";
    int cmp = s.compareVersion(v1, v2);
    cout << "cmp:" << cmp << endl;

    return 0;
}
