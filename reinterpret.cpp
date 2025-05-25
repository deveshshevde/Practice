#include <stdio.h>
#include <stdlib.h>
#include <iostream>

struct machine_state{
    int height;
    int speed;
    int distance;
    bool arm;
    bool remote_control;
};
int main(int argc, char const *argv[])
{
    // float pi = 3.144567890f;
    // std::cout << (int)pi << std::endl; /* c wont care about what will happen after cast  */
    // std::cout << reinterpret_cast<const int*>(&pi) << std::endl; /* reinterpret the bytes and cast it to int from the memory perspective */
    // std::cout << *reinterpret_cast<const float*>(&pi) << std::endl; /* reinterpret the bytes and cast it to float from the memory perspective , so mantisa and all float standard is same so proper results are there*/

    /* Good use of reinterpret cast */
    machine_state drone1 = {71 , 15 , 23 , true , true};
    char somememorychunck[sizeof(drone1)];
    std::cout << sizeof(drone1) << std::endl;
    std::memcpy(somememorychunck , &drone1 , sizeof(drone1));
    std::cout << *((int*)somememorychunck) << std::endl; // this is some how unclear for c++ folks so they added one more level of indirection lol

    std::cout << *reinterpret_cast<int*>(somememorychunck) << std::endl;
    std::cout << *reinterpret_cast<int*>(somememorychunck + 4) << std::endl;
    std::cout << *reinterpret_cast<int*>(somememorychunck + 8) << std::endl;
    std::cout << *reinterpret_cast<bool*>(somememorychunck + 12) << std::endl;
    std::cout << *reinterpret_cast<bool*>(somememorychunck + 13) << std::endl;

    return 0;
}
