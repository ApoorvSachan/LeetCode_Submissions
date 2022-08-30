class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
    int ans=0;
    for(int i=0;i<customers.size();i++)
        if(!grumpy[i]) ans+=customers[i];
    int power=0;
    for(int i=0;i<minutes && i<customers.size(); i++)
        if(grumpy[i]) power+=customers[i];
    int temp=power;
    for(int i=minutes; i<customers.size(); i++){
        if(grumpy[i-minutes]) temp-=customers[i-minutes];
        if(grumpy[i]) temp+=customers[i];
        power=max(power,temp);
    }
    return ans+power;
    }
};