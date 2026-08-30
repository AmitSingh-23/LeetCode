class Solution {
public:
    int minBishopMoves(vector<int>& source, vector<int>& target) {
        int r = source[0];
        int c = source[1];
        int tr = target[0];
        int tc = target[1];
        if ((r + c) % 2 != (tr + tc) % 2)
            return -1;
        if (abs(tr-r)  == abs(c - tc))
            return 1;
        return 2;
    }
};