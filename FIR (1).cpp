#include<iostream>
#include<string>
#include<vector>
#include<fstream>
using namespace std;
class FIR {
    private:
    string complainantName;
    string complainantAddress;
    public:
    int id;
    string incidentDate;
    string incidentTime;
    string incidentLocation;
    string description;
    string status;
     FIR(){
        cout<< "Welcome to the Jaipur Police Station" <<endl;
    }
    FIR(int id,string incidentDate,string incidentTime,string incidentLocation,string description,string status){
        cout<< id << incidentDate << incidentTime << incidentLocation << description << status << "Constructor" << endl;
    }
    
    void setcomplaintName(string complainantName){
        this->complainantName=complainantName;
    }
    string getcomplainantName(){
        cin>> complainantName;
        return complainantName;
    }
    void setcomplaintAddress(string complainantAddress){
        this->complainantAddress=complainantAddress;
    }
    string getcomplainantAddress(){
        cin>> complainantAddress;
        return complainantAddress;
    }
    ~FIR(){
        cout<< "SATARK RAHE SURAKSHIT RAHE !!" <<endl;
    }
};

vector<FIR> firDatabase;

void addFIR() {
    FIR newFIR;
    cout << "Enter FIR details:" << endl;
    cout << "Complainant Name: ";
    newFIR.getcomplainantName();
    cout << "Complainant Address: ";
    newFIR.getcomplainantAddress();
    cout << "Incident Date (DD/MM/YYYY): ";
    cin >>newFIR.incidentDate;
    cout << "Incident Time (HH:MM:SS): ";
    cin >>newFIR.incidentTime;
    cout << "Incident Location: ";
    cin >>newFIR.incidentLocation;
    cout << "Description: ";
    cin >>newFIR.description;
    cout << "Status: ";
    cin >>newFIR.status;

    newFIR.id = firDatabase.size() + 1;
    firDatabase.push_back(newFIR);

    cout << "FIR added successfully! FIR ID: " << newFIR.id << endl;
}

void viewFIR() {
    if (firDatabase.empty()) {
        cout << "No FIRs in the database." << endl;
        return;
    }

    cout << "FIR Database:" << endl;
    for (const auto& fir : firDatabase) {
        cout << "FIR ID: " << fir.id << endl;
        cout << "Incident Date: " << fir.incidentDate << endl;
        cout << "Incident Time: " << fir.incidentTime << endl;
        cout << "Incident Location: " << fir.incidentLocation << endl;
        cout << "Description: " << fir.description << endl;
        cout << "Status: " << fir.status << endl;
        cout << "------------------------" << endl;
    }
}

void searchFIR() {
    int id;
    cout << "Enter FIR ID to search: ";
    cin >> id;

    for (const auto& fir : firDatabase) {
        if (fir.id == id) {
            cout << "FIR Found!" << endl;
            cout << "Incident Date: " << fir.incidentDate << endl;
            cout << "Incident Time: " << fir.incidentTime << endl;
            cout << "Incident Location: " << fir.incidentLocation << endl;
            cout << "Description: " << fir.description << endl;
            cout << "Status" << fir.status << endl;
            return;
        }
    }

    cout << "FIR not found." << endl;
}

int main() {
    int choice;
    while (true) {
        cout << "FIR Management System" << endl;
        cout << "1. Add FIR" << endl;
        cout << "2. View FIRs" << endl;
        cout << "3. Search FIR" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addFIR();
                break;
            case 2:
                viewFIR();
                break;
            case 3:
                searchFIR();
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

        cout << endl;
    }

    return 0;
}