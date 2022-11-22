echo "Vypis parametry prikazove radky"

# Vypis parametru prikazove radky
echo "Pocet parametru: $#"
echo "Parametry: $*"
echo "Parametry: $@"
echo "Posledni parametr: ${!#}"

# Vypis parametru prikazove radky pomoci cyklu
echo "Vypis parametru pomoci cyklu"
for parametr in "$@"
do
  echo "Parametr: $parametr"
done