class Solution {
public:
    int numTilePossibilities(string tiles) {
  
        vector<int> vt(26, 0);
        for (int i = 0; i < tiles.length(); i++) {
            vt[tiles[i] - 'A']++;
        }
        int count = 0;
        string s = "";
        check(count, s, vt);
        return count;
    }
    void check(int& count, string& s, vector<int>& vt) {

        for (int i = 0; i < 26; i++) {
            if (vt[i] > 0) {
                vt[i]--;
                s += (char)i + 'A';
                count++;
                 check(count, s, vt);

                vt[i]++;
                s.pop_back();
            }
        }
    }
};