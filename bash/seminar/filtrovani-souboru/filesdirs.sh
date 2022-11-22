#! /bin/bash

# filesdirs.sh -f | -d [-h] [-hid]

# -f - vypíše seznam souborů aktuálního adresáře
# -d - vypíše seznam podadresářů aktuálního adresáře
# -h - (nepovinný) vypíše nápovědu
# -hid - (nepovinný) vypíše i skryté soubory nebo adresáře

function vypis_napovedu {
	echo "filesdirs.sh -f | -d [-h] [-hid]"
	echo "-f - vypíše seznam souborů aktuálního adresáře"
	echo "-d - vypíše seznam podadresářů aktuálního adresáře"
	echo "-h - (nepovinný) vypíše nápovědu"
	echo "-hid - (nepinný) vypíše i skryté soubory nebo adresáře"
}

# Vypis souboru
function vypis_soubory {
	if [ "$1" = true ]
	then
		for soubor in .* *
		do
			if [ -f "$soubor" ]
			then
				echo "$soubor"
			fi
		done
	else
		for soubor in *
		do
			if [ -f "$soubor" ]
			then
				echo "$soubor"
			fi
		done
	fi
}

function vypis_adresare {
	if [ "$1" = true ]
	then
		for adresar in .* *
		do
			if [ -d "$adresar" ]
			then
				echo "$adresar"
			fi
		done
	else
		for adresar in *
		do
			if [ -d "$adresar" ]
			then
				echo "$adresar"
			fi
		done
	fi
}


# no arguments
if [ $# -eq 0 ]
then
	vypis_napovedu
	exit 1
fi

# -h argument in any position
for parametr in "$@"
do
  if [ "$parametr" = "-h" ]
  then
	vypis_napovedu
	exit 1
  fi
done

# -hid argument in any position
for parametr in "$@"
do
  if [ "$parametr" = "-hid" ]
  then
	hid=true
  fi
done

for parametr in "$@"
do
  if [ "$parametr" = "-f" ]
  then
	vypis_soubory "$hid"
	exit 0
  elif [ "$parametr" = "-d" ]
  then
	vypis_adresare "$hid"
	exit 0
  fi
done

echo "Neplatny parametr"
vypis_napovedu
exit 1
