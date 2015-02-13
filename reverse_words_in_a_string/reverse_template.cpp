#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
        vector<string> v;
        istringstream iss(s);
        string word;
        while (iss >> word)
            v.push_back(word);

        s = join(v.rbegin(), v.rend(), " ");
    }

private:
    template<typename Iter>
    string join(Iter start, Iter end, const string& delim) {
        string ret;
        if (start != end)
            ret += *start++;

        while (start != end)
            ret += delim + *start++;
        return ret;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    string str = "     hi!               my test here.    ";
    cout << str << endl;
    s.reverseWords(str);
    cout << str << endl;

    return 0;
}
