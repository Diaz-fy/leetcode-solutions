#include <string>
class Solution {
public:
    std::string pushDominoes(std::string dominoes) {
        int n = dominoes.size();
        int left = -1; 
        int right = -1;
        std::string result = dominoes;

        for (int i = 0; i <= n; ++i) {
            char c = (i < n ? result[i] : 'R');

            if (c == 'R') {
                if (right > left) {
                    for (int j = right + 1; j < i; ++j)
                        result[j] = 'R';
                }
                right = i;
            } else if (c == 'L') {
                if (right > left) {
                    int low = right + 1;
                    int high = i - 1;
                    while (low < high) {
                        result[low++] = 'R';
                        result[high--] = 'L';
                    }
                } else {
                    for (int j = left + 1; j < i; ++j)
                        result[j] = 'L';
                }
                left = i;
                right = -1;
            }
        }

        return result;
    }
};
// https://leetcode.com/problems/push-dominoes/
