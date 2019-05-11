echo off
SET PROJECT_NAME=Button
SET HEX=%cd%\build\%PROJECT_NAME%.hex

REM Flash code to the microcontroller
avrdude.exe -e -P usb -c USBasp -p Atmega32 -e -U "flash:w:%HEX%:a"