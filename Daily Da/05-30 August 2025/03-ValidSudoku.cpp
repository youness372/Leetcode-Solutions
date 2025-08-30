#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> rows(9), cols(9), boxes(9);
        
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char c = board[i][j];
                if (c == '.') continue;
                
                int boxIndex = (i / 3) * 3 + (j / 3);
                
                if (rows[i].count(c) || cols[j].count(c) || boxes[boxIndex].count(c)) {
                    return false;
                }
                
                rows[i].insert(c);
                cols[j].insert(c);
                boxes[boxIndex].insert(c);
            }
        }
        
        return true;
    }
};
