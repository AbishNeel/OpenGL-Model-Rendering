# OpenGLModelRendering

A program written in OpenGL and C++ that can import and render 3D models saved in the GLTF format. Makes use of concepts such as Vertex Buffer Objects, Index Buffer Objects, fragment shaders and vertex shaders to render models robustly. I have provided a few models that can be rendered and the program will prompt you asking which model you want to load in.


HOW TO RUN
1. Clone this repo. (This repo contains all of the dependencies except jsoncpp, use vcpkg to integrate install jsoncpp with visual studio)
2. Go to build > bin > OpenGL Model Rendering > x64 > Debug and run OpenGL Model Rendering.exe


CONTROLS
1. Hold down the left mouse button and move the mouse around to look around.
2. WASD to move up down left and right (relative to camera rotation).
3. L-ctrl to move down and space bar to move up (absolute).
