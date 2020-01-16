#include <iostream>
#include "X_O.h"

void X_O::changeValue() {
    int n{};
    std::cout << "Enter a number between 1 and 9: \n";
    std::cin >> n;
    while(array[n] == '0' || array[n] == 'X'|| n < 1 || n > 9){
        std::cout << "Pick another number! Enter a number between 1 and 9: \n";
        std::cin >> n;
    }
    if(turn)
        array[n] ='X';
    else
        array[n] ='0';
    turn = !turn;
    count++;
}

bool X_O::result() {
    if(array[1] == array[2] && array[2] == array[3])
        return true;
    else if(array[1] == array[4] && array[4] == array[7])
        return true;
    else if(array[1] == array[5] && array[5] == array[9])
        return true;
    else if(array[2] == array[5] && array[5] == array[8])
        return true;
    else if(array[3] == array[6] && array[6] == array[9])
        return true;
    else if(array[4] == array[5] && array[5] == array[6])
        return true;
    else if(array[7] == array[8] && array[8] == array[9])
        return true;
    else if(array[3] == array[5] && array[5] == array[7])
        return true;
    return false;
}

void X_O::displayArray() {
    for(int i = 1; i <= 9; i++){
        if(i % 3 == 1)
            std::cout << " " << array[i] << " | ";
        else if(i % 3 == 2)
            std::cout << array[i];
        else {
            if(i != 9) {
                std::cout << " | " << array[i] << '\n';
                std::cout << "---|---|---" << '\n';
            } else{
                std::cout  << " | " << array[i] << '\n';
            }
        }
    }
}

void X_O::youWon() {
    if(X_O::result()){
        if(turn)
            std::cout << "Player 1 won!"<<'\n';
        else
            std::cout << "Player 2 won"<<'\n';
        running = 0;
    }
    else if(count == 9){
        std::cout << "Draw!"<<'\n';
        running = 0;
    }
}

X_O::X_O(){
    while(running){
        X_O::displayArray();
        X_O::changeValue();
        X_O::youWon();
    }
};

X_O::~X_O() {
    X_O::displayArray();
}