func lengthOfLongestSubstring(s string) int {
    m := map[int]int{} 
    i :=0 
    j := 0 
    ret := 0
    for j < len(s) {
        if v, ok := m[int(s[j])]; !ok || v < i {
            if j - i + 1 > ret {
                ret = j - i + 1
            }
        } else {
            i = v + 1
        }
        m[int(s[j])] = j
        j = j + 1
    }
    return ret
}
