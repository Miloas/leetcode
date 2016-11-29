func reverse_s(s string) string {
	chars := []rune(s)
	for i, j := 0, len(chars)-1; i < j; i, j = i+1, j-1 {
		chars[i], chars[j] = chars[j], chars[i]
	}
	return string(chars)
}

func reverse(x int) int {
    var ret int64
    if x > 0 {
        ret, _ = strconv.ParseInt(reverse_s(strconv.Itoa(x)), 10, 64)
    } else {
        ret, _ = strconv.ParseInt(reverse_s(strconv.Itoa(x)[1:]), 10, 64)
        ret = -ret
    }
    if ret > 0x7fffffff || ret <= -0x80000000 {
        return 0
    }
    return int(ret)
}