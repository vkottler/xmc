/* third-party */
#include "generated/structs/itm.h"
#include "hal-xmc4700/generated/structs/port5.h"

extern "C"
{
/* toolchain */
#include <semihost.h>

    /*
     * Must be set by a debugger.
     */
    volatile bool enable_semihosting = false;
}

inline void led2_state(bool state)
{
    if (state)
    {
        XMC4700::PORT5->set_OMR_PS8();
    }
    else
    {
        XMC4700::PORT5->set_OMR_PR8();
    }
}

inline void led1_state(bool state)
{
    if (state)
    {
        XMC4700::PORT5->set_OMR_PS9();
    }
    else
    {
        XMC4700::PORT5->set_OMR_PR9();
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

int main(void)
{
    ARM::ITM->set_TCR_ITMENA();
    for (size_t i = 0; i < ARM::itm::TER_length; i++)
    {
        ARM::ITM->TER[i] = 0xffffffff;
    }

    /* Set initial output values. */
    led1_state(false);
    led2_state(false);

    /* Set drive strength. What class pads are these? */
    // P5.9
    // P5.8

    /* Configure pin (recommended before setting to output). */

    /* Set LED pins as outputs. */
    XMC4700::PORT5->set_IOCR8_PC8(
        XMC4700::PORT5_IOCR0_PC3::output_push_pull_general_purpose_output);
    XMC4700::PORT5->set_IOCR8_PC9(
        XMC4700::PORT5_IOCR0_PC3::output_push_pull_general_purpose_output);

    bool state = false;

    int iterations = 0;
    while (true)
    {
        if (iterations % 100000 == 0)
        {
            led1_state(state);
            led2_state(not state);
            state = not state;
        }

        if (iterations % 10000 == 0)
        {
            write_byte('H');
            write_byte('e');
            write_byte('l');
            write_byte('l');
            write_byte('o');
            write_byte(',');
            write_byte(' ');
            write_byte('w');
            write_byte('o');
            write_byte('r');
            write_byte('l');
            write_byte('d');
            write_byte('!');
            write_byte(' ');
            write_byte('(');
            write_byte('I');
            write_byte('T');
            write_byte('M');
            write_byte(')');
            write_byte('\n');

            if (enable_semihosting)
            {
                sys_semihost_write0("Hello, world! (semihost)\n");
            }
        }

        /* try checking user input here? */
        iterations++;
    }

    return 0;
}
