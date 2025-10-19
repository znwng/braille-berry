package main

import (
	"braille/designs"
	"time"
)

func main() {
	designs.Loading(100 * time.Millisecond, 1<<63-1)
	designs.Zero2255(100 * time.Millisecond)

}

