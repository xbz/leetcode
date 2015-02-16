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
    int carry = 0;
    reverse(digits.begin(), digits.end());
    for (size_t i=0; i<digits.size(); i++) {
      int sum = digits[i] + carry;
      if (i == 0)
        sum += 1;
      digits[i] = sum%10;
      carry = sum/10;
    }
    if (carry > 0)
      digits.push_back(1);
    reverse(digits.begin(), digits.end());
    return digits;
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

