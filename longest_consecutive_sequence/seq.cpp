#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

void print(const vector<int>& v)
{
    vector<int>::size_type i;
    for (i=0; i<v.size()-1; i++)
        cout << v[i] << ' ';
    cout << v[i] << endl;
}

class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        int seq = 0;
        unordered_set<int> dup;
        unordered_map<int, int> m;
        for (size_t i=0; i<num.size(); ++i) {
            if (dup.count(num[i]) != 0)
                continue;

            dup.insert(num[i]);
            int up = num[i] - 1;
            int down = num[i] + 1;
            m[num[i]] = num[i];

			int x = num[i];
			if (m.count(up) != 0) {
                x = m[up];
                m[num[i]] = x;
                m[x] = num[i];
                if (x != up)
                    m.erase(up);
            }

			int y = num[i];
			if (m.count(down) != 0) {
                y = m[down];
                m[x] = y;
                m[y] = x;
                if (y != down)
                    m.erase(down);
            }
			seq = max(seq, y-x+1);
		}
        return seq;
    }
};

int main(int argc, char *argv[])
{
	int arr[] = { 100, 4, 200, 1, 3, 2 };
	// int arr[] = { 100 };
	int len = sizeof(arr) / sizeof(arr[0]);
	vector<int> v(arr, arr+len);
	Solution s;
	int seq = s.longestConsecutive(v);
	cout << "seq:" << seq << endl;

    return 0;
}
