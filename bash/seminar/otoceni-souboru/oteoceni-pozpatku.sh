# #!/bin/bash

# echo stream input
# cat

# Solution 1
# echo stream input reversed
rev | tac


# Solution 2
# read stream by lines and reverse them
# tac | while read line; do
# 	echo $line | rev
# done


# Solution 3
# read stream by lines and print line number
# tac | while read line; do
# 	echo $line | rev
# done | nl