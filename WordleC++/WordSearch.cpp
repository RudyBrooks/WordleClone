#include <iostream>
#include <fstream>
#include <ctime>
#include "WordSearch.h"
int numOfvalidwords = 14855;



std::string wordf::word_selector() 
{
    srand(time(0));
    int randomNum = (rand() % 2315) + 1;
    std::fstream filein("txt_files/wordle-answers-alphabetical.txt");
    std::string randword;
    if(filein.is_open())
    {
        for(int i = 1; i <= randomNum; i++)
        {
            std::getline(filein, randword);
        }
    }
    else 
    {
        std::cout << "error while trying to find wordle answer txt file";
        exit(1);
    }
    filein.close();

    return randword;
}

bool wordf::checkifword(std::string wordtocheck)
{
    bool realword = false;
    std::string allowedguess;
    std::ifstream filein("txt_files/valid-wordle-words.txt");

    if(filein.is_open()) 
    {
        for(int i = 1; i <= numOfvalidwords; i++) 
        {
            std::getline(filein, allowedguess);
            if(allowedguess == wordtocheck)
            {
                realword = true;
                break;
            }
        }
        filein.close();
    }
    else 
    {
        std::cout << "error while opening valid wordle list";
        exit(0);
    }

    return realword;

}


