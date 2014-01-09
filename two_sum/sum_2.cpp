#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(const vector<int>& v)
{
  vector<int>::const_iterator it;
  for (it=v.begin(); it!=v.end(); ++it)
    cout << *it << " ";
  cout << endl;
}

bool cmp(const pair<int,int>& l, const pair<int,int>& r)
{
  return l.first < r.first;
}

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
      vector<pair<int, int> > v(numbers.size());
      for (size_t k=0; k<numbers.size(); k++)
        v[k] = make_pair(numbers[k], k+1);

      sort(v.begin(), v.end(), cmp);
      size_t i = 0;
      size_t j = v.size() - 1;
      while (i < j) {
        int sum = v[i].first + v[j].first;
        if (sum == target)
          break;
        else if (sum < target)
          ++i;
        else
          --j;
      }

      vector<int> ret;
      ret.push_back(min(v[i].second, v[j].second));
      ret.push_back(max(v[i].second, v[j].second));
      return ret;
    }
};

int main(int argc, char *argv[])
{
  int arr[] = { 0, 4, 3, 0 };
  //int arr[] = { 3, 4, 2, 9, 1, 20, 15, 6 };
  vector<int> v(arr, arr+sizeof(arr)/sizeof(arr[0]));
  Solution s;
  vector<int> r = s.twoSum(v, 0);
  print(r);

  return 0;
}

