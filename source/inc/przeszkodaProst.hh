#ifndef PRZESZKODAPROST_HH
#define PRZESZKODAPROST_HH

#include "InterfejsPrzeszkody.hh"
#include "Prostopadloscian.hh"
#include "InterfejsDrona.hh"

/*!
* \brief Klasa definiujaca przeszkode prostopadloscienna 
*/

class PrzeszkodaProst : public InterfejsPrzeszkody, public Prostopadloscian{

protected:

public:

/*!
* \brief Konstruktor przeszkody
* \param api lacze do gnuplota
* \param srodek srodek prostopadloscianiu 
*/
    PrzeszkodaProst(std::shared_ptr<drawNS::Draw3DAPI> &api, const Wektor<double, 3> & srodek){

        this->Srodek = srodek;
        nowy_wierzcholek();
        rysujG(api);
    }

/*!
* \brief Niedokonczona funkcja sprawdzajaca kolizje Drona z ta przeszkoda
*/

    bool czy_kolizja(std::shared_ptr<InterfejsDrona> shptrD){

        return false;
    }

};

#endif