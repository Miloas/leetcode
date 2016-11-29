func myAtoi(str string) int {
	s, op, ret := strings.Trim(str, " "), 1, 0
	for i:=0; i < len(s); {
		if s[i]=='-' || s[i]=='+' {
		   if s[i]=='-' {
			   op = -1
		   } else {
			   op = 1
		   } 
		   i += 1
		}
		for i < len(s) && s[i] >= '0' && s[i] <= '9' {
			ret = ret * 10 + int(s[i]) - '0'
			i += 1
			if ret * op  >= 0x7fffffff {
				return 0x7fffffff
			}
			if ret * op <= -0x80000000 {
				return -0x80000000
			}
		}
		return ret * op
	}
	return ret
}