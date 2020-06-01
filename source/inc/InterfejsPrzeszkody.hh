#ifndef INTERFEJSPRZESZKODY_HH
#define INTERFEJSPRZESZKODY_HH

#include "InterfejsDrona.hh"

class InterfejsPrzeszkody{

protected:

public:

    bool czy_kolizja(std::shared_ptr<InterfejsDrona> shptrD);

};

#endif