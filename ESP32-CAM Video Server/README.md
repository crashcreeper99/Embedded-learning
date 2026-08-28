# ESP32-CAM Live Video Server

## Overview
This project uses an ESP32-CAM with an OV2640 camera to host a live video stream over Wi-Fi. A phone or computer on the same network can open the ESP32-CAM web interface and view the camera feed in a browser.

## Components
- ESP32-CAM
- OV2640 camera
- Stable 5V power source
- USB-to-serial programmer or compatible programming interface
- Jumper wires
- Wi-Fi network

## Core Concepts
- Embedded camera interfaces
- Wi-Fi networking
- HTTP web servers
- Video streaming
- ESP32-CAM programming
- Image configuration

## How It Works
1. The ESP32-CAM initializes the OV2640 camera.
2. It connects to the configured Wi-Fi network.
3. The board starts a camera web server.
4. The ESP32 prints its local IP address.
5. A browser connects to that IP address.
6. The camera stream is displayed through the web interface.

## Testing
- Verify that the board programs successfully.
- Remove the programming-mode connection if required and restart the board.
- Confirm that it connects to Wi-Fi and prints an IP address.
- Open the IP address from a device on the same network.
- Start the stream and verify that live video appears.

## What I Learned
This project expands beyond basic sensors by using an embedded camera, networking, and a browser-based interface together. It demonstrates how an ESP32 can serve real-time visual information without a separate computer controlling the camera.

## Future Improvements
- Capture still photographs.
- Save images to microSD.
- Add PIR-triggered capture.
- Build a remote security camera.
- Add timestamps to saved images.

## Status
Planned build for the August 27, 2026 catch-up sprint. Do not mark complete until physically built and tested.
