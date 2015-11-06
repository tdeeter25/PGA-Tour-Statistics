#include <iostream>; 
#include <fstream>; 
#include <string>; 

using namespace std; 


int main() {
	string player; 
	cout << "Enter a player to search for "; 
	cin >> player; 
	bool playerFound = false; 
	string stats[] = {"Greens In Regulation.txt", "Driving Accuracy.txt", "Driving Distance.txt", "Scoring Average.txt" }; 
	
	fstream file; 
	
	for (int i = 0; i < 4; i++){	
		file.open(stats[i]); 
		cout << stats[i] << endl; 
		if (file) {
			while (!file.eof()) {
				//does not have functionality if multiple players have the same first name
				string line;
				getline(file, line);
				if (line.find(player) != std::string::npos) {
					cout << line << endl;
					playerFound = true;
					break;
				}
			}
			file.seekg(0, file.beg); 
			file.close(); 
			if (!playerFound) {
				cout << "Player not found" << endl;
			}

		}
	}

	
	
	system("pause"); 
	return 0; 
}