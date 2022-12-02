FULLNAME=`basename $1`

# NAME=`echo $FULLNAME | cut -d. -f1`
# EXT=`echo $FULLNAME | cut -d. -f2`

NAME=${FULLNAME%.*}
EXT=${FULLNAME##*.}