#  12V to 5V & 3.3V Linear Voltage Regulator

##  Project Overview

This project focuses on designing a regulated DC power supply system that converts a 12V DC input into stable 5V and 3.3V outputs using linear voltage regulators LM7805 and LM1117-3.3.

The regulator is designed for embedded systems and microcontroller-based applications where stable voltage rails are critical for reliable operation.

---

##  Objective

- Convert 12V DC supply into:
  - 5V regulated output
  - 3.3V regulated output
- Provide clean, ripple-free voltage for logic and MCU circuits
- Ensure proper heat dissipation and stable performance

---

##  Components Used

- LM7805 (5V Linear Voltage Regulator)
- LM1117-3.3 (3.3V Linear Voltage Regulator)
- Input and output filter capacitors
- Decoupling capacitors
- DC input terminal
- Custom designed PCB with proper grounding and power routing

---

##  Design Approach

1. 12V DC input is provided to the LM7805 regulator.
2. LM7805 steps down 12V to regulated 5V output.
3. The 5V output is then fed to LM1117-3.3.
4. LM1117 further regulates voltage to stable 3.3V.
5. Proper input/output capacitors are used to:
   - Improve stability
   - Reduce ripple
   - Prevent oscillations
6. PCB designed with:
   - Wide power traces
   - Proper grounding strategy
   - Thermal consideration for regulators

---

##  PCB Design Features

- Compact and clean layout
- Clear separation of input and output sections
- Proper decoupling placement near regulator pins
- Thermal relief for heat dissipation
- Clean silkscreen labeling for easy debugging

---

##  Applications

- Microcontroller boards
- Embedded systems
- Sensor modules
- Development boards
- Automotive low-power electronics

---

##  Skills Demonstrated

✔ Linear Voltage Regulator Design  
✔ Power Supply Circuit Design  
✔ PCB Layout & Routing  
✔ Component Selection   
✔ Thermal Management (use of heat sinks) 

---

##  Files Included

- Schematic Design
- PCB Layout
- Routing Design
- Bill of Materials (BOM)
- Gerbers(pdf)

---

##  Project Demonstration

You can view the project images and working details here:

 **LinkedIn Project Post:**  
[working_video_link ](https://www.linkedin.com/posts/raj-singh-7b5631306_powerelectronics-pcbdesign-voltageregulator-activity-7412274540388626432-Ozpp)

---

> This design was independently developed including component selection, schematic capture, PCB layout, routing optimization, and manufacturing-ready files.
