// CREATE BOARD GAME
#include <stdio.h>
#include <vector>
#include <cstdlib>
#include <map>
#include <iostream>
#include <variant>
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
            return cornerValues[{i,j}]; // A CORNER VALUE
        }else{
            return 4; // NOT A CORNER VALUE
        }
    };
    
  

    auto borderNumber = [size](int i , int j) -> int{
        if(j == 0) return 0;
        if(i == 0) return 1;
        if(j == size - 1) return 2;
        if(i == size - 1) return 3;
        return 4; // NOT A BORDER NUMBER
    };

    auto centralNumber = [borderNumber,cornerNumber](int i , int j) -> int{
        if(borderNumber(i,j) == 4 && cornerNumber(i,j) == 4){
            return 1;
        }else{
            return 0;
        }
    };

    std::vector<std::vector<int>>mat(size,std::vector<int>(size,0));
    auto checkBombsCentralNumber = [&mat,size,borderNumber,centralNumber](int i, int j) -> int {
        int count = 0;
        if(centralNumber(i,j) == 1){
            if(mat[i-1][j-1] == 9) count++; 
            if(mat[i-1][j] == 9) count++; 
            if(mat[i-1][j+1] == 9) count++; 
            if(mat[i][j+1] == 9) count++; 
            if(mat[i+1][j+1] == 9) count++; 
            if(mat[i+1][j] == 9) count++; 
            if(mat[i+1][j-1] == 9) count++; 
            if(mat[i][j-1] == 9) count++; 
            return count;

        }else{
            return count;
        }
    };
    auto checkBombsBorderNumber = [&mat,size,borderNumber](int i,int j) -> int {
        int count = 0;
        switch (borderNumber(i,j)){
            case 0 :
                if(mat[i-1][j] == 9) count++;
                if(mat[i-1][j+1] == 9) count++;
                if(mat[i][j+1] == 9) count++;
                if(mat[i+1][j+1] == 9) count++;
                if(mat[i+1][j] == 9) count++;
                return count;
            case 1 :
                if(mat[i][j-1] == 9) count++;
                if(mat[i+1][j-1] == 9) count++;
                if(mat[i+1][j] == 9) count++;
                if(mat[i+1][j+1] == 9) count++;
                if(mat[i][j+1] == 9) count++;     
                return count;   
            case 2:
                if(mat[i-1][j] == 9) count++;
                if(mat[i-1][j-1] == 9) count++;
                if(mat[i][j-1] == 9) count++;
                if(mat[i+1][j-1] == 9) count++;
                if(mat[i+1][j] == 9) count++;
                return count;
            case 3:
                if(mat[i][j+1] == 9) count++;
                if(mat[i-1][j+1] == 9) count++;
                if(mat[i-1][j] == 9) count++;
                if(mat[i-1][j-1] == 9) count++;
                if(mat[i][j-1] == 9) count++;
                return count;
            default:
                return count;
                break;
        }
    };
    auto checkBombsCornerNumber = [&mat,size](int position) -> int {
        int count = 0;
        switch (position){
           case 0:
                if(mat[0][1] == 9) count++;
                if(mat[1][0] == 9) count++;
                if(mat[1][1] == 9) count++;
                return count;
            case 1:
                if(mat[0][size - 2] == 9) count++;
                if(mat[1][size - 1] == 9) count++;
                if(mat[1][size - 2] == 9) count++;
                return count;
            case 2:
                if(mat[size - 1][size - 2] == 9) count++;
                if(mat[size - 2][size - 1] == 9) count++;
                if(mat[size - 2][size - 2] == 9) count++;
                return count;
            case 3:
                if(mat[size - 2][0] == 9) count++;
                if(mat[size - 1][1] == 9) count++;
                if(mat[size - 2][1] == 9) count++;
                return count;
            default:
                return 0;
        }
    };
    if(it !=  difficultMap.end()){
        srand(time(0));
        while (countbombs > 0) // FILL THE BOARD WITH RANDOM BOMBS
        {   
            int i = rand() % size ;
            int j = rand() % size ;
            if(mat[i][j] == 0){
                mat[i][j] = 9;
                countbombs--;
            }
        }
        int i , j;
        for(i=0;i<size;i++){
            for(j=0;j<size;j++){
                int position = cornerNumber(i,j);
                if(mat[i][j] == 0 && position != 4){
                   mat[i][j] = checkBombsCornerNumber(position);
                }else if(mat[i][j] == 0 && borderNumber(i,j) != 4){
                    mat[i][j] = checkBombsBorderNumber(i,j);
                }else if(mat[i][j] == 0 && centralNumber(i,j) != 0){
                    mat[i][j] = checkBombsCentralNumber(i,j);
                }
               
            }   
        }
        
        
        
        
    }else{
        std::cout << "Dificultad no valida";
    }
    
  
    
    return mat;
}