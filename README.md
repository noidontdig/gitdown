gitdown
=======
__gitdown__ is a git hook which moderates your git committing activity based on your blood alcohol content (BAC).

Usage
-----
First, clone the repo:

    git clone https://github.com/noidontdig/gitdown.git
    cd gitdown

Using this project requires an Arduino Uno with the [DrinkShield](http://www.gfxhax.com/drinkshield/) attachment. Open the `arduino_gitdown/arduino_gitdown.ino` file with the Arduino IDE and load it onto the Arduino.

Then, open the `.gitdown` config file and edit the two configuration parameters:
__mode__: This should be set to either "normal", "krunk", or "baller", corresponding to the modes described below.
__port__: This should be the device name of the Arduino's USB connection on your machine. This can be found from the Arduino IDE's "Serial Port" Menu. The default value is `/dev/tty.usbmodem1421`, which happened to work on the Macbook Air used for development.

Run the setup script, which simply copies the script into the proper location to be a git hook for the gitdown repo:

    ./setup

Then, you can try editing a file in the gitdown repo and committing the change, to see the script in action.

    echo "random change" >> commit-msg
    git commit -a -m "messing up the repo"

Depending on the active mode and your BAC, the script will either permit you to or prevent you from committing!