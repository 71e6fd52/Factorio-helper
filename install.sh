#!/bin/bash
if [ ${output}x == x ]
then
	output=/usr/local
fi
share=$output/share/factorio-helper
bin=$share/bin
xmake install --installdir=$share --root
install -d $output/bin
install -d $bin
install -d $output/share/zsh/site-functions
install -m755 src/factorio-helper $output/bin
install -m755 src/add $bin
install -m755 src/change $bin
install -m755 src/download $bin
install -m755 src/init $bin
install -m755 src/list $bin
install -m755 src/passwd $bin
install -m755 src/pull $bin
install -m755 src/push $bin
install -m755 src/update $bin
install -m755 _factorio-helper $output/share/zsh/site-functions
