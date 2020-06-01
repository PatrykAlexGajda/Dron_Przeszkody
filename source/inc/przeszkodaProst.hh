#ifndef PRZESZKODAPROST_HH
#define PRZESZKODAPROST_HH

#include "InterfejsPrzeszkody.hh"
#include "Prostopadloscian.hh"
#include "InterfejsDrona.hh"

class PrzeszkodaProst : public InterfejsPrzeszkody, Prostopadloscian{

protected:

public:

    PrzeszkodaProst(std::shared_ptr<drawNS::Draw3DAPI> &api, const Wektor<double, 3> & srodek){

        this->Srodek = srodek;
        nowy_wierzcholek();
        rysujG(api);
    }


    bool czy_kolizja(std::shared_ptr<InterfejsDrona> shptrD){

        return false;
    }

};

#endif