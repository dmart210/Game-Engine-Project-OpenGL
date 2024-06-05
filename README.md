
# Game Engine Project - OpenGL

Welcome to the Game Engine Project! This project is a game engine written in C++ using concepts from [LearnOpenGL.com](https://learnopengl.com/). The engine includes classes for handling images, rendering, and game units.

## Table of Contents

- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Project Structure](#project-structure)
- [Contributing](#contributing)
- [License](#license)
- [Acknowledgments](#acknowledgments)

## Features

- **Rendering**: Efficient rendering of graphics using OpenGL.
- **Image Handling**: Support for loading and managing images.
- **Game Units**: Basic structure for creating game units.

## Installation

1. **Clone the repository:**

   ```bash
   git clone https://github.com/dmart210/Game-Engine-Project-OpenGL.git
   cd Game-Engine-Project-OpenGL
   ```

2. **Install dependencies:**

   Ensure you have C++ and OpenGL installed on your system. You may need additional libraries such as GLFW, GLAD, and STB for handling windows, OpenGL functions, and image loading.

   ```bash
   sudo apt-get install build-essential
   sudo apt-get install libglfw3-dev
   sudo apt-get install libglew-dev
   ```

3. **Build the project:**

   After Cloning the repository, open the CMAKE GUI application and generate the CMAKE build.

## Usage

After building the project, you can run the game engine executable by pressing the `Local Debugger` tab in Visual Studio
## Project Structure

```
Game-Engine-Project-OpenGL/
├── src/
│   ├── main.cpp
│   ├── Image.cpp
│   ├── Renderer.cpp
│   ├── Unit.cpp
│   └── ...
├── include/
│   ├── Image.h
│   ├── Renderer.h
│   ├── Unit.h
│   └── ...
├── shaders/
│   ├── vertex_shader.glsl
│   ├── fragment_shader.glsl
│   └── ...
├── assets/
│   ├── textures/
│   └── models/
├── CMakeLists.txt
└── README.md
```

- **src/**: Source code files.
- **include/**: Header files.
- **shaders/**: Shader programs.
- **assets/**: Game assets like textures and models.
- **CMakeLists.txt**: Build configuration.
- **README.md**: Project documentation.


## Acknowledgments

- This project uses concepts and tutorials from [LearnOpenGL.com](https://learnopengl.com/).
- Special thanks to all contributors and the open-source community.
