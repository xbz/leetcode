#include <algorithm>
#include <iostream>
#include <vector>
#include <tr1/unordered_set>
#include <climits>

using namespace std;
using std::tr1::unordered_set;

void print(const vector<string>& v)
{
    vector<string>::const_iterator it;
    for (it=v.begin(); it!=v.end(); ++it)
        cout << *it << " ";
    cout << endl;
}

class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        vector<string> vdict;
        for (unordered_set<string>::iterator it=dict.begin(); it!=dict.end();
             ++it)
            vdict.push_back(*it);
        vdict.push_back(start);
        vdict.push_back(end);

        vector<string> path;
        int len = vdict.size();
        int min_len = 0;
        dfs(vdict, path, len, start, end, min_len);

        if (min_len == 0)
            return 0;
        return min_len + 2;
    }

private:
    void dfs(vector<string> &dict,
             vector<string> &path, size_t n,
             const string& s_start, const string& s_end, int &min_len) {
        if (path.size()>0 && path.back()==s_end) {
            if (path.size() < min_len)
                min_len = path.size();
            return;
        }

        for (size_t i=0; i!=dict.size(); ++i) {
            swap(dict[i], dict[0]);
            if (path.size()==0 && dict[0]!=s_start)
                continue;
            if (path.size()>0 && dist(path.back(), dict[0])!=1)
                continue;

            path.push_back(dict[0]);
            vector<string> part(dict.begin()+1, dict.end());
            dfs(part, path, n, s_start, s_end, min_len);
            path.pop_back();
            swap(dict[i], dict[0]);
        }
    }

    int dist(const string &s1, const string &s2) {
        int d = 0;
        for (size_t i=0; i<s1.size(); ++i) {
            if (s1[i] != s2[i])
                ++d;
        }
        return d;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    string start = "hit";
    string end = "hox";
    unordered_set<string> dict;
    dict.insert("hot");
    dict.insert("dot");
    dict.insert("dog");
    dict.insert("lot");
    dict.insert("log");
    int len = s.ladderLength(start, end, dict);
    cout << "len:" << len << endl;

    return 0;
}

