#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Aeroflot {
private:
    string destination;
    int id;
    int departureDays[7] = { 0, 0, 0, 0, 0, 0, 0 };

public:
    Aeroflot() {
        destination = "";
        id = 0;
        for (int i = 0; i < 7; ++i) {
            departureDays[i] = 0;
        }
    }

    Aeroflot(const std::string& dest, int flightNum, int depDays[7]) {
        destination = dest;
        id = flightNum;
        for (int i = 0; i < 7; ++i) {
            departureDays[i] = depDays[i];
        }
    }
    Aeroflot(const Aeroflot& item) {
        destination = item.destination;
        id = item.id;
        for (int i = 0; i < 7; ++i) {
            departureDays[i] = item.departureDays[i];
        }
    }

    string getDestination() const {
        return destination;
    }

    int getId() const {
        return id;
    }

    const int* getDepartureDays() const {
        return departureDays;
    }

    friend istream& operator>>(istream& in, Aeroflot& aeroflot) {
        in >> aeroflot.destination;
        in >> aeroflot.id;
        for (int i = 0; i < 7; ++i) {
            in >> aeroflot.departureDays[i];
        }
        return in;
    }

    friend ostream& operator<<(ostream& out, const Aeroflot& aeroflot) {
        out << "Destination: " << aeroflot.destination << "\n";
        out << "Flight Number: " << aeroflot.id << "\n";
        out << "Departure Days: ";
        for (int i = 0; i < 7; ++i) {
            out << aeroflot.departureDays[i] << " ";
        }
        out << "\n";

        return out;
    }
};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//int countt = 0;
vector<Aeroflot> readDataFromFile(const std::string& filename) {
    vector<Aeroflot> aeroflots;
    ifstream file(filename);

    if (file.is_open()) {
        Aeroflot aeroflot;
        while (file >> aeroflot) {
            aeroflots.push_back(aeroflot);
        }

        file.close();
    }
    else {
        cerr << "Unable to open file: " << filename << endl;
    }
    return aeroflots;
}

void displayAllFlights(const vector<Aeroflot>& aeroflots) {
    cout << "All Flights:\n";
    for (const Aeroflot& aeroflot : aeroflots) {
        cout << aeroflot << "\n";
    }
}

vector<Aeroflot> findByDestination(vector<Aeroflot> flots, const string dest) {
    vector<Aeroflot> sorted;
    for (const Aeroflot& flot : flots) {
        if (flot.getDestination() == dest) sorted.push_back(flot);
    }
    return sorted;
}

bool compareById(const Aeroflot& first, const Aeroflot& second) {
    return first.getId() < second.getId();
}

vector<Aeroflot> sortById(vector<Aeroflot> flots) {
    vector<Aeroflot> sorted;
    for (const Aeroflot& flot : flots) {
        sorted.push_back(Aeroflot(flot));
    }
    
    sort(sorted.begin(), sorted.end(), compareById);

    return sorted;
}


vector<Aeroflot> sortByDepartureDays(vector<Aeroflot> flots, int day) {
    vector<Aeroflot> copied;
    for (const Aeroflot& flot : flots) {
        copied.push_back(Aeroflot(flot));
    }

    vector<Aeroflot> sorted;
    for (const Aeroflot& flot : copied) {
        if (flot.getDepartureDays()[day - 1] == 1) {
            sorted.push_back(flot);
        }
    }
    return sorted;

}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main() {

    vector<Aeroflot> aeroflots = readDataFromFile("flights.txt");





    int choice;

    do {
        // Вивід меню
        std::cout << "\nMenu:\n";
        std::cout << "1. Sort by flight number\n";
        std::cout << "2. Sort by departure days\n";
        std::cout << "3. Search by destination\n";
        std::cout << "4. Display all flights\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;


        if (choice == 1) {
            // Сортування за номерами рейсів
            vector<Aeroflot> sorted = sortById(aeroflots);
            displayAllFlights(sorted);
            
        }
        else if (choice == 2) {
            // Сортування за днями вильоту
            int day;
            cout << "Enter number of day for sorting: ";
            cin >> day;
            vector<Aeroflot> sorted = sortByDepartureDays(aeroflots, day);
            displayAllFlights(sorted);
        }
        else if (choice == 3) {
            // Пошук за пунктом призначення
            string searchDestination;
            cout << "Enter destination to search: ";
            cin >> searchDestination;
            vector<Aeroflot> sorted = findByDestination(aeroflots, searchDestination);
            displayAllFlights(sorted);
            
        }
        else if (choice == 4) {
            // Виведення всіх рейсів
            displayAllFlights(aeroflots);
        }
        else if (choice == 0) {
        cout << "Exiting...\n";
        break;}

        else{
            std::cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 0);


    return 0;
}

