package main

import "fmt"

func fib(n int, mem map[int]int) int {
	if val, ok := mem[n]; ok {
		return val
	}
	mem[n] = fib(n-1, mem) + fib(n-2, mem)
	return mem[n]
}

func main() {
	var n int
	var mem = make(map[int]int)
	mem[0] = 1
	mem[1] = 1

	fmt.Scan(&n)
    fmt.Println(fib(n, mem))
}