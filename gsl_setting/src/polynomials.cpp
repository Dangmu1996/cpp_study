#include <iostream>
#include <gsl/gsl_poly.h>

/*P(x) = x^5 -1*/
using namespace std;

int main(int argc, char ** argv)
{
    int i;
    double a[6]= { -1 , 0 , 0 ,0,0, 1};
    double z[10];

    gsl_poly_complex_workspace * w = gsl_poly_complex_workspace_alloc(6);
    gsl_poly_complex_solve(a, 6, w, z);

    gsl_poly_complex_workspace_free (w);
    for(int i=0; i<5; i++)
    {
        cout<<"z"<<i<<"="<<z[2*i]<<" "<<z[2*i+1]<<endl;
    }



    return 0;
}