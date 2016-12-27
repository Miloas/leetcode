/**
 * @param {character[][]} board
 * @return {void} Do not return anything, modify board in-place instead.
 */
var solveSudoku = function(board) {
  let isValid = (r, c, ch) => {
    for(let i = 0; i < 9; ++i) if(board[i][c] == ch) return false
    for(let i = 0; i < 9; ++i) if(board[r][i] == ch) return false
    for (let i = ((r / 3) | 0) * 3; i < ((r / 3 | 0) + 1) * 3; i++) {
      for (let j = ((c / 3) | 0) * 3; j < ((c / 3 | 0) + 1) * 3; j++) {
        if(board[i][j] == ch) return false
      }
    }
    return true
  }
  let solve = () => {
    for(let r = 0; r < 9; ++r)
    for(let c = 0; c < 9; ++c) {
      if(board[r][c] == '.') {
        for(let i = 1; i <= 9; ++i) if(isValid(r, c, i+'')) {
          board[r][c] = i+''
          if(solve()) return true
          board[r][c] = '.'
        }
        return false
      }
    }
    return true
  }
  solve()
};