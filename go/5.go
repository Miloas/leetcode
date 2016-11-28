package main

import "fmt"

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
func longestPalindrome(s string) string {
	n := len(s)*2 + 2
	p := make([]int, n, n*2)
	a := make([]byte, n, n*2)
	for i, j := 0, 1; i < len(s); i++ {
		a[j] = '.'
		j += 1
		a[j] = s[i]
		j += 1
	}
	a[n-1] = '.'
	for x, mx, i := 0, 0, 0; i < len(a); i++ {
		if i < mx && p[x*2-i] != mx-i {
			p[i] = min(p[x*2-i], mx-i)
		} else {
			x = i
			mx = max(mx, i)
			for mx < len(a) && 2*x-mx >= 0 && a[mx] == a[2*x-mx] {
				mx++
			}
			p[i] = mx - x
		}
	}
	x, v := 0, 0
	for i := 0; i < len(a); i++ {
		if p[i] > v {
			v = p[i]
			x = i
		}
	}
	return s[(x-v+1)/2 : (x-v+1)/2+v-1]
}
func main() {
	fmt.Println(longestPalindrome("cbbd"))
}
