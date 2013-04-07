gitdown
=======
__gitdown__ is a git hook which moderates your git committing activity based on your blood alcohol content (BAC). It uses the [DrinkShield](http://www.gfxhax.com/drinkshield/) for Arduino as a breathalyzer.

It was built for hackNY spring 2013 by Alex Qin and Geoffrey Litt.

Usage
-----
First, clone the repo and install necessary gems:

    git clone https://github.com/noidontdig/gitdown.git
    cd gitdown
    bundle install

To use the script as a hook for the gitdown repo itself, copy it to the proper location:

    cp commit-msg .git/hooks/

Using this project requires an Arduino Uno with the [DrinkShield](http://www.gfxhax.com/drinkshield/) attachment. Open the `arduino_gitdown/arduino_gitdown.ino` file with the Arduino IDE and load it onto the Arduino.

Then, open the `.gitdown` config file and edit the two configuration parameters:
- __mode__: This should be set to either "normal", "krunk", or "baller", corresponding to the modes described below.
- __port__: This should be the device name of the Arduino's USB connection on your machine. This can be found from the Arduino IDE's "Serial Port" Menu. The default value is `/dev/tty.usbmodem1421`, which happened to work on the Macbook Air used for development.

Then, you can try editing a file in the gitdown repo and committing the change, to see the script in action.

    echo "random change" >> commit-msg
    git commit -a -m "messing up the repo"

Depending on the active mode and your BAC, the script will either permit you to or prevent you from committing!

If you want to actually use gitdown in another repository, copy the `commit-msg` script to that repo's `.git/hooks` directory, and make sure to copy the `.gitdown` config file to that repository as well.

Modes
------
- __Normal mode__: Only lets you commit with a BAC of less than 0.05%.
- __Krunk mode__: Only lets you commit with a BAC of __greater__ than 0.05%.
- __Ball(m)er mode__: Only lets you commit with a BAC of [between 0.13% and 0.15%](http://xkcd.com/323/).