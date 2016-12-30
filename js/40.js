/**
 * @param {number[]} candidates
 * @param {number} target
 * @return {number[][]}
 */
var combinationSum2 = function (candidates, target) {
  let ret = [], hs = new Set()
  let dfs = (dep, x, xs) => {
    if (x === 0) {
      let t = Object.assign([], xs)
      let ts = t.sort((a,b)=>a-b)+''
      if(hs.has(ts)) return 
      hs.add(ts)
      ret.push(t)
      return
    }
    for (let i = dep; i < candidates.length; ++i) {
      if (x - candidates[i] >= 0) {
        xs.push(candidates[i])
        dfs(i + 1, x - candidates[i], xs)
        xs.pop()
      }
    }
  }
  dfs(0, target, [])
  return ret
};