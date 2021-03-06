package main

import "fmt"

func twoSum(nums []int, target int) []int {
    m := make(map[int]int)
    for i, v := range nums {
        if _, ok := m[target-v]; ok {
            return []int{m[target-v], i}
        }
        m[v] = i
    }
    return []int{}
}

func main() {
    fmt.Println(twoSum([]int{0, 4, 3, 0}, 0))
}
