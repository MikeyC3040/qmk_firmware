/*
Copyright 2018 Mattia Dal Ben <matthewdibi@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

/* Use I2C or Serial, not both */
// #define USE_SERIAL
#define USE_I2C

/* Select hand configuration */
//#define MASTER_LEFT
// #define MASTER_RIGHT
#define EE_HANDS


#define OLED_DISPLAY_ADDRESS 	0x3C 	//The i2c address of the OLED Display
#define OLED_FONT_H 	"glcdfont.c" 	//The font code file to use for custom fonts
#define OLED_FONT_START 	0 	//The starting character index for custom fonts
#define OLED_FONT_END 	223 	//The ending character index for custom fonts
#define OLED_FONT_WIDTH 	6 	//The font width
#define OLED_FONT_HEIGHT 	8 	//The font height (untested)
#define OLED_TIMEOUT 	60000 	//Turns off the OLED screen after 60000ms of screen update inactivity. Helps reduce OLED Burn-in. Set to 0 to disable.
//#define OLED_FADE_OUT 	Not defined 	//Enables fade out animation. Use together with OLED_TIMEOUT.
#define OLED_FADE_OUT_INTERVAL 	0 	//The speed of fade out animation, from 0 to 15. Larger values are slower.
#define OLED_SCROLL_TIMEOUT 	0 	//Scrolls the OLED screen after 0ms of OLED inactivity. Helps reduce OLED Burn-in. Set to 0 to disable.
//#define OLED_SCROLL_TIMEOUT_RIGHT 	//Not defined 	Scroll timeout direction is right when defined, left when undefined.
#define OLED_IC 	OLED_IC_SSD1306 	//Set to OLED_IC_SH1106 if you’re using the SH1106 OLED controller.
#define OLED_BRIGHTNESS 	255 	//The default brightness level of the OLED, from 0 to 255.
#define OLED_UPDATE_INTERVAL 10 //Set the time interval for updating the OLED display in ms. This will improve the matrix scan rate.