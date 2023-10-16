/* third-party */
#include "hal-xmc4700/generated/structs/port5.h"

void led2_state(bool state)
{
    if (state)
    {
        XMC4700::PORT5->set_OMR_PS8();
    }
    else
    {
        XMC4700::PORT5->clear_OMR_PS8();
    }
}

void led1_state(bool state)
{
    if (state)
    {
        XMC4700::PORT5->set_OMR_PS9();
    }
    else
    {
        XMC4700::PORT5->clear_OMR_PS9();
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
    XMC4700::PORT5->set_IOCR8_PC8(XMC4700::PORT5_IOCR8_PC8::value9);
    XMC4700::PORT5->set_IOCR8_PC9(XMC4700::PORT5_IOCR8_PC9::value9);

    bool state = false;

    while (true)
    {
        led1_state(state);
        led2_state(not state);
        state = not state;
    }

    return 0;
}
