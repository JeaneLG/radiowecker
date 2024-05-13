


<div align="center">

|[:skull:ISSUE](https://github.com/JeaneLG/radiowecker/issues?q=is%3Aissue)|[:speech_balloon: Forum /Discussion](https://github.com/JeaneLG/radiowecker/discussions?discussions_q=)|[:grey_question:WiKi](https://github.com/JeaneLG/radiowecker/wiki)|
|--|--|--|
|![GitHub issues](https://img.shields.io/github/issues/JeaneLG/radiowecker)![GitHub closed issues](https://img.shields.io/github/issues-closed/JeaneLG/radiowecker)|![GitHub Discussions](https://img.shields.io/github/discussions/JeaneLG/radiowecker)![GitHub User's stars](https://img.shields.io/github/stars/JeaneLG)|![GitHub release (with filter)](https://img.shields.io/github/v/release/JeaneLG/radiowecker)


</div>


|This project is based on the blog article "[Internet clock radio with touchscreen](https://www.az-delivery.de/blogs/azdelivery-blog-fur-arduino-und-raspberry-pi/internet-radiowecker-mit-touchscreen)" by Gerald Lechner / Az-Delivery. | Dieses Projekt basiert auf dem Blogartikel "[Internet Radiowecker mit Touchscreen](https://www.az-delivery.de/blogs/azdelivery-blog-fur-arduino-und-raspberry-pi/internet-radiowecker-mit-touchscreen)" von Gerald Lechner / Az-Delivery.  |
|--|--|


**Parts required: / Benötigte Teile:** 

||Pro|Cheap|Minimal|
|--|--|--|--|
|[1 x AZ-Touch MOD mit 2,8" Touchscreen](https://amzn.to/3srKxjE)|:white_check_mark:|:ballot_box_with_check:[1xTFT](https://amzn.to/3MEtdyy)|:x:|
|[1 x ESP-32 Dev Kit C V4](https://amzn.to/40ApxUA)|:white_check_mark:|:white_check_mark:|:white_check_mark:|
|[2 x I2S 3W MAX98357A](https://amzn.to/3QSHtGF)|:white_check_mark:|:white_check_mark:|:white_check_mark:(1x)|
|[1 x Lautsprecher Set](https://amzn.to/3SSyQNR)|:white_check_mark:|:white_check_mark:|:white_check_mark:|
|[1 x Widerstand 470 kOhm](https://amzn.to/3Sw17cL)|:white_check_mark:|:white_check_mark:|:white_check_mark:(1x470kOhm)|
|[DC Einbaubuchse](https://amzn.to/47it0ZY)|:white_check_mark:|:x:|:x:|
|[1 x LDR](https://de.aliexpress.com/item/1005005686593216.html?spm=a2g0o.detail.pcDetailTopMoreOtherSeller.3.ea26A9qMA9qMU1&gps-id=pcDetailTopMoreOtherSeller&scm=1007.40050.354490.0&scm_id=1007.40050.354490.0&scm-url=1007.40050.354490.0&pvid=502dbab5-c2dc-4ed9-bb2b-68eed9b1ec68&_t=gps-id:pcDetailTopMoreOtherSeller,scm-url:1007.40050.354490.0,pvid:502dbab5-c2dc-4ed9-bb2b-68eed9b1ec68,tpp_buckets:668%232846%238108%231977&pdp_npi=4%40dis%21EUR%211.02%211.02%21%21%211.07%211.07%21%40211b801917155988644807966ef794%2112000034009081343%21rec%21DE%214183551953%21&utparam-url=scene%3ApcDetailTopMoreOtherSeller%7Cquery_from%3A)|:white_check_mark:|:x:|:x:|
||~95,-|~54,-|~37,-|

[German Version below / Deutsche Version unten:point_down:](#german-version)
----
# Clock radio

I have extended and adapted this project.

The main changes include:

1. Alarm settings can be edited on touchscreen
2. Nov up to three alarms can be used
3. Alarm can be paused using additional touch pin
4. Major bugfixes

The main changes from beabel:
1. customizable colors.
2. more information on the main page.
3. splitting the radio and settings pages to make space for favorites buttons.
4. a completely redesigned web configuration page with full remote view and control of the radio.

At the time of publishing this blog article, a complete set was available for purchase from AZ-Delivery. Currently this is not offered, but all required parts can be ordered individually.


**[Additional information::point_down:](#informationen)**

## [Screenshots:point_down:](#screenshots)

## German Version

# Radiowecker

Ich habe dieses Projekt erweitert und angepasst.

Die wesentlichen Änderungen umfassen:

1. Die Alarm Einstellungen können auf dem Touchscrenn geändert werden
2. Es können bis zu drei Alarme eingestellt werden
3. Der Alarm kann pausiert werden. Dazu wird ein Touch Pin des ESP32 verwendet.
4. Wichtige Bug Fixes

Die wesentlichen Änderungen von beabel:
1. Anpassbare Farben.
2. Mehr Informationen auf der Hauptseite.
3. Aufteilung der Radio- und Einstellungsseiten, um Platz für Favoritentasten zu schaffen.
4. Eine vollständig überarbeitete Webkonfigurationsseite mit umfassender Fernansicht und Steuerung des Radios.

Zum Zeitpunkt der Veröffentlichung des Blogartikels gab es ein vollständiges Set bei AZ-Delivery zu kaufen. Aktuell wird dies nicht angeboten, aber alle benötigten Teile können einzeln bestellt werden.

# Informationen

**Boardverwalter URL:**
[https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json](https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json)
- ESP32 von Espressif Systems

**Bibliotheken:**
- [Adafruit_ILI9341 by Adafruit Version 1.6.00](https://github.com/adafruit/Adafruit_ILI9341)
- [Adafruit_GFX by Adafruit Version 1.11.9](https://github.com/adafruit/Adafruit-GFX-Library)
- [XPT2046_Touchscreen by Paul Stoffregen Version 1.4.0](https://github.com/PaulStoffregen/XPT2046_Touchscreen)
- [Touchevent by Gerald-Lechner Version 1.3.0](https://github.com/GerLech/TouchEvent)
- [ESP8266Audio by Earle F. Philhower Version 1.9.7](https://github.com/earlephilhower/ESP8266Audio)

# Screenshots

![Main Screen](screenshot/result.jpg?raw=true "Hauptbildschirm")

![Radio Screen](screenshot/radio.jpg?raw=true "Radiobildschirm")

![Setting Screen](screenshot/settings.jpg?raw=true "Einstellungen")

![Color Setting](screenshot/settings_color.png?raw=true "Farbeinstellungen")

![Konfigurationswebsite](screenshot/website.png?raw=true "Musik")

![Konfigurationswebsite](screenshot/website_2.png?raw=true "Wecker")

![Konfigurationswebsite](screenshot/website_3.png?raw=true "Radio")

![Konfigurationswebsite](screenshot/website_4.png?raw=true "WLAN")
