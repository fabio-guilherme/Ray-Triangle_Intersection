# Ray-Triangle Intersection

This project demonstrates the mathematical concept of ray-triangle intersection, often used in computer graphics for rendering, collision detection, and ray tracing.

## Structure

The project includes implementations for both **Mac (Xcode)** and **Windows (Visual Studio 2022)**:

## Project Structure  

```/Ray-Triangle_Intersection 
│── /mac # Xcode project setup
│── /windows # Visual Studio 2022 setup 
│ ├── /lib # Contains required DLLs and libraries for Windows 
│ ├── /Lec02_Ray-Triangle_Intersection # Windows project files 
│── README.md # This file 
│── .gitattributes # Ensure consistent handling of line endings and file formats across different operating systems  
│── .gitignore # Ignore unnecessary build files```

## Dependencies

- **Windows**: Uses `freeglut`, included in `windows/lib`.
- **Mac**: Uses system OpenGL and GLUT (no extra setup needed).

## Notes

- If you encounter any issues, ensure your IDE is configured for **x64** architecture.