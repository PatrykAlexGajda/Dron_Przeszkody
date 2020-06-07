#ifndef INTERFEJSPRZESZKODY_HH
#define INTERFEJSPRZESZKODY_HH

#include "InterfejsDrona.hh"

/*!
* \brief Klasa definiujaca interfejs przeszkody
*/

class InterfejsPrzeszkody{

public:

    bool czy_kolizja(std::shared_ptr<InterfejsDrona> shptrD);

};

#endif