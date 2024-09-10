package main

import (
	"fmt"
	"os"
)

func main() {
	i := os.Args[1:]
	// fmt.Println(len(i))

	for f := 0; f < len(i)-1; f++ {
		// fmt.Println(i[f])

		for fm := 0; fm < len(i)-1; fm++ {
			// fmt.Println(i[fm])
			if i[fm] > i[fm+1] {
				i[fm], i[fm+1] = i[fm+1], i[fm]
			}
		}
	}
	fmt.Println(i)
}
