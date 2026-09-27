class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        vector<long long> vt(100001, 0);
        set<int> boundary;
        for (int i = 0; i < segments.size(); i++) {
            vt[segments[i][0]] += segments[i][2];
            vt[segments[i][1]] -= segments[i][2];
            boundary.insert(segments[i][0]);
            boundary.insert(segments[i][1]);
        }
        for (int i = 1; i < vt.size(); i++) {
            vt[i] += vt[i - 1];
        }
        int start = 1;
        vector<vector<long long>> result;
        while (start < vt.size()) {

            if (vt[start] == 0) {
                start++;
                continue;
            }

            int end = start + 1;

            while (end < vt.size() && vt[start] == vt[end] &&
                   boundary.find(end) == boundary.end()) {
                end++;
            }
            result.push_back({start, end, vt[start]});
            start = end;
        }

        return result;
    }
};