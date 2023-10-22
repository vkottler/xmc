/**
 * \file
 * \brief Some interfaces used for test and development.
 */
#pragma once

extern "C"
{
/* toolchain */
#include <semihost.h>
}

/* internal */
#include "generated/structs/itm.h"

/*
 * Must be set by a debugger.
 */
extern volatile bool enable_semihosting;

extern int stdin_fd;
const char *prompt = "$ ";

void initialize_semihosting()
{
    if (enable_semihosting)
    {
        stdin_fd = sys_semihost_open(":tt", 0);
        if (stdin_fd != -1)
        {
            printf(prompt);
        }
    }
}

void initialize_itm()
{
    ARM::ITM->set_TCR_ITMENA();
    for (size_t i = 0; i < ARM::itm::TER_length; i++)
    {
        ARM::ITM->TER[i] = 0xffffffff;
    }
}

void write_byte(char data, size_t index = 0)
{
    while (!ARM::ITM->STIM[index].get_u32_FIFOREADY())
    {
        ;
    }

    ARM::ITM->STIM[index].u8 = data;
}
