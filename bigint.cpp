#include "bigint.h"
#include <iostream>

using namespace std;


//constructor (initialize data member v)
//converts digits (chars of s) to ints (elements of vector)
//reverse the order
BigInt::BigInt(string s)
{
  for(int i=s.size()-1; i>=0; i--)
  {
    v.push_back(int(s[i])-48); //put converted into vector in reverse order
  }
}

//get string representation to print out
string BigInt::to_string()
{
  string s1;
  //reverse order to properly show number
  for(int i=v.size()-1; i>=0; i--)
  {
    s1+= '0' + v[i]; //convert to ascii
  }
  return s1;
}

//add another BigInt to this one
void BigInt::add(BigInt b)
{
  int bigger=0; //determine amount of times to loop (bigger size)
  int carry=0; //initialize carry to 0 for first iteration
  int sum=0; //sum of current digits
  if(v.size()>b.v.size())
  {
    bigger=v.size();
  }
  else bigger=b.v.size();
  
  //match the amount of digits
  while(b.v.size()>v.size())
  {
    v.push_back(0);
  }
  while(b.v.size()<v.size())
  {
    b.v.push_back(0);
  }
  
  //main loop
  for(int i=0; i<bigger; i++)
  {
    sum=v[i]+b.v[i]+carry;
    if(sum>9) //if we need to carry
    {
      v[i]=sum%10; //number that stays
      carry=sum/10; //new carry
    }
    else //if we dont need to carry
    {
      carry=0; //reset carry
      v[i]=sum;
    }
  }
  //last carry
  if(carry>0)
  {
    v.push_back(carry);
  }
}

