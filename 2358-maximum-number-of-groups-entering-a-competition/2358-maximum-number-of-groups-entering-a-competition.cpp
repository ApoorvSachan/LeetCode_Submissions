class Solution {
public:
    int maximumGroups(vector<int>& grades) {
    int l=grades.size();
    return sqrt((2*l)+0.25)-0.5;
    }
};

