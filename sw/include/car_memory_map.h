// Copyright 2022 ETH Zurich and University of Bologna.
// Licensed under the Apache License, Version 2.0, see LICENSE for details.
// SPDX-License-Identifier: Apache-2.0
//
// Nicole Narr <narrn@student.ethz.ch>
// Christopher Reinwardt <creinwar@student.ethz.ch>
// Paul Scheffler <paulsc@iis.ee.ethz.ch>
// Robert Balas <balasr@iis.ee.ethz.ch>
// Alessandro Ottaviano <aottaviano@iis.ee.ethz.ch>
//
// This header provides information defined by hardware parameters, such as
// the address map. In the future, it should be generated automatically as
// part of the SoC generation process.

#ifndef __CAR_MEMORY_MAP_H
#define __CAR_MEMORY_MAP_H

#include "car_params.h"
#include "regs/safety_soc_ctrl.h"
#include "regs/soc_ctrl.h"
#include "regs/spatz_cluster_peripheral.h"

// Base addresses provided at link time
extern void *__base_l2;

// Main Islands and accelerators

// Cheshire
#define CHESHIRE_REGS_BASE_ADDR 0x03000000
#define CHESHIRE_NUM_INT_HARTS  CHESHIRE_REGS_BASE_ADDR + CHESHIRE_NUM_INT_HARTS_REG_OFFSET
#define CHESHIRE_HARTS_SYNC     CHESHIRE_REGS_BASE_ADDR + CHESHIRE_HARTS_SYNC_REG_OFFSET

// CVA6 HMR Unit
#define HMR_BASE_ADDR               0x0300B000
#define HMR_CORE_OFFS               0x100
#define HMR_DMR_OFFS                0x200
#define HMR_TMR_OFFS                0x300
#define HMR_CORE_INCREMENT          0x010
#define HMR_CORE_SLL                0x004
#define HMR_DMR_INCREMENT           0x010
#define HMR_DMR_SLL                 0x004
#define HMR_TMR_INCREMENT           0x010
#define HMR_TMR_SLL                 0x004

// Stack Pointer storage register
#define HMR_CORE_REGS_SP_STORE_REG_OFFSET 0x8
#define HMR_DMR_ENABLE_OFFS         0x0
#define HMR_DMR_CFG_REG_OFFS        0x4
#define HMR_DMR_CHECKPOINT_REG_OFFS 0x8
#define HMR_DMR_ENABLE              HMR_BASE_ADDR + HMR_DMR_OFFS + HMR_DMR_ENABLE_OFFS
#define HMR_DMR_CFG                 HMR_BASE_ADDR + HMR_DMR_OFFS + HMR_DMR_CFG_REG_OFFS
#define HMR_DMR_CHECKPOINT          HMR_BASE_ADDR + HMR_DMR_OFFS + HMR_DMR_CHECKPOINT_REG_OFFS

// L2 port 0
#define CAR_L2_SPM_PORT0_INTERLEAVED_BASE_ADDR(BASE) BASE
#define CAR_L2_SPM_PORT0_INTERLEAVED_END_ADDR(BASE)  (BASE + 0x20000)
#define CAR_L2_SPM_PORT0_CONTIGUOUS_BASE_ADDR(BASE)  BASE
#define CAR_L2_SPM_PORT0_CONTIGUOUS_END_ADDR(BASE)   (BASE + 0x20000)

// L2 port 1
#define CAR_L2_SPM_PORT1_INTERLEAVED_BASE_ADDR(BASE) BASE
#define CAR_L2_SPM_PORT1_INTERLEAVED_END_ADDR(BASE)  (BASE + 0x10000)
#define CAR_L2_SPM_PORT1_CONTIGUOUS_BASE_ADDR(BASE)  BASE
#define CAR_L2_SPM_PORT1_CONTIGUOUS_END_ADDR(BASE)   (BASE + 0x10000)

// Safety Island
#define CAR_SAFETY_ISLAND_SPM_BASE_ADDR(BASE) BASE
#define CAR_SAFETY_ISLAND_SPM_END_ADDR(BASE) (CAR_SAFETY_ISLAND_SPM_BASE_ADDR(BASE) + 0x20000)
#define CAR_SAFETY_ISLAND_PERIPHERALS_OFFSET 0x00200000
#define CAR_SAFETY_ISLAND_SOC_CTRL_OFFSET    0x00000000
#define CAR_SAFETY_ISLAND_ENTRY_POINT(BASE)        (CAR_SAFETY_ISLAND_SPM_BASE_ADDR(BASE) + 0x00010080)
#define CAR_SAFETY_ISLAND_SOC_CTRL_ADDR(BASE)      (CAR_SAFETY_ISLAND_SPM_BASE_ADDR(BASE) + CAR_SAFETY_ISLAND_PERIPHERALS_OFFSET + CAR_SAFETY_ISLAND_SOC_CTRL_OFFSET)

#define CAR_SAFETY_ISLAND_BOOTADDR_ADDR(BASE)      (CAR_SAFETY_ISLAND_SOC_CTRL_ADDR(BASE) + SAFETY_SOC_CTRL_BOOTADDR_REG_OFFSET)
#define CAR_SAFETY_ISLAND_FETCHEN_ADDR(BASE)       (CAR_SAFETY_ISLAND_SOC_CTRL_ADDR(BASE) + SAFETY_SOC_CTRL_FETCHEN_REG_OFFSET)
#define CAR_SAFETY_ISLAND_BOOTMODE_ADDR(BASE)      (CAR_SAFETY_ISLAND_SOC_CTRL_ADDR(BASE) + SAFETY_SOC_CTRL_BOOTMODE_REG_OFFSET)
#define CAR_SAFETY_ISLAND_CORESTATUS_ADDR(BASE)    (CAR_SAFETY_ISLAND_SOC_CTRL_ADDR(BASE) + SAFETY_SOC_CTRL_CORESTATUS_REG_OFFSET)

#define CAR_SAFETY_ISLAND_PERIPHS_BASE_ADDR(BASE) (CAR_SAFETY_ISLAND_SPM_BASE_ADDR(BASE) + CAR_SAFETY_ISLAND_PERIPHERALS_OFFSET)
#define CAR_SAFETY_ISLAND_PERIPHS_END_ADDR(BASE) (CAR_SAFETY_ISLAND_PERIPHS_BASE_ADDR(BASE) + 0x100000)

// Integer Cluster
#define CAR_INT_CLUSTER_SPM_BASE_ADDR(BASE) BASE
#define CAR_INT_CLUSTER_SPM_END_ADDR(BASE) (BASE + 0x20000)

#define CAR_INT_CLUSTER_PERIPH_OFFS           0x00200000
#define CAR_INT_CLUSTER_CTRL_UNIT_OFFS        0x00000000
#define CAR_INT_CLUSTER_CTRL_UNIT_RETURN_OFFS 0x100
#define CAR_INT_CLUSTER_RETURN_ADDR(BASE) (CAR_INT_CLUSTER_SPM_BASE_ADDR(BASE) + CAR_INT_CLUSTER_PERIPH_OFFS + CAR_INT_CLUSTER_CTRL_UNIT_OFFS + CAR_INT_CLUSTER_CTRL_UNIT_RETURN_OFFS)

#define CAR_INT_CLUSTER_BOOT_ADDR_OFFS 0x40
#define CAR_INT_CLUSTER_BOOT_ADDR_REG(BASE) (CAR_INT_CLUSTER_SPM_BASE_ADDR(BASE) + CAR_INT_CLUSTER_PERIPH_OFFS + CAR_INT_CLUSTER_CTRL_UNIT_OFFS + CAR_INT_CLUSTER_BOOT_ADDR_OFFS)

// Floating Point Spatz Cluster
#define CAR_FP_CLUSTER_SPM_BASE_ADDR(BASE) BASE
#define CAR_FP_CLUSTER_SPM_END_ADDR(BASE)  (BASE + 0x20000)

#define CAR_FP_CLUSTER_PERIPHS_BASE_ADDR(BASE) (BASE + 0x20000)
// #define CAR_FP_CLUSTER_PERIPHS_END_ADDR  unknown

// HyperRAM
#define CAR_HYPERRAM_BASE_ADDR 0x80400000
#define CAR_HYPERRAM_END_ADDR  0x80800000

// Peripheral devices
// from cheshire
#define CAR_BOOTROM_BASE_ADDR        0x000002000000
#define CAR_CLINT_BASE_ADDR          0x000002040000 // for both cores
#define CAR_IRQ_ROUTER_BASE_ADDR     0x000002080000
#define CAR_IRQ_AXI_REALM_BASE_ADDR  0x0000020c0000
#define CAR_CHESHIRE_CFG_BASE_ADDR   0x000003000000
#define CAR_LLC_CFG_BASE_ADDR        0x000003001000
#define CAR_CLIC_CFG_BASE_ADDR(id)   0x000008000000

// from carfield proper
#define CAR_PERIPHS_BASE_ADDR        0x20000000

#define CAR_ETHERNET_OFFSET          0x0000000
#define CAR_CAN_OFFSET               0x0001000
#define CAR_SYSTEM_TIMER_OFFSET      0x0004000
#define CAR_ADVANCED_TIMER_OFFSET    0x0005000
#define CAR_WATCHDOG_TIMER_OFFSET    0x0007000
#define CAR_HYPERBUS_CFG_OFFSET      0x0008000
#define CAR_STREAMER_CFG_OFFSET      0x0009000
#define CAR_STREAMER_APB_OFFSET      0x0011000
#define CAR_PAD_CFG_OFFSET           0x1000000

#define CAR_ETHERNET_BASE_ADDR       (CAR_PERIPHS_BASE_ADDR + CAR_ETHERNET_OFFSET)
#define CAR_CAN_BASE_ADDR            (CAR_PERIPHS_BASE_ADDR + CAR_CAN_OFFSET)
#define CAR_SYSTEM_TIMER_BASE_ADDR   (CAR_PERIPHS_BASE_ADDR + CAR_SYSTEM_TIMER_OFFSET)
#define CAR_ADVANCED_TIMER_BASE_ADDR (CAR_PERIPHS_BASE_ADDR + CAR_ADVANCED_TIMER_OFFSET)
#define CAR_WATCHDOG_TIMER_BASE_ADDR (CAR_PERIPHS_BASE_ADDR + CAR_WATCHDOG_TIMER_OFFSET)
#define CAR_HYPERBUS_CFG_BASE_ADDR   (CAR_PERIPHS_BASE_ADDR + CAR_HYPERBUS_CFG_OFFSET)
#define CAR_STREAMER_CFG_BASE_ADDR   (CAR_PERIPHS_BASE_ADDR + CAR_STREAMER_CFG_OFFSET)
#define CAR_STREAMER_APB_BASE_ADDR   (CAR_PERIPHS_BASE_ADDR + CAR_STREAMER_APB_OFFSET)
#define CAR_PAD_CFG_BASE_ADDR        (CAR_PERIPHS_BASE_ADDR + CAR_PAD_CFG_OFFSET)
#define CAR_SOC_CTRL_BASE_ADDR(BASE) BASE

// Mailbox
#define CAR_NUM_MAILBOXES            25
#define CAR_MBOX_BASE_ADDR           0x40000000

#define MBOX_INT_SND_STAT_OFFSET     0x00
#define MBOX_INT_SND_SET_OFFSET      0x04
#define MBOX_INT_SND_CLR_OFFSET      0x08
#define MBOX_INT_SND_EN_OFFSET       0x0C
#define MBOX_INT_RCV_STAT_OFFSET     0x40
#define MBOX_INT_RCV_SET_OFFSET      0x44
#define MBOX_INT_RCV_CLR_OFFSET      0x48
#define MBOX_INT_RCV_EN_OFFSET       0x4C
#define MBOX_LETTER0_OFFSET          0x80
#define MBOX_LETTER1_OFFSET          0x84

#define MBOX_CAR_INT_SND_STAT(id)		  (CAR_MBOX_BASE_ADDR + MBOX_INT_SND_STAT_OFFSET + (id*0x100))
#define MBOX_CAR_INT_SND_SET(id)          (CAR_MBOX_BASE_ADDR + MBOX_INT_SND_SET_OFFSET  + (id*0x100))
#define MBOX_CAR_INT_SND_CLR(id)          (CAR_MBOX_BASE_ADDR + MBOX_INT_SND_CLR_OFFSET  + (id*0x100))
#define MBOX_CAR_INT_SND_EN(id)           (CAR_MBOX_BASE_ADDR + MBOX_INT_SND_EN_OFFSET   + (id*0x100))
#define MBOX_CAR_INT_RCV_STAT(id)         (CAR_MBOX_BASE_ADDR + MBOX_INT_RCV_STAT_OFFSET + (id*0x100))
#define MBOX_CAR_INT_RCV_SET(id)          (CAR_MBOX_BASE_ADDR + MBOX_INT_RCV_SET_OFFSET  + (id*0x100))
#define MBOX_CAR_INT_RCV_CLR(id)          (CAR_MBOX_BASE_ADDR + MBOX_INT_RCV_CLR_OFFSET  + (id*0x100))
#define MBOX_CAR_INT_RCV_EN(id)           (CAR_MBOX_BASE_ADDR + MBOX_INT_RCV_EN_OFFSET   + (id*0x100))
#define MBOX_CAR_LETTER0(id)              (CAR_MBOX_BASE_ADDR + MBOX_LETTER0_OFFSET      + (id*0x100))
#define MBOX_CAR_LETTER1(id)              (CAR_MBOX_BASE_ADDR + MBOX_LETTER1_OFFSET      + (id*0x100))

//TCTM Streamer
#define TCTM_STREAMER_CFG_OFFS        0x0
#define TCTM_STREAMER_MAP_ROUTER_OFFS 0x0
#define TCTM_STREAMER_HPC_OFFS        0x80
#define TCTM_STREAMER_OBT_OFFS        0x100
#define TCTM_STREAMER_PTME_OFFS       0x180
#define TCTM_STREAMER_PTD_OFFS        0x200
#define TCTM_STREAMER_LLC_OFFS        0x280

#define TCTM_STREAMER_PTME_CFG_OFFS   0x000
#define TCTM_STREAMER_TM_PACKETS_OFFS 0x400
#define TCTM_STREAMER_TC_BUFFER_OFFS  0x800
#define TCTM_STREAMER_TX_BUFFER_OFFS  0xC00

#define TCTM_STREAMER_CFG_MAP_ROUTER_BASE CAR_STREAMER_CFG_BASE_ADDR + TCTM_STREAMER_MAP_ROUTER_OFFS
#define TCTM_STREAMER_CFG_HPC_BASE        CAR_STREAMER_CFG_BASE_ADDR + TCTM_STREAMER_HPC_OFFS
#define TCTM_STREAMER_CFG_OBT_BASE        CAR_STREAMER_CFG_BASE_ADDR + TCTM_STREAMER_OBT_OFFS
#define TCTM_STREAMER_CFG_PTME_BASE       CAR_STREAMER_CFG_BASE_ADDR + TCTM_STREAMER_PTME_OFFS
#define TCTM_STREAMER_CFG_PTD_BASE        CAR_STREAMER_CFG_BASE_ADDR + TCTM_STREAMER_PTD_OFFS
#define TCTM_STREAMER_CFG_LLC_BASE        CAR_STREAMER_CFG_BASE_ADDR + TCTM_STREAMER_LLC_OFFS

#define TCTM_STREAMER_APB_PTME_CFG        CAR_STREAMER_APB_BASE_ADDR + TCTM_STREAMER_PTME_CFG_OFFS
#define TCTM_STREAMER_APB_TM_PACKET_BASE  CAR_STREAMER_APB_BASE_ADDR + TCTM_STREAMER_TM_PACKETS_OFFS
#define TCTM_STREAMER_APB_TC_BUFFER_BASE  CAR_STREAMER_APB_BASE_ADDR + TCTM_STREAMER_TC_BUFFER_OFFS
#define TCTM_STREAMER_APB_TX_BUFFER_BASE  CAR_STREAMER_APB_BASE_ADDR + TCTM_STREAMER_TX_BUFFER_OFFS

// PLL
#define CAR_PLL_BASE_ADDRESS         0x21003000
#define PLL_ADDR_SPACE               0x200
#define PLL_BASE_ADDRESS(id)         (CAR_PLL_BASE_ADDRESS + (id+1)*PLL_ADDR_SPACE)

// Error codes
#define EHOSTDEXEC 1 // Execution error host domain
#define ESAFEDEXEC 2 // Execution error safe domain
#define EINTCLEXEC 3 // Execution error integer cluster
#define EFPCLEXEC  4 // Execution error floating point cluster

// Memory-mapped registers
#define CAR_INT_CLUSTER_FETCHEN_ADDR(BASE) (CAR_SOC_CTRL_BASE_ADDR(BASE) + CARFIELD_PULP_CLUSTER_FETCH_ENABLE_REG_OFFSET)
#define CAR_INT_CLUSTER_BOOTEN_ADDR(BASE)  (CAR_SOC_CTRL_BASE_ADDR(BASE) + CARFIELD_PULP_CLUSTER_BOOT_ENABLE_REG_OFFSET)
#define CAR_INT_CLUSTER_BUSY_ADDR(BASE)    (CAR_SOC_CTRL_BASE_ADDR(BASE) + CARFIELD_PULP_CLUSTER_BUSY_REG_OFFSET)
#define CAR_INT_CLUSTER_EOC_ADDR(BASE)     (CAR_SOC_CTRL_BASE_ADDR(BASE) + CARFIELD_PULP_CLUSTER_EOC_REG_OFFSET)

#endif /* __CAR_MEMORY_MAP_H */
