class ParkingSystem {
public:
int bigCount, mediumCount, smallCount;

    ParkingSystem(int big, int medium, int small) {
        this -> bigCount = big;
        this -> mediumCount = medium;
        this -> smallCount = small;
    }
    
    bool addCar(int carType) {
        if(carType == 1 && this -> bigCount > 0){
            this -> bigCount -= 1;
            return true;
        }
        if(carType == 2 && this -> mediumCount > 0){
            this -> mediumCount -= 1;
            return true;
        }
        if(carType == 3 && this -> smallCount > 0){
            this -> smallCount -= 1;
            return true;
        }

        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */