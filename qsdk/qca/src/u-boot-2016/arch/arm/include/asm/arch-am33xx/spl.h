/*
 * (C) Copyright 2012
 * Texas Instruments, <www.ti.com>
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */
#ifndef	_ASM_ARCH_SPL_H_
#define	_ASM_ARCH_SPL_H_

#define BOOT_DEVICE_NONE	0x00
#define BOOT_DEVICE_MMC2_2	0xFF

#if defined(CONFIG_TI814X)
#define BOOT_DEVICE_XIP		0x01
#define BOOT_DEVICE_XIPWAIT	0x02
#define BOOT_DEVICE_NAND	0x05
#define BOOT_DEVICE_NAND_I2C	0x06
#define BOOT_DEVICE_MMC2	0x08 /* ROM only supports 2nd instance. */
#define BOOT_DEVICE_MMC1	0x09
#define BOOT_DEVICE_SPI		0x15
#define BOOT_DEVICE_UART	0x41
#define BOOT_DEVICE_USBETH	0x44
#define BOOT_DEVICE_CPGMAC	0x46

#define MMC_BOOT_DEVICES_START	BOOT_DEVICE_MMC2
#define MMC_BOOT_DEVICES_END	BOOT_DEVICE_MMC1
#elif defined(CONFIG_TI816X)
#define BOOT_DEVICE_XIP		0x01
#define BOOT_DEVICE_XIPWAIT	0x02
#define BOOT_DEVICE_NAND	0x03
#define BOOT_DEVICE_ONENAD	0x04
#define BOOT_DEVICE_MMC2	0x05 /* ROM only supports 2nd instance. */
#define BOOT_DEVICE_MMC1	0x06
#define BOOT_DEVICE_UART	0x43
#define BOOT_DEVICE_USB		0x45

#define MMC_BOOT_DEVICES_START	BOOT_DEVICE_MMC2
#define MMC_BOOT_DEVICES_END	BOOT_DEVICE_MMC1
#elif defined(CONFIG_AM33XX)
#define BOOT_DEVICE_XIP		0x01
#define BOOT_DEVICE_XIPWAIT	0x02
#define BOOT_DEVICE_NAND	0x05
#define BOOT_DEVICE_NAND_I2C	0x06
#define BOOT_DEVICE_MMC1	0x08
#define BOOT_DEVICE_MMC2	0x09
#define BOOT_DEVICE_SPI		0x15
#define BOOT_DEVICE_UART	0x41
#define BOOT_DEVICE_USBETH	0x44
#define BOOT_DEVICE_CPGMAC	0x46

#define MMC_BOOT_DEVICES_START	BOOT_DEVICE_MMC1
#define MMC_BOOT_DEVICES_END	BOOT_DEVICE_MMC2
#elif defined(CONFIG_AM43XX)
#define BOOT_DEVICE_NOR		0x01
#define BOOT_DEVICE_NAND	0x05
#define BOOT_DEVICE_MMC1	0x07
#define BOOT_DEVICE_MMC2	0x08
#define BOOT_DEVICE_SPI		0x0A
#define BOOT_DEVICE_UART	0x41
#define BOOT_DEVICE_USB		0x45
#define BOOT_DEVICE_CPGMAC	0x47

#define MMC_BOOT_DEVICES_START	BOOT_DEVICE_MMC1
#ifdef CONFIG_SPL_USB_SUPPORT
#define MMC_BOOT_DEVICES_END	BOOT_DEVICE_USB
#else
#define MMC_BOOT_DEVICES_END	BOOT_DEVICE_MMC2
#endif
#endif

#endif