#include <stdio.h>
#include <iostream>
#include "board.h"
#include <stdlib.h>
//  0 = VACIO
//  1 = MINA

int main(){
    // int rows,columns,fill;

    // std::cout << "Number of rows: ";
    // std::cin  >> rows;
    // std::cout << "Numbers of columns: ";
    // std::cin >>  columns; 
    // std::cout << "Number to fill: ";
    // std::cin >>  fill; 

    // int rows = 8;
    // int columns = 10 ;
    char difficult;
    std::cout << "Enter difficult (e = Easy , m = Medium , h = hard): ";
    std::cin >> difficult;

    system("cls");
    auto board = createBoardGame(difficult);
     for (const auto& row : board) {
        for (int val : row) {
            if (val == 0)
            {
                std::cout <<" O "; 
            }else{
                std::cout <<" B "; 

            }
            
            
        }
        std::cout << std::endl;
    }

   
    return 0;
    
}