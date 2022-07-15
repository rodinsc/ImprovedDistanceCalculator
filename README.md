# Improved Distance Meter

Improved Distance Meter is a distance meter for Arduino using HC-SR04, DHT11 sensors and an LCD screen. The improved thing is the calculation of sound speed which is used to get distance.

## Calculation of distance

Common usage of HC-SR04 when calculating distance is like:

```cpp
float distance = (duration/2) / 29.1;
```
The important thing here is the `29.1` value. It is the sound speed in microseconds/centimeter format. But the temperature of the environment affects that value. So to get distance with more accuracy, we need to change this value according to temperature of the environment.

So, to calculate this value, the code simply solves the following equation.

<img src="https://i.hizliresim.com/j6cpuy4.png" width="350"></img> <br>
And then turns it into microseconds/centimeter format to be used in the calculation of distance. Simply gets more accuracy by doing this.

## Scheme

<img src="https://i.hizliresim.com/8bo9fjd.png" width="500"></img>

## About LCD and I2C

The used I2C LCD library may not be compatible with your LCD. Try the following before changing the library.

- Change the values `16, 2` in `LiquidCrystal_I2C lcd(0x27, 16, 2);` to row and column count of your LCD screen.

- Try to change value `0x27` in `LiquidCrystal_I2C lcd(0x27, 16, 2);` to `0x3F`.
