A small project done on the STM32F401RE microcontroller. This project uses
Pulse-Width Modulation (PWM) to control the brightness of two different LEDs.

It also has two buttons that accept "click" input: one for "pausing" the session
(haults the PWM channel, so that the brightness of the LEDs are kept in place),
and one for toggling the sound that comes from the passive buzzer included in the
circuit.

The user button (blue button on the F401RE, B2) pauses/resumes the session,
and the button on the breadboard toggles the passive buzzer.

The circuit can be found by viewing the "Circuit Diagram" file. It utilizes a breadboard.
