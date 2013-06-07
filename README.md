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
plase /system/etc/firmware/WIFI_RAM_CODE
-------------------------------------------------------
TRIED also with newer WIFI_RAM_CODE, same result :(
with this kernel from time to time firmware load fails,
seems a timing problem after Wifi device reset.
in this case just reboot.
-------------------------------------------------------
dmesg
    4.355293] camera 33-1-gc2035_front_2: RK Camera driver detached from camera1(gc2035_front_2)
[    4.856095] camera 33-1-gc2035_front_2: Probe gc2035_front_2 failed
[    9.044205] DWC_OTG: dwc_otg_hcd_connect_detect schedule delaywork, hprt 0x00001000, grfstatus 0x00000000
[    9.124331] DWC_OTG: dwc_otg_hcd_enable, disable host controller
[    9.124506] DWC_OTG: PortPower off
[   16.844151] DWC_OTG: ********vbus detect*********************************************
[   17.028917] DWC_OTG: ********soft connect!!!*****************************************
[   17.034925] DWC_OTG: USB SUSPEND
[   17.153409] DWC_OTG: USB RESET
[   17.266013] android_work: sent uevent USB_STATE=CONNECTED
[   17.269097] DWC_OTG: USB RESET
[   17.398772] android_usb gadget: high speed config #1: android
[   17.399513] android_work: sent uevent USB_STATE=CONFIGURED
[   21.484558] adbd (173): /proc/173/oom_adj is deprecated, please use /proc/173/oom_score_adj instead.
[   34.721381] initWlan
[   34.722767] rk29sdk_wifi_power: 0
[   34.923777] wifi shut off power
[   35.133934] rk29sdk_wifi_power: 1
[   35.249010] wifi turn on power
[   35.449098] rk29sdk_wifi_set_carddetect:1
[   35.449110] mmc1: slot status change detected(0-1)
[   35.449154] rk29_sdmmc_change_clk_div..1945..  newDiv=42, newCLK=294Khz [sdio]
[   35.644324] 
[   35.644348] /home/fede/picuntu/myrepo/picuntu-3.0.8-alok/drivers/mmc/core/core.c...1827..  ===== mmc_rescan Begin....[mmc1]
[   35.688536] 
[   35.688559] mmc_attach_sdio..800..  ===== Begin to identify card as SDIO-card. [mmc1]
[   35.721274] rk29_sdmmc_change_clk_div..1945..  newDiv=0, newCLK=24750Khz [sdio]
[   35.725885] mmc1: new high speed SDIO card at address 0001
[   35.728140] wireless_dev prWdev(0xed9bd600) allocated
[   35.728343] wiphy (0xed522120) allocated
[   35.728632] net_device prDev(0xedb1c000) allocated
[   35.731273] Open FW image: WIFI_RAM_CODE done
[   35.748618] Allocating 4096 bytes for COMMON MGMT MEMORY POOL.
[   35.748851] Virtual Address = f700d000 for COMMON MGMT MEMORY POOL.
[   35.749007] Allocating 11136 bytes for SW_RFB_T.
[   35.749201] Virtual Address = f7073000 for SW_RFB_T.
[   35.749332] Allocating 13312 bytes for MSDU_INFO_T.
[   35.749493] Virtual Address = f7077000 for MSDU_INFO_T.
[   35.874450] u4Value:2560
[   36.030709] Using embedded MAC address[wifi] wlan%d netif_carrier_off
[   36.033261] tx_thread starts running... 
[   36.035461] MAC address: 00:0c:e7:b0:29:63
[   36.043576] mmc_rescan_try_freq..1678..  ===== Initialize SDIO successfully. [mmc1]


root@(none):~# iwlist wlan0 scan
wlan0     Scan completed :
          Cell 01 - Address: 00:1E:2A:FD:C6:88
                    ESSID:"NETNI"
                    Frequency:2.447 GHz (Channel 8)
                    Mode:Managed
                    Signal level=-58 dBm  
                    Encryption key:off
                    Bit Rates:54 Mb/s
                    Extra:Rates (Mb/s): 1 2 5.5 11 6 9 12 18 24 36 48 54

[   36.043576] mmc_rescan_try_freq..1678..  ===== Initialize SDIO successfully. [mmc1]
[  251.072266] ioctl 8b0b
[  251.072456] -48940 CMD:0x8b0b
[  251.072988] ioctl 8b18
[  251.073142] -48940 CMD:0x8b18
[  251.324407] ioctl 8b19
[  251.324430] -48680 CMD:0x8b19
[  251.379773] NAF=0,0,0

iwconfig wlan0 essid NETNI
[  292.810005] ioctl 8b1a
[  292.810029] -7200 CMD:0x8b1a
[  292.810061] wext_set_essid: NETNI (5)
[  292.810179] set essid 0
[  292.824842] NAF=0,0,0
[  293.170676] ChReq net=0 token=1 b=1 c=8 s=0
[  293.172527] ChGrant net=0 token=1 ch=8 sco=0
[  300.164301] mmc_wait_for_req..267.. !!!!! wait for CMD53 timeout [mmc1]
[  300.164506] sdio_writesb() reports error: fffffffbHAL_PORT_WR access fail! 0x2c
[  300.164853] QM: Enter qmFlushStaTxQueues(0)
[  300.164977] QM: -STA[0]
[  300.165073] ChAbort net=0 token=1

iwconfig
lo        no wireless extensions.

sit0      no wireless extensions.

ip6tnl0   no wireless extensions.

wlan0     Disconnected  ESSID:""  
          Mode:Managed  Access Point: 00:00:00:00:05:40   Tx-Power=off   
          RTS thr=0 B   Fragment thr:off
          Encryption key:off
          Power Management period:2  
          Link Quality:0  Signal level:0  Noise level:0
          Rx invalid nwid:0  Rx invalid crypt:0  Rx invalid frag:0
          Tx excessive retries:0  Invalid misc:0   Missed beacon:0

octl 8b01
[  364.945092] 64940 CMD:0x8b01
[  364.945214] ioctl 8b03
[  364.945303] 64940 CMD:0x8b03
[  364.945409] ioctl 8b05
[  364.945494] 64940 CMD:0x8b05
[  364.945600] ioctl 8b2b
[  364.945685] 64940 CMD:0x8b2b
[  364.945913] ioctl 8b1b
[  364.946009] 64940 CMD:0x8b1b
[  364.946332] ioctl 8b07
[  364.946431] 64940 CMD:0x8b07
[  364.946669] ioctl 8b0b
[  364.946766] 64940 CMD:0x8b0b
[  364.947065] ioctl 8b15
[  364.947165] 64940 CMD:0x8b15
[  364.947276] ioctl 8b21
[  364.947363] 64940 CMD:0x8b21
[  364.947467] ioctl 8b2d
[  364.947551] 64940 CMD:0x8b2d
[  364.947710] ioctl 8b1d
[  364.947801] 64940 CMD:0x8b1d
[  364.947907] ioctl 8b27
[  364.947991] 64940 CMD:0x8b27
[  364.948095] ioctl 8b09
[  364.948177] 64940 CMD:0x8b09
[  364.948278] ioctl 8b29
[  364.948362] 64940 CMD:0x8b29
[  364.948463] ioctl 8b23
[  364.948547] 64940 CMD:0x8b23
[  364.948751] ioctl 8b25
[  364.948846] 64940 CMD:0x8b25


