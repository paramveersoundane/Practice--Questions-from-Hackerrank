#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
/* *Ways to give a check (chess.c)
Sample Input.

2
########
#k#P####
########
########
########
########
#K######
########
########
######P#
####k###
########
########
########
####K###
########
Constraints:
->There are at most 4 pieces of each color on the board
->Each player has exactly one King and the given position on the board is a valid chess position assuming that it's White's move
->It is guaranteed that White has exactly one Pawn in the 7th rank that can be promoted in a single move

*/
int waysToGiveACheck(char board[8][9]) {
    int check=0,l,i,j,c=1,m=0,n=0;
    int N[][2]={{2,1},{1,2},{2,-1},{1,-2}};
    int B[][2]={{1,1},{2,2},{3,3},{4,4},{5,5},{6,6},{7,7},{1,-1},{2,-2},{3,-3},{4,-4},{5,-5},{6,-6},{7,-7}};
    int R[][2]={{1,0},{2,0},{3,0},{4,0},{5,0},{6,0},{7,0}, {0,1},{0,2},{0,3},{0,4},{0,5},{0,6},{0,7}, {0,-1},{0,-2},{0,-3},{0,-4},{0,-5},{0,-6},{0,-7}};
    while(c<9){
       // printf("%c : %d\n",board[1][c],c);
        if(board[1][c]=='P' && c<=8 && c>0){
            l=c;
           
        }
        c++;
    }
    board[1][l]='#';
   // printf("%c",board[1][8]);
    //Knight promotion
    i=0;
    j=l;
    c=0;
  // printf("k is 0 and l is %d \n",l);
    while(c<4 ){

        i=i+N[c][0];
        j=j+N[c][1];
       // printf("i is %d and j is %d ,N[%d][0] is %d,N[%d][1] is %d \n",i,j,c,N[c][0],c,N[c][1]);
        if(board[i][j]=='k' && i<=7 && i>=0 && j<=8 && j>0){
           // printf("i %d j %d char %c",i,j,board[i][j]);
            return 1;

        }
        c++;
        i=0;
        j=l;
    }

    //bishop promotion
    i=0;
    j=l;
    c=0;
    while(c<14){


        i=i+ B[c][0];
        j=j+ B[c][1] ;
        //printf("i is %d and j is %d ,N[%d][0] is %d,N[%d][1] is %d \n",i,j,c,N[c][0],c,N[c][1]);

        if(board[i][j]=='k' && i<=7 && i>=0 && j<=8 && j>0){
            m=i;
            n=j;

          //  printf("m=%d , n=%d \n",m,n);
            check=2;
        }
        i=0;
        j=l;
        if(m!=0 && n !=0){
        while(i!=m && j!=n){
            if(n<j){

              if(board[i][j] != '#' && board[i][j] != 'k' && board[i][j] != 'K' && i<=7 && i>=0 && j<=8 && j>0){
               return 0;
              }
              i++; j--;
            }
           if(n>j){
              // printf("i is %d , j is %d & m is %d , n is %d \n",i,j,m,n);
              if(board[i][j] != '#' && board[i][j] != 'k' && board[i][j] != 'K'&& i<=7 && i>=0 && j<=8 && j>0){
               return 0;
              } i++; j++;
           }
        }

        }
        c++;
    }
    // Rook promotion
    i=0;
    j=l;
    c=0;m=0;n=0;
    while(c<21){
         i=i+ R[c][0];
         j=j+ R[c][1];

        if(board[i][j]=='k' && i<=7 && i>=0 && j<=8 && j>0){
           // printf("i is %d and j is %d ,R[%d][0] is %d,R[%d][1] is %d \n",i,j,c,R[c][0],c,R[c][1]);
            m=i;
            n=j;
           // printf(" m is %d and n is %d \n",m,n);
            check=2;
        }
        i=0;
        j=l;
        if((m!=0) ||(n!=0)){
        while(i!=m || j!=n){
            if(m==i && j<n){
                // printf("i is %d , j is %d & m is %d , n is %d \n",i,j,m,n);
                if(board[i][j] != '#' && board[i][j] != 'K' && board[i][j] != 'k' && i<=7 && i>=0 && j<=8 && j>0){
                // printf("Here in return \n");
                 return 0;
                }j++;
             }
            else if(m==i && j>n){
                //  printf("i is %d , j is %d & m is %d , n is %d \n",i,j,m,n);
                 if(board[i][j] != '#' &&board[i][j] != 'K' && board[i][j] != 'k' && i<=7 && i>=0 && j<=8 && j>0){
                 return 0;
                 }j--;

             }


           else if(n==j){
             //  printf("i is %d , j is %d & m is %d , n is %d \n",i,j,m,n);
              if(board[i][j] != '#'  && board[i][j] != 'k' && i<=7 && i>=0 && j<=8 && j>0){
               return 0;
              } i++;
           }
         }
        }
        c++;
    }

     return check;

}

int main() {
    int t;
    scanf("%i", &t);
    for(int a0 = 0; a0 < t; a0++){
        char board[8][9];
        for (int board_i = 0; board_i < 8; board_i++) {
           for (int board_j = 0; board_j < 9; board_j++) {

              scanf("%c",&board[board_i][board_j]);
           }
        }
      /*  for(int i=0;i<8;i++)
        {
            for(int j=0;j<9;j++)
            {
                printf("board[%d][%d] : %c \n",i,j,board[i][j]);
            }
        }*/
        waysToGiveACheck(board);
        int result = waysToGiveACheck(board);
        //printf("result %d",result);
        printf("%d\n", result);
    }
    return 0;
}
