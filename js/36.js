/**
 * @param {character[][]} board
 * @return {boolean}
 */
var isValidSudoku = function(board) {
    let valid = (row) => {
      let h = new Set()
      for(let i = 0; i < row.length; ++i) if(row[i]!='.') {
        if(h.has(row[i])) return false 
        h.add(row[i])
      }
      return true
    }
    let validR = (r) => {
      return valid(board[r]) 
    }
    let validC = (c) => {
      let column = [] 
      for(let i = 0; i < board.length; ++i) column.push(board[i][c])
      return valid(column)
    }
    let validSq = (ith) => {
      let x = ith / 3 | 0, y = ith % 3,
          sx = x * 3, sy = y * 3,
          ex = sx + 3, ey = sy + 3, sq = [] 
          for(let i = sx; i < ex; ++i)
          for(let j = sy; j < ey; ++j)
          sq.push(board[i][j])
          return valid(sq)
    }
    for(let i = 0; i < 9; ++i) {
      if(!validR(i)||!validC(i)||!validSq(i)) return false
    } 
    return true
};