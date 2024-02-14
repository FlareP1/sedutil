#!/bin/sh
clear
#Set serial port to 115200
/bin/stty -F /dev/ttyS0 115200
#Call PBA in background on serial S0
/sbin/linuxpba <dev/ttyS0 >dev/ttyS0 2>/dev/null &
#Call PBA in background on tty 
/sbin/linuxpba <dev/tty0 >dev/tty0 2>/dev/null &
#Sleep forever (in effect 7days)
#waiting for the previous pba calls to unlock drives and call reboot
/bin/sleep 7d 
#/sbin/linuxpba 2>/tmp/pbaerror.log
