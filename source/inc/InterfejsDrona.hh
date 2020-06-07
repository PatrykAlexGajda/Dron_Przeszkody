#ifndef INTERFEJSDRONA_HH
#define INTERFEJSDRONA_HH


/*!
* \brief Deklaracja klasy InterfejsPrzeszkody zamiast dziedziczenia poniewaz dziedziczy ona po klasie InterfejsDrona
*/

class InterfejsPrzeszkody;

/*!
* \brief Klasa definiujaca interfejs drona
* Zawiera promien wokol drona do sprawdzania kolizji z przeszkodami
*/

class InterfejsDrona{

protected:

    double R=4;

public:

    InterfejsDrona(){}

    Wektor<double, 3> getSrodek();

    void RuchR(std::shared_ptr<drawNS::Draw3DAPI> &api, double distance, std::vector<std::shared_ptr<InterfejsPrzeszkody> > kolekcja_przeszkod);
    void obracanieR(std::shared_ptr<drawNS::Draw3DAPI> & api, char a, double alfa);

};

#endif