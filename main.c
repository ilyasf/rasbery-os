void main(void) {
    volatile unsigned int* const GPIO_FSEL1 = (unsigned int*)0x20200004;
    volatile unsigned int* const GPIO_SET0 = (unsigned int*)0x2020001C;
    volatile unsigned int* const GPIO_CLR0 = (unsigned int*)0x20200028;

    // Configure GPIO pin 16 as output
    *GPIO_FSEL1 |= (1 << 18);

    while (1) {
        // Turn LED on
        *GPIO_SET0 = (1 << 16);
        for (volatile int i = 0; i < 500000; i++);

        // Turn LED off
        *GPIO_CLR0 = (1 << 16);
        for (volatile int i = 0; i < 500000; i++);
    }
}
