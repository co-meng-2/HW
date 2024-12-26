
#include <iostream>
#include "HW_OOP.h"
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

using namespace std;

int main()
{
    {
        srand(time(NULL));
        cout << "Enter animal count : ";
        int n;
        cin >> n;
        Zoo zoo(n);

        zoo.PerformActions();
    }
    
    _CrtDumpMemoryLeaks();
    
    return 0;
}
