#ifndef POWIERZCHNIA_HH
#define POWIERZCHNIA_HH

#include "Dron.hh"
#include "InterfejsPrzeszkody.hh"
#include "InterfejsRys.hh"
#define R 24

/*!
* \brief Klasa definiujaca powierzchnie, dziedziczy po klasie InterfejsRysowania
* Zawiera tablice wektorow do rysowania poweirzchni
*/
class Powierzchnia : public InterfejsPrzeszkody, public InterfejsRysowania{

protected:

    Wektor<double, 3> Wek[15];

public:

    void usun(std::shared_ptr<drawNS::Draw3DAPI> & api, int a){}

    int rysuj(std::shared_ptr<drawNS::Draw3DAPI> & api){return 0;}

/*!
* \brief Konstruktor domyslny, zeruje wszystkie elementy tablicy wektorow
*/
    Powierzchnia(){

        for(int i=0;i<15;i++){
            Wek[i].ustaw(0,0,0);
        }
    }
};

#endif