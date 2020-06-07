#include <iostream>

#include "Dr3D_gnuplot_api.hh"
#include "MacierzOb.hh"
#include "Dron.hh"
#include "InterfejsRys.hh"
#include "Draw3D_api_interface.hh"
#include "dno.hh"
#include "woda.hh"
#include "przeszkodaProst.hh"

using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;
using std::cout;
using std::endl;

int main(){

std::shared_ptr<drawNS::Draw3DAPI> api(new APIGnuPlot3D(-R,R,-R,R,-R,R,0));

std::vector<std::shared_ptr<InterfejsPrzeszkody> > kolekcja_przeszkod;
std::shared_ptr<Dron> ptrD;


Wektor<double, 3> srodekA, srodekB, srodek1, srodek2, srodek3;
srodekA.ustaw(12,12,12);
srodekB.ustaw(-8,8,0);
srodek1.ustaw(0,-16,0);
srodek2.ustaw(12,-16,12);
srodek3.ustaw(-12,-16,-12);

std::shared_ptr<Dron> D1(new Dron(api, srodek1));
std::shared_ptr<Dron> D2(new Dron(api, srodek2));
std::shared_ptr<Dron> D3(new Dron(api, srodek3));

//std::shared_ptr<Dron> D1(new Dron(api, srodek1));
//std::shared_ptr<Dron> D2(new Dron(api, srodek2));

std::vector<std::shared_ptr<InterfejsPrzeszkody>> przeszkody{
  std::make_shared<PrzeszkodaProst>(api, srodekA),
  std::make_shared<PrzeszkodaProst>(api, srodekB),
  std::make_shared<Woda>(api),
  std::make_shared<Dno>(api),
};

char czytaj;
int wyborDrona = 0;

std::cout << "\nWirniki pojawia sie po wykonaniu jakiejkolwiek operacji na danym dronie!\nWybor drona nastepuje po wybraniu operacji." << std::endl;

while(1){

  std::cout << "\nz - obrot drona wokol osi OZ\n";
  std::cout << "x - obrot drona wokol osi OX\n";
  std::cout << "f - ruch drona do przodu\n";
  std::cout << "q - koniec programu\n";
  std::cout << "Wybierz opcje:\t";
  std::cin >> czytaj;

  switch(czytaj){

    case 'z':{
      char z = 'z';
      double kat=0;
      std::cout << "Podaj kat obrotu: ";
      std::cin >> kat;

      std::cout << "\nWybierz drona...\n";
      std::cout << "Wspolrzedne drona 1: " << D1->getSrodek();
      std::cout << "Wspolrzedne drona 2: " << D2->getSrodek();
      std::cout << "Wspolrzedne drona 3: " << D3->getSrodek();
      std::cout << "Wpisz 1, 2 lub 3...\n";
      std::cin >> wyborDrona;

      if(wyborDrona == 1){
        D1->obracanieR(api, z, kat);
      } else if(wyborDrona == 2){
        D2->obracanieR(api, z, kat);
      } else if(wyborDrona == 3){
        D3->obracanieR(api, z, kat);
      }

    } break;

    case 'x':{
      char x = 'x';
      double kat=0;
      std::cout << "Podaj kat obrotu: ";
      std::cin >> kat;

      std::cout << "\nWybierz drona...\n";
      std::cout << "Wspolrzedne drona 1: " << D1->getSrodek();
      std::cout << "Wspolrzedne drona 2: " << D2->getSrodek();
      std::cout << "Wspolrzedne drona 3: " << D3->getSrodek();
      std::cout << "Wpisz 1, 2 lub 3...\n";
      std::cin >> wyborDrona;

      if(wyborDrona == 1){
        D1->obracanieR(api, x, kat);
      } else if(wyborDrona == 2){
        D2->obracanieR(api, x, kat);
      } else if(wyborDrona == 3){
        D3->obracanieR(api, x, kat);
      }

    } break;

    case 'f':{

      double odl;
      std::cout << "Podaj odleglosc: ";
      std::cin >> odl;

      std::cout << "\nWybierz drona...\n";
      std::cout << "Wspolrzedne drona 1: " << D1->getSrodek();
      std::cout << "Wspolrzedne drona 2: " << D2->getSrodek();
      std::cout << "Wspolrzedne drona 3: " << D3->getSrodek();
      std::cout << "Wpisz 1, 2 lub 3...\n";
      std::cin >> wyborDrona;

      if(wyborDrona == 1){
        D1->RuchR(api, odl, przeszkody);
      } else if(wyborDrona == 2){
        D2->RuchR(api, odl, przeszkody);
      } else if(wyborDrona == 3){
        D3->RuchR(api, odl, przeszkody);
      }

    } break;

    case 'q':{
  
      return 0;

    } break;
  }
}

wait4key();
return 0;

/*

  std::shared_ptr<drawNS::Draw3DAPI> api(new APIGnuPlot3D(-5,5,-5,5,-5,5,1000)); //włacza gnuplota, pojawia się scena [-5,5] x [-5,5] x [-5,5] odświeżana co 1000 ms
  //drawNS::Draw3DAPI * api = new APIGnuPlot3D(-5,5,-5,5,-5,5,1000); //alternatywnie zwykły wskaźnik
  api->change_ref_time_ms(0); //odświeżanie sceny zmienione na opcję "z każdym pojawieniem się lub zniknięciem kształtu"
  int a=api->draw_line(drawNS::Point3D(0,0,0),drawNS::Point3D(2,0,0)); //rysuje linię pomiędzy (0,0,0) a (2,0,0), zapamiętuje id kształtu w zmiennej a 
  api->draw_line(drawNS::Point3D(0,0,0),drawNS::Point3D(0,0,5),"red"); //rysuje czerwoną linie pomiędzy (0,0,0) a (0,0,5)

  cout << endl << "pojawiły się 2 linie: czarna i czerwona" << endl;  
  wait4key();

  api->erase_shape(a); //usuwa kształt o id a
  cout << "czarna linia zniknęła" << endl;

  wait4key();

  api->draw_polygonal_chain(vector<Point3D> {drawNS::Point3D(0,0,0),
	drawNS::Point3D(0,4,0),drawNS::Point3D(4,4,0),
	drawNS::Point3D(4,0,0),drawNS::Point3D(4,0,4)},"purple"); //rysuje fioletową łamaną
  cout << "pojawiła się fioletowa łamana" << endl;
  
  wait4key();
  api->change_ref_time_ms(1000);
  int b=api->draw_polygonal_chain(vector<Point3D> {drawNS::Point3D(0,0,0),
	drawNS::Point3D(0,-4,0),drawNS::Point3D(-4,-4,0),
	drawNS::Point3D(-4,0,0),drawNS::Point3D(-4,0,-4)},"green");
  cout << "pojawiła się zielona łamana" << endl;
  
  wait4key();
  api->change_shape_color(b,"yellow");//zmienia kolor
  cout << "zmiana koloru z zielonej na żółtą" << endl;

  wait4key();
  api->change_ref_time_ms(-1);//odświerzanie sceny zmienione na opcję "tylko za pomocą metody redraw()"

  api->draw_polyhedron(vector<vector<Point3D> > {{
	drawNS::Point3D(0,0,0), drawNS::Point3D(0,1,0), drawNS::Point3D(1,1,0)
      },{
	drawNS::Point3D(0,0,3), drawNS::Point3D(0,1,3), drawNS::Point3D(1,2,4)       
	  }},"blue");//rysuje niebieski graniastosłup
  cout << "nie pojawia się niebieski graniastosłup" << endl;
  
  wait4key();

  api->redraw();//odświerzenie sceny
  cout << "dopiero teraz pojawiła się niebieski graniastosłup" << endl;

  wait4key();
  api->change_ref_time_ms(0);

  api->draw_surface(vector<vector<Point3D> > {{
	drawNS::Point3D(-4,-2,-4), drawNS::Point3D(-4,0,-4), drawNS::Point3D(-4,2,-4)
	  },{
	drawNS::Point3D(-2,-2,-4), drawNS::Point3D(-2,0,-4), drawNS::Point3D(-2,2,-4)       
	  },{
	drawNS::Point3D(-0,-2,-4), drawNS::Point3D(-0,0,-3), drawNS::Point3D(-0,2,-4)       
	  },{
	drawNS::Point3D(2,-2,-4), drawNS::Point3D(2,0,-4), drawNS::Point3D(2,2,-4)       
	  },{
	drawNS::Point3D(4,-2,-4), drawNS::Point3D(4,0,-4), drawNS::Point3D(4,2,-4)       
	  }},"grey");//rysuje szarą powierzchnie
  cout << "pojawiła się szara powierzchnia" << endl;

  
  wait4key();
  
  //delete api;//dla zwykłych wskaźników musimy posprzątać

*/

}
