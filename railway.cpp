#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Train {
protected:
    int trainNumber;
    string trainName;
    int totalSeats;
    string startPlace;
    string destinationPlace;
    int ticketprice;

public:
    Train(int number, const string& name, int seats, const string& start, const string& destination)
        : trainNumber(number), trainName(name), totalSeats(seats), startPlace(start), destinationPlace(destination) {}

    void viewInformation() const {
    	
        cout << "\tTrain Number: " << trainNumber << endl;
        cout << "\tTrain Name: " << trainName << endl;
        cout << "\tTotal Seats: " << totalSeats << endl;
        cout << "\tStart Place: " << startPlace << endl;
        cout << "\tDestination Place: " << destinationPlace << endl;
        cout<< "\tticket price: " <<ticketprice <<endl;
    }

    void displayAvailableSeats() const {
        cout << "\tAvailable Seats: " << totalSeats << endl;
    }

    bookTicket(int numTickets) {
        if (numTickets <= totalSeats) {
            totalSeats -= numTickets;
            return true;
        } else {
            return false;
        }
    }

    void cancelTicket() {
        totalSeats++;
    }
};

class Passenger : public Train {
private:
    string name;
    string phoneNumber;
    int seatNumber;

public:
    Passenger(int number, const string& name, int seats, const string& start, const string& destination)
        : Train(number, name, seats, start, destination) {}

    void inputPassengerDetails(int ticketNumber) {
        cout << "Enter details for Passenger " << ticketNumber << ":" << endl;
        cout << "\tEnter your name: ";
        cin.ignore();
        getline(cin, name);
        cout << "\tEnter your phone number: ";
        cin >> phoneNumber;
        cout << "\tEnter seat number: ";
        cin >> seatNumber;
		
        cout << "\tEnter train number: ";
        cin >> trainNumber;
        if(trainNumber!=123){
        	cout<<"\ttrain not available\nttry again "<<endl;
        	cout<<"\t Enter train number: ";
        cin >> trainNumber;
		}
    }

    void bookTicket(int numTickets) {
        if (Train::bookTicket(numTickets)) {
            for (int i = 1; i <= numTickets; ++i) {
                inputPassengerDetails(i);
                cout << "\nTicket booked for " << name << " with seat number " << seatNumber << "." << endl;
            }
        } else {
            cout << "Sorry, not enough seats available." << endl;
        }
    }

    void cancelTicket() {
        Train::cancelTicket();
        cout << "Enter your phone number to cancel the ticket: ";
        string userPhoneNumber;
        cin >> userPhoneNumber;

        if (userPhoneNumber == phoneNumber) {
            cout << "Ticket cancelled successfully!" << endl;
        } else {
            cout << "Invalid phone number. Unable to cancel ticket." << endl;
        }
    }
};

int main() {
    Passenger passenger(123, "Express", 100, "islamabad", "karachi");
    int choice;
    cout<<"\n\t****RAILWAY MANAGEMENT SYSTEM********"<<endl;

    do {
    	
        cout << "\n[1] VIEW INFORMATION" << endl;
        cout << "[2] BOOK TICKET" << endl;
        cout << "[3] CANCEL TICKET" << endl;
        cout << "[4] DISPLAY AVAILABLE SEATS" << endl;
        cout << "[5] EXIT" << endl;
        cout << "ENTER YOUR CHOICE:" ;
        cin >> choice;

        switch (choice) {
            case 1:
                passenger.viewInformation();
                break;

            case 2: {
                int numTickets;
                cout << "Enter the number of tickets you want to buy: ";
                cin >> numTickets;

                passenger.bookTicket(numTickets);
                break;
            }

            case 3:
                passenger.cancelTicket();
                break;

            case 4:
                passenger.displayAvailableSeats();
                break;

            case 5:
                cout << "Exiting the program." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    } 
	while (choice != 5);

    return 0;
}
