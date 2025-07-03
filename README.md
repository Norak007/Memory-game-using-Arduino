# Simple Simon Game – Arduino Project

This is a simple memory game based on the classic "Simon Game", built using Arduino.  
It uses 3 LEDs and 3 buttons — no sound is included in this version.

## Components Used
- Arduino Uno
- 3 LEDs (Red, Green, Blue)
- 3 Push Buttons
- 3 × 220Ω resistors (for LEDs)
- 3 × 10KΩ resistors (for buttons)
- Breadboard + Jumper Wires

| LED Color | Arduino Pin |
|-----------|-------------|
| Red       | D2          |
| Green     | D3          |
| Blue      | D4          |

| Button Color | Arduino Pin |
|--------------|-------------|
| Red          | D5          |
| Green        | D6          |
| Blue         | D7          |

## How to Play
1. Watch the LED sequence.
2. Repeat the pattern using the buttons.
3. If you succeed, the level increases.
4. If you fail, it restarts from level 1.
