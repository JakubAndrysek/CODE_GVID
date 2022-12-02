#!/bin/bash

cat <<< "Ahoj svete"


tac << END
jedna
dva
tri
ctyri
END

# vnoreny skript
{
    echo Ahoj
} > /dev/stderr