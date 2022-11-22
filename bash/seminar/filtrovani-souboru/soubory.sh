

# Vypis viditelne soubory v adresari
echo "Vypis viditelne soubory v adresari"
for soubor in *
do
  if [ -f "$soubor" ]
  then
	echo "Viditelny soubor: $soubor"
  fi
done


# Vypis skryte soubory v adresari
echo "\nVypis skryte soubory v adresari"
for soubor in .*
do
  if [ -f "$soubor" ]
  then
	echo "Skryty soubor: $soubor"
  fi
done



# Vypis skryte i viditelne soubory v adresari
echo "\nVypis skryte i viditelne soubory v adresari"
for soubor in .* *
do
  if [ -f "$soubor" ]
  then
	echo "Jakykoliv soubor: $soubor"
  fi
done



# Vypis viditelne adresare v adresari
echo "\nVypis viditelne adresare v adresari"
for adresar in *
do
  if [ -d "$adresar" ]
  then
	echo "Viditelny adresar: $adresar"
  fi
done

# Vypis skryte adresare v adresari
echo "\nVypis skryte adresare v adresari"
for adresar in .*
do
  if [ -d "$adresar" ]
  then
	echo "Skryty adresar: $adresar"
  fi
done



# Vypis skryte i viditelne adresare v adresari
echo "\nVypis skryte i viditelne adresare v adresari"
for adresar in .* *
do
  if [ -d "$adresar" ]
  then
	echo "Jakykoliv adresar: $adresar"
  fi
done