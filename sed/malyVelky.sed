#!/bin/sed -Ef

/A.*/ { # radky zacinajici na A
	s/b/B/g # nahradit b za B
	s/c/C/g # nahradit c za C
}