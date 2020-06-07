#ifndef DRON_HH
#define DRON_HH

#include "Prostopadloscian.hh"
#include "Wirnik.hh"
#include "InterfejsDrona.hh"
#include "InterfejsPrzeszkody.hh"

/*!
* \brief Zmienne tworzace dwa wirniki z przesunieciem na osi x wzgledem domyslnego polozenia
*/

/*!
* \brief Klasa definiujaca dron, dziedziczy po klasie Prostopadloscian
*/
class Dron : public Prostopadloscian, public InterfejsDrona, public InterfejsPrzeszkody{

protected:

    Wirnik W1;
    Wirnik W2;
    std::shared_ptr<Dron> D;

public:

/*!
* \brief Konstruktor domyslny tworzacy drona jako bryle o domyslnych polach dziedziczonych klas
*/
    Dron(){}

/*!
* \brief Konstruktor tworzacy drona o srodku w danym punkcie
* \param center wektor ze wspolrzednymi srodka bryly
*/
    Dron(std::shared_ptr<drawNS::Draw3DAPI> & api, const Wektor<double, 3> & center){

        Wirnik WA(-1.7, 0, 0);
        Wirnik WB(1.7, 0, 0);  
        W1 = WA;
        W2 = WB;
        this->Srodek = center;    
        nowy_wierzcholek();
        indeks[3] = rysujR(api);
    }

    Wektor<double, 3> getSrodek(){

        return Srodek;
    }

/*!
* \brief Metoda powodujaca przesuwanie sie Drona wraz z dwoma wirnikami o pewien dystans z animacja
* \param api lacze do gnuplota
* \param distance dystans o jaki przesunie sie dron po skonczeniu animacji
*/
    void RuchR(std::shared_ptr<drawNS::Draw3DAPI> &api, double distance, std::vector<std::shared_ptr<InterfejsPrzeszkody> > kolekcja_przeszkod){

        double a = distance/40;
        Wektor<double, 3> w(0,a,0);
        
/*!
* \brief Petla tworzaca wzglednie plynna animacje ruchu drona z wirnikami
*/
        for(int i=0;i<40;i++){

            //bool kolizja = false;

            usun(api, indeks[0]);
            usun(api, indeks[1]);
            usun(api, indeks[2]);
            usun(api, indeks[3]);
            MacierzOb M;
            M.ObrotY(9);
            W1.ZmianaOrientacji(M);
            W1.nowy_wierzcholekO();
            W2.ZmianaOrientacji(M);
            W2.nowy_wierzcholekO();
            PrzesunSrodek(w);
            nowy_wierzcholek();
            W1.nowy_wierzcholekW(Srodek, Orientacja);
            W2.nowy_wierzcholekW(Srodek, Orientacja);
            //kolizja = kolekcja_przeszkod[3]->czy_kolizja(D);

            /* 
                Proba wywalania funkcji czy_kolizja generuje blad: undefined reference to `InterfejsPrzeszkody::czy_kolizja
            */
           
            indeks[0] = rysujR(api);
            indeks[1] = W1.rysujR(api);
            indeks[2] = W2.rysujR(api);
            usleep(80000);
        }
    }

/*!
* \brief Metoda powodujaca obrot drona wraz z dwoma wirnikami wzgledem danej osi o dany kat alfa z animacja
* \param api lacze do gnuplota
* \param a wybrana os wedlug ktorej nastapi obrot
* \param alfa kat o jaki obroci sie dron po skonczeniu animacji
*/
    void obracanieR(std::shared_ptr<drawNS::Draw3DAPI> & api, char a, double alfa){

/*!
* \brief Kiedy obrot ma nastapic wokol osi x
*/
        if(a == 'x'){
            
            for(int i=0;i<40;i++){

                usun(api, indeks[0]);
                usun(api, indeks[1]);
                usun(api, indeks[2]);
                usun(api, indeks[3]);
                MacierzOb M;
                M.ObrotX(alfa/40);
                ZmianaOrientacji(M);
                W1.nowy_wierzcholekW(Srodek, Orientacja);
                W2.nowy_wierzcholekW(Srodek, Orientacja);
                nowy_wierzcholek();
                indeks[0] = rysujR(api);
                indeks[1] = W1.rysujR(api);
                indeks[2] = W2.rysujR(api);
                usleep(80000);
                
            }
        }

/*!
* \brief Kiedy obrot ma nastapic wokol osi z
*/
        if(a == 'z'){
            
            for(int i=0;i<40;i++){

                usun(api, indeks[0]);
                usun(api, indeks[1]);
                usun(api, indeks[2]);
                usun(api, indeks[3]);
                MacierzOb M;
                M.ObrotZ(alfa/40);
                ZmianaOrientacji(M);
                W1.nowy_wierzcholekW(Srodek, Orientacja);
                W2.nowy_wierzcholekW(Srodek, Orientacja);
                nowy_wierzcholek();
                indeks[0] = rysujR(api);
                indeks[1] = W1.rysujR(api);
                indeks[2] = W2.rysujR(api);
                usleep(80000);
                
            }
        }
    }
};

#endif
