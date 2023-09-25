[![MCHP](./images/microchip.png)](https://www.microchip.com)



# Direct Memory Access (DMA) on PIC MCUs [Part one]:
This is the first part an example showing how to set up [Direct Memory Access (DMA)](https://www.microchip.com/design-centers/8-bit/peripherals/core-independent/direct-memory-access?utm_campaign=PIC18FQ43&utm_source=GitHub&utm_medium=embeddedLink&utm_term=&utm_content=pic18f57q43-dma-adc-to-uart-part1-MMTCha) using the [Microchip Code Configurator (MCC)](https://www.microchip.com/Developmenttools/ProductDetails/DM164150?utm_campaign=PIC18FQ43&utm_source=GitHub&utm_medium=embeddedLink&utm_term=&utm_content=pic18f57q43-dma-adc-to-uart-part1-MMTCha) on the [PIC18F57Q43 Curiosity Nano](https://www.microchip.com/design-centers/8-bit/pic-mcus/device-selection/pic18f-q10-product-family?utm_campaign=PIC18FQ43&utm_source=GitHub&utm_medium=embeddedLink&utm_term=&utm_content=pic18f57q43-dma-adc-to-uart-part1-MMTCha) to transfer an Analog to Digital (ADC) conversion to a UART TX buffer with zero lines of code and zero CPU utilization using DMA.


![](images/part1-gif.gif)


[**Part 2**](https://github.com/microchip-pic-avr-examples/pic18f57q43-dma-uart-to-pwm-part2) covers how to set up the second device that utilizes DMA to transfer the contents of the received message in the UART RX buffer to a PWM module that will vary the brightness of an LED.

![](images\system-architecture.JPG)


## Table of Contents
  - [Related Documentation](#related-documentation)
  - [Software Used](#software-used)
  - [Hardware Used](#hardware-used)
  - [Setup](#setup)
  - [Operation](#operation)
  - [Summary](#summary)
  - [Walkthrough](#walkthrough)


This example is extendable to the entire PIC18 Q43 family, and other 8-bit PIC devices with the DMA feature, like PIC18F K42.

The Timer (TMR0), Analog to Digital Converter with Computation (ADCC), and Universal Asynchronous Receiver Transmitter (UART3) and DMA on-chip peripherals are all used in this project (part1).

**This example is covered in a video format** [**linked here**](https://www.youtube.com/watch?v=Wz7gt11gpSw&t=1s).

## Related Documentation and Resouces
- **Videos**:
  - [DMA Overview on PIC® MCUs](https://www.youtube.com/watch?v=Lpru4TY-aHE)
  - [How to use DMA on 8 bit PIC MCUs](https://www.youtube.com/watch?v=Wz7gt11gpSw)
- **Tech Briefs** - Written briefs covering fundamentals
  - [TB3242: Configuring the DMA Peripheral](https://ww1.microchip.com/downloads/en/Appnotes/90003242A.pdf)
  - [TB3164: Direct Memory Access on 8-bit PIC® Microcontrollers](http://ww1.microchip.com/downloads/en/AppNotes/TB3164-Direct%20Memory-Access-on-8-bit-PIC-MCU-DS90003164B.pdf)
- **Application Notes** - Real-world use-cases
  - [AN3312: Arbitrary Waveform Generator Using DAC and DMA](https://www.microchip.com/00003312)
  - [AN3382: ADCC Context Switching Using DMA](https://microchip.com/00003382)
  - [AN3398: Building Hardware State Machines with CIPs](https://www.microchip.com/00003398)

## Software Used
- [MPLAB® X IDE 6.15](https://www.microchip.com/mplab/mplab-x-ide?utm_campaign=PIC18FQ43&utm_source=GitHub&utm_medium=embeddedLink&utm_term=&utm_content=pic18f57q43-dma-adc-to-uart-part1-MMTCha) or newer
- [MPLAB® XC8 2.45](https://www.microchip.com/mplab/compilers?utm_campaign=PIC18FQ43&utm_source=GitHub&utm_medium=embeddedLink&utm_term=&utm_content=pic18f57q43-dma-adc-to-uart-part1-MMTCha) or newer
- [MPLAB® Code Configurator (MCC) 5.5.7](https://www.microchip.com/mplab/mplab-code-configurator?utm_campaign=PIC18FQ43&utm_source=GitHub&utm_medium=embeddedLink&utm_term=&utm_content=pic18f57q43-dma-adc-to-uart-part1-MMTCha) or newer
 - [MPLAB® Code Configurator (MCC) Device Libraries PIC10 / PIC12 / PIC16 / PIC18 MCUs (5.25.0)](https://www.microchip.com/mplab/mplab-code-configurator?utm_campaign=PIC18FQ43&utm_source=GitHub&utm_medium=embeddedLink&utm_term=&utm_content=pic18f57q43-dma-adc-to-uart-part1-MMTCha) or newer
- [Microchip PIC18F-Q Series Device Support (1.21.411)](https://packs.download.microchip.com/?utm_campaign=PIC18FQ43&utm_source=GitHub&utm_medium=embeddedLink&utm_term=&utm_content=pic18f57q43-dma-adc-to-uart-part1-MMTCha) or newer

## Hardware Used
- PIC18F57Q43 Curiosity Nano Evaluation Kit [(DM164150)](https://www.microchip.com/Developmenttools/ProductDetails/DM164150?utm_campaign=PIC18FQ43&utm_source=GitHub&utm_medium=embeddedLink&utm_term=&utm_content=pic18f57q43-dma-adc-to-uart-part1-MMTCha)
  - NOTE: There is second Curiosity Nano Evaluation Kit used in [**part two**](https://github.com/microchip-pic-avr-examples/pic18f57q43-dma-uart-to-pwm-part2)
- Potentiometer (x1)
-  Curiosity Nano Base for Click boards™ [(AC164162)](https://www.microchip.com/Developmenttools/ProductDetails/AC164162?utm_campaign=PIC18FQ43&utm_source=GitHub&utm_medium=embeddedLink&utm_term=&utm_content=pic18f57q43-dma-adc-to-uart-part1-MMTCha) - **[Optional]** this was only used in lieu of a breadboard.

## Setup
The hardware is setup as shown [in this video](https://www.youtube.com/watch?v=Wz7gt11gpSw&t=1s). All the specific pins are present in the diagram below. The Curiosity Nano Baseboard for clicks are no present in the diagram, since they were only used as breadboard-alternatives.

![](images/hardware_setup.jpg)

### Connections

| Potentiometer | Q43 (part 1)      |               | Q43 (part 2)|
|---------------|-------------------|---------------|-------------|
|        +      |    3.3V           |               |             |
|       gnd     |    gnd            |               |             |
|   output      |    RA0            | (Yellow Wire) |             |             
|               |    RA3 (UART3 TX) | -----------> |    RA4 (UART3 RX)  |             |


## Operation
![](images/part1-gif.gif)

## Summary

As noted before - this is part 1 of 2 of an example showing how to set up [Direct Memory Access (DMA)](https://www.microchip.com/design-centers/8-bit/peripherals/core-independent/direct-memory-access?utm_campaign=PIC18FQ43&utm_source=GitHub&utm_medium=embeddedLink&utm_term=&utm_content=pic18f57q43-dma-adc-to-uart-part1-MMTCha) using the [Microchip Code Configurator (MCC)](https://www.microchip.com/mplab/mplab-code-configurator?utm_campaign=PIC18FQ43&utm_source=GitHub&utm_medium=embeddedLink&utm_term=&utm_content=pic18f57q43-dma-adc-to-uart-part1-MMTCha) on the [PIC18F57Q43 Curiosity Nano](https://www.microchip.com/Developmenttools/ProductDetails/DM164150?utm_campaign=PIC18FQ43&utm_source=GitHub&utm_medium=embeddedLink&utm_term=&utm_content=pic18f57q43-dma-adc-to-uart-part1-MMTCha) to transfer an Analog to Digital (ADC) conversion to a UART TX buffer without writing **any lines of code and zero CPU utilization** using DMA.

More generally, the technique detailed below shows the process of how one can:
- Use the DMA GUI provided in MCC
- Use the DMA to transfer memory from one special function register (SFR) to another SFR
- Specify hardware triggers that will initiate the above memory transfer


The goal here is to exemplify the usage of the GUI provided by MCC that will generate all the code we need. This means that **any device that has the DMA peripheral and is supported in MCC** can be similarly configured through the same methods. The section below details how to do this.

<!-- Summarize what the example has shown -->
## Walkthrough
[Back to Table of Contents](#table-of-contents)
<!-- Summarize what the example has shown -->
### Create New MPLAB X Project and Open MCC
1. Open the MPLAB X IDE
2. Create new project by clicking the icon: ![](images/new_project_icon.png)   
   1. Alternatively: file >> New Project
3. In the **Choose Project** window:
   1. Select **Microchip Embedded** category
   2. Select **Standalone Project**
   3. Click **Next>**
4. In the **Select Device** window:
   1. Select **PIC18F57Q43** as your device
   2. Pro-tip: Input the last three or four characters of the device, then select the device from the drop-down list (e.g. Q43).
   3.  Click **Next>**
5.  In the **Select Tool** window (Optional): 
    1.  If device is connected, select PIC18F57Q43 Curiosity Nano (PKOB nano)
    2.  If not, The Curiosity Nano can be selected later on.
    3.  Click **Next>**
6.  In the **Select Compiler** window:
    1.  Select XC8 (v2.45)
    2. Click **Finish**
7.  Open MCC by clicking the icon in the toolbar ![](images/open_mcc_icon.png)

### Configure MCC
1. In the project resources window: check the dropdown box for **System** =>  click clock control.
   
![](images/project_resources_clock_control.png)

   1. In the clock control window: go to the easy view tab, and set **Clock Settings** to **HFINTOSC**

![](images/clock_control.png)

2. Under Device Resources in left-hand pane:
   1. Open the **Drivers** drop-down
   2. Click the green plus sign next to **ADCC**, **DMA**, **TMR0** and **UART3** peripherals to add them your project.


![](images/device_resources.png)

   After adding drivers for ADCC, DMA1, TMR0, and UART3. The project resources window will look like below.

![](images/project_resources.png)

3. In the **TMR0** window:
   1. Select **FOSC/4** for **Clock Source**
   2. Set **Clock pre-scaler** to **1:64**
   3. Set **Requested Period** to **50 ms**
   4. The **TMR0** was configured to overflow every ~50 ms. The user can reconfigure the clock source, system clock, and pre/post-scalars to change the error rate or the range of acceptable inputs for the timer period.


![](images/tmr0_easyview.png)

4. In the **ADCC** window:
   1. Set **Clock Source** to **ADCRC**
   2. Set **Auto-Conversion Trigger** to **TMR0**
   3. The default setting is changed for the clock source to the internal ADC RC oscillator circuit (i.e. FRC), and set up the ADC to get a conversion every time a rising edge is detected from TMR0.


![](images/adcc_setup.png)

5. In the **UART** window:
   1. Set Baud Rate to 9600.

![](images/uart3_setup.png)

6. In the Pin Manager: Grid View window:
   1. UART3 TX3 --> A3
   2. UAR3 RX3 --> A4 (not required for transmitting)
   3. ADCC ANx --> A0

![](images/pin_grid_view.png)

7. In the **DMA Manager** window:<br>

![](images/dma1_easyview.png) <br>

|     | Module | Region | SFR    | VarName | VarSize | Address | Mode      | Message Size | Start Trigger | Abort Trigger |
|-----|--------|--------|--------|---------|---------|---------|-----------|--------------|---------------|---------------|
| Src | ADCC   | SFR    | ADRESL | -       | -       | -       | increment | 2            | U3TX          | None          |
| Dst | UART3  | SFR    | U3TXB  | -       | -       | -       | unchanged | 1            | U3TX          | None          |

1. Enable **DMA Channel1**
   1. **ADCC** is the **source module** of the DMA channel
   2. **ADRESL** is the **SFR region** that we want data to be sourced from
   3. **Mode** must be **incremented** to get the value from ADRESH, which is directly above ADRESL according to the SFR Memory Map.
   4. **Message size** is basically **how many bytes** are coming from the source module. The ADC result register is a *16-bit register*, so the **message size is 2-bytes**.
   5. Similarly, the UART TX Buffer is 1-byte, so we need to indicate that it can only handle one byte at a time. (i.e. message size = 1)
   6. Set the DMA **start trigger** to fire every time TX Buffer is empty (**U3TXB**). At this point you might wonder – why don’t I just set the trigger for every time there is an ADC conversion? You are certainly given the flexibility to do so by setting Start Trigger to AD. I encourage you to try and see what happens.
      1. **Note!** In many cases you will find that there is garbage data being transmitted from the UART. The reason for this is that depending on the relative speed of the UART, the DMA might be overwriting the buffer before the bits are shifting out. The DMA has no knowledge of this information, it’s a messenger.
2. Click **Generate Project** and
3. Click **Program the device**![](images/program-device-icon.png)

## Conclusion:

After finishing part 1, the user can either check out the results by using a logic analyzer, oscilloscope, or even a serial terminal like the Data Visualizer plugin or standalone application. Next, [**check out part 2**](https://github.com/microchip-pic-avr-examples/pic18f57q43-dma-uart-to-pwm-part2) to complete the application.

![](images\system-architecture.JPG)

[Back to Table of Contents](#table-of-contents)
