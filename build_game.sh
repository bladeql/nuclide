#!/bin/sh
set -e
SCRPATH="$( cd "$( dirname $(readlink -nf $0) )" && pwd )"
PATH="$SCRPATH"/bin:"$PATH"

if [ -f "$SCRPATH"/bin/fteqcc ]; then
	export OLDDIR=$(pwd)
	find "$SCRPATH" -name Makefile | grep 'src\/Makefile' | grep -v engine | while read MFILE_N; do
		cd $(dirname $MFILE_N)
		make
		cd ..
		export GAMEDIR=$(basename $PWD)
		cd $OLDDIR
		./make_mapdef.sh $GAMEDIR
	done;
else
	printf "FTEQCC compiler is not present, please run build_engine.sh\n"
fi
