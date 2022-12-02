function List
{
	for i in * ; do
		if [ -d $i ]; then
		 ( cd $i
		   List
		 )
		else
		#  echo `pwd` / $i
		 echo $i
		fi
	done
}

List