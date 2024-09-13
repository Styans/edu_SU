package main

import "fmt"

func main() {

	// i := []int{4, 3, 1, 3, 3}
	j := []int{1, 2, 3, 4, 5}
	if !FindAll(Sort(j)) {
		fmt.Println("NO")
	} else {
		fmt.Println("YES")
	}

}

func Sort(a []int) []int {
	for i := 0; i < len(a); i++ {
		for j := 1; j < len(a); j++ {
			if a[j] < a[j-1] {
				buf := a[j]
				a[j] = a[j-1]
				a[j-1] = buf
			}
		}
	}
	return a
}

func FindAll(a []int) bool {
	for s, i := range a {
		for t, j := range a {
			if s != t {
				if i == j {
					return true
				}
			}
		}
	}
	return false
}
