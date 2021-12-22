#include <iostream>
#include <string>
int main()
{
    /*std::string line;
    while (std::getline(std::cin, line)) // Read from standard in line by line using std::cin and std::getline
    {
         std::cout << "Line received! Contents: " << line << std::endl;
    }*/
    char c;
    while(1)
    {
        std::cin >> c;
        //if(((int)c != 48) && ((int)c != 59))
        {
            //for(int i = 0; i < (int)c; i++) std::cout << "-";
            //std::cout << std::endl;
            std::cout << "valor: " << (int)c << std::endl;
        }
    }
}
