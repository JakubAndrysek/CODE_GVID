#!/usr/bin/sed -Ef

# změň na HTML začátek tabulky
s/^!table/<table border="1">/g

# změň na HTML konec tabulky
s/^!!table/<\/table>/g

# pokud řádek nezačíná komentářem, nebo mezerou, provedu následující
/^[^\ \#]/ {
	# zpracuj řádek ve správném formátu do html
	s/([^,]*),([^,]*),([^,]*),([^,]*),(.*)/<tr><td>\1<\/td><td>\2<\/td><td>\3<\/td><td>\4<\/td><td>\5<\/td><\/tr>/g
	# změň znak @ na html entitu
	s/@/\&commat;/g
}

# uprav řádky začínající na # na komentáře
s/^\#(.*)/<!-- \1 -->/g