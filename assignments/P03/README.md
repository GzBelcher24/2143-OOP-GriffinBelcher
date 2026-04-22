Final form of imagetool. THis program takes command line arguments, and uses them to manipulte an image. The tool can flip an image Horizontaly of verticaly, turn grayscale, brighten or blur, and rotate an image.

All tools are located in their own files, as well as a .h header file.
Args.cpp- is the parser. THis takes the args from the command line, and parses them to the other parts of the program
pipeline.cpp-this controls when the args are run.
stb image-library for working with images.
main.cpp-driver and main method, creates objects, and contains the main method.
