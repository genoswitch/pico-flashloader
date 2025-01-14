//****************************************************************************
// Copyright 2021 Richard Hulme
//
// SPDX-License-Identifier: BSD-3-Clause
//
// Flashloader for the RP2040

#ifndef __FLASHLOADER_INCL__
#define __FLASHLOADER_INCL__

#include <stdint.h>

static const uint32_t FLASH_MAGIC1 = 0x8ecd5efb; // Randomly picked numbers
static const uint32_t FLASH_MAGIC2 = 0xc5ae52a9;

static const uint32_t FLASH_APP_UPDATED = 0xe3fa4ef2; // App has been updated

/**
 * pico-platform has a macro for '__packed __aligned(4)'
 * When including flashloader.h from another project, the error
 * "error: expected declaration specifiers or '...' before numeric constant" triggers for __aligned(4).
 * This change appears to fix it.
 *
 * The flashloader already depends on pico-platform so no cmake changes are needed.
 */
typedef struct __packed_aligned
{
    uint32_t magic1;
    uint32_t magic2;
    uint32_t length;
    uint32_t crc32;
    uint8_t data[];
} tFlashHeader;

#endif // __FLASHLOADER_INCL__
