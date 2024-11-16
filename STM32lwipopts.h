/*
 *  © 2024 Harald Barth
 *  All rights reserved.
 *
 *  This file is part of CommandStation-EX
 *
 *  This is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  It is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with CommandStation.  If not, see <https://www.gnu.org/licenses/>.
 */
//
// Rewrite of the STM32lwipopts.h file from STM
// To be copied into where lwipopts_default.h resides
//
#ifndef __STM32LWIPOPTS_H__
#define __STM32LWIPOPTS_H__

// include this here and then override things we do differnet
#include "lwipopts_default.h"

// we can not include our "defines.h" here
// so we need to duplicate that define
#define MAX_NUM_TCP_CLIENTS 20

// increase ARP cache
#undef  MEMP_NUM_APR_QUEUE
#define MEMP_NUM_ARP_QUEUE MAX_NUM_TCP_CLIENTS+3 // one for each client (all on different HW) and a few extra

// Example for debug
//#define LWIP_DEBUG                      1
//#define TCP_DEBUG                       LWIP_DBG_ON

// NOT STRICT NECESSARY ANY MORE BUT CAN BE USED TO SAVE RAM
#undef  MEM_LIBC_MALLOC
#define MEM_LIBC_MALLOC         1       // use the same malloc as for everything else
#undef  MEMP_MEM_MALLOC
#define MEMP_MEM_MALLOC         1       // uses malloc which means no pools which means slower but not mean 32KB up front

#undef  MEMP_NUM_TCP_PCB
#define MEMP_NUM_TCP_PCB        MAX_NUM_TCP_CLIENTS+1 // one extra so we can reject number N+1 from our code
#define MEMP_NUM_TCP_PCB_LISTEN 6

#undef  MEMP_NUM_TCP_SEG
#define MEMP_NUM_TCP_SEG        MAX_NUM_TCP_CLIENTS

#undef  MEMP_NUM_SYS_TIMEOUT
#define MEMP_NUM_SYS_TIMEOUT    MAX_NUM_TCP_CLIENTS+2

#undef  PBUF_POOL_SIZE
#define PBUF_POOL_SIZE          MAX_NUM_TCP_CLIENTS

#undef  LWIO_ICMP
#define LWIP_ICMP                       1
#undef  LWIP_RAW
#define LWIP_RAW                        1 /* PING changed to 1 */
#undef  DEFAULT_RAW_RECVMBOX_SIZE
#define DEFAULT_RAW_RECVMBOX_SIZE       3 /* for ICMP PING */

#undef  LWIP_DHCP
#define LWIP_DHCP               1
#undef  LWIP_UDP
#define LWIP_UDP                1

/*
The STM32F4x7 allows computing and verifying the IP, UDP, TCP and ICMP checksums by hardware:
 - To use this feature let the following define uncommented.
 - To disable it and process by CPU comment the  the checksum.
*/

#if CHECKSUM_GEN_TCP == 1
#error On STM32 TCP checksum should be in HW
#endif

#undef  LWIP_IGMP
#define LWIP_IGMP       1

//#define SO_REUSE 1
//#define SO_REUSE_RXTOALL 1

#endif /* __STM32LWIPOPTS_H__ */
