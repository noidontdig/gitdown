gitdown
=======

![example of gitdown aborting a commit](http://www.evernote.com/shard/s36/sh/1ff80994-e1f9-49ae-a5d0-4be3a8cec71a/25bde2f60f30b833c703f05ab636fa2b/deep/0/Screenshot%204/8/13%207:45%20AM.jpg)

__gitdown__ is a script which moderates your git committing activity based on your blood alcohol content (BAC). It uses the [DrinkShield](http://www.gfxhax.com/drinkshield/) for Arduino as a breathalyzer, and a Ruby script as the git hook.

It was built for hackNY's spring 2013 hackathon by Alex Qin (@alexqin) and Geoffrey Litt (@geoffreylitt), and won first place there. 
 
You can watch a demo video of gitdown in action at [this Youtube link](http://www.youtube.com/watch?v=NnBb1wmHj5k).

Modes
------
gitdown has three modes of operation:

- __Normal mode__: Only lets you commit with a BAC of less than 0.05%.
- __Krunk mode__: Only lets you commit with a BAC of _greater_ than 0.05%.
- __Ball(m)er mode__: Only lets you commit with a BAC of [between 0.13% and 0.15%](http://xkcd.com/323/).

In Krunk mode and Baller mode, gitdown will mangle your commit messages to make them appear more intoxicated, and will also post your name, current BAC, and the commit message to the official [gitdown Tumblr](http://gitdownhackny.tumblr.com), with a silly related photo attached.

When the "verbose" configuration parameter is turned on as described below, gitdown also gives you helpful facts about your current level of impairment, based on your BAC.

Usage
-----
First, clone the repo and install necessary gems:

    git clone https://github.com/noidontdig/gitdown.git
    cd gitdown
    bundle install

To use the script as a hook for the gitdown repo itself, copy it to the proper location:

    cp commit-msg .git/hooks/

Using this project requires an Arduino Uno with the [DrinkShield](http://www.gfxhax.com/drinkshield/) attachment. Open the `arduino_gitdown/arduino_gitdown.ino` file with the Arduino IDE and load it onto the Arduino.

Then, open the `.gitdown` config file and edit the three configuration parameters:
- __mode__: This should be set to either "normal", "krunk", or "baller", corresponding to the modes described above.
- __port__: This should be the device name of the Arduino's USB connection on your machine. This can be found from the Arduino IDE's "Serial Port" Menu. The default value is `/dev/tty.usbmodem1421`, which happened to work on the Macbook Air used for development.
- __verbose__: Set to "true" or "false", depending on whether you want the system to output helpful information about your current BAC level.

Then, you can try editing a file in the gitdown repo and committing the change, to see the script in action.

    echo "random change" >> commit-msg
    git commit -a -m "messing up the repo"

Depending on the active mode and your BAC, the script will either permit you to or prevent you from committing!

If you want to actually use gitdown in another repository, copy the `commit-msg` script to that repo's `.git/hooks` directory, and make sure to copy the `.gitdown` config file to that repository as well.

