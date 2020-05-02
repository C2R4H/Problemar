/*
 * n - tari care exporta petrol
 * i - stat
 *   ai - dolari
 *   bi - euro
 * Trebuie de folosit doar dolari sau euro
*/

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

struct tari{
  double dolari;
  double euro;
};

int main(){

  ifstream read;//citim dintrun fisier predefinit
  read.open("oilin.txt");

  double read_temp,n;//creeam variabilele necesare
  int i = 0;
  tari moldova;
  vector<double> tari_pret_dolari;
  vector<double> tari_pret_euro;

  while(read>>read_temp){
    i++;
    if (i==1) {n=read_temp;}
    if (i==2) {moldova.dolari=read_temp;}
    if (i==3) {moldova.euro=read_temp;}

    if(i>3){
      if(i%2!=0){
        tari_pret_euro.push_back(read_temp);}
      else{
        tari_pret_dolari.push_back(read_temp);}
    }
  }
  read.close();

  ofstream write;//scrim in fisierul de iesire
  write.open("oilout.txt");

  double smallest_price_dolar = 9999;
  double smallest_price_euro = 9999;
  int j = 0;
  for(i  = 0;i<tari_pret_dolari.size();i++){
    if(smallest_price_dolar>tari_pret_dolari[i]){
      smallest_price_dolar=tari_pret_dolari[i];
      j = i;}
  }

  for(i = 0;i<tari_pret_euro.size();i++){
    if(smallest_price_euro>tari_pret_euro[i] && i!=j)
      smallest_price_euro=tari_pret_euro[i];
  }

  double out_dolari = moldova.dolari/smallest_price_dolar;
  double out_euro = moldova.euro/smallest_price_euro;

  cout<<"Cel mai mic pret dolari = "<<smallest_price_dolar<<endl;
  cout<<"Cel mai mic pret euro = "<<smallest_price_euro<<endl;

  double out = out_dolari+out_euro;

  cout<<"out = "<<out<<endl;
  write.close();
}
