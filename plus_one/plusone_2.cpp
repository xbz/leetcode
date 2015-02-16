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
  vector<int> plusOne(vector<int> &digits) {
    reverse(digits.begin(), digits.end());
    plus(digits, 1);
    reverse(digits.begin(), digits.end());
    return digits;
  }

private:
  void plus(vector<int> &v, int n) {
    int carry = n;
    for (size_t i=0; i<v.size(); i++) {
      int sum = v[i] + carry;
      v[i] = sum%10;
      carry = sum/10;
      if (carry == 0)
        break;
    }
    if (carry > 0)
      v.push_back(1);
  }
};

int main(int argc, char *argv[])
{
  int arr[] = { 9, 9, 9, 9 };
  vector<int> v(arr, arr+sizeof(arr)/sizeof(arr[0]));
  Solution s;
  print(v);
  vector<int> r = s.plusOne(v);
  print(r);

  return 0;
}

