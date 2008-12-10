/*
 * This file is part of the coreboot project.
 *
 * Copyright (C) 2007 Rudolf Marek <r.marek@assembler.cz>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License v2 as published by
 * the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301 USA
 */

#ifndef SOUTHBRIDGE_VIA_VT8237_VT8237_H
#define SOUTHBRIDGE_VIA_VT8237_VT8237_H

#include <types.h>

/* IDE */
#define IDE_CS				0x40
#define IDE_CONF_I			0x41
#define IDE_CONF_II			0x42
#define IDE_CONF_FIFO			0x43
#define IDE_MISC_I			0x44
#define IDE_MISC_II			0x45
#define IDE_UDMA			0x50

#define SATA_MISC_CTRL 0x45

/* SMBus */
#define VT8237_POWER_WELL		0x94
#define VT8237_SMBUS_IO_BASE_REG	0xd0
#define VT8237_SMBUS_HOST_CONF		0xd2

#define SMBHSTSTAT			0x0
#define SMBSLVSTAT			0x1
#define SMBHSTCTL			0x2
#define SMBHSTCMD			0x3
#define SMBXMITADD			0x4
#define SMBHSTDAT0			0x5

#define HOST_RESET 			0xff
/* 1 in the 0 bit of SMBHSTADD states to READ. */
#define READ_CMD			0x01
#define SMBUS_TIMEOUT			(100 * 1000 * 10)
#define I2C_TRANS_CMD			0x40
#define CLOCK_SLAVE_ADDRESS		0x69

struct vt8237_network_rom {
	u8 mac_address[6];
	u8 phy_addr;
	u8 res1;
	u16 sub_sid;
	u16 sub_vid;
	u16 pid;
	u16 vid;
	u8 pmcc;
	u8 data_sel;
	u8 pmu_data_reg;
	u8 aux_curr;
	u16 reserved;
	u8 min_gnt;
	u8 max_lat;
	u8 bcr0;
	u8 bcr1;
	u8 cfg_a;
	u8 cfg_b;
	u8 cfg_c;
	u8 cfg_d;
	u8 checksum;
} __attribute__ ((packed));

void enable_smbus(u16);
void vt8237_stage1(u16);
u8 smbus_read_byte(u16, u8, u16);
void vt8237_enable(struct device *);

#endif
