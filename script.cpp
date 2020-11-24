/*  CLIc example source file - Copyright 2020 Stéphane Rigaud, Robert Haase,
*   Institut Pasteur Paris, Max Planck Institute for Molecular Cell Biology and Genetics Dresden
*
*   CLIc is part of the clEsperanto project http://clesperanto.net 
*
*/

// CLIc include
#include "CLE.h"

// I/O include
#include "tiffreader.h"
#include "tiffwriter.h"

// Set CLIc Namespace
using namespace cle;

/**
 * Main function
 */
int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cerr << "Usage: argv[0] filename [filename]" << std::endl;
        return EXIT_FAILURE;
    }
    
    /*
     * Manage input and output of the executable.
     */ 
    std::string inputFilename = argv[1];
    std::string outputFilename = "./output.tif";
    if (argc > 2)
    {
        outputFilename = argv[2];
    }
    
    /*
     * Read image from filename.
     */ 
    unsigned int width, height, depth;
    TiffReader reader(inputFilename.c_str());
    float* array = reader.read(&width, &height, &depth);
    Image<float> image(array, width, height, depth, "float");



    /**
     * Paste your clEsperento - CLIc code here ! 
     */



    /*
     * Write image to filename.
     */ 
    TiffWriter writer(outputFilename.c_str());
    writer.write(image.GetData(), width, height, depth);

    /*
     * That's all folks!
     */ 
    return EXIT_SUCCESS;
}
