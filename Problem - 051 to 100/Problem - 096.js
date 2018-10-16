let getUnsolvedPosition = (sudokuArray) => {
    for (let row = 0; row < 9; row++) 
        for (let col = 0; col < 9; col++) 
            if (sudokuArray[row][col] == 0) 
                return { row: row, col: col }; 
    return { row: -1, col: -1 };
}

let inRow = (sudokuArray, row, num) => {
    for (let col = 0; col < 9; col++) 
        if (sudokuArray[row][col] == num) 
            return true; 
    return false; 
}

let inCol = (sudokuArray, col, num) => {
    for (let row = 0; row < 9; row++) 
        if (sudokuArray[row][col] == num) 
            return true; 
    return false;
}

let inBox = (sudokuArray, startRow, startCol, num) => {
    for (let row = 0; row < 3; row++) 
        for (let col = 0; col < 3; col++) 
            if (sudokuArray[row + startRow][col + startCol] == num) 
                return true; 
    return false; 
}

let isCorrectPosition = (sudokuArray, row, col, num) => {
    return !inRow(sudokuArray, row, num) && !inCol(sudokuArray, col, num) && 
        !inBox(sudokuArray, row - row % 3 , col - col % 3, num);
}

let SolveSudoku = (sudokuArray) => {
    var unsolvedPosition = getUnsolvedPosition(sudokuArray);
    var row = unsolvedPosition.row;
    var col = unsolvedPosition.col;

    if (row == -1 && col == -1)
        return sudokuArray[0][0] * 100 + sudokuArray[0][1] * 10 + sudokuArray[0][2];
    
    for (let num = 1; num <= 9; num++) {
        if (isCorrectPosition(sudokuArray, row, col, num)) {
            sudokuArray[row][col] = num;

            let result = SolveSudoku(sudokuArray);
            if (result)
                return result;

            sudokuArray[row][col] = 0;
        }
    }
    return false;
}

let getDigitSumForSudoku = (sudoku) => {
    return SolveSudoku(sudoku.map((elem) => elem.split('').map((row) => parseInt(row))));
}

let getSplitStrings = () => {
    return new Array(Math.ceil(input.length / 9))
        .fill("")
        .map(() => input.splice(0, 9)
    );
}

let getDigitSum = () => {
    return getSplitStrings().map((elem) => getDigitSumForSudoku(elem));
}

let initialize = () => {
    document.getElementById("solution-container")
        .innerText = getDigitSum().reduce((a, b) => a + b).toString();
}
