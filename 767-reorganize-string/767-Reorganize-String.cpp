class Solution {
public:
    string reorganizeString(string s) {
        priority_queue<pair<int, char>> pq;
        unordered_map<char, int> umpp;
        string result = "";
        for (int i = 0; i < s.length(); i++) {
            umpp[s[i]]++;
        }
        for (auto& [key, value] : umpp) {
            pq.push({value, key});
        }
        if (pq.top().first > (s.length() + 1) / 2) {
            return "";
        }
        while (!pq.empty()) {
            if (pq.size() == 1)
                break;
            char top = pq.top().second;
            int topval = pq.top().first;
            pq.pop();
            char sec = pq.top().second;
            int secval = pq.top().first;
            pq.pop();

            result += top;
            result += sec;
            if (topval - 1 > 0)
                pq.push({topval - 1, top});
            if (secval - 1 > 0)
                pq.push({secval - 1, sec});
        }
        if (!pq.empty())
            result += pq.top().second;

        return result;
    }
};