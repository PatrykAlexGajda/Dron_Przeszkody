#ifndef INTERFEJSDRONA_HH
#define INTERFEJSDRONA_HH

class InterfejsPrzeszkody;

class InterfejsDrona{

protected:

    double R=4;

public:

    Wektor<double, 3> getSrodek();

    void RuchR(std::shared_ptr<drawNS::Draw3DAPI> &api, double distance, std::vector<std::shared_ptr<InterfejsPrzeszkody> > kolekcja_przeszkod);
    void obracanieR(std::shared_ptr<drawNS::Draw3DAPI> & api, char a, double alfa);

};

#endif