#!/bin/bash

seznam="Jablko Hruska Pomeranc Konec"

echo "Zadej cislo od 1 do $(echo $seznam | wc -w)"

select vyber in $seznam; do
    case $vyber in
        "Konec" )
            echo "Budu koncit"
            break
        ;;
        *)
            echo "Vybral jsi $vyber"
        ;;
    esac
done