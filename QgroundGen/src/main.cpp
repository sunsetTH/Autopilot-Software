#include <iostream>
#include <string>
#include "source.h"
#include "coordinate.h"

//------------------------------------------------------------------------------------------------

using namespace std;

//------------------------------------------------------------------------------------------------
int main(int argc, char *argv[]) {
	Source datasource;
	string file;
	file  = "C:/Users/james/Desktop/QgroundGen/files/test1.txt";
	string outputfile;
	outputfile = "C:/Users/james/Desktop/QgroundGen/files/missionOutput.mission";
	datasource.ReadFromFile(file, 100);
//--ask for inputs -----------------------------------------------------------------------------------------
//________________________________________________________________________________________________________s
	Coordinate takeoff;
	Coordinate takeoffWay;
	Coordinate LandWay;
	Coordinate homePos;
	cout << "enter homepse: lat lon alt\n";
	double lat1, lon1, alt1;
	cin >> lat1 >> lon1 >> alt1;
	if (lat1 == 0 && lon1 == 0 && alt1 == 0) {
		homePos.setAltitude(0.0);
		homePos.setLatitude(37.803784);
		homePos.setLongitude(-122.462276);
	}
	else {
		homePos.setAltitude(alt1);
		homePos.setLatitude(lat1);
		homePos.setLongitude(lon1);
	}
	cout << "enter takeoff: lat lon alt\n";
	double lat2, lon2, alt2;
	cin >> lat2 >> lon2 >> alt2;
	if (lat2 == 0 && lon2 == 0 && alt2 == 0) {
		takeoff.setAltitude(50);
		takeoff.setLongitude(-122.4626676);
		takeoff.setLatitude(37.803800950000003);
	}
	else {
		takeoff.setAltitude(alt2);
		takeoff.setLatitude(lat2);
		takeoff.setLongitude(alt2);
	}
	cout << "enter takeoffway: lat lon alt\n";
	double lat3, lon3, alt3;
	cin >> lat3 >> lon3 >> alt3;
	if (lat3 == 0 && lon3 == 0 && alt3 == 0) {
		takeoffWay.setAltitude(100);
		takeoffWay.setLatitude(37.803784);
		takeoffWay.setLongitude(-122.472276);
	}
	else {
		takeoffWay.setAltitude(alt3);
		takeoffWay.setLatitude(lat3);
		takeoffWay.setLongitude(lon3);
	}
	cout << "enter Landway: lat lon alt\n";
	double lat4, lon4, alt4;
	cin >> lat4 >> lon4 >> alt4;
	if (lat4 == 0 && lon4 == 0 && alt4 == 0) {
		LandWay.setAltitude(100);
		LandWay.setLatitude(37.803784);
		LandWay.setLongitude(-122.457276);
	}
	else {
		LandWay.setAltitude(alt4);
		LandWay.setLatitude(lat4);
		LandWay.setLongitude(lon4);
	}
//___________________________________________________________________________________________________________
	cout << "enter search altitude:\n";
	double searchalt;
	cin >> searchalt;
	cout << "enter turn around dist:\n";
	double turnaround;
	cin >> turnaround;
	cout << "enter spacing:\n";
	double spacingdist;
	cin >> spacingdist;
	datasource.WriteToFile(outputfile,homePos,takeoff,LandWay, takeoffWay, searchalt,turnaround,spacingdist,25);

	return EXIT_SUCCESS;
}

//------------------------------------------------------------------------------------------------


