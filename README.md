# fract'ol - Computer Graphics Fractals (v3)

Welcome to **fract'ol** – a thrilling dive into the world of computer graphics and fractals, built entirely in C! This project was my first foray into creating visually stunning graphics using the MLX42 library, and it was an incredibly exciting challenge.

---

## Summary

- **Project:** fract'ol – Computer Graphics Fractals  
- **Version:** 3  
- **Description:** Create graphically beautiful fractals (Mandelbrot, Julia and Burning Ship sets) using C and MLX42. Experience interactive zoom, smooth color gradients, and bonus features that bring extra life to fractals.

---

## Table of Contents

- [Foreword](#foreword)
- [Introduction](#introduction)
- [Objectives](#objectives)
- [Common Instructions](#common-instructions)
- [Mandatory Part](#mandatory-part)
  - [Rendering](#rendering)
  - [Graphic Management](#graphic-management)
- [Bonus Features](#bonus-features)
- [Usage](#usage)
- [Conclusion](#conclusion)
- [License](#license)

---

## Foreword

Inspired by the fascinating world of fractals and the idea of infinite complexity, this project channels the spirit of mathematical art into an interactive graphics program.

---

## Introduction

The term *fractal* was coined by Benoit Mandelbrot and represents structures that repeat at every scale. In fract'ol, I implemented the classic Mandelbrot set along with the Burning Ship and dynamic Julia sets, harnessing the power of C and MLX42 library for graphics rendering. This project opened up a whole new world of computer graphics for me!

---

## Objectives

- **Learn & Explore:** Get hands-on with the MLX42 library and basic computer graphics in C.
- **Understand Fractals:** Dive into the math behind fractals and visualize the beauty of the Mandelbrot and Julia sets.
- **Interactive Experience:** Implement zooming with the mouse wheel, smooth window management, and dynamic rendering.
- **Bonus Challenge:** Push boundaries with extra fractal types, mouse-driven zoom, arrow key navigation, and color shifting for that extra psychedelic touch.

---

## Common Instructions

- **Language:** Written entirely in C.
- **Norm Compliance:** All code must follow the Norm standards (including bonus files).
- **Memory Management:** No leaks! All dynamically allocated memory must be freed.
- **Makefile:** Must include the following rules:
  - `$(NAME)`, `all`, `clean`, `fclean`, `re`
  - A `bonus` rule to compile extra features.
- **Libraries Used:** MLX42 for graphics, math library (`-lm`), and optionally ft_printf for custom printing.

---

## Mandatory Part

### Rendering

- **Fractals:**  
  - Mandelbrot Set
  - Burning Ship Set 
  - Julia Set (configurable via command-line parameters)
- **Interactivity:**  
  - Use the mouse wheel to zoom in and out (practically infinite zoom!)
  - Command-line parameters define which fractal to display.
- **Coloring:**  
  - Multiple colors are used to represent the fractal depth.
  - Enjoy some basic psychedelic effects that show the true beauty of fractals.

### Graphic Management

- **Window Handling:**  
  - The program displays the fractal in a dedicated window.
  - Smooth management of window events (minimizing, switching windows, etc.).
- **User Input:**  
  - Pressing ESC or clicking the window close button exits the program cleanly.
- **Technical Requirements:**  
  - Use MLX42 images to render the fractals.
  - No global variables – all data is managed cleanly and efficiently.

---

## Bonus Features

The bonus part is where things get even more exciting! Extra points are awarded for:
- Implementing an additional fractal type (there are hundreds out there!)
- Making the zoom center follow the actual mouse position.
- Allowing view movement via arrow keys.
- Dynamically shifting the color range to enhance visual effects.

---

## Usage

1. **Compilation:**
   - Run `make` to compile the project.
   - For bonus features, run `make bonus`.

2. **Running the Program:**
```bash
./fractol [fractal_type] [optional_parameters]
```

Example: ./fractol mandelbrot or ./fractol julia 0.285 0.01

### 3. Controls:
Mouse Wheel: Zoom in/out
ESC / Window Close Button: Exit the program
(Bonus) Arrow Keys: Move the view
(Bonus) Dynamic Color Shift: Enjoy the psychedelic effects!

## Conclusion

Working on fract'ol was a transformative experience. For the first time, I dove into computer graphics with C, and it was both challenging and exhilarating. Implementing fractals taught me not only about complex mathematical concepts but also about efficient memory management, event handling, and the joy of creating interactive art with code.