class Solution {
public:
// Approach is same as word ladder
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> st (bank.begin(), bank.end());
        queue<pair<string, int>> q;
        q.push({startGene, 0});
        st.erase(startGene);

        while(!q.empty()){
            string gene = q.front().first;
            int count = q.front().second;
            q.pop();

            if(gene == endGene){
                return count;
            }

            for(char c: "ACGT"){
                for(int i = 0; i < gene.size(); i++){
                    char original = gene[i];
                    gene[i] = c;
                    if(st.find(gene) != st.end()){
                        q.push({gene, count + 1});
                        st.erase(gene);
                    }

                    gene[i] = original;
                }
                
            }

        }

        return -1;

    }
};