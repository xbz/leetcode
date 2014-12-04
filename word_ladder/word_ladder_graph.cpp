#include <algorithm>
#include <iostream>
#include <vector>
#include <tr1/unordered_set>
#include <climits>
#include <map>
#include <fstream>

using namespace std;
using std::tr1::unordered_set;

void print(const vector<string>& v)
{
    vector<string>::const_iterator it;
    for (it=v.begin(); it!=v.end(); ++it)
        cout << *it << " ";
    cout << endl;
}

void print(const vector<int>& v)
{
    vector<int>::const_iterator it;
    for (it=v.begin(); it!=v.end(); ++it)
        cout << *it << " ";
    cout << endl;
}

void print(const map<string, vector<string> > &G) {
    map<string, vector<string> >::const_iterator it;
    for (it=G.begin(); it!=G.end(); ++it) {
        cout << it->first << ": ";
        print(it->second);
    }
}

struct Edge {
    Edge(int f, int t) : from(f), to(t) {
    }
    int from;
    int to;
};

typedef unordered_set<string>::iterator USETIT;
class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        map<int, string> m;
        int num = 0;
        vector<string> vdict;
        vdict.push_back(start);
        for (USETIT it=dict.begin(); it!=dict.end(); ++it)
            vdict.push_back(*it);
        vdict.push_back(end);

        for (size_t i=0; i!=vdict.size(); ++i) {
            m[num] = vdict[i];
            ++num;
        }

        vector<Edge> vedge;
        int vertex_num = vdict.size();
        int edge_num = 0;
        for (int j=0; j<vertex_num; ++j) {
            for (int k=j+1; k<vertex_num; ++k) {
                string str_j = m[j];
                string str_k = m[k];
                if (dist(str_j, str_k) == 1) {
                    ++edge_num;
                    Edge e1(j, k);
                    vedge.push_back(e1);
                    Edge e2(k, j);
                    vedge.push_back(e2);
                }
            }
        }
        cout << "vertex num:" << vdict.size() << endl;
        cout << "edge num:" << edge_num << endl;

        vector<int> d(vdict.size(), INT_MAX);
        d[0] = 0;
        shortest_path_bellmanford(0, d, vedge);
        int shortest_vertex = d[vdict.size()-1] + 1;
        return shortest_vertex;
    }

private:
    // TLE on case:
    //   vertex num:2857
    //   edge num:13262
    // Bellman–Ford runs in O(|V|*|E|) time
    void shortest_path_bellmanford(int source, vector<int> &d, const vector<Edge> ve) {
        while (true) {
            bool update = false;
            for (size_t i=0; i!=ve.size(); ++i) {
                Edge edge = ve[i];
                if (d[edge.from]!=INT_MAX && d[edge.to]>d[edge.from]+1) {
                    d[edge.to] = d[edge.from] + 1;
                    update = true;
                }
            }
            if (!update)
                break;
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
    // string start = "hit";
    // string end = "cog";
    // dict.insert("hot");
    // dict.insert("dot");
    // dict.insert("dog");
    // dict.insert("lot");
    // dict.insert("log");
    ifstream fs("sample_format");
    string start;
    fs >> start;
    string end;
    fs >> end;
    string t;
    unordered_set<string> dict;
    while (fs) {
        fs >> t;
        dict.insert(t);
    }

    int len = s.ladderLength(start, end, dict);
    cout << "len:" << len << endl;

    return 0;
}

