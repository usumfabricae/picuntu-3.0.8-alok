/* arch/arm/mach-rk30/board-rk30-sdk-sdmmc.c
 *
 * Copyright (C) 2012 ROCKCHIP, Inc.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#ifdef CONFIG_SDMMC_RK29

#if !defined(CONFIG_SDMMC_RK29_OLD)	
static void rk29_sdmmc_gpio_open(int device_id, int on)
{
    switch(device_id)
    {
        case 0://mmc0
        {
            #ifdef CONFIG_SDMMC0_RK29
            if(on)
            {
                gpio_direction_output(GPIO3B_GPIO3B0,GPIO_HIGH);//set mmc0-clk to high
                gpio_direction_output(GPIO3B_GPIO3B1,GPIO_HIGH);// set mmc0-cmd to high.
                gpio_direction_output(GPIO3B_GPIO3B2,GPIO_HIGH);//set mmc0-data0 to high.
                gpio_direction_output(GPIO3B_GPIO3B3,GPIO_HIGH);//set mmc0-data1 to high.
                gpio_direction_output(GPIO3B_GPIO3B4,GPIO_HIGH);//set mmc0-data2 to high.
                gpio_direction_output(GPIO3B_GPIO3B5,GPIO_HIGH);//set mmc0-data3 to high.

                mdelay(30);
            }
            else
            {
                rk30_mux_api_set(GPIO3B0_SDMMC0CLKOUT_NAME, GPIO3B_GPIO3B0);
                gpio_request(RK30_PIN3_PB0, "mmc0-clk");
                gpio_direction_output(RK30_PIN3_PB0,GPIO_LOW);//set mmc0-clk to low.

                rk30_mux_api_set(GPIO3B1_SDMMC0CMD_NAME, GPIO3B_GPIO3B1);
                gpio_request(RK30_PIN3_PB1, "mmc0-cmd");
                gpio_direction_output(RK30_PIN3_PB1,GPIO_LOW);//set mmc0-cmd to low.

                rk30_mux_api_set(GPIO3B2_SDMMC0DATA0_NAME, GPIO3B_GPIO3B2);
                gpio_request(RK30_PIN3_PB2, "mmc0-data0");
                gpio_direction_output(RK30_PIN3_PB2,GPIO_LOW);//set mmc0-data0 to low.

                rk30_mux_api_set(GPIO3B3_SDMMC0DATA1_NAME, GPIO3B_GPIO3B3);
                gpio_request(RK30_PIN3_PB3, "mmc0-data1");
                gpio_direction_output(RK30_PIN3_PB3,GPIO_LOW);//set mmc0-data1 to low.

                rk30_mux_api_set(GPIO3B4_SDMMC0DATA2_NAME, GPIO3B_GPIO3B4);
                gpio_request(RK30_PIN3_PB4, "mmc0-data2");
                gpio_direction_output(RK30_PIN3_PB4,GPIO_LOW);//set mmc0-data2 to low.

                rk30_mux_api_set(GPIO3B5_SDMMC0DATA3_NAME, GPIO3B_GPIO3B5);
                gpio_request(RK30_PIN3_PB5, "mmc0-data3");
                gpio_direction_output(RK30_PIN3_PB5,GPIO_LOW);//set mmc0-data3 to low.

                mdelay(30);
            }
            #endif
        }
        break;
        
        case 1://mmc1
        {
            #ifdef CONFIG_SDMMC1_RK29
            if(on)
            {
                gpio_direction_output(RK30_PIN3_PC5,GPIO_HIGH);//set mmc1-clk to high
                gpio_direction_output(RK30_PIN3_PC0,GPIO_HIGH);//set mmc1-cmd to high.
                gpio_direction_output(RK30_PIN3_PC1,GPIO_HIGH);//set mmc1-data0 to high.
                gpio_direction_output(RK30_PIN3_PC2,GPIO_HIGH);//set mmc1-data1 to high.
                gpio_direction_output(RK30_PIN3_PC3,GPIO_HIGH);//set mmc1-data2 to high.
                gpio_direction_output(RK30_PIN3_PC5,GPIO_HIGH);//set mmc1-data3 to high.
                mdelay(100);
            }
            else
            {
                rk30_mux_api_set(GPIO3C5_SDMMC1CLKOUT_NAME, GPIO3C_GPIO3C5);
                gpio_request(RK30_PIN3_PC5, "mmc1-clk");
                gpio_direction_output(RK30_PIN3_PC5,GPIO_LOW);//set mmc1-clk to low.

                rk30_mux_api_set(GPIO3C0_SMMC1CMD_NAME, GPIO3C_GPIO3C0);
                gpio_request(RK30_PIN3_PC0, "mmc1-cmd");
                gpio_direction_output(RK30_PIN3_PC0,GPIO_LOW);//set mmc1-cmd to low.

                rk30_mux_api_set(GPIO3C1_SDMMC1DATA0_NAME, GPIO3C_GPIO3C1);
                gpio_request(RK30_PIN3_PC1, "mmc1-data0");
                gpio_direction_output(RK30_PIN3_PC1,GPIO_LOW);//set mmc1-data0 to low.
            #if defined(CONFIG_WIFI_COMBO_MODULE_CONTROL_FUNC) || defined(CONFIG_MT5931)
                rk29_mux_api_set(GPIO3C2_SDMMC1DATA1_NAME, GPIO3C_GPIO3C2);
                gpio_request(RK30_PIN3_PC2, "mmc1-data1");
                gpio_direction_output(RK30_PIN3_PC2,GPIO_LOW);//set mmc1-data1 to low.

                rk29_mux_api_set(GPIO3C3_SDMMC1DATA2_NAME, GPIO3C_GPIO3C3);
                gpio_request(RK30_PIN3_PC3, "mmc1-data2");
                gpio_direction_output(RK30_PIN3_PC3,GPIO_LOW);//set mmc1-data2 to low.

                rk29_mux_api_set(GPIO3C4_SDMMC1DATA3_NAME, GPIO3C_GPIO3C4);
                gpio_request(RK30_PIN3_PC4, "mmc1-data3");
                gpio_direction_output(RK30_PIN3_PC4,GPIO_LOW);//set mmc1-data3 to low.
           #endif
                mdelay(100);
            }
            #endif
        }
        break; 
        
        case 2: //mmc2
        break;
        
        default:
        break;
    }
}

static void rk29_sdmmc_set_iomux_mmc0(unsigned int bus_width)
{
    switch (bus_width)
    {
        
    	case 1://SDMMC_CTYPE_4BIT:
    	{
        	rk30_mux_api_set(GPIO3B3_SDMMC0DATA1_NAME, GPIO3B_SDMMC0_DATA1);
        	rk30_mux_api_set(GPIO3B4_SDMMC0DATA2_NAME, GPIO3B_SDMMC0_DATA2);
        	rk30_mux_api_set(GPIO3B5_SDMMC0DATA3_NAME, GPIO3B_SDMMC0_DATA3);
    	}
    	break;

    	case 0x10000://SDMMC_CTYPE_8BIT:
    	    break;
    	case 0xFFFF: //gpio_reset
    	{
            rk30_mux_api_set(GPIO3A7_SDMMC0PWREN_NAME, GPIO3A_GPIO3A7);
            gpio_request(RK30_PIN3_PA7,"sdmmc-power");
            gpio_direction_output(RK30_PIN3_PA7,GPIO_HIGH); //power-off

            rk29_sdmmc_gpio_open(0, 0);

            gpio_direction_output(RK30_PIN3_PA7,GPIO_LOW); //power-on

            rk29_sdmmc_gpio_open(0, 1);
    	}
    	break;

    	default: //case 0://SDMMC_CTYPE_1BIT:
        {
        	rk30_mux_api_set(GPIO3B1_SDMMC0CMD_NAME, GPIO3B_SDMMC0_CMD);
        	rk30_mux_api_set(GPIO3B0_SDMMC0CLKOUT_NAME, GPIO3B_SDMMC0_CLKOUT);
        	rk30_mux_api_set(GPIO3B2_SDMMC0DATA0_NAME, GPIO3B_SDMMC0_DATA0);

            rk30_mux_api_set(GPIO3B3_SDMMC0DATA1_NAME, GPIO3B_GPIO3B3);
            gpio_request(RK30_PIN3_PB3, "mmc0-data1");
            gpio_direction_output(RK30_PIN3_PB3,GPIO_HIGH);//set mmc0-data1 to high.

            rk30_mux_api_set(GPIO3B4_SDMMC0DATA2_NAME, GPIO3B_GPIO3B4);
            gpio_request(RK30_PIN3_PB4, "mmc0-data2");
            gpio_direction_output(RK30_PIN3_PB4,GPIO_HIGH);//set mmc0-data2 to high.

            rk30_mux_api_set(GPIO3B5_SDMMC0DATA3_NAME, GPIO3B_GPIO3B5);
            gpio_request(RK30_PIN3_PB5, "mmc0-data3");
            gpio_direction_output(RK30_PIN3_PB5,GPIO_HIGH);//set mmc0-data3 to high.
    	}
    	break;
	}
}

static void rk29_sdmmc_set_iomux_mmc1(unsigned int bus_width)
{
    rk30_mux_api_set(GPIO3C0_SMMC1CMD_NAME, GPIO3C_SMMC1_CMD);
    rk30_mux_api_set(GPIO3C5_SDMMC1CLKOUT_NAME, GPIO3C_SDMMC1_CLKOUT);
    rk30_mux_api_set(GPIO3C1_SDMMC1DATA0_NAME, GPIO3C_SDMMC1_DATA0);
    rk30_mux_api_set(GPIO3C2_SDMMC1DATA1_NAME, GPIO3C_SDMMC1_DATA1);
    rk30_mux_api_set(GPIO3C3_SDMMC1DATA2_NAME, GPIO3C_SDMMC1_DATA2);
    rk30_mux_api_set(GPIO3C4_SDMMC1DATA3_NAME, GPIO3C_SDMMC1_DATA3);
}

static void rk29_sdmmc_set_iomux_mmc2(unsigned int bus_width)
{
    ;//
}

static void rk29_sdmmc_set_iomux(int device_id, unsigned int bus_width)
{
    switch(device_id)
    {
        case 0:
            #ifdef CONFIG_SDMMC0_RK29
            rk29_sdmmc_set_iomux_mmc0(bus_width);
            #endif
            break;
        case 1:
            #ifdef CONFIG_SDMMC1_RK29
            rk29_sdmmc_set_iomux_mmc1(bus_width);
            #endif
            break;
        case 2:
            rk29_sdmmc_set_iomux_mmc2(bus_width);
            break;
        default:
            break;
    }    
}

#endif

static int rk29sdk_wifi_status(struct device *dev);
static int rk29sdk_wifi_status_register(void (*callback)(int card_presend, void *dev_id), void *dev_id);

#if defined(CONFIG_WIFI_COMBO_MODULE_CONTROL_FUNC)
static int rk29sdk_wifi_mmc0_status(struct device *dev);
static int rk29sdk_wifi_mmc0_status_register(void (*callback)(int card_presend, void *dev_id), void *dev_id);
static int rk29sdk_wifi_mmc0_cd = 0;   /* wifi virtual 'card detect' status */
static void (*wifi_mmc0_status_cb)(int card_present, void *dev_id);
static void *wifi_mmc0_status_cb_devid;

int rk29sdk_wifi_power_state = 0;
int rk29sdk_bt_power_state = 0;
#endif

static int rk29sdk_wifi_cd = 0;   /* wifi virtual 'card detect' status */
static void (*wifi_status_cb)(int card_present, void *dev_id);
static void *wifi_status_cb_devid;

#ifdef CONFIG_WIFI_CONTROL_FUNC
//#define RK29SDK_WIFI_BT_GPIO_POWER_N       RK30_PIN3_PD0
//#define RK29SDK_WIFI_GPIO_RESET_N          RK30_PIN3_PD0
//#define RK29SDK_BT_GPIO_RESET_N            RK30_PIN3_PD1
#ifdef CONFIG_MT5931
//#define RK30SDK_WIFI_GPIO_POWER_N       RK30_PIN0_PD5
//#define RK30SDK_WIFI_GPIO_RESET_N       RK30_PIN0_PC7
//FDA iMito MX1
#define RK30SDK_WIFI_GPIO_POWER_N      RK30_PIN3_PC7//RK30_PIN3_PD0
#define RK30SDK_WIFI_GPIO_RESET_N      RK30_PIN3_PD1

#else
#define RK30SDK_WIFI_GPIO_POWER_N       RK30_PIN3_PD0
//#define RK30SDK_BT_GPIO_POWER_N         RK30_PIN3_PD1
#endif

#define PREALLOC_WLAN_SEC_NUM           4
#define PREALLOC_WLAN_BUF_NUM           160
#define PREALLOC_WLAN_SECTION_HEADER    24

#define WLAN_SECTION_SIZE_0     (PREALLOC_WLAN_BUF_NUM * 128)
#define WLAN_SECTION_SIZE_1     (PREALLOC_WLAN_BUF_NUM * 128)
#define WLAN_SECTION_SIZE_2     (PREALLOC_WLAN_BUF_NUM * 512)
#define WLAN_SECTION_SIZE_3     (PREALLOC_WLAN_BUF_NUM * 1024)

#define WLAN_SKB_BUF_NUM        16

static struct sk_buff *wlan_static_skb[WLAN_SKB_BUF_NUM];

struct wifi_mem_prealloc {
        void *mem_ptr;
        unsigned long size;
};

static struct wifi_mem_prealloc wifi_mem_array[PREALLOC_WLAN_SEC_NUM] = {
        {NULL, (WLAN_SECTION_SIZE_0 + PREALLOC_WLAN_SECTION_HEADER)},
        {NULL, (WLAN_SECTION_SIZE_1 + PREALLOC_WLAN_SECTION_HEADER)},
        {NULL, (WLAN_SECTION_SIZE_2 + PREALLOC_WLAN_SECTION_HEADER)},
        {NULL, (WLAN_SECTION_SIZE_3 + PREALLOC_WLAN_SECTION_HEADER)}
};

static void *rk29sdk_mem_prealloc(int section, unsigned long size)
{
        if (section == PREALLOC_WLAN_SEC_NUM)
                return wlan_static_skb;

        if ((section < 0) || (section > PREALLOC_WLAN_SEC_NUM))
                return NULL;

        if (wifi_mem_array[section].size < size)
                return NULL;

        return wifi_mem_array[section].mem_ptr;
}

static int __init rk29sdk_init_wifi_mem(void)
{
        int i;
        int j;

        for (i = 0 ; i < WLAN_SKB_BUF_NUM ; i++) {
                wlan_static_skb[i] = dev_alloc_skb(
                                ((i < (WLAN_SKB_BUF_NUM / 2)) ? 4096 : 8192));

                if (!wlan_static_skb[i])
                        goto err_skb_alloc;
        }

        for (i = 0 ; i < PREALLOC_WLAN_SEC_NUM ; i++) {
                wifi_mem_array[i].mem_ptr =
                                kmalloc(wifi_mem_array[i].size, GFP_KERNEL);

                if (!wifi_mem_array[i].mem_ptr)
                        goto err_mem_alloc;
        }
        return 0;

err_mem_alloc:
        pr_err("Failed to mem_alloc for WLAN\n");
        for (j = 0 ; j < i ; j++)
               kfree(wifi_mem_array[j].mem_ptr);

        i = WLAN_SKB_BUF_NUM;

err_skb_alloc:
        pr_err("Failed to skb_alloc for WLAN\n");
        for (j = 0 ; j < i ; j++)
                dev_kfree_skb(wlan_static_skb[j]);

        return -ENOMEM;
}

static int rk29sdk_wifi_status(struct device *dev)
{
        return rk29sdk_wifi_cd;
}

static int rk29sdk_wifi_status_register(void (*callback)(int card_present, void *dev_id), void *dev_id)
{
        if(wifi_status_cb)
                return -EAGAIN;
        wifi_status_cb = callback;
        wifi_status_cb_devid = dev_id;
        return 0;
}

static int __init rk29sdk_wifi_bt_gpio_control_init(void)
{
    rk29sdk_init_wifi_mem();
    
    rk29_mux_api_set(GPIO3D0_SDMMC1PWREN_NAME, GPIO3D_GPIO3D0);
    
    if (gpio_request(RK30SDK_WIFI_GPIO_POWER_N, "wifi_power")) {
           pr_info("%s: request wifi power gpio failed\n", __func__);
           return -1;
    }

#ifdef CONFIG_MT5931
    if (gpio_request(RK30SDK_WIFI_GPIO_RESET_N, "wifi reset")) {
           pr_info("%s: request wifi reset gpio failed\n", __func__);
           gpio_free(RK30SDK_WIFI_GPIO_POWER_N);
           return -1;
    }
#endif

    /*if (gpio_request(RK29SDK_BT_GPIO_RESET_N, "bt reset")) {
          pr_info("%s: request bt reset gpio failed\n", __func__);
          gpio_free(RK30SDK_WIFI_GPIO_RESET_N);
          return -1;
    }*/

    gpio_direction_output(RK30SDK_WIFI_GPIO_POWER_N, GPIO_LOW);
#ifdef CONFIG_MT5931    
    gpio_direction_output(RK30SDK_WIFI_GPIO_RESET_N,    GPIO_LOW);
#endif    
    //gpio_direction_output(RK29SDK_BT_GPIO_RESET_N,      GPIO_LOW);

    #if defined(CONFIG_SDMMC1_RK29) && !defined(CONFIG_SDMMC_RK29_OLD)

#ifndef CONFIG_MT5931    
    rk29_mux_api_set(GPIO3C2_SDMMC1DATA1_NAME, GPIO3C_GPIO3C2);
    gpio_request(RK30_PIN3_PC2, "mmc1-data1");
    gpio_direction_output(RK30_PIN3_PC2,GPIO_LOW);//set mmc1-data1 to low.

    rk29_mux_api_set(GPIO3C3_SDMMC1DATA2_NAME, GPIO3C_GPIO3C3);
    gpio_request(RK30_PIN3_PC3, "mmc1-data2");
    gpio_direction_output(RK30_PIN3_PC3,GPIO_LOW);//set mmc1-data2 to low.

    rk29_mux_api_set(GPIO3C4_SDMMC1DATA3_NAME, GPIO3C_GPIO3C4);
    gpio_request(RK30_PIN3_PC4, "mmc1-data3");
    gpio_direction_output(RK30_PIN3_PC4,GPIO_LOW);//set mmc1-data3 to low.
#endif    
    rk29_sdmmc_gpio_open(1, 0); //added by xbw at 2011-10-13
    #endif    
    pr_info("%s: init finished\n",__func__);

    return 0;
}

#ifdef CONFIG_MT5931
static int rk29sdk_wifi_power(int on)
{
        pr_info("%s: %d\n", __func__, on);
        if (on){
                gpio_set_value(RK30SDK_WIFI_GPIO_POWER_N, GPIO_HIGH);
								mdelay(3);
								
                #if defined(CONFIG_SDMMC1_RK29) && !defined(CONFIG_SDMMC_RK29_OLD)	
                rk29_sdmmc_gpio_open(1, 1); //added by xbw at 2011-10-13
                #endif

                gpio_set_value(RK30SDK_WIFI_GPIO_RESET_N, GPIO_HIGH);
                mdelay(12);
                pr_info("wifi turn on power\n");
        }else{
                gpio_set_value(RK30SDK_WIFI_GPIO_POWER_N, GPIO_LOW);

                #if defined(CONFIG_SDMMC1_RK29) && !defined(CONFIG_SDMMC_RK29_OLD)	
                rk29_sdmmc_gpio_open(1, 0); //added by xbw at 2011-10-13
                #endif
                
                mdelay(100);
                pr_info("wifi shut off power\n");
                gpio_set_value(RK30SDK_WIFI_GPIO_RESET_N, GPIO_LOW);
								mdelay(10);
        }

        return 0;
}
#else
static int rk29sdk_wifi_power(int on)
{
        pr_info("%s: %d\n", __func__, on);
        if (on){
                gpio_set_value(RK30SDK_WIFI_GPIO_POWER_N, GPIO_HIGH);

                #if defined(CONFIG_SDMMC1_RK29) && !defined(CONFIG_SDMMC_RK29_OLD)	
                rk29_sdmmc_gpio_open(1, 1); //added by xbw at 2011-10-13
                #endif

                //gpio_set_value(RK29SDK_WIFI_GPIO_RESET_N, GPIO_HIGH);
                mdelay(100);
                pr_info("wifi turn on power\n");
        }else{
//                if (!rk29sdk_bt_power_state){
                        gpio_set_value(RK30SDK_WIFI_GPIO_POWER_N, GPIO_LOW);

                        #if defined(CONFIG_SDMMC1_RK29) && !defined(CONFIG_SDMMC_RK29_OLD)	
                        rk29_sdmmc_gpio_open(1, 0); //added by xbw at 2011-10-13
                        #endif
                        
                        mdelay(100);
                        pr_info("wifi shut off power\n");
//                }else
//                {
//                        pr_info("wifi shouldn't shut off power, bt is using it!\n");
//                }
                //gpio_set_value(RK29SDK_WIFI_GPIO_RESET_N, GPIO_LOW);

        }

//        rk29sdk_wifi_power_state = on;
        return 0;
}
#endif

static int rk29sdk_wifi_reset_state;
static int rk29sdk_wifi_reset(int on)
{
        pr_info("%s: %d\n", __func__, on);
        //gpio_set_value(RK29SDK_WIFI_GPIO_RESET_N, on);
        //mdelay(100);
        rk29sdk_wifi_reset_state = on;
        return 0;
}

int rk29sdk_wifi_set_carddetect(int val)
{
        pr_info("%s:%d\n", __func__, val);
        rk29sdk_wifi_cd = val;
        if (wifi_status_cb){
                wifi_status_cb(val, wifi_status_cb_devid);
        }else {
                pr_warning("%s, nobody to notify\n", __func__);
        }
        return 0;
}
EXPORT_SYMBOL(rk29sdk_wifi_set_carddetect);

#define WIFI_HOST_WAKE RK30_PIN3_PD2

static struct resource resources[] = {
	{
		.start = WIFI_HOST_WAKE,
		.flags = IORESOURCE_IRQ,
		.name = "bcmdhd_wlan_irq",
	},
};


///////////////////////////////////////////////////////////////////////////////////
#elif defined(CONFIG_WIFI_COMBO_MODULE_CONTROL_FUNC)

    #if defined(CONFIG_USE_SDMMC0_FOR_WIFI_DEVELOP_BOARD)
    #define USE_SDMMC_CONTROLLER_FOR_WIFI 0
    #define RK29SDK_WIFI_COMBO_GPIO_POWER_N      RK30_PIN4_PD2
    #define RK29SDK_WIFI_COMBO_GPIO_RESET_N      RK30_PIN4_PD1
    #define RK29SDK_WIFI_COMBO_GPIO_VDDIO        RK30_PIN1_PA6   
    #define RK29SDK_WIFI_COMBO_GPIO_BGF_INT_B    RK30_PIN1_PA7    
    #define RK29SDK_WIFI_COMBO_GPS_SYNC          RK30_PIN3_PC7    
    
    #else
/*
    #define USE_SDMMC_CONTROLLER_FOR_WIFI 1
    #define RK29SDK_WIFI_COMBO_GPIO_POWER_N      RK30_PIN3_PC7//RK30_PIN3_PD0   
    #define RK29SDK_WIFI_COMBO_GPIO_RESET_N      RK30_PIN3_PD1   
    #define RK29SDK_WIFI_COMBO_GPIO_WIFI_INT_B   RK30_PIN3_PD2
    
    #define RK29SDK_WIFI_COMBO_GPIO_VDDIO        RK30_PIN2_PC5   
    #define RK29SDK_WIFI_COMBO_GPIO_BGF_INT_B    RK30_PIN6_PA7    
    #define RK29SDK_WIFI_COMBO_GPS_SYNC          RK30_PIN3_PD0//RK30_PIN3_PC7    
*/
    #define USE_SDMMC_CONTROLLER_FOR_WIFI 1
    #define RK29SDK_WIFI_COMBO_GPIO_POWER_N      RK30_PIN4_PD7
    #define RK29SDK_WIFI_COMBO_GPIO_POWER_N_MUX_NAME      GPIO4D7_SMCDATA15_TRACEDATA15_NAME		
    #define RK29SDK_WIFI_COMBO_GPIO_POWER_N_MUX_MODE	GPIO4D_GPIO4D7	

    #define RK29SDK_WIFI_COMBO_GPIO_RESET_N      RK30_PIN0_PC7   
    #define RK29SDK_WIFI_COMBO_GPIO_RESET_N_MUX_NAME GPIO0C7_TRACECTL_SMCADDR3_NAME		
    #define RK29SDK_WIFI_COMBO_GPIO_RESET_N_MUX_MODE GPIO0C_GPIO0C7	

    #define RK29SDK_WIFI_COMBO_GPIO_WIFI_INT_B   RK30_PIN0_PD0
    #define RK29SDK_WIFI_COMBO_GPIO_WIFI_INT_B_MUX_NAME   GPIO0D0_I2S22CHCLK_SMCCSN0_NAME
    #define RK29SDK_WIFI_COMBO_GPIO_WIFI_INT_B_MUX_MODE GPIO0D_GPIO0D0		
    
    //#define RK29SDK_WIFI_COMBO_GPIO_VDDIO        RK30_PIN2_PC5   
	
    #define RK29SDK_WIFI_COMBO_GPIO_BGF_INT_B    RK30_PIN0_PD5
    #define RK29SDK_WIFI_COMBO_GPIO_BGF_INT_B_MUX_NAME GPIO0D5_I2S22CHSDO_SMCADDR1_NAME	
    #define RK29SDK_WIFI_COMBO_GPIO_BGF_INT_B_MUX_MODE GPIO0D_GPIO0D5		

    #define RK29SDK_WIFI_COMBO_GPS_SYNC          RK30_PIN0_PD1
    #define RK29SDK_WIFI_COMBO_GPS_SYNC_MUX_NAME          GPIO0D1_I2S22CHSCLK_SMCWEN_NAME
    #define RK29SDK_WIFI_COMBO_GPS_SYNC_MUX_MODE GPIO0D_GPIO0D1				
    #endif


#define debug_combo_system 0

int rk29sdk_wifi_combo_get_BGFgpio(void)
{
    return RK29SDK_WIFI_COMBO_GPIO_BGF_INT_B;
}
EXPORT_SYMBOL(rk29sdk_wifi_combo_get_BGFgpio);


int rk29sdk_wifi_combo_get_GPS_SYNC_gpio(void)
{
    return RK29SDK_WIFI_COMBO_GPS_SYNC;
}
EXPORT_SYMBOL(rk29sdk_wifi_combo_get_GPS_SYNC_gpio);


static int rk29sdk_wifi_combo_module_gpio_init(void)
{        
    rk30_mux_api_set(RK29SDK_WIFI_COMBO_GPIO_BGF_INT_B_MUX_NAME, RK29SDK_WIFI_COMBO_GPIO_BGF_INT_B_MUX_MODE);
    rk30_mux_api_set(RK29SDK_WIFI_COMBO_GPIO_WIFI_INT_B_MUX_NAME, RK29SDK_WIFI_COMBO_GPIO_WIFI_INT_B_MUX_MODE);
    
    rk30_mux_api_set(RK29SDK_WIFI_COMBO_GPIO_RESET_N_MUX_NAME, RK29SDK_WIFI_COMBO_GPIO_RESET_N_MUX_MODE);
    rk30_mux_api_set(RK29SDK_WIFI_COMBO_GPIO_RESET_N_MUX_NAME, RK29SDK_WIFI_COMBO_GPIO_RESET_N_MUX_MODE);
    if (gpio_request(RK29SDK_WIFI_COMBO_GPIO_RESET_N, "combo-RST"))
    {
        pr_info("%s:request combo-RST failed\n", __func__);
        return -1;
    }
    gpio_direction_output(RK29SDK_WIFI_COMBO_GPIO_RESET_N, GPIO_LOW);

    rk30_mux_api_set(RK29SDK_WIFI_COMBO_GPIO_POWER_N_MUX_NAME, RK29SDK_WIFI_COMBO_GPIO_POWER_N_MUX_MODE);
    if (gpio_request(RK29SDK_WIFI_COMBO_GPIO_POWER_N, "combo-PMUEN"))
	{
		pr_info("%s:request combo-PMUEN failed\n", __func__);
		return -1;
	}
	
	//gpio_pull_updown(RK29SDK_WIFI_COMBO_GPIO_POWER_N,0);
	//gpio_direction_input(RK29SDK_WIFI_COMBO_GPIO_POWER_N);
	gpio_direction_output(RK29SDK_WIFI_COMBO_GPIO_POWER_N, GPIO_LOW);
    return 0;
}


int rk29sdk_wifi_combo_module_power(int on)
{
     if(on)
    {
        //gpio_set_value(RK29SDK_WIFI_COMBO_GPIO_VDDIO, GPIO_HIGH);
        //mdelay(10);
        gpio_set_value(RK29SDK_WIFI_COMBO_GPIO_POWER_N, GPIO_HIGH);     
        mdelay(10);
        pr_info("combo-module turn on power\n");
    }
    else
    {
        gpio_set_value(RK29SDK_WIFI_COMBO_GPIO_POWER_N, GPIO_LOW);        
        mdelay(10);
        //gpio_set_value(RK29SDK_WIFI_COMBO_GPIO_VDDIO, GPIO_LOW);
        pr_info("combo-module turn off power\n");
    }
     return 0;
    
}
EXPORT_SYMBOL(rk29sdk_wifi_combo_module_power);


int rk29sdk_wifi_combo_module_reset(int on)
{
    if(on)
    {
        gpio_set_value(RK29SDK_WIFI_COMBO_GPIO_RESET_N, GPIO_HIGH);     
        pr_info("combo-module reset out 1\n");
    }
    else
    {
        gpio_set_value(RK29SDK_WIFI_COMBO_GPIO_RESET_N, GPIO_LOW);        
        pr_info("combo-module  reset out 0\n");
    }

    return 0;   
}
EXPORT_SYMBOL(rk29sdk_wifi_combo_module_reset);


static int rk29sdk_wifi_mmc0_status(struct device *dev)
{
        return rk29sdk_wifi_mmc0_cd;
}

static int rk29sdk_wifi_mmc0_status_register(void (*callback)(int card_present, void *dev_id), void *dev_id)
{
        if(wifi_mmc0_status_cb)
                return -EAGAIN;
        wifi_mmc0_status_cb = callback;
        wifi_mmc0_status_cb_devid = dev_id;
        return 0;
}


static int rk29sdk_wifi_status(struct device *dev)
{
        return rk29sdk_wifi_cd;
}

static int rk29sdk_wifi_status_register(void (*callback)(int card_present, void *dev_id), void *dev_id)
{
        if(wifi_status_cb)
                return -EAGAIN;
        wifi_status_cb = callback;
        wifi_status_cb_devid = dev_id;
        return 0;
}
extern unsigned int sdio_irq_global;

int rk29sdk_wifi_power(int on)
{
    pr_info("%s: %d\n", __func__, on);
    if (on){
    
        #if defined(CONFIG_SDMMC1_RK29) && !defined(CONFIG_SDMMC_RK29_OLD)  
            
          #if defined(CONFIG_USE_SDMMC0_FOR_WIFI_DEVELOP_BOARD)
             rk29_sdmmc_gpio_open(0, 1); 
          #else
            rk29_sdmmc_gpio_open(1, 0);                
            mdelay(10);
            rk29_sdmmc_gpio_open(1, 1); 
          #endif 
        #endif
    
            mdelay(100);
            pr_info("wifi turn on power\n");
    }
    else
    {    
#if defined(CONFIG_SDMMC1_RK29) && !defined(CONFIG_SDMMC_RK29_OLD)
        #if defined(CONFIG_USE_SDMMC0_FOR_WIFI_DEVELOP_BOARD)
        rk29_sdmmc_gpio_open(0, 0);
        #else
        rk29_sdmmc_gpio_open(1, 0);
        #endif
#endif      
        mdelay(100);
        pr_info("wifi shut off power\n");
         
    }
    
    rk29sdk_wifi_power_state = on;
    return 0;

}
EXPORT_SYMBOL(rk29sdk_wifi_power);


int rk29sdk_wifi_reset(int on)
{    
    return 0;
}
EXPORT_SYMBOL(rk29sdk_wifi_reset);


#if defined(CONFIG_USE_SDMMC0_FOR_WIFI_DEVELOP_BOARD)
int rk29sdk_wifi_set_carddetect(int val)
{
    pr_info("%s:%d\n", __func__, val);
    rk29sdk_wifi_mmc0_cd = val;
    if (wifi_mmc0_status_cb){
            wifi_mmc0_status_cb(val, wifi_mmc0_status_cb_devid);
    }else {
            pr_warning("%s,in mmc0 nobody to notify\n", __func__);
    }
    return 0; 
}

#else
int rk29sdk_wifi_set_carddetect(int val)
{
    pr_info("%s:%d\n", __func__, val);
    rk29sdk_wifi_cd = val;
    if (wifi_status_cb){
            wifi_status_cb(val, wifi_status_cb_devid);
    }else {
            pr_warning("%s,in mmc1 nobody to notify\n", __func__);
    }
    return 0; 
}
#endif

EXPORT_SYMBOL(rk29sdk_wifi_set_carddetect);

#endif  ///  #endif ---#elif defined(CONFIG_WIFI_COMBO_MODULE_CONTROL_FUNC)



#if defined(CONFIG_WIFI_CONTROL_FUNC)
static struct wifi_platform_data rk29sdk_wifi_control = {
        .set_power = rk29sdk_wifi_power,
        .set_reset = rk29sdk_wifi_reset,
        .set_carddetect = rk29sdk_wifi_set_carddetect,
        .mem_prealloc   = rk29sdk_mem_prealloc,
};

static struct platform_device rk29sdk_wifi_device = {
        .name = "bcmdhd_wlan",
        .id = 1,
        .num_resources = ARRAY_SIZE(resources),
        .resource = resources,
        .dev = {
                .platform_data = &rk29sdk_wifi_control,
         },
};

#elif defined(CONFIG_WIFI_COMBO_MODULE_CONTROL_FUNC)

    #if debug_combo_system
        static struct combo_module_platform_data rk29sdk_combo_module_control = {
            .set_power = rk29sdk_wifi_combo_module_power,
            .set_reset = rk29sdk_wifi_combo_module_reset,  
        };

        static struct platform_device  rk29sdk_combo_module_device = {
                .name = "combo-system",
                .id = 1,
                .dev = {
                        .platform_data = &rk29sdk_combo_module_control,
                 },
        };
    #endif

static struct wifi_platform_data rk29sdk_wifi_control = {
        .set_power = rk29sdk_wifi_power,
        .set_reset = rk29sdk_wifi_reset,
        .set_carddetect = rk29sdk_wifi_set_carddetect,
};

static struct platform_device rk29sdk_wifi_device = {
        .name = "combo-wifi",
        .id = 1,
        .dev = {
                .platform_data = &rk29sdk_wifi_control,
         },
};

#endif


#endif // endif --#ifdef CONFIG_SDMMC_RK29

