# Horno y Node-RED

## Trabajo previo
Aquí hay un poco de info útil sobre Node-RED y RPi  
https://github.com/Glioce/MiniBrazoRS  
Cómo escribir un valor en nodo numeric (Node-RED Dashboard)  
https://github.com/node-red/node-red-dashboard/issues/509  

La perilla de control de temperatura que estaba instalada en el horno tiene un valor máximo de
450 ^F = 232.2 ^C  
El horno se ha calentado hasta 300 ^C con las resistencia al rojo vivo durante 10 minutos seguidos,
no se presentaron problemas.  
Las primeras veces que se calentó generó humo. Después solo se veía el aire caliente saliendo de
la parte superior del horno.  

### Componentes de circuito para controlar temperatura de resistencias
Arduino Nano  
Optoacoplador **H11AA** para detectar cruce por cero  
Optoacoplador **MOC3011** para activar triac  
Triac **BTA24** para encender resistencias  

### Módulo MAX6675
Termocople tipo K  
Rango de temperatura 0 - 1023.75 ^C  
Máximo 4 lecturas por segundo  
Lectura de 12 bits en el rango 0 - 4095, en unidades de 0.25 ^C  
Exactitud +-2 ^C de 0 a 700 ^C  
+- 5 ^C de 700 a 1000 ^C  
Parece que esa exatitud es suficiente  

### Colores de cables en GPIO de RPi
Versión 1
| Color | Función | Pin en Pi | Nombre | Pin en conector Molex 
|------------|------|----|-----------|------------------------
| Rojo-negro | MISO | 21 | MISO      | 1
| Café       | CS   | 24 | CE0       | 2
| Amarillo   | SCK  | 23 | SCLK      | 3
| Naranja    | 3.3V | 17 | 3V3       | 4
| Negro      | GND  | Por fuera  | - | 5 
| Azul       | Rel1 | 16 | BCM23     | 6
| Azul-negro | Rel2 | 18 | BCM24     | 7
| Rojo       | 5V   | Por fuera  | - | 8

Versión 2
| Color | Función | Pin en Pi | Nombre | Pin en conector Molex 
|------------|------|----|------|------------------------
| Rojo-negro | MISO | 21 | MISO | 1
| Café       | CS   | 24 | CE0  | 2
| Amarillo   | SCK  | 23 | SCLK | 3
| Naranja    | 3.3V | 17 | 3V3  | 4
| Negro      | GND  | 39 | GND  | 5 
| Azul       | TX   | 16 | TXD  | 6
| Azul-negro | RX   | 18 | RXD  | 7
| Rojo       | 5V   | 2  | 5V   | 8

Triac  
https://es.wikipedia.org/wiki/Triac  
https://www.electronics-tutorials.ws/power/triac.html  

Circuito de detección de cruce por cero  
https://www.prometec.net/zero-crossing-detection/  
http://www.bristolwatch.com/ele2/zcnew.htm

## Especificaciones del horno
nutrichef - Vertical Rotisserie Oven  
Model No.: PKRT97  
Power: 120V / 60Hz / 1500W  
Capacity: 23L

## Especificaciones de gato (jack)
Voltage: DC 12 V +- 1  
Current: 11 A  
Power: 75 W  
Overcurrent protection: 15 A  
Lifting range: 11-34 cm  
Max Loading weight: 2000 kg  
Cable de alimentación: Café +12 V, Azul GND  
Cables de interruptores de límites: azul, blanco y café  
Para controlar el gato desde la RPi se pueden puentear los botones con otros relevadores o transistores  

Falta sensor para medir la presión.  

## Medir presión  
En este documento se describen varias opciones para medir presión  
https://dspace.ups.edu.ec/bitstream/123456789/4482/1/UPS-CT001920.pdf  

Opciones para medir presión  
https://www.disai.net/producto/celulas-carga-traccion-compresion-utilcell/  
https://www.flintec.com/mx/sensores-de-peso/celulas-de-carga/plataforma  
https://www.flintec.com/mx/sensores-de-peso/celulas-de-carga/ultraprecision  

Otros  
https://forum.arduino.cc/index.php?topic=135043.0  
http://www.nerdkits.com/videos/weighscale/  


## Bibliotecas para MAX6675
Muchas bibliotecas que se mencionan más adelante se recomendaron en este hilo (desde 2016 hasta feb 2019).  
Ninguna biblioteca funcionó bien.  
https://www.raspberrypi.org/forums/viewtopic.php?t=145568  

### Adafruit / Arduino
Biblioteca para Arduino. Sí funciona (en Arduino).  
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
En la terminal y en Node-RED funciona muy bien. Esta es la bib elegida.  
https://github.com/tdack/MAX6675  

### Otras bibliotecas que no se han probado  
Un programa escrito en C y compilado es llamado por otro programa escrito en Python  
No suena muy eficiente  
http://www.bristolwatch.com/rpi/geany.htm  
Bib para NodeJS. Hay una serie de dependencias y eso podría complicar la instalación  
https://www.npmjs.com/package/max6675-raspi  
Un script corto. La discusión en stackexchange tiene un link a otra página donde se puede descargar un zip.  
No necesita una biblioteca externa. Parece buena opción, pero la bib de tdack ya funciona bien.  
https://raspberrypi.stackexchange.com/questions/63556/using-a-max6675-with-raspberry-pi-3  
http://abyz.me.uk/rpi/pigpio/examples.html#Python_MAX6675_py  
http://abyz.me.uk/rpi/pigpio/code/MAX6675_py.zip  

## Usar python en Node-RED
Interpretar Python dentro de Node-RED  
https://flows.nodered.org/node/node-red-contrib-python-function  
https://flows.nodered.org/node/node-red-contrib-python3-function  
Para usar módulos externos se usará este método  
https://github.com/arnauorriols/node-red-contrib-python-function/issues/3  

Nota: Una ventaja del nodo python-function (en comparación con pythonshell) es que todo el código está en el flujo y no se requiere un archivo py externo.

Ejecutar un archivo py  
https://flows.nodered.org/node/node-red-contrib-pythonshell

Crear servidor que se comunica con Node-RED y ejecuta archivos py  
Está en fase pre-alpha!  
https://pypi.org/project/pynodered/  

## Cambios en la configuración de la RPi
Hasta ahora se han realizdo los siguientes cambios:  
+ Activar I2C y SPI desde `raspi-config` (También se puede cambiar desde el menú Inicio / Preferecias / Configuración de Raspberry Pi / Interfaces)  
+ Modificación de archivos en /etc/ (revisar nombre de arvhivos)  

## PID
PID (Calibración)  
https://en.wikipedia.org/wiki/PID_controller#Loop_tuning  

Valores - En la RPi el ancho de pulso de PWM se expresa como un porcentaje. Para evitar saturación de la salida del controlador se usará esta configuración: Un error de 300 grados causará una salida de 100%. El error proporcional más grande que se espera es de 250 grados (83.3%), sumando la parte integral y la parte derivativa se puede alcanzar la salida de 100%. La salida no puede ser negativa (no se puede enfriar más rápido).  

Kp inicial = 0.33  
Incrementar o disminuir Kp hasta tener poco sobre-tiro y oscilación.  
Cambiar Kp a la mitad de su valor (o 60%)  
Incrementar Ki para eliminar offset  
Incrementar Kd si es necesario  

| PWM | Temperatura límite | Tiempo
------|--------------------|-------
| 1%  | 28 ^C? | x
| 10% | 57 ^C  | x
| 50% | 140 ^C | 10 min
