#! /bin/bash
CURRENT_DIRECTORY="$(dirname "${0}")"

CPU_LIMIT=${1:-50}
RAM_LIMIT=${2:-5242880}

echo "Step A: generate a unique ID (uuid)"
UUID=$(date | sha256sum | cut -f1 -d" ")

echo "Step B: create cgroups"
sudo mkdir /sys/fs/cgroup/{cpu,memory}/$UUID
echo $RAM_LIMIT | sudo tee /sys/fs/cgroup/memory/$UUID/memory.limit_in_bytes
echo 100 | sudo tee /sys/fs/cgroup/cpu/$UUID/cpu.cfs_period_us
echo $CPU_LIMIT | sudo tee /sys/fs/cgroup/cpu/$UUID/cpu.cfs_quota_us

echo "Step C: prepare the folder structure to be our chroot"
bash $CURRENT_DIRECTORY/new-filesystem.sh $UUID
cd $FILESYSTEM_NAME

echo "Step D: put the current process into the cgroups"
echo $$ | sudo tee /sys/fs/cgroup/{cpu,memory}/$UUID/tasks

echo "Step E: start our namespaced chroot container-ish: $UUID"
sudo unshare \
    --fork \
    --pid \
    chroot . \
    /bin/bash -c "mkdir -p /proc && /bin/mount -t proc proc /proc && exec /bin/bash"
