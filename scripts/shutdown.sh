#!/usr/bin/env bash

# Save this file in /storage/.config/shutdown.sh on OpenElec

case "$1" in
  halt)
    # your commands here
    /usr/bin/curl "http://192.168.38.110:8080/json.htm?type=command&param=switchscene&idx=4&switchcmd=Off"
    ;;
  poweroff)
    # your commands here
    /usr/bin/curl "http://192.168.38.110:8080/json.htm?type=command&param=switchscene&idx=4&switchcmd=Off"
    ;;
  reboot)
    # your commands here
    ;;
  *)
    # your commands here
    ;;
esac