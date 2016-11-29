func isPalindrome(x int) bool {
   if x < 0 {
       return false
   } 
   rx, tx := 0, x
   for tx > 0 {
       rx = rx * 10 + tx % 10
       tx /= 10
   }
   return rx == x
}