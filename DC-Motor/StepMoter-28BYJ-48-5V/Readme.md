# How Stepper motors work?

Stepper motors use a cogged wheel and electromagnets to nudge the wheel round a ‘step’ at a time.

Each high pulse sent energizes the coil, attracting the teeth closest to the cogged wheel and rotating the motor in precise and fixed angle increments known as steps.

The number of steps that the stepper motor has in a 360 degree rotation is actually the number of teeth on the cog.

# Stepped Motor 28BYJ-48-5V with ULN2003 Driver Image

![WechatIMG23001](https://github.com/josthlee/IoT-HW-Module-Quickstart/assets/154501794/80ffd0d4-9547-4624-8270-7b4ba24de5fb)

# Stepped Motor 28BYJ-48-5V Images

![WechatIMG2762 copy](https://github.com/josthlee/IoT-HW-Module-Quickstart/assets/154501794/646e13ec-5f89-46fc-bde8-bb7564dbe461)

![WechatIMG23002](https://github.com/josthlee/IoT-HW-Module-Quickstart/assets/154501794/675b1043-eccb-4a79-b989-d89e58816f5c)

# Stepped Motor 28BYJ-48-5V Pinout

![d52c4e843918d9d65c85604d87272fc8](https://github.com/josthlee/IoT-HW-Module-Quickstart/assets/154501794/d7b526a8-32ed-4beb-98a7-2c8930acc42e)

# Stepped Motor 28BYJ-48-5V and ULN2003 with Arduino Wiring Image

![WechatIMG2760](https://github.com/josthlee/IoT-HW-Module-Quickstart/assets/154501794/9a617ec0-c65c-4381-9bcb-11f0117dc193)

# Gear Reduction Ratio

According to the data sheet, when the 28BYJ-48 motor is operated in full-step mode, each step corresponds to a rotation of 11.25°. This means there are 32 steps per revolution (360°/11.25° = 32).

In addition, the gearbox inside the motor has a 64:1 gear reduction. This results in 2048 (32*64) steps per revolution.

![WeChate20ed1fcfacc82aadbd3d9d6a29e80a9](https://github.com/josthlee/IoT-HW-Module-Quickstart/assets/154501794/c2675253-2743-4d03-adb3-81df1eca1844)

# Power Comsumption

The 28BYJ-48 typically draws about 240 mA.

Because the motor consumes a significant amount of power, it is preferable to power it directly from an external 5V power supply rather than from the Arduino.

It is worth noting that the motor consumes power even when it is at rest in order to maintain its position.
# Technical Specification

![27651708827827_ pic](https://github.com/josthlee/IoT-HW-Module-Quickstart/assets/154501794/01c46eac-b4b4-4052-be1a-a57c1f0984a3)



