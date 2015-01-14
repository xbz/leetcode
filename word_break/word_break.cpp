#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        bool f[s.size()+1];
        f[0] = true;

        for (size_t i=1; i<=s.size(); ++i) {
            f[i] = false;
            for (size_t j=0; j<i; ++j) {
                string sub = s.substr(j, i-j);
                if (f[j] && dict.find(sub)!=dict.end() && !f[i])
                    f[i] = true;
            }
        }
        return f[s.size()];
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    string str = "lintcodecodelintsummer";
    unordered_set<string> dict;
    dict.insert("lint");
    dict.insert("code");
    dict.insert("sum");
    dict.insert("summer");

    bool bSeg = s.wordBreak(str, dict);
    cout << "can word segment:" << bSeg << endl;

    return 0;
}
