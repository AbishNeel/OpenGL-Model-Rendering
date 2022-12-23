# OpenGLModelRendering

A program written in OpenGL and C++ that can import and render 3D models saved in the GLTF format. Makes use of concepts such as Vertex Buffer Objects, Index Buffer Objects, fragment shaders and vertex shaders to render models robustly. I have provided a few models that can be rendered and the program will prompt you asking which model you want to load in.


SCREENSHOTS

![Screenshot (27)](https://user-images.githubusercontent.com/75297748/209404079-e16b4e98-25b6-4fe6-ba2c-dda543d6b192.png)


![Screenshot (28)](https://user-images.githubusercontent.com/75297748/209404093-e9c6679c-bf2c-4d12-aca0-8689f8579206.png)


![Screenshot (29)](https://user-images.githubusercontent.com/75297748/209404106-3b9d24c6-9c2d-4275-898c-dc609fbf837c.png)


![Screenshot (30)](https://user-images.githubusercontent.com/75297748/209404112-ba078290-2e3d-4e4a-b8b0-8acceb6a3fb4.png)


HOW TO RUN
1. Clone this repo. (This repo contains all of the dependencies except jsoncpp, use vcpkg to integrate install jsoncpp with visual studio)
2. Go to build > bin > OpenGL Model Rendering > x64 > Debug and run OpenGL Model Rendering.exe


CONTROLS
1. Hold down the left mouse button and move the mouse around to look around.
2. WASD to move up down left and right (relative to camera rotation).
3. L-ctrl to move down and space bar to move up (absolute).
