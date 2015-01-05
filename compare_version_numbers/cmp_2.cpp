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
        rm_tail0(v1);
        rm_tail0(v2);

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
    int str2int(const string& s) {
        istringstream iss(s);
        int n;
        iss >> n;
        return n;
    }

    vector<int> split(const string& s_version) {
        istringstream iss_version(s_version);
        string token;
        vector<int> ret;
        while (getline(iss_version, token, '.'))
            ret.push_back(str2int(token));

        return ret;
    }

    void rm_tail0(vector<int>& v) {
        for (size_t i=v.size()-1; i>0; i--) {
            if (v[i] == 0)
                v.pop_back();
            else
                break;
        }
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
