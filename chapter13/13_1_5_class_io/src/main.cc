#include "Muffin.hpp"


using namespace std;

int main(int argc, char ** argv)
{
    Muffin mf;

    mf.setDescription("changmin");
    mf.setHasChocolateChips(true);
    mf.setSize(3);
    printf("The Muffin is");
    mf.output();
    printf("-- yummu!\n");


    return 0;
}