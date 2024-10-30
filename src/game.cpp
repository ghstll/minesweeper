#include <iostream>
#include "..\include\board.h"
#include <conio.h>
void game(){
    char difficult;
    std::cout << "Enter difficult (e = Easy , m = Medium , h = hard): ";
    std::cin >> difficult;
    system("cls");

    auto board = createBoardGame(difficult);
    while(true){
        std::cout << "square coords: " << std::endl;
        for (const auto& row : board) {
            for (int val : row) {
                std::cout << "[ " <<  " ]"; 
                
            }
            std::cout << std::endl;
        }
        getch();
    }
}