picuntu-3.0.8-alok
==================
iMito MX1
MT5931 - Test kernel

use fda_config as .config to build kernel Image (This has fixed GPIO for iMito)

cd drivers/staging/mtk_5931/

export KDIR=<PathtoKernel>

export ARCH=arm

export CROSS_COMPILE=arm-linux-gnueabi-

make 

this will compile wlan_mt6620.ko

following the test after insmod wlan_mt6620.ko  

place /system/etc/firmware/WIFI_RAM_CODE

-------------------------------------------------------
TRIED also with newer WIFI_RAM_CODE, same result :(
with this kernel from time to time firmware load fails,
seems a timing problem after Wifi device reset.
in this case just reboot.
-------------------------------------------------------
