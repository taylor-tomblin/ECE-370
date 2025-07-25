#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    int n = 10;
    float x = 100.56;

    std::cout << "Hello World!" << endl;

    std:: cout << "\n\nGoodbye!";

    std::cout << "\n\nn: " << n << "   x: " << x;

    string str;

    str = "hi there";

    n = str.length();

    cout << "\n\nn: " << n;

    // concatonate
    str = str + "!!";

    n = str.length();

    cout << "\n\nn: " << n;

    string s;

    s = str.replace(2, 1, "_");

    cout << "\n\nn: " << n;

    cout << "\n\nstr: " << str;
    cout << "\n\ns: " << s;

    string s1 = "base" + string(" ") + "ball";

    cout << "\n\ns1: " << s1;

    string myStr("Paul");    // calling the string constructor

    string poem[3];

    poem[0] = "To be or not to be";
    poem[1] = "That is the question";
    poem[2] = "Whether 'tis nobler...";    // to suffer the slings and arrows of life's misfortunes...

    for (int i = 0; i < 3; i++) {
        cout << "\npoem[" + to_string(i) + string("]: ") + poem[1];
    }

    int p = 508;

    string q = to_string(p);

    cout << "\n\nq: " << q;

    cout << "\n\nPlease guess an integer from 1 to 10: ";

    cin >> n;

    cout << "\n\nn: " << n;

    string fullName;

    cout << "\n\nPlease enter your full name:";

    // char temp;
    // cin >> temp;
    // cin.clear();

    fflush(stdin);

    getline(cin, fullName);

    cout << "\n\nfullName: " << fullName;

    string line;
    string fileName = "hamlet.txt";

    ifstream myfile(fileName.c_str());  //The constructor wants a
                                        //C-style string!
    if (myfile.is_open()==true)
    {
        while (getline(myfile, line))
        {
            cout << line << '\n';
        }
        myfile.close();
    }
    else cout << "\nError: Cannot open file: " << fileName;

    cout << "\n\n";

    return 0;
}
