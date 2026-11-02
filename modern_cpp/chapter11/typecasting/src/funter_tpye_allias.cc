#include <iostream>

using namespace std;

/*펑터 tpye allias*/
using MatchFunction = bool(*)(int, int);


/*type allias 된걸로 부르기*/
void findMathces(int values1[], int values2[], size_t numValues, MatchFunction matcher)
{
    for(size_t i=0; i< numValues; i++)
    {
        if(matcher(values1[i], values2[i]))
        {
            cout<<"Match found at position " << i << " (" << values1[i] <<", "<<values2[i]<< ")" <<endl;
        }
    }
}

bool intEqual(int item1, int item2)
{
    return item1==item2;
}

bool bothOdd(int item1, int item2)
{
    return item1 % 2 ==1 && item2 % 2 ==1 ;
}

int main(int argc, char **argv)
{
    int arr1[] = {2, 5, 6, 9, 10, 1, 1};
    int arr2[] = {4, 4, 2, 9, 0, 3, 4};

    size_t arrSize = std::size(arr1);
    cout << "Calling findMatches() using int Equal()"<< endl;
    findMathces(arr1, arr2, arrSize, &intEqual);

    cout << "Calling findMatches() using bothODd()"<< endl;
    findMathces(arr1, arr2, arrSize, &bothOdd);


    return 0;
}