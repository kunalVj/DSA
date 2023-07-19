class Solution {
public:
    bool squareIsWhite(string coordinates) {
        char letter = coordinates[0], num = coordinates[1];

        if((letter & 1 && num & 1) || (!(letter & 1) && !(num & 1))){ // if odd
                return false;
        }

        // else if(letter == 'b' || letter == 'd' || letter == 'f' || letter == 'h'){
        //     if(num == '2' || num == '4' || num == '6' || num == '8'){
        //         return false;
        //     }
        // }

        return true;
    }
};