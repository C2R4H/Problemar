#include <iostream>
#include <cstring>
#include <string>
#include <fstream>

using namespace std;

int main(){
  ofstream in;
  in.open("input.txt");
  string expresie;
  cin>>expresie;
  in<<expresie;
  in.close();

  ifstream read;
  read.open("input.txt");
  read>>expresie;
  char expresie_t[expresia.size() + 1];
  strcpy(expresie_t,expresie.c_str());
  for(int i = 0;i < expresia.size();i++){
    if(isdigit(expresie_t[i])){
    }
  }
  read.close();
}
