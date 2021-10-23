// FileConversion.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <regex>
using namespace std;

bool validCpp(string str);
bool validHTML(string str);
bool testOpen(string readPath, string writePath);
void readCppWriteHTML(string readPath, string writePath);

struct ExpertExceptionUse : public exception
{
public:
    const string what()
    {
        return "My own personal exception happened.";
    }
};


int main()
{
    string filepath;
    string newfilepath;
    std::cout << "Welcome to the C++ to HTML conversion program.\n";
    do
    {
        do
        {
            std::cout << "Please enter the full filename and path of the cpp file you wish to convert to HTML\nexample: C:/doc/thisfile.cpp\n";
            std::cin >> filepath;
        } while (!validCpp(filepath)); //loop til we get a valid cpp name/path

        do
        {
            std::cout << "Please enter the full filename and path of the new HTML file you wish to create\nexample: C:/doc/thatfile.html\n";
            std::cin >> newfilepath;
        } while (!validHTML(newfilepath)); //loop til valid html name/path

    } while (!testOpen(filepath, newfilepath)); //test opening the files without doing anything just in case something messed up, re-request on failure

    readCppWriteHTML(filepath, newfilepath); //if all the dowhiles pass, attempt to convert file

}   

bool validCpp(string str)
{
    
    if (!str.empty())
    {
        regex regexp("^([\\w]\\:\\/)([a-zA-Z0-9\\_\\-\\.\\/]+)(\\.cpp)$"); //https://www.regextester.com this took forever and i'm sure it still doesn't get everything
        if (regex_match(str, regexp))
        {
            return true;
        }
    }
    
    return false;
}

bool validHTML(string str)
{
    regex regexp("^([\\w]\\:\\/)([a-zA-Z0-9\\_\\-\\.\\/]+)(\\.html)$");
    if (!str.empty())
    {
        if (regex_match(str, regexp))
        {
            return true;
        }
    }
    return false;
}

bool testOpen(string readPath, string writePath)
{
    ifstream cppFile;
    ofstream HTMLFile;
    try
    {
        cppFile.open(readPath);
        
        if(cppFile.fail())
        {
            throw invalid_argument("Error loading cpp file, please check path and filename.");
        }
        else
        {
            cppFile.close();
        }
    }
    catch (const invalid_argument& e)
    {
        cout << e.what();
        return false;
    }

    try
    {
        HTMLFile.open(writePath);

        if (HTMLFile.fail())
        {
            throw ExpertExceptionUse();
        }
        else
        {
            HTMLFile.close();
            return true;
        }

    }
    catch (ExpertExceptionUse& e)
    {
        cout << e.what() << endl;
        return false;
    }
    catch (...)
    {
        cout << "Default exception?" << endl;
        return false;
    }
}

void readCppWriteHTML(string readPath, string writePath)
{
    string line;
    ifstream cppFile;
    ofstream HTMLFile;
    try
    {
        cppFile.open(readPath);

        if (cppFile.is_open()) //if successfully opened
        {
            HTMLFile.open(writePath);
            if (HTMLFile.is_open())
            {
                HTMLFile << "<PRE>" << endl;
                while (!cppFile.eof()) //loop to end of cpp file
                {
                    getline(cppFile, line);
                    for (char i : line)
                    {
                        string lineChar = string(1, i);
                        if (lineChar == "<")
                        {
                            HTMLFile << "&lt;";
                        }
                        else if (lineChar == ">")
                        {
                            HTMLFile << "&gt;";
                        }
                        else
                        {
                            HTMLFile << lineChar;
                        }
                    }
                    HTMLFile << endl; //I wasn't sure if the <br> is necessary, but I'm going off this line in the assignment
                                                //"You can test your output file by opening it with a web browser. The contents should appear identical to the original source code
                }
                HTMLFile << "</PRE>";
                HTMLFile.close(); //make sure to close file
            }
            else
            {
                throw runtime_error("file failed to open");
            }
            cppFile.close(); //make sure to close file
        }
        else
        {
            throw runtime_error("file failed to open");
        }
    }
    catch (runtime_error& e)
    {
        cout << e.what();
    }
    
}