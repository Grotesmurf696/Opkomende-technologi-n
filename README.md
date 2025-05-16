# Overkoepelende opdracht Motion Sensor

> Victor Fransen en Sam Verkimpe

## Inleiding

In dit document lees je alles over ons project, van het initiële idee tot aan de uitvoering en het resultaat.

Voor deze overkoepelende opdracht van *Opkomende Technologieën* hebben wij gekozen voor de 'Motion Sensor'. Hierbij wordt verwacht input van een gyroscoop om te zetten in een visuele of auditieve output.

## Aanpak

De eerste stap in een dergelijke opdracht is steeds het kijken wat er gevraagd wordt en met welke resources je kan werken. Zo hebben wij even snel gebrainstormd over wat we wilden doen met onze motion sensor. Initieel hadden we het idee gekregen om de output van de gyroscoop om te zetten in ledjes die in een cirkelvorm gingen branden, meer specifiek de NeoPixel LED Circle (zie onderstaande figuur).

<p align="center">
  <img src="https://github.com/Grotesmurf696/Opkomende-technologi-n/blob/main/Images/IMG_3490.jpg?raw=true" width="500" />
</p>

Dit eerste idee kon opgedeeld worden in 2 delen: het uitlezen van de gyroscoop en het besturen van de leds. Om het proces wat sneller te laten gaan, hadden we ervoor gekozen deze twee delen op te splitsen. Victor zou de gyroscoop uitlezen en Sam de leds besturen.

Maar deze twee delen konden niet zomaar communiceren met elkaar, dus hadden we een "mergepoint" opgesteld. Dit punt was een set van output- en inputwaarden. Victor zette alle ingelezen waardes van de gyroscoop om in waardes van \[0 < x < 360], oftewel 360 graden. Sam zette dan deze waardes om in een visuele representatie van de gyroscoop in de led-ring.

### Gyroscoop
#### Basis/validatie

Om het concept en werking van de gyroscoop en het coderen ervan onder de knie te krijgen is er eerst een zeer eenvoudige code opgesteld. Hiermee werd ook de werking van de input (gyroscoop) gevalideerd. Met deze code kon bepaald worden of de gyroscoop gekanteld werd en in welke richting er gekanteld werd. Deze data werd vervolgens geprint op de seriële monitor. Hierdoor kreeg de gebruiker te zien of er naar voor, links, rechts, schuin links vooruit, schuin links achteruit, schuin rechts vooruit of schuin rechts achteruit gekanteld werd met de gyroscoop. Klik [hier](https://github.com/Grotesmurf696/Opkomende-technologi-n/blob/main/Code/Gyroscoop/Gyroscope/Gyroscope.ino) voor de code.

Schakeling:
<p align="center">
  <img src="https://github.com/Grotesmurf696/Opkomende-technologi-n/blob/main/Images/Schermafbeelding%202025-05-15%20121743.png?raw=true" width="500" />
</p>

#### Balncing game

Na het onder de knie krijgen van de werking van de gyroscoop werd er een spelletje opgesteld. Hierbij was het de bedoeling dat de speler de gyroscoop perfect recht gebalanceerd krijgt. In combinatie met de NEOpixel LEDring werd gekeken naar welke kant de gyroscoop leunde. Aan deze kant lichte een LED van de NEOpixel ring op. Hierdoor kan de speler zien in welke richtng hij afwijkt. Wanneer de gyroscoop vlak wordt gehouden volgt er ook een trilling. De code voor de gyroscoop van de balancing game staat [hier](https://github.com/Grotesmurf696/Opkomende-technologi-n/blob/main/Code/Gyroscoop/Gyroscope2.0/Gyroscope2.0.ino).

Schakeling:
<p align="center">
  <img src="https://github.com/Grotesmurf696/Opkomende-technologi-n/blob/main/Images/schakeling%20balancing.jpg?raw=true" width="500" />
</p>

#### Where is waldo? (Protopie)

Na een kort feedbackmoment met de docent werd uitgedaagd om ook een visuele representaie/spel op te stellen zodat er ook iets bestuurd kan worden met de gyroscoop. Aangezien er al een tof project was opgesteld met de balanceerder, zou het zonde zijn om de NEOpixel weg te laten. Daarom werd ook de NEOpixel inbegrepen in dit laatste spel.

Ook hier werd eerst een basisprogramma opgesteld om de combinatie van Arduino en Protopie onder de knie te krijgen en de output te valideren. Hierbij werd een grijze bol bestuurd op het scherm met de beweging van de gyroscoop. Deze code is [hier](https://github.com/Grotesmurf696/Opkomende-technologi-n/blob/main/Code/Gyroscoop/output_validation_where_is_waldo/output_validation_where_is_waldo.ino) te vinden.

<p align="center">
  <img src="https://github.com/Grotesmurf696/Opkomende-technologi-n/blob/main/Images/eerste%20protopie.gif?raw=true" width="500" />
</p>


Later werd deze basislogica gebruikt om een 'where is Waldo?' game op te stellen. Hierbij is het doel om Waldo te vinden op het scherm. Met de gyroscoop word een rode cirkel bestuurd. Wanneer deze cirkel over Waldo wordt geplaats en op de knop word gedrukt op de controller, krijgt de speler haptische feedback aan de hand van een trilmotor. Hierna zal de speler naar een volgend 'level' gestuurd worden. Dit zal enkel gebeuren als de cirkel over waldo wordt gaplaatst en op hetzelfde moment op de knop gedrukt wordt. Als er op een random plaats op de knop gedrukt wordt zal er niets geeuren. Aangezein de werking van de trilmotor simpelweg het hoog en laag zetten van een output pin is, was deze validatie snel gemaakt. [Hier](https://github.com/Grotesmurf696/Opkomende-technologi-n/blob/main/Code/Gyroscoop/validatie_motor/validatie_motor.ino) is de code voor de validatie van de werking van de trilmotor. Hetzelfde geldt voor de knop. Deze was snel gevalideerd door het uilezen van de knop. [Hier](https://github.com/Grotesmurf696/Opkomende-technologi-n/blob/main/Code/Gyroscoop/validatie_knop/validatie_knop.ino) is de code voor de validatie van de werking van de drukknop.

De code voor de gyroscoop van de balancing game staat [hier](https://github.com/Grotesmurf696/Opkomende-technologi-n/blob/main/Code/Gyroscoop/Where%20is%20waldo/Where%20is%20waldo.ino).


<p align="center">
  <img src="https://github.com/Grotesmurf696/Opkomende-technologi-n/blob/main/Images/Waldo%20GIF.gif?raw=true" width="500" />
</p>


Schakeling:
<p align="center">
  <img src="https://github.com/Grotesmurf696/Opkomende-technologi-n/blob/main/Images/Schermafbeelding%202025-05-15%20122638.jpg?raw=true" width="500" />
</p>


## Resultaat

Als alle elementen samenkomen tot één geheel, wordt er een where is waldo met visuele en haptische feedback bekomen. De volledige code is [hier](https://github.com/Grotesmurf696/Opkomende-technologi-n/blob/main/Code/Final/Final.ino) te vinden.

Schakeling:
<p align="center">
  <img src="https://github.com/Grotesmurf696/Opkomende-technologi-n/blob/main/Images/volledige%20schakeling.jpg?raw=true" width="500" />
</p>
<p align="center">
  <img src="https://github.com/Grotesmurf696/Opkomende-technologi-n/blob/main/Images/tot%20nu%20toe%20finaal%20GIF.gif?raw=true" width="500" />
  <img src="https://github.com/Grotesmurf696/Opkomende-technologi-n/blob/main/Images/image1%20(23).jpeg?raw=true" width="300" />
</p>
