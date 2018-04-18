#include <iostream>
#include <cstdlib>//for "exit()" on some systems
#include <vector>
#include <string>

using namespace std;

void selectionSort(auto& data); //sort data using selection sort method

int main()
{
  vector<string> inputs;
  string search_key, input;

   cout<<"Welcome to \"sort it\". We first need some input data."<<endl;
   cout<<"We'll assume the inputs do not have any spaces."<<endl<<endl;
   cout<<"To end input type the #-character (followed by Enter)"<<endl<<endl;

   cin>>input;
 
    while(input != "#")//read an unknown number of inputs from keyboard
    {
       inputs.push_back(input);
       cin>>input;
    }

   cout<<endl<<"["<<inputs.size()<<" values read from input source]"<<endl<<endl;

  if(inputs.size() == 0)//no input
  {
      cout<<endl<<"No input received, quiting..."<<endl<<endl;
       exit(1);//nothing to do but quit program
  }
 
  selectionSort(inputs); //sort input
  
  for(unsigned int i=0; i<inputs.size()-1; i++)
  {
    cout << inputs[i] << endl;
  }
 
   cout<<endl<<"Program \"sort it\" is now finished."<<endl<<endl;

    return 0;
}

void selectionSort(auto& data)
{
  //find smallest data and put at beggining
  //have temp hold smallest and check untill end of list
  //each time start at next data++ for beggining
  //loop untill no changes
  for(unsigned int i=0; i<=data.size(); i++)
  {
    //swap temp with data start position
    unsigned int smallest_position = i;
    auto smallest_value = data[i];
    
    for(unsigned int j=i; j<data.size(); j++) //outer loop, checkes if start position data is lowest
    {
      if(data[j] < smallest_value) //check if any data is smaller than start position data
      {
        smallest_position = j;
	smallest_value = data[j];
      }
    }

    if(smallest_position != i) //swap lowest value with starting position
    {
      auto swap_variable = data[i];
      data[i] = data[smallest_position];
      data[smallest_position] = swap_variable;
    }

    if( (i%20000) == 0) //for every 20000 searches
    {
      cout << "Number of passes = " << i << endl;
    }
  }
}


