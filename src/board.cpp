// CREATE BOARD GAME
#include <stdio.h>
#include <vector>
#include <cstdlib>
#include <map>
#include <iostream>
std::vector<std::vector<int>> createBoardGame(char difficult){



    
    std::map<char,int> difficultMap = {
        {'e',8}, // EASY 
        {'m',12}, // MEDIUM
        {'h',16} // HARD
    };

    std::map<int,int> ratioBombs = { //{size,bombs}
        {8,10},
        {12,22},
        {16,38}
    };
    
    auto it = difficultMap.find(difficult);
    int size = it -> second;
    int countbombs = ratioBombs[size];

    std::map<std::pair<int,int>,int> cornerValues ={
        {{0,0},0}, // TOP LEFT CORNER
        {{0,size-1},1}, // TOP RIGHT CORNER
        {{size-1,size-1},2}, // BOTTOM RIGHT CORNER
        {{size-1,0},3} // BOTTOM LEFT CORNER
    };

    auto cornerNumber = [size,&cornerValues](int i,int j) -> int { // FUNCTION TO CHECK IF A SQUARE IS A CORNER NUMBER
        std::pair<int,int> key ={i , j};
        auto it = cornerValues.find(key);
        if(it != cornerValues.end()){
            return cornerValues[{i,j}]; 
        }else{
            return 4;
        }
    };
   
    std::vector<std::vector<int>>mat(size,std::vector<int>(size,0));
    if(it !=  difficultMap.end()){
        while (countbombs > 0) // FILL BOARD WITH BOMBS 
        {   
            int i = rand() % size ;
            int j = rand() % size ;
            if(mat[i][j] == 0){
                mat[i][j] = 1;
                countbombs--;
            }
        }
        
        
        
        
    }else{
        std::cout << "Dificultad no valida";
    }

  
    
    return mat;
}