# Keypad Password Lock

## Overview
This project turns an ESP32 and 4x4 matrix keypad into a PIN-based access-control system. The user enters a password through the keypad and the ESP32 compares it with the stored PIN before showing an accepted or rejected result.

## Components
- ESP32 DevKit V1
- 4x4 matrix keypad
- Green LED
- Red LED
- Buzzer
- 220-ohm resistors
- Breadboard
- Jumper wires

## Core Concepts
- Matrix keypad scanning
- Password/PIN authentication
- String input
- State handling
- User feedback
- Embedded security basics

## How It Works
1. The ESP32 waits for keypad input.
2. Number keys are added to the entered PIN.
3. A confirmation key submits the PIN.
4. The program compares the entered value with the stored password.
5. A correct PIN activates the success indicator.
6. An incorrect PIN activates the denied indicator/buzzer.
7. The input is cleared for the next attempt.

## Testing
- Enter the correct PIN and verify the success response.
- Enter an incorrect PIN and verify the denied response.
- Test clearing an entry before submission.
- Test several attempts in sequence.

## What I Learned
This project helped me work with matrix input and build authentication logic without relying on RFID. It also provides a foundation for combining multiple authentication methods later.

## Future Improvements
- Add an OLED display.
- Add a servo-operated lock.
- Limit failed attempts.
- Add RFID for two-factor authentication.
- Store multiple user PINs.

## Status
Planned build for the August 27, 2026 catch-up sprint. Do not mark complete until physically built and tested.
