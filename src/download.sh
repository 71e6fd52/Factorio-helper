#!/bin/bash
mkdir $fac/mods -p
while read type
do
	read url
	read name
	basename=`echo $name | cut -d_ -f 1`
	oldname=`ls $fac/mods/ -1 | grep -E "^${basename}_"`
	echo $basename
	echo $url
	if [ $type == 'git' ]
	then
		if [ "${oldname}x" == "x" ]
		then
			git clone --depth 1 "https://github.com/$url.git" "$fac/mods/$name"
		else
			if [ "$oldname" != "$name" ]
			then
				mv "$fac/mods/$oldname" "$fac/mods/$name"
				cd "$fac/mods/$name"
				git pull origin
			fi
		fi
	elif [ $type == 'file' ]
	then
		name=`echo $url | cut -d/ -f 9`;
		if [ "${oldname}x" != "x" ]
		then
			if [ "$oldname" == "$name" ]
			then
				continue
			else
				rm "$fac/mods/${basename}_*"
			fi
		fi
		curl --location --cookie "${cookie}" \
         --continue-at - "$url" -o "$fac/mods/$name"
	fi
done
