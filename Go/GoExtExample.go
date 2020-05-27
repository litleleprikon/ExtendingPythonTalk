package main

// #cgo pkg-config: python3
// #include <Python.h>
import "C"
import "fmt"

// SieveOfEratosthenes calculates prime numbers
//export SieveOfEratosthenes
func SieveOfEratosthenes(n int, result *[]int) {
	integers := make([]bool, n+1)
	for i := 2; i < n+1; i++ {
		integers[i] = true
	}

	for p := 2; p*p <= n; p++ {
		if integers[p] == true {
			for i := p * 2; i <= n; i += p {
				integers[i] = false
			}
		}
	}

	for p := 2; p <= n; p++ {
		if integers[p] == true {
			*result = append(*result, p)
		}
	}
}

func main() {
	result := make([]int, 0)
	SieveOfEratosthenes(1000, &result)
	fmt.Println()
}
