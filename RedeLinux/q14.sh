#!/bin/bash
DOWNLINK='http://distro.ibiblio.org/puppylinux/puppy-4.3.1/pup-431.iso'
DOWNPATH='$HOME/Downloads/'
FILENAME=$(basename "$DOWNLINK")
echo "Image downloader and installer"
echo "==> USE AT YOUR OWN RISK! <=="
echo ""
sleep 3
echo "Starting ISO download..."
wget $DOWNLINK -P $HOME/Downloads
cd $HOME/Downloads/
echo ""
echo "Now, type the device name of the pendrive, ex: sdb"
sleep 1	
lsblk
echo "Type the name of your pendrive and press [ENTER]: "
read dname
echo "The device selected is $dname. Proceed with script (y / n): "
read ans
if [ $ans = "n" ]
then
	exit
fi
echo ""
echo "Unmounting device /dev/$dname..."
sudo umount /dev/$dname
echo ""
echo "Writing iso to device /dev/$dname..."
sudo dd if=$(pwd)/$FILENAME of=/dev/$dname bs=4M && sync
echo "Finished writing"

