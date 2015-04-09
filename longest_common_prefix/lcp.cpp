#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.size() == 0)
            return "";

        string ret = strs[0];
        for (size_t i=1; i<strs.size(); ++i)
            ret = lcp(ret, strs[i]);
        return ret;
    }

private:
    string lcp(const string& s, const string& t) {
        size_t pos = 0;
        while (pos<s.size() && pos<t.size() && s[pos]==t[pos])
            ++pos;
        return s.substr(0, pos);
    }
};

class Solution_Simpler {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.size() == 0)
            return "";

        string ret = strs[0];
        for (size_t i=1; i<strs.size(); ++i) {
            while (strs[i].find(ret) != 0)
                ret = ret.substr(0, ret.size()-1);
        }
        return ret;
	}
};

int main(int argc, char *argv[])
{
    Solution s;
    string s1 = "he_llo world";
    string s2 = "he_world";
	vector<string> vs;
	vs.push_back(s1);
	vs.push_back(s2);

    string lcp = s.longestCommonPrefix(vs);
    cout << "lcp str:" << lcp << endl;

    return 0;
}

