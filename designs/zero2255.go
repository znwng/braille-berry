package designs

import (
	"braille/core"
	"time"
)

func Zero2255(delay time.Duration) {
	for i := range 256 {
		core.PrintBraille(core.GetBinary(i))
		time.Sleep(delay)
	}
}

func Loading(delay time.Duration, duration time.Duration) {
	set := [8][8]int{
		{1, 1, 1, 1, 1, 1, 1, 0},
		{1, 1, 1, 1, 1, 0, 1, 1},
		{1, 1, 1, 0, 1, 1, 1, 1},
		{1, 0, 1, 1, 1, 1, 1, 1},
		{0, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 0, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 0, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 0, 1},
	}

	stop := time.After(duration)

Loop:
	for {
		select {
		case <-stop:
			break Loop
		default:
			for _, i := range set {
				core.PrintBraille(i)
				time.Sleep(delay)
			}
		}
	}
}

