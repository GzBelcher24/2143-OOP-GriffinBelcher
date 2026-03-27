#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Args {
private:
    int numArgs;
    char** args;
  const  vector<string> valid = {"--grayscale","--brightness","--rotate","--blur","--flipH","--flipV","--g","--b","--l","--h","--v","--r"};
    bool needsParam = false;
public:
    //constructors
    Args();
    Args(int argc, char** argv) {
        numArgs = argc;
        args = argv;
        //open files
        ifstream fin;
        fin.open(args[1]);
        ofstream out;
        out.open(args[2]);
    };
    //checks if an argument is valid
    bool argTester(string arg) {
        for (auto& item : valid) {
            if (arg == item) {
                return true;
            }
        }
        return false;
    }
    bool fileTester(string fileName) {
        //checks if there are enough arguments(at least 2, one input file, one output file)
        if (numArgs < 2) {
            cout << "Error: need a filename!" << endl;
            cout << "Usage: ./args <filename>" << endl;
            exit(1);
        }
        //string fileName = file;
        int length = fileName.length();
        if (fileName.ends_with(".png")|| fileName.ends_with(".jpg")|| fileName.ends_with(".jpeg")|| fileName.ends_with(".gif")) {
            return true;
        }
        else {
            cout << "file is not a valid format"<<endl;
                return false;
                exit(1);
        }
    }

    void parse() {
        //checks if the two files are valid types
         fileTester(args[1]);
         fileTester(args[2]);
        
        // actual parsing, takes each argument, and says what will happen
        cout << "passed: " << numArgs << " arguments" << endl;
        //dosent check the first 3 args, because they are the file name, and the input and output files 
        for (int i = 3; i < numArgs; i++) {
            if (needsParam == true) {
                needsParam = false;
            }
            else {
                if (argTester(args[i])) {
                    //code for if the argument is valid
                    //checks each valid arg, and outputs a message based on what would happen long and short forms are checked at the same time
                    if (args[i] == valid[0] || args[i] == valid[6]) {
                        cout << "image has been turned grayscale!" << endl;
                    }
                    else if (args[i] == valid[3] || args[i] == valid[7]) {
                        cout << "image has been blured!" << endl;
                    }
                    else if (args[i] == valid[4] || args[i] == valid[9]) {
                        cout << "image has been fliped horizontaly!" << endl;
                    }
                    else if (args[i] == valid[5] || args[i] == valid[10]) {
                        cout << "image has been fliped verticaly!" << endl;
                    }
                    else if (args[i] == valid[1] || args[i] == valid[7]) {
                      
                        needsParam = true;
                        cout << "brigthness has increaced by " << args[i + 1] << endl;

                    }
                    else if (args[i] == valid[2] || args[i] == valid[11]) {
                        
                        needsParam = true;
                        cout << "image has been rotated by " << args[i + 1] << " degrees!" << endl;

                    }
                    else {

                        cout << "argumet has not been added yet" << endl;
                    }
                }
                else {
                    cout << "ERROR: argument " << args[i] << " is not valid" << endl;
                    exit(1);
                }
            }
        }
    }
};

int main(int argc, char** argv) {
    Args parser(argc,argv);
    parser.parse();
}