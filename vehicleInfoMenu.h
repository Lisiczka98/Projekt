#ifndef VEHICLEINFOMENU_H_
#define VEHICLEINFOMENU_H_

#include <iostream>

using namespace std;

extern int vehicle_choice;
extern int from_which_menu; // 1-takenVehicles; 2-availableVehicles

extern vector <Vehicle*> wolnePojazdy;
extern vector <Vehicle*> uzywanePojazdy;

extern vector <Mission*> listaMisji;


void vehicleInfoMenu(int vehicle_choice, int from_which_menu){

	system("CLS");

	if(from_which_menu == 1) {

		cout << "===============================================\n";
		cout << "           ";
		uzywanePojazdy.at(vehicle_choice)->getVehicleBrand();
		cout << "      ";
		uzywanePojazdy.at(vehicle_choice)->getVehicleModel();
		cout << "\n===============================================\n\n";

		cout << "\nAKTUALNIE W TRASIE: Tak\n\n";

		cout << "1. Wyswietl aktualna misje\n";

		cout << "0. Powrot";

		int choice;

		cin >> choice;
		cout << "\n";

		bool poprawna = false;

		while(poprawna == false){

			switch (choice){

			case 1: {

				poprawna = true;

				int id_converted;

				uzywanePojazdy.at(vehicle_choice)->saveVehicleID(&id_converted);

				int mission_choice_remote;
				int function_employee_id_remote;
				int function_vehicle_id_remote;

				for (unsigned int i=0; i<listaMisji.size(); i++){

					listaMisji.at(i)->saveMissionVehicleID(&function_vehicle_id_remote);

					if((function_vehicle_id_remote) == id_converted) {

						mission_choice_remote = i; break;

					}
				}

				listaMisji.at(mission_choice_remote)->saveMissionEmployeeID(&function_employee_id_remote);

				missionInfoMenu(mission_choice_remote, 1, function_employee_id_remote-1, function_vehicle_id_remote-1);
				break; }

			case 0: {poprawna = true; system("CLS"); takenVehicles(); break;}

			default: {cout << "Wybrano niepoprawna opcje.\n\nWybierz opcje: "; cin >> choice; cout << "\n";}
				}
			}
		}

	if(from_which_menu == 2){
		cout << "===============================================\n";
		cout << "           ";
		wolnePojazdy.at(vehicle_choice)->getVehicleBrand();
		cout << "      ";
		wolnePojazdy.at(vehicle_choice)->getVehicleModel();
		cout << "\n===============================================\n\n";

		cout << "\nAKTUALNIE W TRASIE: Nie\n\n";

		cout << "0. Powrot\n\n";

		int choice;

		cin >> choice;
		cout << "\n";

		bool poprawna = false;

		while(poprawna == false){

			switch (choice){

			case 0: {poprawna = true; system("CLS"); availableVehicles(); break;}

			default: {cout << "Wybrano niepoprawna opcje.\n\nWybierz opcje: "; cin >> choice; cout << "\n";}
			}
		}
	}
}



#endif /* VEHICLEINFOMENU_H_ */
