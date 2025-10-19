package core

import "fmt"

func PrintBraille(bits [8]int) {
	fmt.Print("\033[H\033[2J")
	for i := 0; i < 8; i += 2 {
		if bits[i] == 0 && bits[i+1] == 0 {
			fmt.Println("  ")
		} else if bits[i] == 0 && bits[i+1] == 1 {
			fmt.Println(" █")
		} else if bits[i] == 1 && bits[i+1] == 0 {
			fmt.Println("█ ")
		} else if bits[i] == 1 && bits[i+1] == 1 {
			fmt.Println("██")
		}
	}
}

