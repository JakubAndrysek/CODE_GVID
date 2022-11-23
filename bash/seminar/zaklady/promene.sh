#!/bin/bash

for param in $*; do
    echo "para: $param"
done

function par
{
    echo "Parametry funkce"
    echo "nulty parametr:
    $0"
}


function pozdrav 
{
    jmeno=$1
    prijmeni=$2


    echo "Ahoj $jmeno $prijmeni"
}

par "Toto jsou argumenty"

pozdrav Jakube Andrysku