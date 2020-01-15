Hay un poco de info útil sobre Node-RED y RPi en  
https://github.com/Glioce/MiniBrazoRS

Medir presión  
https://dspace.ups.edu.ec/bitstream/123456789/4482/1/UPS-CT001920.pdf  

Opciones para medir presión  
https://www.disai.net/producto/celulas-carga-traccion-compresion-utilcell/  
https://www.flintec.com/mx/sensores-de-peso/celulas-de-carga/plataforma  
https://www.flintec.com/mx/sensores-de-peso/celulas-de-carga/ultraprecision  

Cómo conectar MAX6675. Hilo en foro desde 2016 hasta feb 2019  
https://www.raspberrypi.org/forums/viewtopic.php?t=145568  

## Bibliotecas para MAX6675

### Adafruit / Arduino
Biblioteca para Arduino  
https://github.com/adafruit/MAX6675-library  

### tuckie, node-alpha
Esta bib solo funciona con MAX31855, pero el fork de abajo agrega MAX6675.  
Desventajas: Usa bit-banging, y no el hardware SPI, restando eficiencia.  
Ventajas: Se puede usar casi cualquier pin y conectar varios sensores.  
https://github.com/Tuckie/max31855  
https://github.com/node-alpha/max31855  
Se intentó instalar con estas referencias pero no funcionó  
https://github.com/Tuckie/max31855/issues/10  
https://www.raspberrypi-spy.co.uk/2012/05/install-rpi-gpio-python-library/  
Se puede usar la biblioteca sin instalar, con el método mostrado más abajo.  
Sí funciona, pero a veces la lectura no cambia!  

### keiichishima
Esta bib no ha funcionado bien.
Parece que devuelve valores al azar (7.5 se repite mucho)  
https://github.com/keiichishima/RPiSensors  
Hay un fork que parece prometedor, pero tampoco funciona.  
https://github.com/vitiral/linsensors  

### apolo-ng/picoReflow
Proyecto de control de temperatura de un horno  
https://github.com/apollo-ng/picoReflow/blob/master/lib/oven.py  
Usa una librería similar a la de tukie (bitbanging y pines configurables) y falla de la misma forma :(  
https://github.com/apollo-ng/picoReflow/blob/master/lib/max6675.py

### tdack
Esta biblioteca permite elegir si se usa hardware SPI o bit-banging.  
En la terminal y en Node-RED funciona muy bien.  
https://github.com/tdack/MAX6675  

### Otras bibliotecas que no se han probado  
Un programa escrito en C y compilado es llamado por otro programa escrito en Python  
No suena muy eficiente  
http://www.bristolwatch.com/rpi/geany.htm  
Para NodeJS. Hay una serie de dependencias  
https://www.npmjs.com/package/max6675-raspi  
Un script corto  
https://raspberrypi.stackexchange.com/questions/63556/using-a-max6675-with-raspberry-pi-3  

## Usar python en Node-RED
Interpretar Python dentro de Node-RED  
https://flows.nodered.org/node/node-red-contrib-python-function  
https://flows.nodered.org/node/node-red-contrib-python3-function  
Para usar módulos externos se usará este método  
https://github.com/arnauorriols/node-red-contrib-python-function/issues/3  

Ejecutar un archivo py  
https://flows.nodered.org/node/node-red-contrib-pythonshell

Crear servidor que se comunica con Node-RED y ejecuta archivos py  
Está en fase pre-alpha!  
https://pypi.org/project/pynodered/  

## Cambios en la configuración de la RPi
Hasta ahora se han realizdo los siguientes cambios:  
+ Activar I2C y SPI desde `raspi-config` (También se puede cambiar desde el menú Inicio / Preferecias / Configuración de Raspberry Pi / Interfaces)  
+ Modificación de archivos en /etc/ (revisar nombre de arvhivos)  
