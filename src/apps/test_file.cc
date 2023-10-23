/* third-party */
#include "hal-xmc4700/generated/structs/port5.h"

/* internal */
#include "testing.h"

/* toolchain */
#include <stdio.h>

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

/*
 * Must be set by a debugger.
 */
volatile bool enable_cli = false;

int main(void)
{
    /* Set initial output values. */
    bool led1_state_val = false;
    bool led2_state_val = false;
    led1_state(led1_state_val);
    led2_state(led2_state_val);

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

    initialize_semihosting();

    char input[BUFSIZ];

    while (true)
    {
        if (iterations % 100000 == 0)
        {
            led1_state(state);
            led2_state(not state);
            state = not state;
        }

        if (enable_cli and gets(input) != NULL)
        {
            if (!input[0])
            {
                printf(prompt);
                continue;
            }

            if (strcmp(input, "led1") == 0)
            {
                led1_state_val = not led1_state_val;
                led1_state(led1_state_val);
                printf("Toggling LED 1 %s.\n", led1_state_val ? "on" : "off");
            }
            else if (strcmp(input, "led2") == 0)
            {
                led2_state_val = not led2_state_val;
                led2_state(led2_state_val);
                printf("Toggling LED 2 %s.\n", led2_state_val ? "on" : "off");
            }
            else if (strcmp(input, "cli") == 0)
            {
                /* Toggle CLI. */
                enable_cli = not enable_cli;
            }
            else
            {
                printf("input: '%s'\n", input);
            }

            printf(prompt);
        }

        iterations++;
    }

    return 0;
}
