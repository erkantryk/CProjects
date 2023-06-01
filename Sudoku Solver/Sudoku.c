#include <stdio.h>

int puzzle[4][4];
int num;
int row=4;
int col=4;
int numbers[4][4][4] = {{{1,2,3,4},{1,2,3,4},{1,2,3,4},{1,2,3,4}},
                        {{1,2,3,4},{1,2,3,4},{1,2,3,4},{1,2,3,4}},
                        {{1,2,3,4},{1,2,3,4},{1,2,3,4},{1,2,3,4}},
                        {{1,2,3,4},{1,2,3,4},{1,2,3,4},{1,2,3,4}}};



// 4x4 sudokuyu tanımlıyoruz
void createSudoku(){
    printf("Set 4x4 sudoku from left to right\n");
    printf("Write 0 for blank points\n");
    for(col=0; col<4; col++){
        for(row=0; row<4; row++){
            printf("Set a number for col %d row %d\n",col+1,row+1);
            scanf("%d", &puzzle[col][row]);
        }
    }
}



void setNumbers(){
    
    //Her satırda hangi sayılar var kontrol edip o satır için boş yerlere gelebilecek sayı kümesinden o satırda bulunan sayıları çıkartıyor
    for(col=0; col<4; col++){
        for(row=0; row<4; row++){
            int length= sizeof(numbers[col][row]) / sizeof(int);
            for(num=1; num<5; num++){
                for(int i=0 ; i< length ; i++){
                    if(numbers[col][row]==num){
                        for(int j=i; j<(length-1); j++)
                            numbers[col][row][j] = numbers[col][row][j+1];
                            i--;
                            length--;
                    }                
                }
            }    
        }
    }

    //Her sütunda hangi sayılar var kontrol edip o sütun için boş yerlere gelebilecek sayı kümesinden o sütunda bulunan sayıları çıkartıyor
    for(row=0; row<4; row++){
        for(col=0; col<4; col++){
            int length= sizeof(numbers[col][row]) / sizeof(int);
            for(num=1; num<5; num++){
                for(int a=0 ; a< length ; a++){
                    if(numbers[col][row]==num){
                        for(int b=a; b<(length-1); b++)
                            numbers[col][row][b] = numbers[col][row][b+1];
                            a--;
                            length--;
                    }                
                }
            }    
        }
    }
}


//Tek sayı yazma şansımız olan boşlukları bu sayılarla dolduruyoruz
void solveSudoku(){  
     
    for(col=0; col<4; col++){
        for(row=0; row<4; row++){
            if(puzzle[col][row]==0 && sizeof(numbers[col][row]) / sizeof(int)==1){
                puzzle[col][row]= numbers[col][row][0];
            }
        }
    }
}

//Çözülmüş sudokuyu yazdırma işlemi
void printSudoku(){
    for(col=0; col<4; col++){
        for(row=0; row<4; row++){
        printf("%d ",puzzle[col][row]);
        }
        printf("\n");
    }
}


int main()
{
    createSudoku();
    setNumbers();
    solveSudoku();
    printSudoku();

    return 0;
}

//Erkan Tiryakioğlu
