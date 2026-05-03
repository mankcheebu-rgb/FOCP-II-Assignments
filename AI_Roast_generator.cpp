#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>  // for rand() and srand()
#include <ctime>    // for time()

using namespace std;

// Function to replace {name} in the template
string generateRoast(string roastTemplate, string name) {
    size_t pos = roastTemplate.find("{name}");
    
    // Replace all occurrences of {name}
    while (pos != string::npos) {
        roastTemplate.replace(pos, 6, name);
        pos = roastTemplate.find("{name}");
    }

    return roastTemplate;
}

int main() {
    string name;

    cout << "Enter your name: ";
    getline(cin, name);

    // Handle empty input (basic bug prevention)
    if (name.empty()) {
        cout << "Error: Name cannot be empty!" << endl;
        return 1;
    }

    // List of roast templates
    vector<string> roasts = {
        "{name} writes code so slow that even a turtle switched to Python.",
        "If procrastination were an Olympic sport, {name} would have gold medals already.",
        "{name}'s debugging style is just staring at the screen until the bug gives up.",
        "{name}'s code has more bugs than a jungle.",
        "{name} doesn't write bugs — they write surprise features.",
        "Even autocorrect refuses to fix {name}'s code.",
        "{name}'s WiFi is faster than their thinking speed.",
        "If laziness had a brand ambassador, it would be {name}.",
        "{name} doesn't debug code — they negotiate with bugs.",
        "{name}'s code runs so slowly that even dial-up internet feels fast."
    };

    // Seed random number generator (IMPORTANT for randomness)
    srand(time(0));

    // Generate random index
    int randomIndex = rand() % roasts.size();

    // Generate final roast
    string finalRoast = generateRoast(roasts[randomIndex], name);

   cout << "\n=== Roast Generator ===" << endl;
    cout << finalRoast << endl;

    return 0;
}