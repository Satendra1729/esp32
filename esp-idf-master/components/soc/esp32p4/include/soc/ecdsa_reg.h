/**
 * SPDX-FileCopyrightText: 2023 Espressif Systems (Shanghai) CO LTD
 *
 *  SPDX-License-Identifier: Apache-2.0
 */
#pragma once

#include <stdint.h>
#include "soc/soc.h"
#ifdef __cplusplus
extern "C" {
#endif

/** ECDSA_CONF_REG register
 *  ECDSA configure register
 */
#define ECDSA_CONF_REG (DR_REG_ECDSA_BASE + 0x4)
/** ECDSA_WORK_MODE : R/W; bitpos: [1:0]; default: 0;
 *  The work mode bits of ECDSA Accelerator. 0: Signature Verify Mode. 1: Signature
 *  Generate Mode. 2: Export Public Key Mode. 3: invalid.
 */
#define ECDSA_WORK_MODE    0x00000003U
#define ECDSA_WORK_MODE_M  (ECDSA_WORK_MODE_V << ECDSA_WORK_MODE_S)
#define ECDSA_WORK_MODE_V  0x00000003U
#define ECDSA_WORK_MODE_S  0
/** ECDSA_ECC_CURVE : R/W; bitpos: [2]; default: 0;
 *  The ecc curve select bit of ECDSA Accelerator.  0: P-192.  1: P-256.
 */
#define ECDSA_ECC_CURVE    (BIT(2))
#define ECDSA_ECC_CURVE_M  (ECDSA_ECC_CURVE_V << ECDSA_ECC_CURVE_S)
#define ECDSA_ECC_CURVE_V  0x00000001U
#define ECDSA_ECC_CURVE_S  2
/** ECDSA_SOFTWARE_SET_K : R/W; bitpos: [3]; default: 0;
 *  The source of k select bit. 0: k is automatically generated by hardware. 1: k is
 *  written by software.
 */
#define ECDSA_SOFTWARE_SET_K    (BIT(3))
#define ECDSA_SOFTWARE_SET_K_M  (ECDSA_SOFTWARE_SET_K_V << ECDSA_SOFTWARE_SET_K_S)
#define ECDSA_SOFTWARE_SET_K_V  0x00000001U
#define ECDSA_SOFTWARE_SET_K_S  3
/** ECDSA_SOFTWARE_SET_Z : R/W; bitpos: [4]; default: 0;
 *  The source of z select bit. 0: z is generated from SHA result. 1: z is written by
 *  software.
 */
#define ECDSA_SOFTWARE_SET_Z    (BIT(4))
#define ECDSA_SOFTWARE_SET_Z_M  (ECDSA_SOFTWARE_SET_Z_V << ECDSA_SOFTWARE_SET_Z_S)
#define ECDSA_SOFTWARE_SET_Z_V  0x00000001U
#define ECDSA_SOFTWARE_SET_Z_S  4
/** ECDSA_DETERMINISTIC_K : R/W; bitpos: [5]; default: 0;
 *  The source of hardware generated k. 0: k is generated by TRNG. 1: k is generated by
 *  deterministic derivation algorithm.
 */
#define ECDSA_DETERMINISTIC_K    (BIT(5))
#define ECDSA_DETERMINISTIC_K_M  (ECDSA_DETERMINISTIC_K_V << ECDSA_DETERMINISTIC_K_S)
#define ECDSA_DETERMINISTIC_K_V  0x00000001U
#define ECDSA_DETERMINISTIC_K_S  5
/** ECDSA_DETERMINISTIC_LOOP : R/W; bitpos: [21:6]; default: 0;
 *  The (loop number - 1) value in the deterministic derivation algorithm to derive k.
 */
#define ECDSA_DETERMINISTIC_LOOP    0x0000FFFFU
#define ECDSA_DETERMINISTIC_LOOP_M  (ECDSA_DETERMINISTIC_LOOP_V << ECDSA_DETERMINISTIC_LOOP_S)
#define ECDSA_DETERMINISTIC_LOOP_V  0x0000FFFFU
#define ECDSA_DETERMINISTIC_LOOP_S  6

/** ECDSA_CLK_REG register
 *  ECDSA clock gate register
 */
#define ECDSA_CLK_REG (DR_REG_ECDSA_BASE + 0x8)
/** ECDSA_CLK_GATE_FORCE_ON : R/W; bitpos: [0]; default: 0;
 *  Write 1 to force on register clock gate.
 */
#define ECDSA_CLK_GATE_FORCE_ON    (BIT(0))
#define ECDSA_CLK_GATE_FORCE_ON_M  (ECDSA_CLK_GATE_FORCE_ON_V << ECDSA_CLK_GATE_FORCE_ON_S)
#define ECDSA_CLK_GATE_FORCE_ON_V  0x00000001U
#define ECDSA_CLK_GATE_FORCE_ON_S  0

/** ECDSA_INT_RAW_REG register
 *  ECDSA interrupt raw register, valid in level.
 */
#define ECDSA_INT_RAW_REG (DR_REG_ECDSA_BASE + 0xc)
/** ECDSA_CALC_DONE_INT_RAW : RO/WTC/SS; bitpos: [0]; default: 0;
 *  The raw interrupt status bit  for the ecdsa_calc_done_int interrupt
 */
#define ECDSA_CALC_DONE_INT_RAW    (BIT(0))
#define ECDSA_CALC_DONE_INT_RAW_M  (ECDSA_CALC_DONE_INT_RAW_V << ECDSA_CALC_DONE_INT_RAW_S)
#define ECDSA_CALC_DONE_INT_RAW_V  0x00000001U
#define ECDSA_CALC_DONE_INT_RAW_S  0
/** ECDSA_SHA_RELEASE_INT_RAW : RO/WTC/SS; bitpos: [1]; default: 0;
 *  The raw interrupt status bit  for the ecdsa_sha_release_int interrupt
 */
#define ECDSA_SHA_RELEASE_INT_RAW    (BIT(1))
#define ECDSA_SHA_RELEASE_INT_RAW_M  (ECDSA_SHA_RELEASE_INT_RAW_V << ECDSA_SHA_RELEASE_INT_RAW_S)
#define ECDSA_SHA_RELEASE_INT_RAW_V  0x00000001U
#define ECDSA_SHA_RELEASE_INT_RAW_S  1

/** ECDSA_INT_ST_REG register
 *  ECDSA interrupt status register.
 */
#define ECDSA_INT_ST_REG (DR_REG_ECDSA_BASE + 0x10)
/** ECDSA_CALC_DONE_INT_ST : RO; bitpos: [0]; default: 0;
 *  The masked interrupt status bit  for the ecdsa_calc_done_int interrupt
 */
#define ECDSA_CALC_DONE_INT_ST    (BIT(0))
#define ECDSA_CALC_DONE_INT_ST_M  (ECDSA_CALC_DONE_INT_ST_V << ECDSA_CALC_DONE_INT_ST_S)
#define ECDSA_CALC_DONE_INT_ST_V  0x00000001U
#define ECDSA_CALC_DONE_INT_ST_S  0
/** ECDSA_SHA_RELEASE_INT_ST : RO; bitpos: [1]; default: 0;
 *  The masked interrupt status bit  for the ecdsa_sha_release_int interrupt
 */
#define ECDSA_SHA_RELEASE_INT_ST    (BIT(1))
#define ECDSA_SHA_RELEASE_INT_ST_M  (ECDSA_SHA_RELEASE_INT_ST_V << ECDSA_SHA_RELEASE_INT_ST_S)
#define ECDSA_SHA_RELEASE_INT_ST_V  0x00000001U
#define ECDSA_SHA_RELEASE_INT_ST_S  1

/** ECDSA_INT_ENA_REG register
 *  ECDSA interrupt enable register.
 */
#define ECDSA_INT_ENA_REG (DR_REG_ECDSA_BASE + 0x14)
/** ECDSA_CALC_DONE_INT_ENA : R/W; bitpos: [0]; default: 0;
 *  The interrupt enable bit  for the ecdsa_calc_done_int interrupt
 */
#define ECDSA_CALC_DONE_INT_ENA    (BIT(0))
#define ECDSA_CALC_DONE_INT_ENA_M  (ECDSA_CALC_DONE_INT_ENA_V << ECDSA_CALC_DONE_INT_ENA_S)
#define ECDSA_CALC_DONE_INT_ENA_V  0x00000001U
#define ECDSA_CALC_DONE_INT_ENA_S  0
/** ECDSA_SHA_RELEASE_INT_ENA : R/W; bitpos: [1]; default: 0;
 *  The interrupt enable bit  for the ecdsa_sha_release_int interrupt
 */
#define ECDSA_SHA_RELEASE_INT_ENA    (BIT(1))
#define ECDSA_SHA_RELEASE_INT_ENA_M  (ECDSA_SHA_RELEASE_INT_ENA_V << ECDSA_SHA_RELEASE_INT_ENA_S)
#define ECDSA_SHA_RELEASE_INT_ENA_V  0x00000001U
#define ECDSA_SHA_RELEASE_INT_ENA_S  1

/** ECDSA_INT_CLR_REG register
 *  ECDSA interrupt clear register.
 */
#define ECDSA_INT_CLR_REG (DR_REG_ECDSA_BASE + 0x18)
/** ECDSA_CALC_DONE_INT_CLR : WT; bitpos: [0]; default: 0;
 *  Set this bit to clear the ecdsa_calc_done_int interrupt
 */
#define ECDSA_CALC_DONE_INT_CLR    (BIT(0))
#define ECDSA_CALC_DONE_INT_CLR_M  (ECDSA_CALC_DONE_INT_CLR_V << ECDSA_CALC_DONE_INT_CLR_S)
#define ECDSA_CALC_DONE_INT_CLR_V  0x00000001U
#define ECDSA_CALC_DONE_INT_CLR_S  0
/** ECDSA_SHA_RELEASE_INT_CLR : WT; bitpos: [1]; default: 0;
 *  Set this bit to clear the ecdsa_sha_release_int interrupt
 */
#define ECDSA_SHA_RELEASE_INT_CLR    (BIT(1))
#define ECDSA_SHA_RELEASE_INT_CLR_M  (ECDSA_SHA_RELEASE_INT_CLR_V << ECDSA_SHA_RELEASE_INT_CLR_S)
#define ECDSA_SHA_RELEASE_INT_CLR_V  0x00000001U
#define ECDSA_SHA_RELEASE_INT_CLR_S  1

/** ECDSA_START_REG register
 *  ECDSA start register
 */
#define ECDSA_START_REG (DR_REG_ECDSA_BASE + 0x1c)
/** ECDSA_START : WT; bitpos: [0]; default: 0;
 *  Write 1 to start caculation of ECDSA Accelerator. This bit will be self-cleared
 *  after configuration.
 */
#define ECDSA_START    (BIT(0))
#define ECDSA_START_M  (ECDSA_START_V << ECDSA_START_S)
#define ECDSA_START_V  0x00000001U
#define ECDSA_START_S  0
/** ECDSA_LOAD_DONE : WT; bitpos: [1]; default: 0;
 *  Write 1 to input load done signal of ECDSA Accelerator. This bit will be
 *  self-cleared after configuration.
 */
#define ECDSA_LOAD_DONE    (BIT(1))
#define ECDSA_LOAD_DONE_M  (ECDSA_LOAD_DONE_V << ECDSA_LOAD_DONE_S)
#define ECDSA_LOAD_DONE_V  0x00000001U
#define ECDSA_LOAD_DONE_S  1
/** ECDSA_GET_DONE : WT; bitpos: [2]; default: 0;
 *  Write 1 to input get done signal of ECDSA Accelerator. This bit will be
 *  self-cleared after configuration.
 */
#define ECDSA_GET_DONE    (BIT(2))
#define ECDSA_GET_DONE_M  (ECDSA_GET_DONE_V << ECDSA_GET_DONE_S)
#define ECDSA_GET_DONE_V  0x00000001U
#define ECDSA_GET_DONE_S  2

/** ECDSA_STATE_REG register
 *  ECDSA status register
 */
#define ECDSA_STATE_REG (DR_REG_ECDSA_BASE + 0x20)
/** ECDSA_BUSY : RO; bitpos: [1:0]; default: 0;
 *  The status bits of ECDSA Accelerator. ECDSA is at 0: IDLE, 1: LOAD, 2: GET, 3: BUSY
 *  state.
 */
#define ECDSA_BUSY    0x00000003U
#define ECDSA_BUSY_M  (ECDSA_BUSY_V << ECDSA_BUSY_S)
#define ECDSA_BUSY_V  0x00000003U
#define ECDSA_BUSY_S  0

/** ECDSA_RESULT_REG register
 *  ECDSA result register
 */
#define ECDSA_RESULT_REG (DR_REG_ECDSA_BASE + 0x24)
/** ECDSA_OPERATION_RESULT : RO/SS; bitpos: [0]; default: 0;
 *  The operation result bit of ECDSA Accelerator, only valid when ECDSA calculation is
 *  done.
 */
#define ECDSA_OPERATION_RESULT    (BIT(0))
#define ECDSA_OPERATION_RESULT_M  (ECDSA_OPERATION_RESULT_V << ECDSA_OPERATION_RESULT_S)
#define ECDSA_OPERATION_RESULT_V  0x00000001U
#define ECDSA_OPERATION_RESULT_S  0
/** ECDSA_K_VALUE_WARNING : RO/SS; bitpos: [1]; default: 0;
 *  The k value warning bit of ECDSA Accelerator, valid when k value is bigger than the
 *  curve order, then actually taken k = k mod n.
 */
#define ECDSA_K_VALUE_WARNING    (BIT(1))
#define ECDSA_K_VALUE_WARNING_M  (ECDSA_K_VALUE_WARNING_V << ECDSA_K_VALUE_WARNING_S)
#define ECDSA_K_VALUE_WARNING_V  0x00000001U
#define ECDSA_K_VALUE_WARNING_S  1

/** ECDSA_DATE_REG register
 *  Version control register
 */
#define ECDSA_DATE_REG (DR_REG_ECDSA_BASE + 0xfc)
/** ECDSA_DATE : R/W; bitpos: [27:0]; default: 36716656;
 *  ECDSA version control register
 */
#define ECDSA_DATE    0x0FFFFFFFU
#define ECDSA_DATE_M  (ECDSA_DATE_V << ECDSA_DATE_S)
#define ECDSA_DATE_V  0x0FFFFFFFU
#define ECDSA_DATE_S  0

/** ECDSA_SHA_MODE_REG register
 *  ECDSA control SHA register
 */
#define ECDSA_SHA_MODE_REG (DR_REG_ECDSA_BASE + 0x200)
/** ECDSA_SHA_MODE : R/W; bitpos: [2:0]; default: 0;
 *  The work mode bits of SHA Calculator in ECDSA Accelerator. 1: SHA-224. 2: SHA-256.
 *  Others: invalid.
 */
#define ECDSA_SHA_MODE    0x00000007U
#define ECDSA_SHA_MODE_M  (ECDSA_SHA_MODE_V << ECDSA_SHA_MODE_S)
#define ECDSA_SHA_MODE_V  0x00000007U
#define ECDSA_SHA_MODE_S  0

/** ECDSA_SHA_START_REG register
 *  ECDSA control SHA register
 */
#define ECDSA_SHA_START_REG (DR_REG_ECDSA_BASE + 0x210)
/** ECDSA_SHA_START : WT; bitpos: [0]; default: 0;
 *  Write 1 to start the first caculation of SHA Calculator in ECDSA Accelerator. This
 *  bit will be self-cleared after configuration.
 */
#define ECDSA_SHA_START    (BIT(0))
#define ECDSA_SHA_START_M  (ECDSA_SHA_START_V << ECDSA_SHA_START_S)
#define ECDSA_SHA_START_V  0x00000001U
#define ECDSA_SHA_START_S  0

/** ECDSA_SHA_CONTINUE_REG register
 *  ECDSA control SHA register
 */
#define ECDSA_SHA_CONTINUE_REG (DR_REG_ECDSA_BASE + 0x214)
/** ECDSA_SHA_CONTINUE : WT; bitpos: [0]; default: 0;
 *  Write 1 to start the latter caculation of SHA Calculator in ECDSA Accelerator. This
 *  bit will be self-cleared after configuration.
 */
#define ECDSA_SHA_CONTINUE    (BIT(0))
#define ECDSA_SHA_CONTINUE_M  (ECDSA_SHA_CONTINUE_V << ECDSA_SHA_CONTINUE_S)
#define ECDSA_SHA_CONTINUE_V  0x00000001U
#define ECDSA_SHA_CONTINUE_S  0

/** ECDSA_SHA_BUSY_REG register
 *  ECDSA status register
 */
#define ECDSA_SHA_BUSY_REG (DR_REG_ECDSA_BASE + 0x218)
/** ECDSA_SHA_BUSY : RO; bitpos: [0]; default: 0;
 *  The busy status bit of SHA Calculator in ECDSA Accelerator. 1:SHA is in
 *  calculation. 0: SHA is idle.
 */
#define ECDSA_SHA_BUSY    (BIT(0))
#define ECDSA_SHA_BUSY_M  (ECDSA_SHA_BUSY_V << ECDSA_SHA_BUSY_S)
#define ECDSA_SHA_BUSY_V  0x00000001U
#define ECDSA_SHA_BUSY_S  0

/** ECDSA_MESSAGE_MEM register
 *  The memory that stores message.
 */
#define ECDSA_MESSAGE_MEM (DR_REG_ECDSA_BASE + 0x280)
#define ECDSA_MESSAGE_MEM_SIZE_BYTES 32

/** ECDSA_R_MEM register
 *  The memory that stores r.
 */
#define ECDSA_R_MEM (DR_REG_ECDSA_BASE + 0xa00)
#define ECDSA_R_MEM_SIZE_BYTES 32

/** ECDSA_S_MEM register
 *  The memory that stores s.
 */
#define ECDSA_S_MEM (DR_REG_ECDSA_BASE + 0xa20)
#define ECDSA_S_MEM_SIZE_BYTES 32

/** ECDSA_Z_MEM register
 *  The memory that stores software written z.
 */
#define ECDSA_Z_MEM (DR_REG_ECDSA_BASE + 0xa40)
#define ECDSA_Z_MEM_SIZE_BYTES 32

/** ECDSA_QAX_MEM register
 *  The memory that stores x coordinates of QA or software written k.
 */
#define ECDSA_QAX_MEM (DR_REG_ECDSA_BASE + 0xa60)
#define ECDSA_QAX_MEM_SIZE_BYTES 32

/** ECDSA_QAY_MEM register
 *  The memory that stores y coordinates of QA.
 */
#define ECDSA_QAY_MEM (DR_REG_ECDSA_BASE + 0xa80)
#define ECDSA_QAY_MEM_SIZE_BYTES 32

#ifdef __cplusplus
}
#endif
