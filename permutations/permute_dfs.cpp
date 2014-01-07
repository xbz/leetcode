#include <iostream>
#include <vector>

using namespace std;

void print(const vector<int>& v)
{
  vector<int>::const_iterator it;
  for (it=v.begin(); it!=v.end(); ++it)
    cout << *it;
  cout << endl;
}

class Solution {
public:
  void dfs(vector<vector<int> > &ret, vector<int> &num, vector<int> &path) {
    if (path.size() == num.size()) {
      ret.push_back(path);
      return;
    }

    for (size_t i=0; i<num.size(); i++) {
      vector<int>::iterator it = find(path.begin(), path.end(), num[i]);
      if (it != path.end())
        continue;

      path.push_back(num[i]);
      dfs(ret, num, path);
      path.pop_back();
    }
  }

  vector<vector<int> > permute(vector<int> &num) {
    vector<vector<int> > ret;
    vector<int> path;
    dfs(ret, num, path);
    return ret;
  }
};

int main(int argc, char *argv[])
{
  Solution s;
  vector<int> v;
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);
  v.push_back(4);
  //v.push_back(5);
  vector<vector<int> > ret = s.permute(v);
  cout << "size:" << ret.size() << endl;
  vector<vector<int> >::iterator it;
  for (it=ret.begin(); it!=ret.end(); ++it)
    print(*it);

  return 0;
}

