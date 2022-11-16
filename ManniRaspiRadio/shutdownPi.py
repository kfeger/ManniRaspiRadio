#!/usr/bin/env python
# -*- coding: utf-8 -*-

#
# Creation:    09.06.2013
# Last Update: 07.04.2015
#
# Copyright (c) 2013-2015 by Georg Kainzbauer <http://www.gtkdb.de>
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.
#  Die ist die Version, die auf dem alten Raspiradio lief

# import required modules
import time
import subprocess

#zugefuegt Manni 11/2022
import sys
import time
sys.path.append('/storage/.kodi/addons/virtual.rpi-tools/lib')

import RPi.GPIO as GPIO

# set GPIO pin with connected button
DownPin = 26
LEDPin = 19
# main function
def main():
	value = 0

	while True:
		# Hochzählen, wenn Null
		if not GPIO.input(DownPin):
			value += 0.5
		else:
			value = 0

		# shutdown gewählt wenn value >= 3
		if value >= 3:
			subprocess.call(["shutdown", "-h", "now"])
			#print "Jetzt Shutdown", value
			return 0
		# wait 500ms
		time.sleep(0.5)

	return 0

if __name__ == '__main__':
	# use GPIO pin numbering convention
	GPIO.setmode(GPIO.BCM)

	# setze GPIO pin DOWNPin als input mit Pull-Up
	GPIO.setup(DownPin, GPIO.IN, pull_up_down=GPIO.PUD_UP)
	# setze LEDPin als Output (Shutdown fertig wenn low)
	GPIO.setup(LEDPin, GPIO.OUT)
	GPIO.output(LEDPin, GPIO.HIGH)
	# call main function
	main()

