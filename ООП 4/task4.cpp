#include <iostream>
#include <ostream>
#include "RingBuff.h"
using namespace std;

int main(){
  
  cout<<"enter size: "<<endl;
  int size;
  
  cin>>size;
  list* buffer = init(size);
  
  cout<<"enter the elements: "<<endl;

  do
  {
  int a;
  cin >> a;
  add(buffer, a);
  } while (cin.get() != '\n');

  print(buffer, cout);

}