CPPFLAGS= -c -g -I inc -Wall -pedantic -std=c++17 

__start__: dron
	./dron

dron: obj/Dr3D_gnuplot_api.o obj/main.o obj/Macierz.o obj/Wektor.o
	g++ -o dron obj/main.o obj/Dr3D_gnuplot_api.o obj/Macierz.o obj/Wektor.o -lpthread

obj/main.o: src/main.cpp inc/Dr3D_gnuplot_api.hh inc/Wektor.hh inc/Macierz.hh inc/MacierzOb.hh inc/Bryla.hh inc/InterfejsRys.hh\
						inc/Prostopadloscian.hh inc/Dron.hh inc/powierzchnia.hh inc/woda.hh inc/dno.hh inc/Graniastoslup.hh inc/Wirnik.hh\
						inc/InterfejsDrona.hh inc/InterfejsPrzeszkody.hh inc/przeszkodaProst.hh
	g++ ${CPPFLAGS} -o obj/main.o src/main.cpp

obj/Dr3D_gnuplot_api.o: src/Dr3D_gnuplot_api.cpp inc/Dr3D_gnuplot_api.hh
	g++ ${CPPFLAGS} -o obj/Dr3D_gnuplot_api.o src/Dr3D_gnuplot_api.cpp

obj/Macierz.o: src/Macierz.cpp inc/Macierz.hh
	g++ ${CPPFLAGS} -o obj/Macierz.o src/Macierz.cpp

obj/Wektor.o: src/Wektor.cpp inc/Wektor.hh
	g++ ${CPPFLAGS} -o obj/Wektor.o src/Wektor.cpp

inc/Dr3D_gnuplot_api.hh: inc/Draw3D_api_interface.hh
	touch inc/Dr3D_gnuplot_api.hh

clear:
	rm -f obj/*.o dron
