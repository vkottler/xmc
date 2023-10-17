/* third-party */
#include "hal-xmc4700/generated/structs/port5.h"

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

int main(void)
{
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

    while (true)
    {
        led1_state(state);
        led2_state(not state);
        state = not state;
    }

    return 0;
}
