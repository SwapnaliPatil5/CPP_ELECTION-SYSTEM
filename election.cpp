#include <iostream>
#include <vector>
#include <string>

// Base class Party
class Party {
protected:
    int votes;

public:
    Party() : votes(0) {}

    // Virtual method to display votes
    virtual void displayVotes() const {
        std::cout << "Votes: " << votes;
    }

    // Overload += operator to add votes
    void operator+=(int additionalVotes) {
        votes += additionalVotes;
    }
};

// Derived classes NCP, BJP, Congress inherit from Party
class NCP : public Party {
public:
    void displayVotes() const override {
        std::cout << "NCP: " << votes << std::endl;
    }
};

class BJP : public Party {
public:
    void displayVotes() const override {
        std::cout << "BJP: " << votes << std::endl;
    }
};

class Congress : public Party {
public:
    void displayVotes() const override {
        std::cout << "Congress: " << votes << std::endl;
    }
};

// Class Election
class Election {
private:
    std::vector<Party*> parties;

public:
    Election() {
        // Create instances of each party and store in the vector
        parties.push_back(new NCP());
        parties.push_back(new BJP());
        parties.push_back(new Congress());
    }

    ~Election() {
        // Free memory allocated for party instances
        for (auto party : parties) {
            delete party;
        }
    }

    // Method to cast vote to a specific party
    void castVote(char partyCode) {
        switch (partyCode) {
            case 'N':
                (*parties[0]) += 1; // Add vote to NCP
                break;
            case 'B':
                (*parties[1]) += 1; // Add vote to BJP
                break;
            case 'C':
                (*parties[2]) += 1; // Add vote to Congress
                break;
            default:
                std::cerr << "Invalid party code" << std::endl;
        }
    }

    // Method to display results
    void displayResults() const {
        for (auto party : parties) {
            party->displayVotes();
        }
    }
};

int main() {
    int n;
    std::string votes;
    
    // Input number of votes
    std::cout<<"Number of votes : ";
    std::cin >> n;

    // Input votes as string
    std::cout<<"votes : ";
    std::cin >> votes;

    // Create Election instance
    Election election;

    // Cast votes based on input
    for (char vote : votes) {
        election.castVote(vote);
    }

    // Display results
    election.displayResults();

    return 0;
}
