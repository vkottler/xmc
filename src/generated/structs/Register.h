/**
 * \file
 * \brief Generated by ifgen (3.1.5).
 */
#pragma once

#include "../ifgen/common.h"

namespace ARM
{

/**
 * A generic 32-bit container.
 */
struct [[gnu::packed]] Register
{
    /* Constant attributes. */
    static constexpr std::size_t size = 4; /*!< Register's size in bytes. */

    /* Fields. */
    union
    {
        uint32_t u32;
        uint8_t u8;
        uint16_t u16;
    };

    /* Methods. */
};

static_assert(sizeof(Register) == Register::size);

}; // namespace ARM