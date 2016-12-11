func _3(a int, b int) int {
    if a == b {
        return 1
    }
    return 0
}
var dp [][]int
func f(s string, p string, i int, j int) int {
    if i > len(s) || j > len(p) {
        return 0
    }
    if dp[i][j] != -1 {
        return dp[i][j]
    }
    if j == len(p) {
        dp[i][j] = _3(i, len(s))
        return dp[i][j]
    }
   if j+1 == len(p) || p[j+1] != '*' {
       if i < len(s) && (s[i] == p[j] || p[j] == '.') {
           dp[i][j] = f(s, p, i+1, j+1)
           return dp[i][j]
       }
   } 

   if j+1 < len(p) && p[j+1] == '*' {
       if f(s, p, i, j+2) == 1 {
           dp[i][j] = 1
           return 1
       }
       if i < len(s) && (s[i] == p[j] || p[j] == '.') {
           if f(s, p, i+1, j) == 1 {
               dp[i][j] = 1
               return 1
           }
       }
   }
   dp[i][j] = 0
   return 0
}

func isMatch(s string, p string) bool {
    dp = [][]int{}
    for i:=0; i<=len(s);i++ {
        t := []int{}
        for j:=0; j<=len(p);j++ {
            t = append(t, -1)
        }
        dp = append(dp, t)
    }
    return f(s, p, 0, 0) == 1
}