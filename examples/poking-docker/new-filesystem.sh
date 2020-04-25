#! /bin/bash

set +x

export NEW_FILESYSTEM_ROOT=${1:-~/new_filesystem}
export TOOLS="bash ls ps touch rm"

echo "Step 1. Create a new folder"
mkdir $NEW_FILESYSTEM_ROOT

echo "Step 2. Copy some (very) minimal binaries"
for tool in $TOOLS; do
    cp -v --parents `which $tool` $NEW_FILESYSTEM_ROOT;
done

echo "Step 3. Copy over their libs"
echo -n > ~/.deps
for tool in $TOOLS; do
    ldd `which $tool` | egrep -o '(/usr)?/lib.*\.[0-9][0-9]?' >> ~/.deps
done
cp -v --parents `cat ~/.deps | sort | uniq | xargs` $NEW_FILESYSTEM_ROOT

echo "Done."
echo "To start, run: sudo chroot " $NEW_FILESYSTEM_ROOT
