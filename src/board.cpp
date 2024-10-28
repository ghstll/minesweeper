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
    



    std::vector<std::vector<int>>mat;
    auto it = difficultMap.find(difficult);
    
    int i , j;

    if(it !=  difficultMap.end()){

      

        int size = it -> second;
        for (i=0;i<size;i++){
            std::vector<int> row;
            for (j=0;j<size;j++){
                row.push_back(rand() % 2);
            }
            mat.push_back(row);
        }

    
        std::map<std::pair<int,int>,int> cornerValues ={
            {{0,0},0}, // TOP LEFT CORNER
            {{0,size-1},1}, // TOP RIGHT CORNER
            {{size-1,size-1},2}, // BOTTOM RIGHT CORNER
            {{size-1,0},3} // BOTTOM LEFT CORNER
        };

        auto cornerNumber = [size,&cornerValues](int i,int j) -> int {
            std::pair<int,int> key ={i , j};
          
            auto it = cornerValues.find(key);
            
            if(it != cornerValues.end()){
               return cornerValues[{i,j}]; 
            }  else{
                return 4;
            }

        };
        for (i=0;i<size;i++){
            for(j=0;j<size;j++){
              
            }
        }



    }else{
        std::cout << "Dificultad no valida";
    }

  

    // for( auto& row : mat){
    //     for(int& val : row ){
    //         if (val == 2) {
    //             val = 5;
    //         }
    //     }
    // }
    
    return mat;
}