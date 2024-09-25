#include <stdbool.h>
#include <stdio.h>

void print4SquareInt(int array[][4]){
    for(int r = 0; r < 4; r++){
        for(int c = 0; c < 4; c++){
            printf("%4d", array[r][c]);
        }
        printf("\n");
    }
}

bool hasUniqueElements4Square(int array[][4]){
    int oneArray[16];
    int counter = 0;
    for(int r = 0; r < 4; r++){
        for(int c = 0; c < 4; c++){
            oneArray[counter] = array[r][c];
            counter++;
        }
    }
    for (int i = 0; i < 16; i++) {
        for (int j = i + 1; j < 16; j++) {
            if (oneArray[i] == oneArray[j]) {
                return false; 
            }
        }
    }
    //Had each one drawn out but consulted chat to find a more concise way, learned how the loop was beneficial
        
    return true;
    
}

bool isMagic4Square(int arrayA[][4]){
    int magicNum = arrayA[0][0] + arrayA[0][1] + arrayA[0][2] + arrayA[0][3];
    int colSum = 0;
    int rowSum = 0;
    if (hasUniqueElements4Square(arrayA) == true){
        for(int r = 0; r < 4; r++){
            rowSum = 0;
            for(int c = 0; c < 4; c++){
                rowSum += arrayA[r][c];
            }
            if (rowSum != magicNum){
                return false;
            }
        }
        for(int c = 0; c < 4; c++){
            colSum = 0;
            for(int r = 0; r < 4; r++){
                colSum += arrayA[r][c];
            }
            if (colSum != magicNum){
                return false;
            }
        }
        int dia1 = arrayA[0][0] + arrayA[1][1] + arrayA[2][2] + arrayA[3][3];
        int dia2 = arrayA[0][3] + arrayA[1][2] + arrayA[2][1] + arrayA[3][0];

        if (dia1 != magicNum || dia2 != magicNum) {
            return false;
        }
    }
    else{
        return false;
    }
    return true;
   
}
//used chat gpt to help me debug. I learned how the return works allowing me to remove redundancy. 
//it also caught little mistakes such as the need to set colsum to 0. 

/*char penteWinner(char board[19][19], int row, int col){
    for(int i = 0; i < 5; i++){
        int counter = 0;
        if(board[row][col] == board[row+i][col]){
            counter++;
        }
        else{
            i = 5;
            return ' ';
        } 
    
    }

    for(int i = 0; i < 5; i++){
        int counter = 0;
        if(board[row][col] == board[row-i][col]){
            counter++;
        }
        else{
            i = 5;
            return ' ';
        }
    }
    for(int i = 0; i < 5; i++){
        int counter = 0;
        if(board[row][col] == board[row-i][col-1]){
            counter++;
        }
        else{
            i = 5;
            return ' ';
        }
    }
    for(int i = 0; i < 5; i++){
        int counter = 0;
        if(board[row][col] == board[row][col+1]){
            counter++;
        }
        else{
            i = 5;
            return ' ';
        }
    }
    return 'w';
}
*/

char penteWinner(char board[19][19], int row, int col) {
    char player = board[row][col];
    if (player == ' ') return ' '; // No winner if the position is empty

    // Directions: (dx, dy)
    int directions[4][2] = {
        {1, 0},  // Vertical down
        {0, 1},  // Horizontal right
        {1, 1},  // Diagonal down-right
        {1, -1}   // Diagonal down-left
    };

    for (int d = 0; d < 4; d++) {
        int dx = directions[d][0];
        int dy = directions[d][1];
        int counter = 1; // Start with the current piece

        // Check in the positive direction
        for (int i = 1; i < 5; i++) {
            int newRow = row + i * dx;
            int newCol = col + i * dy;

            // Check boundaries
            if (newRow >= 0 && newRow < 19 && newCol >= 0 && newCol < 19) {
                if (board[newRow][newCol] == player) {
                    counter++;
                } else {
                    break;
                }
            } else {
                break;
            }
        }

        // Check in the negative direction
        for (int i = 1; i < 5; i++) {
            int newRow = row - i * dx;
            int newCol = col - i * dy;

            // Check boundaries
            if (newRow >= 0 && newRow < 19 && newCol >= 0 && newCol < 19) {
                if (board[newRow][newCol] == player) {
                    counter++;
                } else {
                    break;
                }
            } else {
                break;
            }
        }

        // Check if we have a winner
        if (counter >= 5) {
            return player; // Return the winning player ('X' or 'O')
        }
    }

    return ' '; // No winner
}


// the first is my copy
//the second is how chat told me to fix it
//i looked at the chat version to see where i went wrong
//I understand that I also needed to check diagonals and if i'm on the edge
// I decided my time would be better spend finishing the pex
