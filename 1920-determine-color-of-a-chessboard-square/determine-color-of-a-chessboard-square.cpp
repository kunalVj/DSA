class Solution {
public:
    bool squareIsWhite(string coordinates) {
        char letter = coordinates[0], num = coordinates[1];

        if(letter == 'a' || letter == 'c' || letter == 'e' || letter == 'g'){
            if(num == '1' || num == '3' || num == '5' || num == '7'){
                return false;
            }
        }

        else if(letter == 'b' || letter == 'd' || letter == 'f' || letter == 'h'){
            if(num == '2' || num == '4' || num == '6' || num == '8'){
                return false;
            }
        }

        return true;
    }
};