#include <iostream>
#include <string>
#include <vector>
#include "WordSearch.h"



int targetChar = 5;
int attempts = 6;
bool gamerunning = true;


// SPLIT UP WORDS INTO EACH OF IT'S CHARS
std::vector<std::string> splitword(std::string wordtosplit) 
{
    std::vector<std::string> splittedword(targetChar);
    // reminder to self: you need to reserve space inside of a vector like this or else you will get weird runtime errors that are annoying to debug.

    for(int i = 0; i < targetChar; i++)
    {
        
        splittedword[i] = wordtosplit.substr(i, 1);
        
    }

    return splittedword;
}


// OUTPUT THE SCORE OF THE GAME!!!!!!
void output(std::vector<std::string> outputword, std::vector<int> outputscore)
{
    for(int i = 0; i < targetChar; i++) 
    {
        std::cout << " | " << outputword[i];
    }
    std::cout << " | " << "   Attempts remaining: " << attempts << "\n";
    
    for(int i = 0; i < targetChar; i++) 
    {
        std::cout << " | ";
        
        switch(outputscore[i]) 
        {
        case 1:
            std::cout << "✓";
            break;
        case 2:
            std::cout << "~";
            break;
        case 0:
            std::cout << "✗";
        }
    }
    std:: cout << " | \n";

}


// SCORE HOW SIMILAR WORDS ARE!!!!
std::vector<int> comparewords(std::vector<std::string> word1, std::vector<std::string> word2)
{
    std::vector<int> compare_score(targetChar, 0);
    for(int i = 0; i < targetChar; i++) 
    {

        if(word1[i] == word2[i])
        {
            compare_score[i] = 1;
            
        }

        else 
        {
            for(int J = 0; J <targetChar; J++) 
            {
            if(word1[i] == word2[J])
            {
                compare_score[i] = 2;
            }
            }
        }
        
    }
    

    return compare_score;
}


// TAKE IN USER INPUT!!!??!!!
std::string userInput() 
{
    bool validword = false;
    std::string input = "0";
    int numOfinputs = 0;
    while (input.length() != targetChar || validword == false) 
    {
        std::cout << "Enter a valid " << targetChar << " letter word\n";
        std::getline(std::cin, input);
        numOfinputs++;
        
        validword = wordf::checkifword(input);
    }
    
    for(int i = 0; i < numOfinputs*2; i++) 
    {
        std::cout << "\033[A"; // goes to last line, note to self: make sure it works the same on windows
        std::cout << "\033[K"; // will delete last line
    }


    


    return input;
}


int main () 
{



while (gamerunning == true) 
{
    

    std::string secretword = wordf::word_selector();
    
    while(attempts != 0)
    {
        
        std::string userword = userInput();
        std::vector<std::string> userword_split = splitword(userword);
        std::vector<std::string> secretword_split = splitword(secretword);
        std::vector<int> userscore = comparewords(userword_split, secretword_split);
        attempts--;
        output(userword_split, userscore);

    
    }
    std::cout << "the word was " << secretword << "\n";
    attempts = 6;
    

}
    return 0;
}