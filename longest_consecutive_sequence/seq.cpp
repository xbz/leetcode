#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

void print(const unordered_map<int, int>& m)
{
    unordered_map<int, int>::const_iterator it = m.begin();
    for (; it!=m.end(); ++it)
        cout << it->first << "->" << it->second << " ";
	cout << endl;
}

class Solution {
public:
    int longestConsecutive_better(vector<int> &num) {
		int seq = 0;
		unordered_map<int, int> m;
		for (size_t i=0; i<num.size(); ++i) {
			if (m.count(num[i]) != 0)
				continue;

			int left = num[i];
			int right = num[i];
			int sum = 1;
			if (m.count(num[i]-1) > 0) {
				sum += m[num[i]-1];
				left -= m[num[i]-1];
			}
			if (m.count(num[i]+1) > 0) {
				sum += m[num[i]+1];
				right += m[num[i]+1];
			}

			seq = max(seq, sum);
			m[left] = m[right] = sum;
		}
		return seq;
	}

    int longestConsecutive(vector<int> &num) {
        int seq = 0;
        unordered_map<int, int> m;
        for (size_t i=0; i<num.size(); ++i) {
			if (m.count(num[i]) != 0)
				continue;

            m[num[i]] = num[i];

			int x = num[i];
            int up = num[i] - 1;
			if (m.count(up)!=0 && m[up]<num[i]) {
                x = m[up];
                m[num[i]] = x;
                m[x] = num[i];
                if (x != up)
                    m.erase(up);
            }

			int y = num[i];
            int down = num[i] + 1;
			if (m.count(down)!=0 && m[down]>num[i]) {
                y = m[down];
                m[x] = y;
                m[y] = x;
				// if (x != num[i])
				// 	m.erase(num[i]);
                if (y != down)
                    m.erase(down);
            }
			seq = max(seq, y-x+1);
			cout << num[i] << " " << seq << endl;
			print(m);
		}
        return seq;
    }

    int longestConsecutive1(vector<int> &num) {
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
	int arr[] = { 7,-2,9,9,1,9,8,-4,6,-6,-6,4,1,3,6,3,5,-2,3,4,-6,1,5,-9,6,1,2,-2,1 };
	// int arr[] = { 100 };
	int len = sizeof(arr) / sizeof(arr[0]);
	vector<int> v(arr, arr+len);
	Solution s;
	int seq = s.longestConsecutive(v);
	cout << "seq:" << seq << endl;

    return 0;
}
