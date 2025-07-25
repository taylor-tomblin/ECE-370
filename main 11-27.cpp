#include <iostream>

#include <vector>

using namespace std;

int main() {
    vector<int> x;

    for(int i = 0; i < 10; i++) {
        x.push_back(10 * i);
        // x[i] = 10 * i;    Do not use!!
    }

    cout << "\n\nx: ";

    for(int i = 0; i < 10; i++) {
        cout << x[i] << " ";
    }

    // vector<Circle> myCircles;

    int n = x[0];

    cout << "\n\nx[0]: " << n;

    n = x.at(1);

    cout << "\n\nx.at(1): " << n;

    vector<string> s;

    s.push_back("apple");
    s.push_back("pear");
    s.push_back("grape");
    s.push_back("orange");

    cout << "\n\ns: ";

    for(int i = 0; i < s.size(); i++) {
        cout << s[i] << " ";
    }

    cout << "\n\n" << endl;
    return 0;
}
