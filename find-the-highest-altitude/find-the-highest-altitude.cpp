class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int currAltitude = 0;

        int highestAltitude = currAltitude;

        for(int i = 0; i < gain.size(); i++){

            currAltitude = gain[i] + currAltitude;

            highestAltitude = max(highestAltitude, currAltitude);
        }

        return highestAltitude;
    }
};