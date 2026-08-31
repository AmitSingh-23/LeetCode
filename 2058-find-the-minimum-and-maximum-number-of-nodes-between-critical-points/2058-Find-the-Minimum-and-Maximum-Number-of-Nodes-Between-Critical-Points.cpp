/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> vt;

        ListNode* mover = head->next;
        ListNode* forward = mover->next;

        int i = 1;
        while (mover->next != NULL) {
            if (mover->val > head->val && mover->val > forward->val ||
                mover->val < head->val && mover->val < forward->val) {
                vt.push_back(i);
            }
            head = mover;
            mover = forward;
            forward = forward->next;
            i++;
        }
        if (vt.size() <= 1)
            return {-1, -1};
        int mindis = INT_MAX;
        int maxdis = vt[vt.size()-1] - vt[0];
        for (int j = 1; j < vt.size(); j++) {
            mindis = min(vt[j] - vt[j - 1], mindis);
        }
        return {mindis, maxdis};
    }
};