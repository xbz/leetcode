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
const int INF = 100;

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

        int** cost = new int* [vdict.size()];
        for (size_t i=0; i<vdict.size(); ++i)
            cost[i] = new int[vdict.size()];
        for (size_t i=0; i<vdict.size(); ++i) {
            for (size_t j=0; j<vdict.size(); ++j)
                cost[i][j] = INF;
        }

        int vertex_num = vdict.size();
        int edge_num = 0;
        vector<Edge> vedge;
        for (int j=0; j<vertex_num; ++j) {
            for (int k=j+1; k<vertex_num; ++k) {
                string str_j = m[j];
                string str_k = m[k];
                if (dist(str_j, str_k) == 1) {
                    ++edge_num;
                    cost[j][k] = 1;
                    cost[k][j] = 1;
                }
            }
        }
        cout << "vertex num:" << vdict.size() << endl;
        cout << "edge num:" << edge_num << endl;

        vector<int> d(vdict.size(), INF);
        d[0] = 0;
        shortest_path_dijkstra(0, d, cost);
        int shortest_vertex = d[vdict.size()-1] + 1;
        return shortest_vertex;
    }

private:
    void shortest_path_dijkstra(int source, vector<int> &d, int** cost) {
        vector<int> used(d.size(), false);

        while (true) {
            int v = -1;
            for (size_t u=0; u<d.size(); ++u) {
                if (used[u])
                    continue;
                if (v==-1 || d[u]<d[v])
                    v = u;
            }
            if (v == -1)
                break;
            used[v] = true;

            for (size_t u=0; u<d.size(); ++u)
                d[u] = min(d[u], d[v]+cost[v][u]);
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

