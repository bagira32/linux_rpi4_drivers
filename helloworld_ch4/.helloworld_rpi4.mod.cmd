savedcmd_/home/bagira/linux_rpi4_drivers/helloworld_ch4/helloworld_rpi4.mod := printf '%s\n'   helloworld_rpi4.o | awk '!x[$$0]++ { print("/home/bagira/linux_rpi4_drivers/helloworld_ch4/"$$0) }' > /home/bagira/linux_rpi4_drivers/helloworld_ch4/helloworld_rpi4.mod
