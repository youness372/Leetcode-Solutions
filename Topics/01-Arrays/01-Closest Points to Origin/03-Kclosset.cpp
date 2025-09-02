#include <vector>
#include <queue>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto cmp = [](const pair<int, vector<int>>& a, const pair<int, vector<int>>& b) {
            return a.first > b.first;  
        };
        
        priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, decltype(cmp)> heap(cmp);
        
        for (auto& p : points) {
            int dist = p[0]*p[0] + p[1]*p[1];
            heap.push({dist, p});
        }
        
        vector<vector<int>> result;
        for (int i = 0; i < k; i++) {
            result.push_back(heap.top().second);
            heap.pop();
        }
        
        return result;
    }
};
