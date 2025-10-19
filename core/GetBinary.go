package core

func GetBinary(b int) [8]int {
	var bits [8]int
	for i := 7; i >= 0; i-- {
		if b&(1<<uint(i)) != 0 {
			bits[7-i] = 1
		} else {
			bits[7-i] = 0
		}
	}
	return bits
}

