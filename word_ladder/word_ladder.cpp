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
        vector<string> dict_start;
        for (unordered_set<string>::iterator it=dict.begin(); it!=dict.end();
            ++it) {
            if (dist(*it, start) == 1)
                dict_start.push_back(*it);
        }
        // print(dict_start);

        vector<string> dict_end;
        for (unordered_set<string>::iterator it=dict.begin(); it!=dict.end();
            ++it) {
            if (dist(*it, end) == 1)
				dict_end.push_back(*it);
        }
        // print(dict_end);

        vector<string> vdict;
        for (unordered_set<string>::iterator it=dict.begin(); it!=dict.end();
             ++it)
            vdict.push_back(*it);
        // print(vdict);

        size_t min_len = UINT_MAX;
        // cout << min_len << endl;
        for (size_t i=0; i!=dict_start.size(); ++i) {
            for (size_t j=0; j!=dict_end.size(); ++j) {
                // cout << dict_start[i] << " " << dict_end[j] << endl;

                vector<vector<string> > ret;
                vector<string> path;
                int len = vdict.size();
                dfs(ret, vdict, path, len, dict_start[i], dict_end[j]);

                // cout << "ret:" << endl;
                vector<vector<string> >::iterator it;
                for (it=ret.begin(); it!=ret.end(); ++it) {
                    // print(*it);
                    if (it->size()>0 && it->size()<min_len)
                        min_len = it->size();
                }
            }
        }

        if (min_len == UINT_MAX)
            return 0;
        return min_len + 2;
    }

private:
    void dfs(vector<vector<string> > &ret, vector<string> &dict,
             vector<string> &path, size_t n,
             const string& s_start, const string& s_end) {
        if (path.size()>0 && path.back()==s_end) {
            ret.push_back(path);
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
            dfs(ret, part, path, n, s_start, s_end);
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
    string end = "cog";
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

