//link-->   https://leetcode.com/problems/valid-sudoku/
//Level: Medium 
function isValid (arr) {
    const flags = new Map();
    for(let i = 0; i < arr.length; i++){
        const el = arr[i];
        
        if(el === '.'){
            continue;
        }
        if(flags.has(el)){ //ya esta agregado
            return false;
        }
        else{
            flags.set(el,true);
        }
    }
    return true;
}
function getRow(board, i){
    return board[i];
}

function getColumn(board,i){
    return board.map(row => row[i]);
}

function getBox(board,i){
    const initialRow = Math.floor(i/3) * 3;
    const initialColumn =  (i % 3) * 3;
    
    const box = [];
    for(let i = initialRow; i < initialRow +3 ; i++){
        for(let j = initialColumn; j < initialColumn + 3; j++){
            box.push(board[i][j]);
        }
    }
    
    return box;
}

var isValidSudoku = function(board){
    //validate rows
    for(let i=0; i<9; i++){
        const row = getRow(board, i);
        if(!isValid(row)){
            return false;
        }
    }

    // validate columns
    for(let i=0; i<9; i++){
        const column = getColumn(board,i);
        if(!isValid(column)){
            return false;
        }
    }

    //validate boxes
    for(let i = 0; i < 9; i++){
        const box = getBox(board, i);
        if(!isValid(box)){
            return false;
        }
    }
    return true;
}