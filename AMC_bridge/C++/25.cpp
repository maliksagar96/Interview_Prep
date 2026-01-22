
/*

26. What will happen if the exception will be thrown within a constructor?
    The object is not created and the no destructor is called.
    
*/
#include <iostream>
#include <stdexcept>  // for std::invalid_argument
#include <vector>

using namespace std;

struct Printer {
 
    Printer(int paper):paper(paper) {}

    int paper;

    void useprinter(std::string print) {
        if(paper <= 0) 
            throw "No more paper left in the printer";

        if(print.size() <= 5) 
            throw 101;

        cout<<print<<endl;
        paper--;
    }
};

int main() {
 
    Printer hpPrinter(3);

    try {
        hpPrinter.useprinter("Hi My name is ");
        hpPrinter.useprinter("My");
        hpPrinter.useprinter("Name");
        hpPrinter.useprinter("is");
        hpPrinter.useprinter("sagar");
    }
 
    catch(const char *txtException) {
        cout<<"Error: "<<txtException<<endl;
    }

    catch(const int errorCode) {
        cout<<"Errorcode = "<<errorCode<<endl;
    }

    catch(...) {
        cout<<"Error in printing.\n";
    }

    return 0;
}