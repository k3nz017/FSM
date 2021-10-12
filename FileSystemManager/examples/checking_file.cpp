#include "FileSystemManager.h"

int main()
{
    //Checking a file example - Checks if a file exists .
    std::cout << "Hello World!\n";
    if(fs_cpp::DoesFileExistOnSystem("C:\\Users\\US\\Desktop\\Desktop-Testing\\Test.txt"))
        std::cout << "The file exists.\n";
}


