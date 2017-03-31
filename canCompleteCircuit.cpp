class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int gas_left=0;
        int distance=0;
        int start=0;
        for(int i=0;i<gas.size();i++){
            gas_left+=gas[i]-cost[i];
            distance+=gas[i]-cost[i];
            if(gas_left<0){
                start=i+1;
                gas_left=0;
            }
        }
        if(distance < 0)
            return -1;// total gas less than cost;
        return start;
    }
};