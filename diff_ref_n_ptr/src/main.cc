#include <iostream>
#include <memory>

using namespace std;

void seperateOddsAndEvens(const int arr[], size_t size, int*& odds, size_t& numOdds, int*& evens, size_t& numEvens)
{
   numOdds = numEvens=0;
   for(size_t i=0; i<size; ++i)
   {
      if(arr[i]%2==1)
      {
         ++numOdds;
      }
      else
      {
         ++numEvens;
      }
   }

   
    odds=new int[numOdds];
    evens=new int[numEvens];

   size_t oddPos=0, evenPos=0;
   for(size_t i=0; i<size; ++i)
   {
        if (arr[i]%2==1)
        {
            odds[oddPos++]=arr[i];
        }
        else
        {
            evens[evenPos++]=arr[i];
        }
   }
   
}

int main(void)
{
  int unSplit[]={1,2,3,4,5,6,7,8,9,10};
  int* oddNums=nullptr;
  int* evenNums=nullptr;
  size_t numOdds=0, numEvens=0;

  seperateOddsAndEvens(unSplit, size(unSplit), oddNums, numOdds, evenNums, numEvens);

  cout<<"this is odd nums: ";

  for(int i=0; i<numOdds; i++)
  {
    cout<<oddNums[i]<<", ";
  }

  cout<<endl;

  cout<<"this is even nums: ";

  for(int i=0; i<numEvens; i++)
  {
    cout<<evenNums[i]<<", ";
  }

  cout<<endl;



  delete[] oddNums; oddNums=nullptr;
  delete[] evenNums; evenNums=nullptr;

  return 0;
}