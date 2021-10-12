#include "FileSystemManager.h"

int main()
{
    //Moving Files Example - This moves a file with all its data, from a directory to a new diffrent dir and file.
    std::cout << "Hello World!\n";
    fs_cpp::MoveFileToDirectory("C:\\Users\\US\\Desktop\\Desktop-Testing\\Test.txt", "C:\\Users\\US\\Desktop\\New folder\\MovedFile.txt");
}


