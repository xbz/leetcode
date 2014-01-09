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
  // wrong answer
  // fail on { 0, 3, 0 }, 0
  vector<int> twoSum(vector<int> &numbers, int target) {
    unordered_map<int, int> m;
    for (size_t i=0; i<numbers.size(); i++)
      m.insert(make_pair(numbers[i], i+1));

    vector<int> ret;
    for (size_t i=0; i<numbers.size(); i++) {
      int v = target - numbers[i];
      unordered_map<int, int>::iterator it = m.find(v);
      if (it == m.end())
        continue;

      cout << numbers[i] << " " << v << endl;
      ret.push_back(min(int(i+1), it->second));
      ret.push_back(max(int(i+1), it->second));
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

