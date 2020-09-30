#!/bin/bash

ADR_SABLONY=~/.local
ADR_CONFIG=~/.config/codeblocks

echo "Nastavení výchozí konfigurace programu Code::Blocks"
echo "Autor: David Martinek, GVID, 2019--2020"
echo "Pro Code::Blocks verze 20.03"


echo "Mám nainstalovat šablonu \"Školní projekt\" do adresáře $ADR_SABLONY/share/codeblocks?"
select odpoved in "Ano" "Ne"; do
    case $odpoved in
        Ano ) 
          echo "Instaluji šablonu"
          cp -r share $ADR_SABLONY
          break;;
        Ne )
          echo "Šablona instalována nebude."
          break;;
    esac
done

echo "Mám přepsat konfigurační soubor v $ADR_CONFIG?"
select odpoved in "Ano" "Ne"; do
    case $odpoved in
        Ano ) 
          echo "Přepisuji konfigurační soubor."
          cp default.conf $ADR_CONFIG/default.conf
          break;;
        Ne )
          echo "Konfigurační soubor přepsán nebude."
          break;;
    esac
done


