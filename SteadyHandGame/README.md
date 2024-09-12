# Steady Hand Game

This code is to help build a "steady hand game".

This project is licensed under the [MIT License](https://fossa.com/blog/open-source-licenses-101-mit-license/) and therefore can be modified or used with permission for any purpose.

## Building the project

### Hardware

All the links below take you to a local supplier where possible.  Where this is not possible, Amazon affiliate links have been used with Make Monmouth as the beneficiary of any comission raised.

You'll need:

   * A [Wemos D1 Mini](https://amzn.to/3Ba297o)
   * Some [jumper wires](https://amzn.to/47qFnEk)
   * An [Addressable LED strip](https://coolcomponents.co.uk/products/neopixel-stick-8-x-ws2812-5050-rgb-led-with-integrated-drivers)
   * Some stiff wire (the inside of 3-core mains cable is ideal!) - Handyman House and Screwfix in Monmouth, [Seryn Electrical](https://www.facebook.com/p/Seryn-Electrical-Limited-100054207025056) in Crockers Ash near Ross-on-Wye
   * Some [flexible project wire](https://amzn.to/3MEK4Bb)
   * A cardboard box

#### The build!

OK< you've got all the hardware, let's get building!

   1. Solder three jumper wires onto the LED strip. If you can, try to use RED for the +ve terminal, BLACK for the -ve terminal, and GREEN for the DATA terminal. Make sure you solder the male end to the LED strip so you can use the female end to connect to the D1 Mini
   2. Cut a small length off the end of the stiff wire and shape it into a loop large enough to fit over the stiff wire.  Remember that the larger the loop, the easier the game will be to play.
   3. Solder a length of the flexible project wire to the end of the loop you've created, this will form the "playing piece", so it needs to be long enough for someone to move along the stiff wire easily.
   r42. Shape the stiff wire into the pattern you want to challenge your players with, and then solder a jumper wire to one end of the stiff wire.
   4. Poke a hole at each end of the box and feed one end of the stiff wire through the wire loop, before putting an end of the stiff wire into each hole
   5. Connect the jumper from the stiff wire to pin D3
   6. Connect the jumper from the loop to GND
   7. Take the LED Panel and connect the RED wire to 5v+, the BLACK wire to GND, and the GREEN wire to pin D2 
   8. Connect the device to your laptop/computer using a USB cable

Nothing will happen yet, we need to flash the code, so let's do that now.

### Software

In order to install the software onto the game, we need a few things on our own computers.

   1. Install [PlatformIO](https://platformio.org/platformio-ide)
   2. Clone this repository to your computer and open this folder in PlatformIO
   3. Run the "upload" commands and the game should light up!

## Playing the game

You get 8 lives.  Every time the wire loop touches the stiff wire, you loose a life and an LED turns from GREEN to RED.

When you are out of lives, the LEDs will flash randomly, then the game will wait for a few seconds and reset.

One all the LED's are GREEN again, the game is ready to play!

## Future enhancements

In future, I'd love to add the following features:

   1. A buzzer to let players know when they loose a life or the game restarts
   2. Some kind of scoreboard (the D1 Mini has WiFi built in, so this could send the results to a central location for processing!)

If you've got any more ideas, why not come along to one of our meetings and chat about it? All the details are [on our website](https://www.makemonmouth.co.uk/)
