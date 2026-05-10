// Copyright 2023 jack (@waffle87)
// SPDX-License-Identifier: GPL-2.0-or-later
#pragma once

// Drivers / Pin Layouts
#define I2C_DRIVER I2CD1
#define I2C1_SDA_PIN GP22
#define I2C1_SCL_PIN GP23

// Audio Buzzer
#define AUDIO_PIN GP28
#define AUDIO_PWM_DRIVER PWMD6
#define AUDIO_INIT_DELAY
#define AUDIO_PWM_CHANNEL RP2040_PWM_CHANNEL_A
// #define STARTUP_SONG SONG(ODE_TO_JOY)  // AHHHHHHHH
#define STARTUP_SONG SONG(NO_SOUND) // finally, peace!

// Analog Sticks (I don't have these)
#define ANALOG_JOYSTICK_Y_AXIS_PIN GP26
#define ANALOG_JOYSTICK_X_AXIS_PIN GP27
#define POINTING_DEVICE_INVERT_Y
#define POINTING_DEVICE_INVERT_X

// -------- My Configs -------- //
// not sure if I want to keep this.. maybe just master whichever side is plugged in..
// #define MASTER_LEFT
#define MASTER_RIGHT

// OLED
#define OLED_BRIGHTNESS 200 // 0 - 255
#define OLED_TIMEOUT 10000  // 10 seconds

// Tap Dance
#define TAPPING_TERM 175 // milliseconds

// Combos
#define COMBO_TERM 20 // milliseconds
#define COMBO_ONLY_FROM_LAYER 0
#define COMBO_COUNT 1
#define BOTH_SHIFTS_TURNS_ON_CAPSLOCK

// Split Keyboard Actions
#define SPLIT_ACTIVITY_ENABLE  // allow timeouts
#define SPLIT_LET_STATE_ENABLE // caps-lock, num-lock, etc.
#define SPLIT_MODS_ENABLE      // mod key status
#define SPLIT_OLED_ENABLE      // oled status (on, off, etc.)

// don't care for wpm currently
// #define SPLIT_WPM_ENABLE       // words-per-minute status

// Allow keyboard to turn on at PC cold-boot
// ...going to see what happens if I just comment this out..
// #define SPLIT_USB_TIMEOUT 26000 // milliseconds
