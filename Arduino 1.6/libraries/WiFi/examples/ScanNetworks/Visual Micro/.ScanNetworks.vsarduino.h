/* 
	Editor: http://www.visualmicro.com
	        visual micro and the arduino ide ignore this code during compilation. this code is automatically maintained by visualmicro, manual changes to this file will be overwritten
	        the contents of the Visual Micro sketch sub folder can be deleted prior to publishing a project
	        all non-arduino files created by visual micro and all visual studio project or solution files can be freely deleted and are not required to compile a sketch (do not delete your own code!).
	        note: debugger breakpoints are stored in '.sln' or '.asln' files, knowledge of last uploaded breakpoints is stored in the upload.vmps.xml file. Both files are required to continue a previous debug session without needing to compile and upload again
	
	Hardware: Generic ESP8266 Module, Platform=esp8266, Package=esp8266
*/

#define __ESP8266_ESp8266__
#define __ESP8266_ESP8266__
#define ARDUINO 165
#define ARDUINO_MAIN
#define F_CPU 80000000L
#define printf iprintf
#define __ESP8266__
#define __ets__
#define ICACHE_FLASH
#define F_CPU 80000000L
#define ARDUINO 165
#define ARDUINO_ESP8266_ESP01
#define ARDUINO_ARCH_ESP8266
extern "C" void __cxa_pure_virtual() {;}

//
//
void printMacAddress();
void listNetworks();
void printEncryptionType(int thisType);

#include "C:\Users\sego90\AppData\Roaming\arduino15\packages\esp8266\hardware\esp8266\1.6.5-947-g39819f0\variants\generic\pins_arduino.h" 
#include "C:\Users\sego90\AppData\Roaming\arduino15\packages\esp8266\hardware\esp8266\1.6.5-947-g39819f0\cores\esp8266\arduino.h"
#include <ScanNetworks.ino>
