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
    int longestConsecutive(vector<int> &num) {
		int max_seq = 0;
		unordered_map<int, int> m;
		for (size_t i=0; i<num.size(); ++i) {
			int cur = num[i];
			if (m.count(cur) != 0)
				continue;

			int left_seq = 0;
			if (m.count(cur-1) > 0)
				left_seq = m[cur-1];
			int right_seq = 0;
			if (m.count(cur+1) > 0)
				right_seq = m[cur+1];

            int cur_seq = left_seq + right_seq + 1;
			max_seq = max(max_seq, cur_seq);

			m[cur] = cur_seq;
			m[cur-left_seq]  = cur_seq;
			m[cur+right_seq] = cur_seq;
		}
		return max_seq;
	}

    int longestConsecutive_trick(vector<int> &num) {
		int max_seq = 0;
		unordered_map<int, int> m;
		for (size_t i=0; i<num.size(); ++i) {
			int cur = num[i];
			if (m[cur] != 0)
				continue;

			max_seq = max(max_seq, m[cur-m[cur-1]]=m[cur+m[cur+1]]=m[cur]=m[cur-1]+m[cur+1]+1);
		}
		return max_seq;
	}

    int longestConsecutive_orig(vector<int> &num) {
        int max_seq = 0;
        unordered_map<int, int> m;
        for (size_t i=0; i<num.size(); ++i) {
			int cur = num[i];
			if (m.count(cur) != 0)
				continue;

			int left = cur;
			int right = cur;

            int up = cur - 1;
			if (m.count(up)!=0 && m[up]<cur) {
                left = m[up];
				m.erase(up);
				m.erase(left);
            }

            int down = cur + 1;
			if (m.count(down)!=0 && m[down]>cur) {
                right = m[down];
				m.erase(right);
				m.erase(down);
            }

			m[left] = right;
			m[right] = left;
			max_seq = max(max_seq, right-left+1);
		}
        return max_seq;
    }

    int longestConsecutive_ninechapter(vector<int> &num) {
		int max_seq = 0;
		unordered_map<int, int> m;
		for (size_t i=0; i<num.size(); ++i)
			m[num[i]] = 0;

		for (size_t i=0; i<num.size(); ++i) {
			if (m[num[i]] == 1)
				continue;

			int cur_seq = 1;
			int up = num[i] - 1;
			while (m.count(up) > 0) {
				cur_seq++;
				m[up] = 1;
				up--;
			}

			int down = num[i] + 1;
			while (m.count(down) > 0) {
				cur_seq++;
				m[down] = 1;
				down++;
			}
			max_seq = max(max_seq, cur_seq);
		}
		return max_seq;
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
	// int arr[] = { 7,-2,9,9,1,9,8,-4,6,-6,-6,4,1,3,6,3,5,-2,3,4,-6,1,5,-9,6,1,2,-2,1 };
	int arr[] = { 1, 0 };
	// int arr[] = { 100 };
	int len = sizeof(arr) / sizeof(arr[0]);
	vector<int> v(arr, arr+len);
	Solution s;
	int seq = s.longestConsecutive(v);
	cout << "seq:" << seq << endl;

    return 0;
}
