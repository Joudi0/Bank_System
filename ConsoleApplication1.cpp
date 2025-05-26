#include <iostream>
#include <vector>
#include <string>
#include <array> 
#include "clsLoginScreen.h"
using namespace std;

int main(){

    while (true)
    {
        if (!clsLoginScreen::ShowLoginScreen()) break;
        
    }
    return 0;
}