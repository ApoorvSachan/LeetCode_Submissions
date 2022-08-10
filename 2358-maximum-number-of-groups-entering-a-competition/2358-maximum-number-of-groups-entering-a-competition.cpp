class Solution {
public:
    int maximumGroups(vector<int>& grades) {
    int count=0, l=0, size=1;
    while(l<grades.size()){
        l+=size;
        size++;
        count++;
    }
        return l==grades.size()?count:count-1;
    }
}; 