#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int result1 = check(tops[0], tops, bottoms);
        int result2 = (tops[0] == bottoms[0]) ? INT_MAX : check(bottoms[0], tops, bottoms);

        int minResult = min(result1 == -1 ? INT_MAX : result1,
                            result2 == -1 ? INT_MAX : result2);

        return (minResult == INT_MAX) ? -1 : minResult;
    }

private:
    int check(int target, vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        int rotationsTop = 0;
        int rotationsBottom = 0;

        for (int i = 0; i < n; ++i) {
            if (tops[i] != target && bottoms[i] != target) {
                return -1;
            } else if (tops[i] != target) {
                ++rotationsTop;
            } else if (bottoms[i] != target) {
                ++rotationsBottom;
            }
        }

        return min(rotationsTop, rotationsBottom);
    }
};
// https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/
