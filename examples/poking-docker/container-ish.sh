#! /bin/bash
current_dir="$(dirname "${0}")"
FILESYSTEM_NAME=${1:-container-attempt-2}

# Step 1: execute our familiar new-filesystem script
bash $current_dir/new-filesystem.sh $FILESYSTEM_NAME
cd $FILESYSTEM_NAME

# Step 2: mount /proc
mkdir -p proc
mount --rbind /proc proc

# Step 3: createa new pid namespace, and start a chrooted bash session
unshare \
    --pid \
    --fork \
    chroot . \
    /bin/bash
