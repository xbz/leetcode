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

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
      vector<int> v(numbers.begin(), numbers.end());
      sort(v.begin(), v.end());
      size_t i = 0;
      size_t j = v.size() - 1;
      while (i < j) {
        if (v[i] + v[j] == target)
          break;
        else if (v[i] + v[j] < target)
          ++i;
        else
          --j;
      }
      int ind1 = find(numbers.begin(), numbers.end(), v[i]) - numbers.begin() + 1;
      int ind2 = numbers.size() - (find(numbers.rbegin(), numbers.rend(), v[j]) - numbers.rbegin());

      vector<int> ret;
      ret.push_back(min(ind1, ind2));
      ret.push_back(max(ind1, ind2));
      return ret;
    }
};

int main(int argc, char *argv[])
{
  //int arr[] = { 0, 4, 3, 0 };
  int arr[] = { 3, 4, 2, 9, 1, 20, 15, 6 };
  vector<int> v(arr, arr+sizeof(arr)/sizeof(arr[0]));
  Solution s;
  vector<int> r = s.twoSum(v, 26);
  print(r);

  return 0;
}

