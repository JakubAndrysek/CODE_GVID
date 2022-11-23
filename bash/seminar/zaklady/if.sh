echo "Test IF"

# Testovani podminky if - prvni argument $1
if [ "$1" = "test" ]
then
  echo "Parametr je test - OK"
fi

# Testovani podminky v cyklu for
for parametr in "$@"
do
  if [ "$parametr" = "test" ]
  then
	echo "Parametr je test - v cyklu for"
	break
  fi
done

# Testovani podminky v cyklu for s pouzitim promenne
for parametr in "$@"
do
  if [ "$parametr" = "test" ]
  then
	test="ano"
	break
  fi
done

if [ "$test" = "ano" ]
then
  echo "Parametr je test - testovani promenne"
fi