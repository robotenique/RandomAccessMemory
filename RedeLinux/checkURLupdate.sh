#!/bin/bash
echo "==> Check if a website was updated. USAGE: ./checkWebsite.sh  <URL>"
echo ""
sudo apt-get install notify-osd libnotify-bin
curl $1 -L --compressed -s > 00.html
cp 00.html 01.html
for (( ; ; )); do
    echo "Checking change..."
    mv 01.html 00.html 2> /dev/null
    curl $1 -L --compressed -s > 01.html
    CHGD="$(diff 01.html 00.html)"
    echo $CHGD
    if [ "0" != "${#CHGD}" ]; then
        notify-send REPORT "THE WEBSITE AT $url HAS CHANGED!!!"
    fi
    sleep 5
done
