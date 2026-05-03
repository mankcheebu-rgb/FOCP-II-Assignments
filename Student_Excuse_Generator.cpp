#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    string name;

    // Take user input
    cout << "Enter student name: ";
    getline(cin, name);

    // Store excuse templates
    vector<string> excuses = {
        "{name} couldn't finish the assignment because the laptop installed updates for 6 hours.",
        "{name} was about to complete the homework when the Wi-Fi disappeared.",
        "{name} tried finishing the assignment, but the keyboard stopped working.",
        "{name} couldn't submit the homework because the file got deleted mysteriously.",
        "{name} was working hard, but the power went out suddenly.",
        "{name} couldn't finish because the system froze unexpectedly.",
        "{name} tried to complete the assignment, but the internet was too slow.",
        "{name} lost the homework when the computer crashed.",
        "{name} accidentally saved the file in the wrong format.",
        "{name} was about to submit when the website stopped responding."
    };

    // Seed random number generator
    srand(time(0));

    // Generate random index
    int randomIndex = rand() % excuses.size();

    string excuse = excuses[randomIndex];

    // Replace {name} with actual input
    size_t pos = excuse.find("{name}");
    while (pos != string::npos) {
        excuse.replace(pos, 6, name);
        pos = excuse.find("{name}");
    }

    // Display result
    cout << "\nGenerated Excuse:\n";
    cout << excuse << endl;

    return 0;
}