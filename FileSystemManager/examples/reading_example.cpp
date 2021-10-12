#include "FileSystemManager.h"

int main()
{
    //Reading a file example - reads ALL data from a file
    std::cout << "Hello World!\n";
    std::string Data = fs_cpp::GetFileData("C:\\Users\\US\\Desktop\\Desktop-Testing\\Test.txt");
    std::cout << Data; //show the data
}


