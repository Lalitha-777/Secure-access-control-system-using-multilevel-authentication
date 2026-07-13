# Secure-access-control-system-using-multilevel-authentication.
INTRODUCTION:

This project is an embedded security system designed to provide secure access to restricted areas. The project is built around the LPC2148 microcontroller and uses three levels of authentication:
1. Fingerprint verification
2. Password authentication
3. Administrator authorization

When authentication is successful, a DC motor unlocks the door and the LCD displays the system status and User fingerprint data and other required information are stored securely in EEPROM. This project is suitable for places where high security is required, such as offices, laboratories, banks and restricted areas.

AIM OF THE PROJECT:

The aim of this project is to overcome the traditional access control systems. As we know traditional access control systems that uses only keys, RFID cards (or) passwords are not highly secure because keys can be lost, cards can be stolen and passwords can be guessed (or) shared & this can lead to unauthorized access. So, to overcome these security issues by implementing multilevel authentication to provide higher level of security and reliability.

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

HARDWARE COMPONENTS:

The hardware components used in this project are:

LPC2148 ARM7 Microcontroller – Controls the entire system and processes authentication.
R305 Fingerprint Sensor – Captures and verifies fingerprints.
4×4 Keypad – Used to enter the password.
16×2 LCD Display – Displays system messages and authentication status.
EEPROM – Stores user-related data permanently.
L293D Motor Driver – Drives the DC motor by providing the required current.
DC Motor – Simulates the door lock/unlock mechanism.
Power Supply – Provides the required operating voltage to the system.
Connecting Wires and PCB/Breadboard – Used for circuit connections.

SOFTWARE USED:

The software used to develop this project includes:

Embedded C – Programming language used to write the application.
Keil uVision IDE – Used to write, compile, and debug the Embedded C program.
Flash Magic – Used to upload the compiled HEX file into the LPC2148 microcontroller.
Proteus – Used for circuit simulation and testing before hardware implementation.

WORKING PRINCIPLE:

The Secure Access Control System Using Multi-Level Authentication works by verifying the identity of a user through multiple authentication stages before granting access. The LPC2148 ARM7 microcontroller acts as the central controller, coordinating all hardware modules and making authentication decisions.

When the system is powered on, the 16×2 LCD displays a welcome message and prompts the user to place a finger on the R305 fingerprint sensor. The sensor captures the fingerprint and compares it with the enrolled fingerprint templates. The verification result is transmitted to the LPC2148 through UART communication.

If the fingerprint is successfully verified, the microcontroller prompts the user to enter the password using the 4×4 keypad. The entered password is compared with the password stored in the EEPROM.

If both the fingerprint and password are correct, the LPC2148 sends control signals to the L293D motor driver, which drives the DC motor to unlock the door for a predefined time. The LCD displays "Access Granted" during this process. After the specified delay, the motor rotates in the opposite direction (or stops, depending on the mechanism) to lock the door again.

If either the fingerprint or password verification fails, the LCD displays "Access Denied", the door remains locked, and the user must restart the authentication process.

The system also provides an administrator mode, protected by an admin password. After successful admin authentication, the administrator can enroll new fingerprints, delete existing users, or manage authentication records stored in the system.

Thus, the combination of fingerprint authentication, password verification, and administrator-controlled management ensures that only authorized users can access the protected area, providing a secure and reliable access control system.

AUTHENTICATION FLOW:

                    START
                      │
                      ▼
                  Power ON
                      │
                      ▼
              LCD : WELCOME
                      │
                      ▼
        LEVEL 1 : PLACE FINGER
                      │
                      ▼
          Fingerprint Matched?
             ┌────────┴────────┐
             │                 │
            YES               NO
             │                 │
             ▼                 ▼
   LEVEL 2 : ENTER PASSWORD   ACCESS DENIED
             │              (Door Locked)
             ▼
       Password Correct?
             ┌────────┴────────┐
             │                 │
            YES               NO
             │                 │
             ▼                 ▼
      DOOR UNLOCKED      ACCESS DENIED
     (L293D + DC Motor)  (Door Locked)
             │
             ▼
      LEVEL 3 : ADMIN MODE
      (Admin Authentication)
             │
             ▼
  Enroll / Delete / Manage Users
             │
             ▼
            END


RESULT:

The Secure Access Control System Using Multi-Level Authentication was successfully implemented and tested.

Level 1: The system successfully verified the user's fingerprint using the R305 fingerprint sensor.
Level 2: After successful fingerprint verification, the user entered the correct password through the 4×4 keypad, and the system authenticated it.
Level 3: The administrator successfully logged in using the admin password to enroll, delete, and manage user records.

When all required authentication steps were successful, the L293D motor driver activated the DC motor, unlocking the door, and the LCD displayed "Access Granted."
If the fingerprint or password was incorrect, the LCD displayed "Access Denied," and the door remained locked.
The EEPROM successfully stored user data permanently, even after power was turned off.

APPLICATIONS:

This project can be used in places where high security and controlled access are required, such as:

Offices and corporate buildings
Banks and financial institutions
Laboratories and research centers
Server rooms and data centers
Hospitals and pharmacies
Government and defense organizations
Educational institutions
Industrial restricted areas
Residential smart homes

FUTURE SCCOPE:

The project can be enhanced with the following features:

Integrate IoT for remote monitoring and access control.
Develop a mobile application to manage users and view access logs.
Add face recognition as an additional authentication method.
Implement OTP (One-Time Password) or RFID for enhanced security.
Send GSM/Wi-Fi alerts for unauthorized access attempts.
Store access logs on the cloud for monitoring and analysis.
Add a battery backup to ensure operation during power failures.
Support multiple administrators with different access privileges.

CONCLUSION:

The Secure Access Control System Using Multilevel Authentication was successfully designed and implemented using the LPC2148 microcontroller. The system provides three levels of authentication:

Level 1: Fingerprint verification.
Level 2: User password verification.
Level 3: Admin authentication for user enrollment and management.

By combining these three levels, the system offers enhanced security and ensures that only authorized users can access the protected area, while only the administrator can manage user data. The use of the R305 fingerprint sensor, EEPROM, L293D motor driver, and LCD makes the system reliable, efficient, and suitable for high-security applications.






