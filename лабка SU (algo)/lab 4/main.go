package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)

	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}

	maxLen := 1
	currentLen := 1
	left := 0
	right := 0
	start := 0

	for i := 1; i < n; i++ {
		if a[i] == a[i-1] {
			currentLen++
		} else {
			if currentLen > maxLen {
				maxLen = currentLen
				left = start
				right = i - 1
			}
			start = i
			currentLen = 1
		}
	}

	// Проверяем последний отрезок
	if currentLen > maxLen {
		maxLen = currentLen
		left = start
		right = n - 1
	}

	fmt.Println(maxLen)
	fmt.Println(left+1, right+1) // Выводим в формате 1-индексации
}
