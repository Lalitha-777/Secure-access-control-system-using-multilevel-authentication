# Secure-access-control-system-using-multilevel-authentication.
INTRODUCTION:
→ This project is an embedded security system designed to provide secure access to restricted areas.
→ The project is built around the LPC2148 microcontroller and uses three levels of authentication:
1. Fingerprint verification
2. Password authentication
3. Administrator authorization
→ When authentication is successful, a DC motor unlocks the door and the LCD displays the system status.
→ User fingerprint data and other required information are stored securely in EEPROM.
→ This project is suitable for places where high security is required, such as offices, laboratories, banks and restricted areas.

AIM OF THE PROJECT:
→ The aim of this project is to overcome the traditional access control systems.
→ As we know traditional access control systems that uses only keys, RFID cards (or) passwords are not highly secure.
→ Because, keys can be lost, cards can be stolen and passwords can be guessed (or) shared & this can lead to unauthorized access.
→ So, to overcome these security issues by implementing multilevel authentication to provide higher level of security and reliability.

BLOCK DIAGRAM:
The block diagram shows how all the hardware components are connected and communicate with the LPC2148 microcontroller, which acts as the central controller.
Blocks:
Power Supply
LPC2148 ARM7 Microcontroller
R305 Fingerprint Sensor
4×4 Keypad
16×2 LCD Display
EEPROM
L293D Motor Driver
DC Motor (Door Lock)
Buzzer
Data Flow:
Fingerprint Sensor + Keypad → LPC2148 → Authentication → L293D → DC Motor (Door Unlock/Lock) → LCD displays the status.
<img width="1536" height="1024" alt="ChatGPT Image Jul 13, 2026, 11_03_57 AM" src="https://github.com/user-attachments/assets/3c3e9365-c000-415c-9ee8-03bb3446db3f" />

