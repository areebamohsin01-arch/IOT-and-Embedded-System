
Name  : Areeba Mohsin 
Reg No: 23_NTU_CS_1138
Sec   : BS-CS-5th-B

________________________________________________________________
----------------------------------------------------------------



Task 1 – OLED + LED + Buzzer Mode Controller

In this task, I developed a circuit using the ESP32 ,
where multiple components such as LEDs, buttons, buzzer, 
and an OLED display were connected through GPIO pins.
The code was written in VS Code, and I used the Wokwi 
simulator which was already linked through diagram.json and
 wokwi.toml files.

Each component was assigned to specific GPIO pins:

Component	GPIO Pin	Function
LED 1           GPIO 2	     First LED (Normal ON/OFF)
LED 2	        GPIO 4       Second LED (Alternate blink)
LED 3    	GPIO 5	     PWM fade LED
Mode Button	GPIO 25	     Switch for changing modes
Reset Button	GPIO 27      To reset all LEDs
Buzzer    	GPIO 15	     Beeps on mode change
OLED Display	21,22        Shows current mode text

After uploading the code on Wokwi, I designed the full circuit virtually and
 verified its working.
The project has four modes: All OFF, Alternate Blink, All ON, and PWM Fade.
The OLED screen displays the current mode, while the buzzer gives short tones 
as feedback whenever the mode changes.
Finally, I drew the handmade circuit diagram, scanned it, and added it to
 the report along with screenshots, videos, and all VS Code project files.

Wokwi link : https://wokwi.com/projects/445801309117058049

video and screen short directory:

C:\Users\a\Desktop\5TH SEM\Embedded and IOT system\Projectgit\Assignment_1_23-NTU-CS-1138\Task_1\ss and Vedio




Task 2 – LED Mode Controller with OLED and Button Press Detection

In this task, I made a simpler circuit using the ESP32 GPIO pins to detect short press
 and long press actions on a single button.
The hardware and connections were created in Wokwi, and the code was written and tested in VS Code.

The components and pin mapping were as follows:

Component	GPIO Pin	Function
Push Button	GPIO 25	     Detects short or long press
LED     	GPIO 2	     Toggles on short press
Buzzer	        GPIO 15	     Turns ON for long press
OLED Display  (GPIO 21,22)   Displays message for press type

When the button is pressed for a short time, the LED toggles between ON and OFF,
and the OLED displays “Short Press: LED Toggle.”
When it’s pressed for longer than 1.5 seconds, the buzzer turns ON with a tone, 
and the OLED shows “Long Press: Buzzer.”

Wokwi link: https://wokwi.com/projects/445803461404542977

vedio ans screenshots directory:
C:\Users\a\Desktop\5TH SEM\Embedded and IOT system\Projectgit\Assignment_1_23-NTU-CS-1138\Task_2\ss and Vedio

