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
  vector<vector<int> > permute(vector<int> &num) {
    if (num.size() == 1) {
      vector<vector<int> > v(1, num);
      return v;
    }

    vector<vector<int> > ret;
    for (size_t i=0; i<num.size(); i++) {
      swap(num[0], num[i]);
      vector<int> sub(num.begin()+1, num.end());
      vector<vector<int> > subret = permute(sub);
      for (size_t j=0; j<subret.size(); j++) {
        subret[j].push_back(num[0]);
        ret.push_back(subret[j]);
      }
    }
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
  vector<vector<int> > ret = s.permute(v);
  cout << "size:" << ret.size() << endl;
  vector<vector<int> >::iterator it;
  for (it=ret.begin(); it!=ret.end(); ++it)
    print(*it);

  return 0;
}

