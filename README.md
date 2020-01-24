Pruebas rápidas de varios componentes de la recicladora de plástico.

Cosas por hacer:
- [ ] Subir diagramas
- [ ] Referencias
- [ ] ...

## Problemas de hardware
Algunos cables USB A a micro USB tienen resistencia eléctrica muy elevada, eso causa una caída de voltaje que afecta el funcionamiento de la Raspberry Pi. Se deben usar cables cortos y de buena calidad.

RPi dañada. Se manipuló con cuidado, pero un día dejó de funcionar.

## Configuración de resolución de pantalla
https://learn.adafruit.com/hdmi-uberguide/2299-display-no-touchscreen-1024x600-hdmi-slash-vga-slash-ntsc-slash-pal  
https://www.raspberrypi.org/forums/viewtopic.php?t=14914  
https://www.raspberrypi.org/documentation/configuration/config-txt/video.md  

## Iniciar chromium en el arranque
Chromium inicia en pantalla completa  
https://quaintproject.wordpress.com/2013/07/13/how-to-autostart-google-chromium-on-a-raspberry-pi/  
https://raspberrypi.stackexchange.com/questions/69204/open-chromium-full-screen-on-start-up  
Crear y/o editar archivo `autostart`  
`sudo leafpad ~/.config/lxsession/LXDE/autostart`  
Agregar la siguiente línea  
`@chromium-browser -kiosk`  

## Temperaturas de fusión de plásticos
La tabla ya no está disponible
