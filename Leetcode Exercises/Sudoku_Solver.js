//link: https://leetcode.com/problems/sudoku-solver/
/*
Level: hard
 */
/**
 * @param {character[][]} board
 * @return {void} Do not return anything, modify board in-place instead.
 */
 const VALID_VALUES = ['1', '2', '3', '4', '5', '6', '7', '8','9'];
 const EMPTY_VALUE=".";
 const BOARD_SIZE = 9;
 
 var solveSudoku = function(board) {
     solve(board,0,0);
 };
 
 
 function isValidInBoard (board, row, col,value ) {
     //value is not in row already
     for(let i = 0; i <BOARD_SIZE; i++){
       if(value === board[row][i]){
         return false;
       }
     }
     //value is not in column already
     for(let i=0; i < BOARD_SIZE; i++){
       if(value === board[i][col]){
         return false;
       }
     }
     //value is not in box already
     const boxInitialRow = Math.floor(row / 3) *3;
     const boxInitialColumn = Math.floor(col / 3) *3;
     for(let i = boxInitialRow; i< boxInitialRow +3; i++){
       for(let j = boxInitialColumn; j < boxInitialColumn+3 ; j++){
         if(value === board[i][j]){
           return false;
         }
       }
      }
     return true; // I walked through the whole possibilities, so the value is valid
 }
 function solve (board, row, col){
   if(row === BOARD_SIZE){ //base case , the board has finished
     return true;
   }
   if(col === BOARD_SIZE){ // if I complete the columns, so I have to move to the next row
     return solve(board, row+1, 0);
   }
   if(board[row][col] !== EMPTY_VALUE){ //in the case that the cell I'm looking at is a "." I must continue to the next cell and don't change it
     return solve(board, row, col +1);
   }
   
   //try all values in this cell
   for(let i = 0; i < VALID_VALUES.length; i++){// i walk throught the length
       
       
     if(!isValidInBoard (board, row, col , VALID_VALUES[i])){
       continue; // if this value is already in the board, so continue to the next step of loop
         
     }
     
     board[row][col] = VALID_VALUES[i];
     
     const isValid = solve (board , row, col +1)
     if(isValid){
         return true; 
     }
     board[row][col] = EMPTY_VALUE;
   }
   return false;
 }
 