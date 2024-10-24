#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <algorithm>

using namespace std;

// Base class
class Animal {
protected:
    int id;
    string intakeDate;
    string intakeReason;
    string shelterCode;
    string animalName;
    string breedName;
    string speciesName;
    string animalAge;
    string gender;
    string movementDate;
    string typeOfMovement;
    string returnDate;
    string returnReason;
    string adoptionMonth;

public:
    Animal(int id, const string& intakeDate, const string& intakeReason,
           const string& shelterCode, const string& animalName, const string& breedName,
           const string& speciesName, const string& animalAge, const string& gender,
           const string& movementDate, const string& typeOfMovement, const string& returnDate,
           const string& returnReason, const string& adoptionMonth)
        : id(id), intakeDate(intakeDate), intakeReason(intakeReason), shelterCode(shelterCode),
          animalName(animalName), breedName(breedName), speciesName(speciesName),
          animalAge(animalAge), gender(gender), movementDate(movementDate),
          typeOfMovement(typeOfMovement), returnDate(returnDate), returnReason(returnReason),
          adoptionMonth(adoptionMonth) {}

    int getId() const {
        return id;
    }

    string getSpecies() const {
        return speciesName;
    }

    string getGender() const {
        return gender;
    }

    string getMovementDate() const {
        return movementDate;
    }

    string getReturnDate() const {
        return returnDate;
    }

    string getReturnReason() const {
        return returnReason;
    }

    string getAdoptionMonth() const {
        return adoptionMonth;
    }

    string getIntakeDate() const { return intakeDate; }
    string getIntakeReason() const { return intakeReason; }
    string getShelterCode() const { return shelterCode; }
    string getAnimalName() const { return animalName; }
    string getBreedName() const { return breedName; }
    string getAnimalAge() const { return animalAge; }
    string getTypeOfMovement() const { return typeOfMovement; }

    virtual void displayInfo() const {
        cout << "ID: " << id << ", Intake Date: " << intakeDate 
             << ", Reason: " << intakeReason << ", Shelter Code: " << shelterCode 
             << ", Animal Name: " << animalName << ", Breed: " << breedName 
             << ", Species: " << speciesName << ", Age: " << animalAge 
             << ", Gender: " << gender << ", Movement Date: " << movementDate 
             << ", Type of Movement: " << typeOfMovement 
             << ", Return Date: " << returnDate << ", Return Reason: " << returnReason 
             << ", Adoption Month: " << adoptionMonth << endl;
    }

    virtual ~Animal() {}
};

// Derived classes for Dog, Cat, Rabbit, Hamster, and Tortoise
class Dog : public Animal {
public:
    Dog(int id, const string& intakeDate, const string& intakeReason, const string& shelterCode,
        const string& animalName, const string& breedName, const string& animalAge,
        const string& gender, const string& movementDate, const string& typeOfMovement,
        const string& returnDate, const string& returnReason, const string& adoptionMonth)
        : Animal(id, intakeDate, intakeReason, shelterCode, animalName, breedName, "Dog", animalAge, gender, movementDate, typeOfMovement, returnDate, returnReason, adoptionMonth) {}
};

class Cat : public Animal {
public:
    Cat(int id, const string& intakeDate, const string& intakeReason, const string& shelterCode,
        const string& animalName, const string& breedName, const string& animalAge,
        const string& gender, const string& movementDate, const string& typeOfMovement,
        const string& returnDate, const string& returnReason, const string& adoptionMonth)
        : Animal(id, intakeDate, intakeReason, shelterCode, animalName, breedName, "Cat", animalAge, gender, movementDate, typeOfMovement, returnDate, returnReason, adoptionMonth) {}
};

class Rabbit : public Animal {
public:
    Rabbit(int id, const string& intakeDate, const string& intakeReason, const string& shelterCode,
           const string& animalName, const string& breedName, const string& animalAge,
           const string& gender, const string& movementDate, const string& typeOfMovement,
           const string& returnDate, const string& returnReason, const string& adoptionMonth)
        : Animal(id, intakeDate, intakeReason, shelterCode, animalName, breedName, "Rabbit", animalAge, gender, movementDate, typeOfMovement, returnDate, returnReason, adoptionMonth) {}
};

class Hamster : public Animal {
public:
    Hamster(int id, const string& intakeDate, const string& intakeReason, const string& shelterCode,
            const string& animalName, const string& breedName, const string& animalAge,
            const string& gender, const string& movementDate, const string& typeOfMovement,
            const string& returnDate, const string& returnReason, const string& adoptionMonth)
        : Animal(id, intakeDate, intakeReason, shelterCode, animalName, breedName, "Hamster", animalAge, gender, movementDate, typeOfMovement, returnDate, returnReason, adoptionMonth) {}
};

class Tortoise : public Animal {
public:
    Tortoise(int id, const string& intakeDate, const string& intakeReason, const string& shelterCode,
             const string& animalName, const string& breedName, const string& animalAge,
             const string& gender, const string& movementDate, const string& typeOfMovement,
             const string& returnDate, const string& returnReason, const string& adoptionMonth)
        : Animal(id, intakeDate, intakeReason, shelterCode, animalName, breedName, "Tortoise", animalAge, gender, movementDate, typeOfMovement, returnDate, returnReason, adoptionMonth) {}
};

// Function to read animals from the CSV file
void readAnimalsFromCSV(const string& filename, vector<Animal*>& shelterAnimals) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Failed to open the CSV file!" << endl;
        return;
    }

    string line;
    
    getline(file, line);
    while (getline(file, line)) {
        stringstream ss(line);
        string token;

        int id;
        string intakeDate, intakeReason, shelterCode, animalName, breedName, speciesName, animalAge, gender, movementDate, typeOfMovement, returnDate, returnReason, adoptionMonth;

        getline(ss, token, ',');
        if (token.empty()) continue; 
        id = stoi(token); 
        getline(ss, intakeDate, ',');
        getline(ss, intakeReason, ',');
        getline(ss, shelterCode, ',');
        getline(ss, animalName, ',');
        getline(ss, breedName, ',');
        getline(ss, speciesName, ',');
        getline(ss, animalAge, ',');
        getline(ss, gender, ',');
        getline(ss, movementDate, ',');
        getline(ss, typeOfMovement, ',');
        getline(ss, returnDate, ',');
        getline(ss, returnReason, ',');
        getline(ss, adoptionMonth, ','); 

        // Create Animal objects based on species
        if (speciesName == "Dog") {
            shelterAnimals.push_back(new Dog(id, intakeDate, intakeReason, shelterCode, animalName, breedName, animalAge, gender, movementDate, typeOfMovement, returnDate, returnReason, adoptionMonth));
        } else if (speciesName == "Cat") {
            shelterAnimals.push_back(new Cat(id, intakeDate, intakeReason, shelterCode, animalName, breedName, animalAge, gender, movementDate, typeOfMovement, returnDate, returnReason, adoptionMonth));
        } else if (speciesName == "Rabbit") {
            shelterAnimals.push_back(new Rabbit(id, intakeDate, intakeReason, shelterCode, animalName, breedName, animalAge, gender, movementDate, typeOfMovement, returnDate, returnReason, adoptionMonth));
        } else if (speciesName == "Hamster") {
            shelterAnimals.push_back(new Hamster(id, intakeDate, intakeReason, shelterCode, animalName, breedName, animalAge, gender, movementDate, typeOfMovement, returnDate, returnReason, adoptionMonth));
        } else if (speciesName == "Tortoise") {
            shelterAnimals.push_back(new Tortoise(id, intakeDate, intakeReason, shelterCode, animalName, breedName, animalAge, gender, movementDate, typeOfMovement, returnDate, returnReason, adoptionMonth));
        }
    }

    file.close();
}

void addAnimal(vector<Animal*>& shelterAnimals, const string& filename) {
    string idStr; 
    int id;
    string intakeDate, intakeReason, shelterCode, animalName, breedName, speciesName, animalAge, gender;
    string movementDate, typeOfMovement, returnDate, returnReason, adoptionMonth;

    // Input ID with validation
    while (true) {
        cout << "Enter animal ID: ";
        getline(cin, idStr);

        if (idStr.empty()) {
            cout << "Animal ID cannot be empty. Please enter a valid ID." << endl;
            continue;
        }

        try {
            id = stoi(idStr); 
            break; 
        } catch (const invalid_argument&) {
            cout << "Invalid ID. Please enter a numeric ID." << endl;
        } catch (const out_of_range&) {
            cout << "ID is out of range. Please enter a valid numeric ID." << endl;
        }
    }


    // Mandatory fields input with validation
    cout << "Enter intake date (YYYY-MM-DD): ";
    getline(cin, intakeDate);
    while (intakeDate.empty()) {
        cout << "Intake date cannot be empty. Please enter intake date (YYYY-MM-DD): ";
        getline(cin, intakeDate);
    }

    cout << "Enter intake reason: ";
    getline(cin, intakeReason);
    while (intakeReason.empty()) {
        cout << "Intake reason cannot be empty. Please enter intake reason: ";
        getline(cin, intakeReason);
    }

    cout << "Enter shelter code: ";
    getline(cin, shelterCode);
    while (shelterCode.empty()) {
        cout << "Shelter code cannot be empty. Please enter shelter code: ";
        getline(cin, shelterCode);
    }

    cout << "Enter animal name: ";
    getline(cin, animalName);
    while (animalName.empty()) {
        cout << "Animal name cannot be empty. Please enter animal name: ";
        getline(cin, animalName);
    }

    cout << "Enter breed name: ";
    getline(cin, breedName);
    while (breedName.empty()) {
        cout << "Breed name cannot be empty. Please enter breed name: ";
        getline(cin, breedName);
    }

    cout << "Enter species name (Dog, Cat, Rabbit, Hamster, Tortoise): ";
    getline(cin, speciesName);
    while (speciesName.empty() || (speciesName != "Dog" && speciesName != "Cat" && speciesName != "Rabbit" && speciesName != "Hamster" && speciesName != "Tortoise")) {
        cout << "Species name must be one of the following: Dog, Cat, Rabbit, Hamster, Tortoise. Please enter species name: ";
        getline(cin, speciesName);
    }

    cout << "Enter animal age: ";
    getline(cin, animalAge);
    while (animalAge.empty()) {
        cout << "Animal age cannot be empty. Please enter animal age: ";
        getline(cin, animalAge);
    }

    cout << "Enter gender: ";
    getline(cin, gender);
    while (gender.empty()) {
        cout << "Gender cannot be empty. Please enter gender: ";
        getline(cin, gender);
    }

   // Optional fields with "NA" handling
    cout << "Enter movement date (YYYY-MM-DD, leave empty if not applicable): ";
    getline(cin, movementDate);
    if (movementDate.empty()) movementDate = "NA";

    cout << "Enter type of movement (leave empty if not applicable): ";
    getline(cin, typeOfMovement);
    if (typeOfMovement.empty()) typeOfMovement = "NA";

    cout << "Enter return date (YYYY-MM-DD, leave empty if not applicable): ";
    getline(cin, returnDate);
    if (returnDate.empty()) returnDate = "NA";

    cout << "Enter return reason (leave empty if not applicable): ";
    getline(cin, returnReason);
    if (returnReason.empty()) returnReason = "NA";

    cout << "Enter adoption month (leave empty if not applicable): ";
    getline(cin, adoptionMonth);
    if (adoptionMonth.empty()) adoptionMonth = "NA";


    // Create the appropriate animal object
    Animal* newAnimal = nullptr;
    if (speciesName == "Dog") {
        newAnimal = new Dog(id, intakeDate, intakeReason, shelterCode, animalName, breedName, animalAge, gender, movementDate, typeOfMovement, returnDate, returnReason, adoptionMonth);
    } else if (speciesName == "Cat") {
        newAnimal = new Cat(id, intakeDate, intakeReason, shelterCode, animalName, breedName, animalAge, gender, movementDate, typeOfMovement, returnDate, returnReason, adoptionMonth);
    } else if (speciesName == "Rabbit") {
        newAnimal = new Rabbit(id, intakeDate, intakeReason, shelterCode, animalName, breedName, animalAge, gender, movementDate, typeOfMovement, returnDate, returnReason, adoptionMonth);
    } else if (speciesName == "Hamster") {
        newAnimal = new Hamster(id, intakeDate, intakeReason, shelterCode, animalName, breedName, animalAge, gender, movementDate, typeOfMovement, returnDate, returnReason, adoptionMonth);
    } else if (speciesName == "Tortoise") {
        newAnimal = new Tortoise(id, intakeDate, intakeReason, shelterCode, animalName, breedName, animalAge, gender, movementDate, typeOfMovement, returnDate, returnReason, adoptionMonth);
    }

    if (newAnimal) {
        shelterAnimals.push_back(newAnimal);
        ofstream file(filename, ios::app);
        file << id << "," << intakeDate << "," << intakeReason << "," << shelterCode << ","
             << animalName << "," << breedName << "," << speciesName << "," << animalAge << ","
             << gender << "," << movementDate << "," << typeOfMovement << ","
             << returnDate << "," << returnReason << "," << adoptionMonth << endl;
        file.close();
        cout << "Animal added successfully!" << endl;
    }
}

// Function to display all animals
void displayAllAnimals(const vector<Animal*>& shelterAnimals) {
    for (const auto& animal : shelterAnimals) {
        animal->displayInfo();
    }
}

// Function to find an animal by ID
void findAnimalByID(const vector<Animal*>& shelterAnimals, int id) {
    for (const auto& animal : shelterAnimals) {
        if (animal->getId() == id) {
            animal->displayInfo();
            return;
        }
    }
    cout << "Animal with ID " << id << " not found." << endl;
}

// Function to filter animals by species
void filterBySpecies(const vector<Animal*>& shelterAnimals, const string& species) {
    for (const auto& animal : shelterAnimals) {
        if (animal->getSpecies() == species) {
            animal->displayInfo();
        }
    }
}

// Function to count adoptions by month
void countAdoptionsByMonth(const vector<Animal*>& shelterAnimals, const string& month) {
    int count = 0;
    for (const auto& animal : shelterAnimals) {
        if (animal->getAdoptionMonth() == month) {
            count++;
        }
    }
    cout << "Number of adoptions in " << month << ": " << count << endl;
}

// Function to check if an animal was returned
void checkReturnedStatus(const vector<Animal*>& shelterAnimals, int id) {
    for (const auto& animal : shelterAnimals) {
        if (animal->getId() == id) {
            if (!animal->getReturnDate().empty()) {
                cout << "Animal with ID " << id << " was returned on " << animal->getReturnDate() 
                     << " for reason: " << animal->getReturnReason() << endl;
            } else {
                cout << "Animal with ID " << id << " has not been returned." << endl;
            }
            return;
        }
    }
    cout << "Animal with ID " << id << " not found." << endl;
}

// Function to remove an animal
void removeAnimal(vector<Animal*>& shelterAnimals, const string& filename, int id) {
    auto it = remove_if(shelterAnimals.begin(), shelterAnimals.end(),
                        [id](Animal* animal) { return animal->getId() == id; });
    if (it != shelterAnimals.end()) {
        delete *it; 
        shelterAnimals.erase(it, shelterAnimals.end());
        cout << "Animal with ID " << id << " has been removed." << endl;
        
        
        ofstream outFile(filename);
        outFile << "ID,Intake Date,Intake Reason,Shelter Code,Animal Name,Breed,Species,Age,Gender,Movement Date,Type of Movement,Return Date,Return Reason,Adoption Month\n"; // Header
        for (const auto& animal : shelterAnimals) {
            outFile << animal->getId() << "," << animal->getIntakeDate() << "," 
                    << animal->getIntakeReason() << "," << animal->getShelterCode() << "," 
                    << animal->getAnimalName() << "," << animal->getBreedName() << "," 
                    << animal->getSpecies() << "," << animal->getAnimalAge() << "," 
                    << animal->getGender() << "," << animal->getMovementDate() << "," 
                    << animal->getTypeOfMovement() << "," << animal->getReturnDate() << "," 
                    << animal->getReturnReason() << "," << animal->getAdoptionMonth() << endl;
        }
        outFile.close();
    } else {
        cout << "Animal with ID " << id << " not found." << endl;
    }
}

// Function to count the number of animals species-wise
void countAnimalsBySpecies(const vector<Animal*>& shelterAnimals) {
    unordered_map<string, int> speciesCount;

    for (const auto& animal : shelterAnimals) {
        speciesCount[animal->getSpecies()]++;
    }

    cout << "Number of animals species-wise:\n";
    for (const auto& entry : speciesCount) {
        cout << entry.first << ": " << entry.second << endl;
    }
}

// Main function
int main() {
    vector<Animal*> shelterAnimals;
    string filename = "C:/Users/kumar/OneDrive/Desktop/NewDataset.csv";

    readAnimalsFromCSV(filename, shelterAnimals);

    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Display all animals\n";
        cout << "2. Find animal by ID\n";
        cout << "3. Filter animals by species\n";
        cout << "4. Count adoptions by month\n";
        cout << "5. Check if animal was returned\n";
        cout << "6. Add a new animal\n";
        cout << "7. Remove an animal\n";
        cout << "8. Count animals species-wise\n"; 
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                displayAllAnimals(shelterAnimals);
                break;
            case 2: {
                int id;
                cout << "Enter animal ID: ";
                cin >> id;
                findAnimalByID(shelterAnimals, id);
                break;
            }
            case 3: {
                string species;
                cout << "Enter species to filter by: ";
                cin >> species;
                filterBySpecies(shelterAnimals, species);
                break;
            }
            case 4: {
                string month;
                cout << "Enter the month to count adoptions (e.g., January): ";
                cin >> month;
                countAdoptionsByMonth(shelterAnimals, month);
                break;
            }
            case 5: {
                int id;
                cout << "Enter animal ID: ";
                cin >> id;
                checkReturnedStatus(shelterAnimals, id);
                break;
            }
            case 6: {
                addAnimal(shelterAnimals, filename);
                break;
            }
            case 7: { 
                int id;
                cout << "Enter animal ID to remove: ";
                cin >> id;
                removeAnimal(shelterAnimals, filename, id);
                break;
            }
            case 8:                 
                countAnimalsBySpecies(shelterAnimals);
                break;
            case 0:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice, please try again." << endl;
                break;
        }
    } while (choice != 0);

    // Clean up dynamically allocated memory
    for (auto animal : shelterAnimals) {
        delete animal;
    }

    return 0;
}