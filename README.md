## Estructura
Es una mesa hecha con perfiles estructurales de aluminio.
La prensa es es una caja hecha con dos placas de acero (reforzadas con barras de acero). Se mantienen paralelas con 4 varillas roscadas.
Se usa un gato para levantar automóviles compactos.
La altura de la caja se puede modificar desplazando las tuercas de las 4 varillas roscadas.

### Seguridad en el manejo de la prensa

### Seguridad en el manejo del horno

## Problemas de hardware
Algunos cables USB A a micro USB tienen resistencia eléctrica muy elevada, eso causa una caída de voltaje la Raspberry Pi muestra el ícono de bajo voltaje (rayo). Se deben usar cables cortos y de buena calidad.

La RPi 3A+ parecía dañada, pero al parecer solo fallaba el cable de alimentación.

Si se usan relevadores para controlar las resistencias calentadoras, la luz de las lámparas tiene cambios de intensidad (parpadean).

Al utilizar una RPi 3B+ se tienen varios puertos USB disponibles y se pueden conectar al mismo tiempo la pantalla táctil, el Arduino y un teclado, pero si usa el modelo 3A+ solo hay un puerto disponible. Se pude usar un HUB USB (es mala opción) o se puede conectar el Arduino con los pines UART (sin conectar el teclado).

## Configuración de resolución de pantalla
Editar el archivo `/boot/config.txt` y agregar o descomentar las siguientes líneas

`hdmi_force_hotplug=1
hdmi_group=2
hdmi_mode=1
hdmi_mode=87
hdmi_cvt=1024 600 60 3 0 0 0`

Aquí puedes revisar más información relacionada:
https://learn.adafruit.com/hdmi-uberguide/2299-display-no-touchscreen-1024x600-hdmi-slash-vga-slash-ntsc-slash-pal  
https://www.raspberrypi.org/forums/viewtopic.php?t=14914  
https://www.raspberrypi.org/documentation/configuration/config-txt/video.md  

## Iniciar chromium en el arranque
Chromium inicia en pantalla completa 
https://raspberrypi.stackexchange.com/questions/69204/open-chromium-full-screen-on-start-up
https://quaintproject.wordpress.com/2013/07/13/how-to-autostart-google-chromium-on-a-raspberry-pi/  
Crear y/o editar archivo `autostart`  
`sudo nano /home/pi/.config/lxsession/LXDE-pi/autostart`  
Agregar la siguiente línea  
`@chromium-browser -kiosk`  

## Temperaturas de fusión de plásticos
Poster para comparar diferentes materiales y otros diseños  
https://davehakkens.nl/community/forums/topic/melting-temperature-test/  
https://orangehillsmachinery.com/melting-temperatures/  
https://tecnologias.libres.cc/c_arpino/kanbio/tree/b7482e77ad46f1d2cccb4db407ce499f8697e664/precious-plastic-kit-master/5.%20Create  
https://trimaker.com/pla-y-abs-que-filamento-elegir-en-impresion-3d-por-fdm/  

1. **PET** - Around 150-180°C. You need to be very careful. Do not go above 250°C because it will start releasing hydrocarbons & aldehyds. Also you want to be very careful with the PET you use. Make sure that there is absolutely no water at all because it will simply brake the polymer bonds and your output will 100% time brake. Advise to preheat the PET at around 70-80°C to eliminate the persistant water
2. **HDPE** - For instands milk bottles & bottle caps. Around 120°C. Milk bottles have a Black Carbon sheet between 2 HDPE sheets so the results is a bit yucky & not 100% HDPE… for bottle caps, it works very well !!! Do not go higher than 200°C because of release of hydrocarbons, aldehyds,  ketone & volatile fatty acid
3. **PVC** - Don’t work with PVC
4. **LDPE** - Around 105°C; when your LDPE is melted (it reduces a tons so you need to do couple batchs for a compression), i reckon you should wrap it in the next batch so the first batch doesn’t burn from too long contact on the heat-conductant metal it is melting on.Do not go higher than 200°C because of release of hydrocarbons, aldehyds,  ketone & volatile fatty acid
5. **PP** - Do not go higher than 200°C because of release of hydrocarbons, aldehyds,  ketone & volatile fatty acid
6. **PS** - Only work with Cristal PS, not expanded PS. Around  210°C. From the testing, i have experienced many different fume releases depending on the type of cristal PS used. As of temperature awarenessDo not go higher than 250°C because of release of hydrocarbons, aldehyds,  styrene and its oligomers.
7. **PLA** - Su rango de fusión se encuentra entre los 95° – 105° C, su temperatura de autoignición es a partir de los 388° C y su descomposición térmica comienza a los 250° C. Extrusor: 180° – 230° C
8. **ABS** - su rango de fusión se encuentra entre los 95° – 105° C. En cuanto a la temperatura de autoignición, es a partir de los 300° C, al igual que la descomposición térmica. Extrusor: 225° – 240° C
