#ifndef DNO_HH
#define DNO_HH

#define R1 2

#include "powierzchnia.hh"

/*!
* \brief Klasa definiujaca Dno, dziedziczy po klasie Powierzchnia
*/
class Dno : public Powierzchnia {

protected:

public:

/*!
* \brief Konstruktor domyslny dla tworzenia zmiennej typu Dno
*/
	Dno(std::shared_ptr<drawNS::Draw3DAPI> &api){

      api->draw_surface(vector<vector<Point3D> > {{
	drawNS::Point3D(-R*0.8,-R*0.8,-R*0.8), drawNS::Point3D(-R*0.8,0,-R*0.8), drawNS::Point3D(-R*0.8,R*0.8,-R*0.8)
	  },{
	drawNS::Point3D(-R*0.4,-R*0.8,-R*0.8), drawNS::Point3D(-R*0.4,0,-R*0.8), drawNS::Point3D(-R*0.4,R*0.8,-R*0.8)       
	  },{
	drawNS::Point3D(-0,-R*0.8,-R*0.8), drawNS::Point3D(-0,0,-R*0.8), drawNS::Point3D(-0,R*0.8,-R*0.8)       
	  },{
	drawNS::Point3D(R*0.4,-R*0.8,-R*0.8), drawNS::Point3D(R*0.4,0,-R*0.8), drawNS::Point3D(R*0.4,R*0.8,-R*0.8)       
	  },{
	drawNS::Point3D(R*0.8,-R*0.8,-R*0.8), drawNS::Point3D(R*0.8,0,-R*0.8), drawNS::Point3D(R*0.8,R*0.8,-R*0.8)       
	  }},"yellow");	
	}

    bool czy_kolizja(std::shared_ptr<InterfejsDrona> shptrD){

		Wektor<double, 3> srodekDrona;
		srodekDrona[0] = shptrD->getSrodek[0];
		srodekDrona[1] = shptrD->getSrodek[1];
		srodekDrona[2] = shptrD->getSrodek[2];

		if(srodekDrona[2] <= -15){
			return true;
		} else {
			return false;
		}
    }
};


#endif 