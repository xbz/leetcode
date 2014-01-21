#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

void print(const vector<int>& v)
{
  vector<int>::const_iterator it;
  for (it=v.begin(); it!=v.end(); ++it)
    cout << *it << " ";
  cout << endl;
}

class Solution {
public:
  vector<int> twoSum(vector<int> &numbers, int target) {
    unordered_map<int, vector<int> > m;
    for (size_t i=0; i<numbers.size(); i++)
      m[numbers[i]].push_back(i+1);

    vector<int> ret;
    for (size_t i=0; i<numbers.size(); i++) {
      int v = target - numbers[i];
      unordered_map<int, vector<int> >::iterator it = m.find(v);
      if (it == m.end())
        continue;

      int idx1 = i+1;
      int idx2 = it->second[0];
      if (numbers[i] == v) {
        if (m[numbers[i]].size() == 1)
          continue;
          idx2 = it->second[1];
      }

      ret.push_back(min(idx1, idx2));
      ret.push_back(max(idx1, idx2));
      break;
    }
    return ret;
  }
};

int main(int argc, char *argv[])
{
  //int arr[] = { 0, 4, 3, 0 };
  int arr[] = { 3, 2, 4 };
  //int arr[] = { 3, 4, 2, 9, 1, 20, 15, 6 };
  vector<int> v(arr, arr+sizeof(arr)/sizeof(arr[0]));
  Solution s;
  vector<int> r = s.twoSum(v, 6);
  print(r);

  return 0;
}

