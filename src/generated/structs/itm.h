/**
 * \file
 * \brief Generated by ifgen (3.1.5).
 */
#pragma once

#include "../ifgen/common.h"
#include "Register.h"

namespace ARM
{

/**
 * Instrumentation Trace Macrocell Unit
 */
struct [[gnu::packed]] itm
{
    /* Constant attributes. */
    static constexpr std::size_t size = 4096; /*!< itm's size in bytes. */

    /* Fields. */
    static constexpr std::size_t STIM_length = 32;
    Register STIM[STIM_length];
    static constexpr std::size_t reserved_padding0_length = 864;
    const uint32_t reserved_padding0[reserved_padding0_length] = {};
    uint32_t TER;
    static constexpr std::size_t reserved_padding1_length = 15;
    const uint32_t reserved_padding1[reserved_padding1_length] = {};
    uint32_t TPR;
    static constexpr std::size_t reserved_padding2_length = 15;
    const uint32_t reserved_padding2[reserved_padding2_length] = {};
    uint32_t TCR;
    static constexpr std::size_t reserved_padding3_length = 83;
    const uint32_t reserved_padding3[reserved_padding3_length] = {};
    uint32_t PID4;
    uint32_t PID5;
    uint32_t PID6;
    uint32_t PID7;
    uint32_t PID0;
    uint32_t PID1;
    uint32_t PID2;
    uint32_t PID3;
    uint32_t CID0;
    uint32_t CID1;
    uint32_t CID2;
    uint32_t CID3;

    /* Methods. */
};

static_assert(sizeof(itm) == itm::size);

static volatile itm *const ITM = reinterpret_cast<itm *>(0xE0000000);

}; // namespace ARM
