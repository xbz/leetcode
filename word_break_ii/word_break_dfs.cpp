#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

void print(const vector<string>& v)
{
    vector<vector<string> >::size_type i;
    for (i=0; i<v.size(); i++)
        cout << v[i] << endl;
}

class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        vector<string> words;
        vector<string> ret;
        dfs(s, 0, dict, words, ret);
        return ret;
    }

private:
    void dfs(const string& s, size_t index, unordered_set<string>& dict, \
        vector<string>& words, vector<string>& ret) {
        if (index == s.size()) {
            ret.push_back(helper(words));
            return;
        }

        for (size_t i=index; i<s.size(); ++i) {
            string sub = s.substr(index, i-index+1);
            if (dict.find(sub) == dict.end())
                continue;

            words.push_back(sub);
            dfs(s, i+1, dict, words, ret);
            words.pop_back();
        }
    }

    string helper(const vector<string>& v) {
        string ret;
        for (size_t i=0; i<v.size(); ++i) {
            ret += v[i];
            if (i+1 < v.size())
                ret += " ";
        }
        return ret;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    // string str = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
    string str = "aaaaaaaaaaaaaaaaaaaaa";
    unordered_set<string> dict;

    dict.insert("a");
    dict.insert("aa");
    dict.insert("aaa");
    dict.insert("aaaa");
    dict.insert("aaaaa");
    dict.insert("aaaaaa");
    dict.insert("aaaaaaa");
    dict.insert("aaaaaaaa");
    dict.insert("aaaaaaaaa");
    dict.insert("aaaaaaaaaa");

    vector<string> ret = s.wordBreak(str, dict);
    print(ret);

    return 0;
}
