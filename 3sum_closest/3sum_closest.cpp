#include <vector>
#include <iostream>
#include <climits>
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
    int threeSumClosest(vector<int> &num, int target) {
        sort(num.begin(), num.end());

        int min_dist = INT_MAX;
        int ret = 0;
        for (size_t i=0; i<num.size(); ++i) {
            for (size_t j=i+1; j<num.size(); ++j) {
                for (size_t k=j+1; k<num.size(); ++k) {
                    int sum = num[i] + num[j] + num[k];
                    int d = abs(sum - target);
                    if (d < min_dist) {
                        min_dist = d;
                        ret = sum;
                    }
                    if (sum > target)
                        break;
                }
                if (num[i]+num[j] > target)
                    break;
            }
            if (num[i] > target)
                break;
        }
        return ret;
    }
};

int main(int argc, char *argv[])
{
    // int arr[] = { 0, 4, 3, 0 };
    // int arr[] = { 3, 4, 2, 9, 1, 20, 15, 6, -4 };
    // int arr[] = { 96,80,-63,-52,-48,-35,35,39,-47,-30,-41,83,46,-60,78,53,-80,24,39,31,64,-4,60,20,5,-42,-75,-3,25,54,-17,-41,4,-39,-73,96,1,1,-75,0,-71,-26,-65,-32,-59,24,-58,-73,-62,71,47,37,98,-7,-58,52,82,40,75,-68,-23,76,-89,8,25,-51,-77,-18,58,-11,-100,-77,75,-60,-54,-48,18,90,37,23,-8,-66,-27,91,-9,-32,-98,-21,91,-53,-7,-19,91,-31,-72,22,-27,30,72,4,-55,-21,-11,-57,56,45,77,88,73,28,39,91,-38,-53,74,23,94,-47,20,-39,-79,-39,15,-90,-78,31,-67,83,76,48,-25,44,48,-56,60,44,11,-60,-41,-47,-66,-69,-66,-71,-52,23,-21 };
    int arr[] = {-39,43,71,92,47,-51,-35,-33,-32,98,-40,28,-10,-22,10,-9,-60,-25,-55,-90,-73,-49,40,38,-13,95,-12,-53,-45,-37,79,-71,31,34,11,-54,97,57,-50,-40,-63,48,-22,65,-8,89,80,91,-54,63,46,81,-85,-10,-65,29,-51,70,-77,-74,-1,37,-54,58,-50,-4,-3,71,-54,55,-32,13,-95,-89,-83,-22,24,-30,86,-84,-76,-98,4,33,-50,-9,-5,-97,37,2,-47,-35,16,47,20,2,84,-6,-69,-79,61,32,43,64,-46 };
    vector<int> v(arr, arr+sizeof(arr)/sizeof(arr[0]));
    Solution s;
    int target = 187;
    int sum = s.threeSumClosest(v, target);
    cout << "sum:" << sum << endl;

    return 0;
}
