#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <cstring>
#include <string.h>

using namespace std;

int **CreateMatrix(int NumRows, int NumColumns){
    int** matrix = (int**) malloc(NumRows * sizeof(int*));
    for(int i=0;i<NumRows;i++){
       matrix[i]= (int*) malloc(NumColumns * sizeof(int));
    }
    return matrix;
}


void InputMatrix(int **Matrix, int NumRows, int NumColumns){
    for (int i=0;i<NumRows;i++){
         for (int j=0;j<NumColumns;j++){         
             std::cin >> (Matrix)[i][j]; 
         }                             
    }
    return;
}

void BuildStringFromMatrix (int **Matrix, int NumRows, int NumColumns, char *OutBuffer){
    const int num = NumRows*NumColumns;
    cout << "Const int = " << num << endl;
    for (int i=0;i<NumRows;i++){
         for (int j=0;j<NumColumns;j++){
            cout << (Matrix)[i][j] << " ";                    
         }
         cout << "\n";
    } 
    
    int turn = 0;
    int length = 0;
    size_t len = 0;
    int row = 0 ;
    int col = 0;
    char mat;
    
    mat = (char)(48+Matrix[row][col]);
    len = strlen(OutBuffer);
    OutBuffer[len] = mat;  
    ++length;

    
    /*col = 1;
    mat = (char)(48+Matrix[row][col]);
    cout << mat << " ";
    len = strlen(OutBuffer);
     cout << len << " ";
    OutBuffer[len] = mat; 
    cout << OutBuffer[len] << endl;   
    ++length;
    
    row = 1;
    col = 1;
    mat = (char)(48+Matrix[row][col]);
    cout << mat << " ";
    len = strlen(OutBuffer);
    cout << len << " ";
    OutBuffer[len] = mat; 
    cout << OutBuffer[len] << endl;     
    //strncpy(*OutBuffer[length],&(*temp)[length],sizeof(*temp)[length]); 
    ++length;
    
    col = 0;
    mat = (char)(48+Matrix[row][col]);
    cout << mat << " ";
    len = strlen(OutBuffer);
    cout << len << " ";
    OutBuffer[len] = mat; 
    cout << OutBuffer[len] << endl;     
    //strncpy(*OutBuffer[length],&(*temp)[length],sizeof(*temp)[length]); 
    ++length;
    //temp = (char*) realloc(temp,100);*/
    
    while(length < num){
      if((turn % 4) == 0){
         if(col < NumColumns-1-(turn+1)/4){
            ++col;
            mat = (char)(48+Matrix[row][col]);
            len = strlen(OutBuffer);
            OutBuffer[len] = mat; 
            ++length;
         } 
         else{ 
            ++turn;
         }
      }                
      else if ((turn % 4) == 1){
         if (row < NumRows-1-(turn+1)/4){
            ++row;
            mat = (char)(48+Matrix[row][col]);
            len = strlen(OutBuffer);
            OutBuffer[len] = mat; 
            ++length;
         } 
         else{ 
            ++turn;
         }
      }
      else if ((turn % 4) == 2){ 
         if (col > (turn+1)/4){ 
            --col;
            mat = (char)(48+Matrix[row][col]);
            len = strlen(OutBuffer);
            OutBuffer[len] = mat; 
            ++length;
         } 
         else{ 
            ++turn;
         }
      }
      else if ((turn % 4) == 3){
         if (row > (turn+1)/4){ 
            --row;
            mat = (char)(48+Matrix[row][col]);
            len = strlen(OutBuffer);
            OutBuffer[len] = mat; 
            ++length;
         } 
         else {
            ++turn;
         }
     }
    }
    //memcpy((OutBuffer),&temp,strlen(temp)+1);    
    for (int i=0;i<(strlen(OutBuffer)+2);i++){
       cout << (OutBuffer)[i] << " ";
    }
    cout << endl;
    return;
}

int main () { 
   /* FILE* fp = fopen("matrix.txt","r");
    char** ptr = (char**)malloc(10*sizeof(char*));
    if (fp == NULL){
       cout << "File Not Read!" << endl;
       exit(1);
    }*/
    
    int NumRows, NumColumns;
    cout << "Enter the row of the Matrix:" << endl;
    scanf("%d",&NumRows);
    cout << "Enter the column of the Matrix:" << endl;
    scanf("%d",&NumColumns);
    char* OutBuffer = (char*)malloc((NumRows*NumColumns+1)*sizeof(char)); 
    int** Matrix; 
    Matrix = CreateMatrix(NumRows, NumColumns);
    InputMatrix(Matrix, NumRows, NumColumns);
    BuildStringFromMatrix(Matrix, NumRows, NumColumns, OutBuffer);
    /*for (i=0;i<NumRows;i++){
        for (j=0;j<NumColumns;j++){
            cout << Matrix[i][j] << " ";         
        }
    } */
    free(Matrix);
    free(OutBuffer);
    /*for (i=0;i<NumRows;++i){
        for (j=0;j<NumColumns;++j){
            sprintf(OutBuffer,"%d",Matrix[i][j]);         
        }
    }*/
    /*for (i=0;i<NumRows*NumColumns;++i){
        cout << OutBuffer[i] << " ";
    }*/ 
    return 0;
}

/* int integer,length,loop = 0;
    char integer_string[256];
    while (length < NumRows * NumColumns){
          //loop = min(min(i,j),min(NumRows-i,NumColumns-j));  
          if (i<NumRows/2 && j<NumColumns-loop){
             ++j;
             integer = *Matrix[i][j];
             sprintf(integer_string, "%d", integer);
             strcat(*OutBuffer,integer_string[length]);
             ++length;
             
          }
          if (i<NumRows-loop && j>NumColumns/2){
             ++i;
             integer = *Matrix[i][j];
             sprintf(integer_string, "%d", integer);
             strcat(*OutBuffer,integer_string);
             ++length;
          }  
          if (i>(NumRows/2-1) && j>loop){
             --j;
             integer = *Matrix[i][j];
             sprintf(integer_string, "%d", integer);
             strcat(*OutBuffer,integer_string);
             ++length;
          }
          if (i>loop && j<NumColumns/2){
             --j;
             integer = *Matrix[i][j];
             sprintf(integer_string, "%d", integer);
             strcat(*OutBuffer,integer_string);
             ++length;
          }
     }*/

