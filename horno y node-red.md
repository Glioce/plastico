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

Bibliotecas para MAX6675  

Esta bib solo funciona con MAX21855, pero el fork de abajo agrega MAX6675  
https://github.com/Tuckie/max31855  
https://github.com/node-alpha/max31855  
Se intentó instalar con estas referencias pero no funcionó  
https://github.com/Tuckie/max31855/issues/10  
https://www.raspberrypi-spy.co.uk/2012/05/install-rpi-gpio-python-library/  

Se usará la biblioteca sin instalar, de esta forma
https://github.com/arnauorriols/node-red-contrib-python-function/issues/3

https://github.com/tdack/MAX6675  
https://github.com/apollo-ng/picoReflow/blob/master/lib/oven.py
https://github.com/adafruit/MAX6675-library  

Un programa escrito en C y compilado es llamado por otro programa escrito en Python  
No suena muy eficiente  
http://www.bristolwatch.com/rpi/geany.htm  

Para NodeJS. Hay una serie de dependencias  
https://www.npmjs.com/package/max6675-raspi

Un script corto
https://raspberrypi.stackexchange.com/questions/63556/using-a-max6675-with-raspberry-pi-3
