class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start_ind = 0;
        int total_gas = 0;
        int total_cost = 0;
        int curr_gas = 0;
        for(int i = 0 ; i<gas.size(); i++){
            total_gas += gas[i];
            total_cost += cost[i];
            curr_gas = gas[i] - cost[i] + curr_gas;

            if(curr_gas < 0){
                start_ind = i+1;
                curr_gas = 0;
            }
        }
        if(total_gas >= total_cost){
            return start_ind;
        }
        return -1;
        
        
    }
};