# pixel_flow
==========

Userspace Raspberry Pi PWM library for WS281X LEDs
This includes WS2812 and SK6812RGB RGB LEDs
Preliminary support is now included for SK6812RGBW LEDs (yes, RGB + W)

### QT
![alt text](https://github.com/coppermilk/pixel_flow/blob/main/img/Pixel_flow.gif)

### Background:

The BCM2835 in the Raspberry Pi has a PWM module that is well suited to
driving individually controllable WS281X LEDs.  Using the DMA, PWM FIFO,
and serial mode in the PWM, it's possible to control almost any number
of WS281X LEDs in a chain connected to the PWM output pin.

This library and test program set the clock rate of the PWM controller to
3X the desired output frequency and creates a bit pattern in RAM from an
array of colors where each bit is represented by 3 bits for the PWM
controller as follows.

    Bit 1 - 1 1 0
    Bit 0 - 1 0 0


### Hardware:

WS281X LEDs are generally driven at 5V, which requires that the data
signal be at the same level.  Converting the output from a Raspberry
Pi GPIO/PWM to a higher voltage through a level shifter is required.

It is possible to run the LEDs from a 3.3V - 3.6V power source, and
connect the GPIO directly at a cost of brightness, but this isn't
recommended.

The test program is designed to drive a 8x8 grid of LEDs from Adafruit
(http://www.adafruit.com/products/1487).  Please see the Adafruit
website for more information.

Know what you're doing with the hardware and electricity.  I take no
reponsibility for damage, harm, or mistakes.
