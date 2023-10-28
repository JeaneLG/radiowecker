# radiowecker
ESP Internet Radio angepasst (Dank an Gerald Lechner und AZ-Delivery)

Dies ist meine privat angepasste Version vom original Radiowecker von Gerald Lechner / AZ-Delivery.

Original Beitrag: 

https://www.az-delivery.de/blogs/azdelivery-blog-fur-arduino-und-raspberry-pi/internet-radiowecker-mit-touchscreen?comment=134773833995#comments

Die Anpassungen:

modernere Ansicht der Konfiguration und bessere Tages Eingabe der Wochentage beim Wecker

jetzt monochrom Zahlen, welche jetzt im Code einfacher an die Wunschfarbe angepasst werden können

anpassen der Farbe ermöglicht

NEU alle Einstellungen der Farben an 1 Stelle für die Hauptseite

NEU jetzt sind die Knöpfe monochrom, somit anpassbar
Später werden die Köpfe einzeln sein, um sie dynamisch anzupassen.

Hauptseite etwas umgestaltet, um mehr Informationen über den aktuellen Zustand zu haben.
Siehe im Bild unten.

geändert habe ich die Position des Datums um Platz zu bekommen für den Header Bereich.

Im Header werden rechts angezeigt:
    Wlan Signal-Stärke als Symbol (grün/gelb/rot) 
    Wlan Wert
    Einschlaf-Timer Symbol welches erscheint wenn der Timer aktiv ist.

Im Header werden links angezeigt:
    Wecker Symbol aktiv / deaktiv
    Wecker Zeit / AUS

Im unteren Bereich ist jetzt auf der Hauptseite direkt der Lautstärke regler zu finden.

Außerdem wurde bereits alles vorbereitet um den Piezo zu nutzen.

Hier einige Ansichten:

![Main Screen](screenshot/result.jpg?raw=true "Result")

![Radio Screen](screenshot/radio.jpg?raw=true "Seite Radio")

![Setting Screen](screenshot/settings.jpg?raw=true "Seite Settings")

![Color Setting](screenshot/settings_color.png?raw=true "Setting")

![Konfig Website](screenshot/website.png?raw=true "Konfiguration")


