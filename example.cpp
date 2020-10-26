/*  CLIc example source file - Copyright 2020 Stéphane Rigaud, Robert Haase,
*   Institut Pasteur Paris, Max Planck Institute for Molecular Cell Biology and Genetics Dresden
*
*   CLIc is part of the clEsperanto project http://clesperanto.net 
*
*/


#include "CLE.h"

#include "tiffreader.h"
#include "tiffwriter.h"

/**
 * Main test function
 *
 */
int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cerr << << std::endl;
    }
    
    /*
     * Manage input and output filename.
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
    TiffReader reader (inputFilename.str_c());
    float* array = reader.read(width, height, depth);
    Image<float> image (array, width, height, depth, "float");




    /**
     * Paste your CLIc code here :)
     */



    /*
     * Write image to filename.
     */ 
    unsigned int width, height, depth;
    TiffWriter writer (inputFilename.str_c());
    writer.write(image.GetData(), width, height, depth);

    // That's all folks!
    return EXIT_SUCCESS;
}
