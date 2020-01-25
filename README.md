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
Poster para comparar diferentes materiales y otros diseños  
https://tecnologias.libres.cc/c_arpino/kanbio/tree/b7482e77ad46f1d2cccb4db407ce499f8697e664/precious-plastic-kit-master/5.%20Create  
https://orangehillsmachinery.com/melting-temperatures/  

1. PET
Around 150-180°C. You need to be very careful. Do not go above 250°C because it will start releasing hydrocarbons & aldehyds. Also you want to be very careful with the PET you use. Make sure that there is absolutely no water at all because it will simply brake the polymer bonds and your output will 100% time brake. Advise to preheat the PET at around 70-80°C to eliminate the persistant water
2. HDPE
For instands milk bottles & bottle caps. Around 120°C. Milk bottles have a Black Carbon sheet between 2 HDPE sheets so the results is a bit yucky & not 100% HDPE… for bottle caps, it works very well !!! Do not go higher than 200°C because of release of hydrocarbons, aldehyds,  ketone & volatile fatty acid
PVC
Don’t work with PVC
LDPE
Around 105°C; when your LDPE is melted (it reduces a tons so you need to do couple batchs for a compression), i reckon you should wrap it in the next batch so the first batch doesn’t burn from too long contact on the heat-conductant metal it is melting on.Do not go higher than 200°C because of release of hydrocarbons, aldehyds,  ketone & volatile fatty acid
PP
Do not go higher than 200°C because of release of hydrocarbons, aldehyds,  ketone & volatile fatty acid
PS
Only work with Cristal PS, not expanded PS. Around  210°C. From the testing, i have experienced many different fume releases depending on the type of cristal PS used. As of temperature awarenessDo not go higher than 250°C because of release of hydrocarbons, aldehyds,  styrene and its oligomers.
