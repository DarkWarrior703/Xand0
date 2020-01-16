#ifndef X_AND_0_X_O_H
#define X_AND_0_X_O_H

class X_O {
public:
    char array[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    void displayArray();
    void changeValue();
    bool result();
    bool turn = 0;
    void youWon();
    bool running = 1;
    int count = 0;
    X_O();
    ~X_O();
};

#endif //X_AND_0_X_O_H
