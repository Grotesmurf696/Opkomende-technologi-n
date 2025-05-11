# Overkoepelende opdracht Motion Sensor

> Victor Fransen en Sam Verkimpe

## Inleiding

In dit document lees je alles over ons project, van het initiële idee tot aan de uitvoering en het resultaat.

Voor deze overkoepelende opdracht van *Opkomende Technologieën* hebben wij gekozen voor de 'Motion Sensor'. Hierbij wordt verwacht input van een gyroscoop om te zetten in een visuele of auditieve output.

## Aanpak

De eerste stap in een dergelijke opdracht is steeds het kijken wat er gevraagd wordt en met welke resources je kan werken. Zo hebben wij even snel gebrainstormd over wat we wilden doen met onze motion sensor. Initieel hadden we het idee gekregen om de output van de gyroscoop om te zetten in ledjes die in een cirkelvorm gingen branden, meer specifiek de NeoPixel LED Circle (zie onderstaande figuur).
![Eerste idee](./Images/IMG_3490.jpg)
Dit eerste idee kon opgedeeld worden in 2 delen: het uitlezen van de gyroscoop en het besturen van de leds. Om het proces wat sneller te laten gaan, hadden we ervoor gekozen deze twee delen op te splitsen. Victor zou de gyroscoop uitlezen en Sam de leds besturen.

Maar deze twee delen konden niet zomaar communiceren met elkaar, dus hadden we een "mergepoint" opgesteld. Dit punt was een set van output- en inputwaarden. Victor zette alle ingelezen waardes van de gyroscoop om in waardes van \[0 < x < 360], oftewel 360 graden. Sam zette dan deze waardes om in een visuele representatie van de gyroscoop in de led-ring.

## Feedback

Na een kort feedbackmoment met de docent werd er ons verteld dat het misschien ook een goed idee zou zijn om van onze uitgelezen waardes van de gyroscoop een visuele representatie te geven op een computerscherm. Natuurlijk wilden we onze voortgang met de leds niet verloren laten gaan, dus die implementatie hebben we nog steeds behouden. Na dit feedbackmoment heeft Victor ervoor gezorgd dat onze uitgelezen waardes van de gyroscoop ook weergegeven konden worden op een scherm.

## Schema

Hieronder kan u het gemaakte schema zien, met de Adafruit NeoPixel LED Circle en de gyroscoop.
// nog een foto in plaatsen best
