#!/bin/bash

# pouziva regularni vyrazy

# sed -i 's/old/new/g' file
# s = substitute (nahradit)
# g = global (vsechny vyskyty)
# i = inplace (v souboru)


# nahradit vsechny vyskyty slova "a" slovem "A"
sed -e 's/a/A/' soubor.txt

# sed file

#!/bin/sed -Ef
# s/a/A/


/A.*/ { # radky zacinajici na A
	s/b/B/ # nahradit b za B
	s/c/C/ # nahradit c za C
}

