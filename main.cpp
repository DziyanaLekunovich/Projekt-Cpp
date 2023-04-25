#include <iostream>
#include "siatka.h"
#include <time.h>

using namespace std;

int main()
{
    srand(time(NULL));

    Board b(20, 20);

    for(int i = 0; i < 1000; i++){
    b.cykcle();
    cout << b << endl;
    system("cls");
    }


    //cout << b;

    return 0;
}
