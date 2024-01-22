#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
	string path, name, buffer;
	ofstream outFile;
	do {
		getline(cin, path);
		getline(cin, name);
		cout << (path+string("/")+name).c_str() << endl;
		outFile.open((path+string("/")+name).c_str());
		if(!outFile) {
			cout << "Create Error" << endl;
		}
	} while (!outFile);
	while(getline(cin, buffer)) {
		if(buffer.empty()) break;
		outFile << buffer << endl;
	}
	outFile.close();
	cout << path+string("/")+name << endl << name << endl;
	ifstream inFile((path+string("/")+name).c_str());
	while(getline(inFile, buffer)) {
		if(buffer.empty()) break;
		cout << buffer << endl;
	}
	inFile.close();
}
