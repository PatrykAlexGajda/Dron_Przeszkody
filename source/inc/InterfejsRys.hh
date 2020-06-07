#ifndef INTERFEJSRYSOWANIA_HH
#define INTERFEJSRYSOWANIA_HH

#include "Dr3D_gnuplot_api.hh"

/*!
* \brief Klasa definiujaca interfejs rysowania,
* zawiera dane potrzebne do rysowania danych figur np ich indeks do usuwania lub rysowania
*/
class InterfejsRysowania{

protected:
    std::shared_ptr<drawNS::Draw3DAPI> rysownik;
    int indeks[6] = {10, 10, 10, 10, 10, 10};

public:

    //virtual int rysuj(std::shared_ptr<drawNS::Draw3DAPI> & api);
    //virtual void usun(std::shared_ptr<drawNS::Draw3DAPI> & api, int a);

    // Virtuale w dalszym ciagu generuja undefined refence to vtable
    // pomimo dopisania do kazdej klasie ktora dziedziczy po interfejsie rysowania
    // funkcji rysuj oraz usun
};

#endif