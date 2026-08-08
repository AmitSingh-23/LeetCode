class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double> pq;
       
        double sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            pq.push(nums[i]);
            sum += nums[i];
        }

        double current = sum;
        int count = 0;
        while (current > sum / 2) {
            double val = pq.top();
            pq.pop();
            current -= val / 2;
            count++;
            pq.push(val / 2);
        }
        return count;
    }
};