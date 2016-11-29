func convert(s string, numRows int) string {
    if numRows == 1 {
        return s
    }
    ret := []byte{}
    for i:=0; i < numRows; i++{
        for j:=i; j < len(s); j += 2*numRows-2 {
            ret = append(ret, s[j])
            if i > 0 && i < numRows-1 && j+(numRows-i-1)*2 < len(s) {
                ret = append(ret, s[j+(numRows-i-1)*2])
            }
        }
    }
    return string(ret)
}