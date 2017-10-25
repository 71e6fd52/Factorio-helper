#!/bin/zsh

[[ "$VERBOSE" ]] && set -x

[[ "$install" ]] && output="$install"
[[ "$installdir" ]] && output="$installdir"
[[ "$INSTALLDIR" ]] && output="$INSTALLDIR"
[[ "$OUTPUT" ]] && output="$OUTPUT"
[[ "$DESTDIR" ]] && output="$DESTDIR"
[[ "$output" ]] || output=/usr/local

lib="$output/lib/factorio-helper"
bin="$lib/bin"
xmake install "--installdir=$lib" --root $VERBOSE
install -d "$output/bin"
install -d "$bin"
install -d "$output/share/zsh/site-functions"

install -m755 _factorio-helper "$output/share/zsh/site-functions"
install -m755 src/factorio-helper "$output/bin"

files=(
  add
  change
  delete
  download
  download.file
  download.git
  init
  list
  passwd
  pull
  push
  update
)
for file in $files
do
  install -m755 src/$file "$bin"
done
