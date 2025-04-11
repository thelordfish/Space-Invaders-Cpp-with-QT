# Witch's Garden (Space Invaders in C++ with Qt)

A botanical twist on the classic Space Invaders — written in C++ using Qt!

At the moment you play as a magical square in a witches garden. A spell gone wrong has caused random coloured jellies of various sizes to fall from the sky. You must eat them before they hit the ground and ruin the plants.

To do:
Add illustrations of yarrow, plaintain, dandelion, sorrel, hemlock, and various garden weeds, that explode with their name when hit. To help the user learn to identify plants.


---

## Features

- Randomized projectile types (fork, knife, spoon)
- Slowing effect when cutlery passes through jelly enemies
- Sprite-based graphics using QGraphicsScene
- Written in modular C++ with Qt 6

---

## Built With

- C++
- Qt 6 (Widgets and Graphics View Framework)
- Qt Creator (recommended IDE)

---

## Getting Started

### Prerequisites

- **Qt 6.x** (Install from [qt.io](https://www.qt.io/download) or via the Qt Online Installer)
- A C++ compiler (MinGW is bundled with the Qt installer on Windows)
- **Qt Creator IDE** (strongly recommended)

---

---

## Troubleshooting: Project Doesn't Build or Runs the Wrong Version?

If you've cloned this project or moved its location, Qt Creator might hold onto old build settings from another path. Here's how to fix that:

### 1. Clear Old CMake Config

- Close Qt Creator
- Delete any previous `build-*` folders in the project
- Delete any `.user` or `.user.*` files in the project folder

These contain cached kit and path settings that may point to the wrong location.

### 2. Reopen the Project Cleanly

- Open Qt Creator
- Go to `File > Open File or Project...`
- Select the `CMakeLists.txt` file inside the `spinvader/` folder
- When prompted, select your Qt kit (e.g., Qt 6.7.2 MinGW)
- Use a fresh build directory (e.g., `build-Qt6-Debug` inside your project folder)

### 3. Rebuild the Project

- Hit **Ctrl + B** to build
- Hit **Ctrl + R** to run

If CMake gives errors about mismatched source directories, it means you need to fully delete the old build folder and reconfigure from scratch.

---



## How to Download and Build in Qt Creator

1. **Clone or download the project:**

   - Using Git:
     ```bash
     git clone https://github.com/thelordfish/Space-Invaders-Cpp-with-QT.git
     ```
   - Or download the ZIP from the GitHub repository and extract it.

2. **Open the project in Qt Creator:**

   - Launch Qt Creator
   - Go to `File > Open File or Project...`
   - Navigate to the project folder and open the `.pro` file (e.g., `CutleryInvaders.pro`)

3. **Configure the build:**

   - Select a Qt kit (e.g., Qt 6.7.2 with MinGW)
   - Qt Creator will auto-generate a build directory

4. **Build and run the project:**

   - Press `Ctrl + R` or click the green Run button

---

## Concept

This started as a basic Space Invaders clone. A collision bug that slowed bullets inside enemies inspired the new direction: cutlery weapons and gooey, translucent jelly invaders that absorb hits before popping.

---

## Future Improvements

- Jelly wobble animations
- More distinct cutlery behaviors (e.g., spoon = slower, fork = spread)
- Improved sound effects and feedback
- Game UI with score and lives
- Boss waves and progression

---

## Author

Ollie Appleby  
https://github.com/thelordfish

---

## License

This project is open source under the MIT License.
