#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
public:
    void reverseWords2(string &s) {
        vector<string> v;
        istringstream iss(s);
        string word;
        while (iss >> word)
            v.push_back(word);

        string ret;
        vector<string>::reverse_iterator rit = v.rbegin();
        while (rit!=v.rend()) {
        	ret += *rit++;
        	if (rit != v.rend())
        		ret += ' ';
        }
        s = ret;
    }

    void reverseWords(string &s) {
        istringstream iss(s);
        string word;
        string ret;
        if (iss >> word)
            ret = word;
        while (iss >> word)
            ret = word + " " + ret;
        s = ret;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    string str = "     hi!               my test here.    ";
    cout << str << endl;
    s.reverseWords(str);
    // s.reverseWords2(str);
    cout << str << "$" << endl;

    return 0;
}
