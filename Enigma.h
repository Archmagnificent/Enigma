#pragma once
#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <stdlib.h>
#include <map>

#include "InputValidation.h"

namespace AutoMap //Code I wrote because making a map with multiple values by hand is too tiresome
{
//namespace "Automap" starts here   :
    template<typename T, typename D>
    auto makeMap(const std::vector<T> &key, const std::vector<D> &value)
    {
        std::map<T, D> autoMap{};
        for (auto i{0}; i < key.size(); i++) {
            autoMap[key[i]] = value[i];
        }
        return autoMap;
    }
//Namespace "Automap" ends here     :
}




namespace Enigma 
{
//Namespace "Enigma: starts here :
    using letters                   = std::vector<char>;

    const letters alphabet          { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };


    //Rotor patterns (as found on https://en.wikipedia.org/wiki/Enigma_rotor_details) :

    //Commercial Enigma A, B :
    const letters pattern_IC        { 'D', 'M', 'T', 'W', 'S', 'I', 'L', 'R', 'U', 'Y', 'Q', 'N', 'K', 'F', 'E', 'J', 'C', 'A', 'Z', 'B', 'P', 'G', 'X', 'O', 'H', 'V' };
    const letters pattern_IIC       { 'H', 'Q', 'Z', 'G', 'P', 'J', 'T', 'M', 'O', 'B', 'L', 'N', 'C', 'I', 'F', 'D', 'Y', 'A', 'W', 'V', 'E', 'U', 'S', 'R', 'K', 'X' };
    const letters pattern_IIIC      { 'U', 'Q', 'N', 'T', 'L', 'S', 'Z', 'F', 'M', 'R', 'E', 'H', 'D', 'P', 'X', 'K', 'I', 'B', 'V', 'Y', 'G', 'J', 'C', 'W', 'O', 'A' };

    //German Railway (Rocket) :
    const letters pattern_I         { 'J', 'G', 'D', 'Q', 'O', 'X', 'U', 'S', 'C', 'A', 'M', 'I', 'F', 'R', 'V', 'T', 'P', 'N', 'E', 'W', 'K', 'B', 'L', 'Z', 'Y', 'H' };
    const letters pattern_II        { 'N', 'T', 'Z', 'P', 'S', 'F', 'B', 'O', 'K', 'M', 'W', 'R', 'C', 'J', 'D', 'I', 'V', 'L', 'A', 'E', 'Y', 'U', 'X', 'H', 'G', 'Q' };
    const letters pattern_III       { 'J', 'V', 'I', 'U', 'B', 'H', 'T', 'C', 'D', 'Y', 'A', 'K', 'E', 'Q', 'Z', 'P', 'O', 'S', 'G', 'X', 'N', 'R', 'M', 'W', 'F', 'L' };

    const letters pattern_UKW       { 'Q', 'Y', 'H', 'O', 'G', 'N', 'E', 'C', 'V', 'P', 'U', 'Z', 'T', 'F', 'D', 'J', 'A', 'X', 'W', 'M', 'K', 'I', 'S', 'R', 'B', 'L' };
    const letters pattern_ETW       { 'Q', 'W', 'E', 'R', 'T', 'Z', 'U', 'I', 'O', 'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'P', 'Y', 'X', 'C', 'V', 'B', 'N', 'M', 'L' };

    //Swiss K :
    const letters pattern_I_K       { 'P', 'E', 'Z', 'U', 'O', 'H', 'X', 'S', 'C', 'V', 'F', 'M', 'T', 'B', 'G', 'L', 'R', 'I', 'N', 'Q', 'J', 'W', 'A', 'Y', 'D', 'K' };
    const letters pattern_II_K      { 'Z', 'O', 'U', 'E', 'S', 'Y', 'D', 'K', 'F', 'W', 'P', 'C', 'I', 'Q', 'X', 'H', 'M', 'V', 'B', 'L', 'G', 'N', 'J', 'R', 'A', 'T' };
    const letters pattern_III_K     { 'E', 'H', 'R', 'V', 'X', 'G', 'A', 'O', 'B', 'Q', 'U', 'S', 'I', 'M', 'Z', 'F', 'L', 'Y', 'N', 'W', 'K', 'T', 'P', 'D', 'J', 'C' };

    const letters pattern_UKW_K     { 'I', 'M', 'E', 'T', 'C', 'G', 'F', 'R', 'A', 'Y', 'S', 'Q', 'B', 'Z', 'X', 'W', 'L', 'H', 'K', 'D', 'V', 'U', 'P', 'O', 'J', 'N' };
    const letters pattern_ETW_K     { 'Q', 'W', 'E', 'R', 'T', 'Z', 'U', 'I', 'O', 'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'P', 'Y', 'X', 'C', 'V', 'B', 'N', 'M', 'L' };


    //I will probably not add more as I am lazy

    using connections       = std::map<char, char>;

    const connections IC    = AutoMap::makeMap(alphabet, pattern_IC);
    const connections IIC   = AutoMap::makeMap(alphabet, pattern_IIC);
    const connections IIIC  = AutoMap::makeMap(alphabet, pattern_IIIC);

    const connections I     = AutoMap::makeMap(alphabet, pattern_I);;
    const connections II    = AutoMap::makeMap(alphabet, pattern_II); ;
    const connections III   = AutoMap::makeMap(alphabet, pattern_III);;

    const connections UKW   = AutoMap::makeMap(alphabet, pattern_UKW);;
    const connections ETW   = AutoMap::makeMap(alphabet, pattern_ETW); ;

    const connections I_K   = AutoMap::makeMap(alphabet, pattern_I_K);;
    const connections II_K  = AutoMap::makeMap(alphabet, pattern_II_K);;
    const connections III_K = AutoMap::makeMap(alphabet, pattern_III_K);;

    const connections UKW_K = AutoMap::makeMap(alphabet, pattern_UKW_K);;
    const connections ETW_K = AutoMap::makeMap(alphabet, pattern_ETW_K);;

    //Creatign a map to store the names of specific rotor patterns :
    std::map<connections, std::string_view> patternNames
    {
        //Rotor pattern names       :
        {IC, "IC"}, {IIC, "IIC"}, {IIIC, "IIIC"}, 
        {I, "I"}, {II, "II"}, {III, "III"}, 
        {I_K, "I_K"}, {II_K, "II_K"}, {III_K, "III_K"},
        //Reflector pattern names   :
        {UKW, "UKW"}, {ETW, "ETW"},
    };

    using plug  = std::pair<char, char>;

    using plugboard = std::vector<plug>;


    //Rotor class which mimics the behaviour of real life Enigma machine rotors
    class Rotor
    {
    private:
        connections m_rotorConnections      {};                         //map mapping alphabet letters to the rotor pattern
        short m_rotorPosition               {};                         //position to which the rotor was set 
        short m_rotordisplayPosition        { m_rotorPosition + 1 };    //position for display only
        short m_rotorNotch                  {};                         //position at which the next rotor in line will turn
    public:
        Rotor(const connections& rotorConnections, short rotorPosition, short rotorNotch)
            : m_rotorConnections{ rotorConnections }, m_rotorPosition{ rotorPosition }, m_rotorNotch{ rotorNotch }
        {

        }
        //Notch is irrelevant for last rotor, therefore I'm making a new constructor 
        //so I don't have to type a meaningless value when creating the last rotor object
        Rotor(const connections& rotorConnections, short rotorPosition)
            : m_rotorConnections{ rotorConnections }, m_rotorPosition{ rotorPosition }
        {

        }
        ~Rotor()
        {

        }
        Rotor& operator++();
        Rotor& operator--();
    public:
        //Sets the displayed position of the rotor 
        void setDisplay()
        {
            m_rotordisplayPosition = m_rotorPosition + 1;
        }
        //Encodes the letter recieved from the plugboard
        char encodeLetterForward(const char c)
        {
            char input{ c };


            for (int i{ 0 }; i < m_rotorPosition; i++)
            {
                if(input == 'Z')
                {
                    input = 'A';
                }
                else { input++; }
            }

            char output{ m_rotorConnections[input] };

            for(int i{ 0 }; i < m_rotorPosition; i++)
            {
                if(output == 'A')
                {
                    output = 'Z';
                }
                else { output--; }
            }
            return output;
        }
        //Encodes the letter received from the reflector
        char encodeLetterBackward(const char c)
        {
            char input{ c };

            for (int i{ 0 }; i < m_rotorPosition; i++)
            {
                if (input == 'Z')
                {
                    input = 'A';
                }
                else { input++; }
            }
            char index{'A'};

            char output{};
            for (int i{0}; i < alphabet.size(); i++)
            {
                if (m_rotorConnections[index] == input)
                {
                    output = index;
                    break;
                }
                else { index++; };
            }

            for (int i{0}; i < m_rotorPosition; i++)
            {
                if(output == 'A')
                {
                    output = 'Z';
                }
                else { output--; }
            }
            return output;
        }

    public  :
        //Getters
        short getRotorPosition()            { return m_rotorPosition; }
        short getRotorDiaplay()             { return m_rotordisplayPosition; }
        short getRotorNotch()               { return m_rotorNotch; }
        std::string_view getPatternName()   { return patternNames[m_rotorConnections]; }
        //Setters
        void setRotorPattern(const connections& pattern) { m_rotorConnections = pattern; }
        void setRotorPosition(const short newPosition) 
        {
            if (newPosition >= 1 && newPosition <= 26)
            {
                m_rotorPosition = newPosition - 1;
                m_rotordisplayPosition = m_rotorPosition + 1;
            }
            else { std::cout << "Error : incorrect rotor position"; }
        }
        void setRotorNotch(const short newNotch) { m_rotorNotch = newNotch; }
        //Debug functions :
        void resetRotor()
        {
            m_rotordisplayPosition = 1;
            m_rotorPosition = 0;
        };

    }; 

    //Rotor class non-member operator functions
    Rotor& Rotor::operator++() 
    {
        if(m_rotorPosition < 26)
        {
            m_rotorPosition++;
            setDisplay();
        } else if (m_rotorPosition == 26)
        {
            m_rotorPosition = 0;
            setDisplay();
        }
        return *this;
    }
    Rotor& Rotor::operator--()
    {
        if (m_rotorPosition > 0)
        {
            m_rotorPosition--;
            setDisplay();
        }
        else if (m_rotorPosition == 0)
        {
            m_rotorPosition = 25;
            setDisplay();
        }
        return *this;
    }

    //Reflector class
    class Reflector 
    {
    private :
        connections m_reflectorConnections  {};
    public  :
        Reflector(const connections& reflectorConnections) : m_reflectorConnections{reflectorConnections}{}
        ~Reflector(){}
    public :
        char reflectLetter(const char c)
        {
            return m_reflectorConnections[c];
        }
        void setReflectorPattern(const connections& pattern) { m_reflectorConnections = pattern; }
        std::string_view getPatternName() { return patternNames[m_reflectorConnections]; }
    };

    //Plugboard class
    class Plugboard 
    {
    private :
        plugboard m_plugboard{ {'A', 'U'}, { 'C', 'D' }, { 'H', 'G' } }; 
    public  :
        Plugboard() 
        {
        }
        ~Plugboard() 
        {
        }
    public  :
        void add(const plug& plug)
        {
            bool found{false};

            if (!m_plugboard.empty()) 
            {
                for (auto x : m_plugboard)
                {
                    if ((x.first == plug.first) || (x.second == plug.second) || (x.first == plug.second) || (x.second == plug.first))
                    {
                        found = true;
                    }
                }
            }
            if(found)
            {
                std::cout << "Error : one of the letters is already plugged to the plugboard\n";
            }
            else { m_plugboard.push_back(plug); }
        }
        void remove(const char first) 
        {
            if(!m_plugboard.empty())
            {
                for (int i{ 0 }; i < m_plugboard.size(); i++)
                {
                    if (m_plugboard[i].first == first)
                    {
                        m_plugboard.erase(m_plugboard.begin() + i);
                        m_plugboard.shrink_to_fit();
                    }
                }
            }
            else
            {
                std::cout << "Error : no elements to remove from the plugboard\n";
            }

        }


        char check(const char c)
        {
            if(!m_plugboard.empty())
            {
                for(const auto x : m_plugboard)
                {
                    if(c == x.first)
                    {
                        return x.second;
                    }
                    else if(c == x.second)
                    {
                        return x.first;
                    }
                    else { return c; }
                }
            }
            else { return c; }
        }

        void print()
        {
            if (!m_plugboard.empty()) 
            {
                for (auto x : m_plugboard)
                {
                    std::cout << "(" << x.first << ", " << x.second << ") ";
                }
                std::cout << '\n';
            }
            else { std::cout << "{---NONE---]\n"; }
        }
        void clear()
        {
            m_plugboard.clear();
            m_plugboard.shrink_to_fit();
        }
    public  :
        plugboard getPlugboard(){}
        plug getPlug(const char first){}
    };


    //creating objects of class rotor       :
    Rotor right         {I, 0, 3};
    Rotor middle        {II, 0, 5};
    Rotor left          {III, 0};

    //Creating object of class reflector    :
    Reflector reflector { UKW };

    //Creating object of class plugboard    :
    Plugboard Board     {};


    //Function used to get the settings required to decrypt the message
    void getSettings() 
    {
        std::cout << '\n';
        std::cout << "Plugboard : "; Board.print();
        std::cout << "Right     : Pattern =  " << right.getPatternName() << "| Position = " << right.getRotorDiaplay() << "| Notch = " << right.getRotorNotch() << '\n';
        std::cout << "Middle    : Pattern =  " << middle.getPatternName() << "| Position = " << middle.getRotorDiaplay() << "| Notch = " << middle.getRotorNotch() << '\n';
        std::cout << "Left      : Pattern =  " << left.getPatternName() << "| Position = " << left.getRotorDiaplay() << '\n';
        std::cout << "Reflector : Pattern =  " << reflector.getPatternName() << '\n' << '\n';
    }

    //Function used for the encryption of a single letter
    char encryptLetter(const char c)
    {

        //Check whether the letter should change on the plugboard
        
        char input{Board.check(c)};

        //Turn the right rotor to the next position
        ++right;
        //Then check if its new position is the same as its notch
        //If it is, turn the next rotor to its next position
        if (right.getRotorPosition() == right.getRotorNotch())
        {
            ++middle;
        }
        //Do the same check for the next rotor in line
        if (middle.getRotorPosition() == middle.getRotorNotch())
        {
            ++left;
        }

        //Starting from the right we pass a letter from plugboard to the rotor
        // then to through another rotor in line until we reach reflector 
        input = right.encodeLetterForward(input);
        input = middle.encodeLetterForward(input);
        input = left.encodeLetterForward(input);

        //Get the letter from the reflector
        input = reflector.reflectLetter(input);

        //Then come back, starting form the left rotor
        input = left.encodeLetterBackward(input);
        input = middle.encodeLetterBackward(input);
        input = right.encodeLetterBackward(input);

        //return the letter to the plugboard 

        return Board.check(input);
    }

    //Main function used for encryption
    std::string encrypt(const std::string_view &input)
    {
        getSettings();
        //Create a string variable that will store the encrypted phrase
        std::string output{};
        for(char c : input)
        {
            //If the value of the input string is an empty space, add it to the output
            // without encryption
            if (c == ' ')
            {
                output.push_back(c);
            }
            //If not, send the letter for encryption
            else { output.push_back(encryptLetter(c)); }
        }
        return output;
    }

    //Functions for navigating the enigma menus

    void setRotorPosition();

    void userInteface_Enigma()
    {
        std::cout << " _____________________________________\n";
        std::cout << "| [Q] [W] [E] [R] [T] [Z] [U] [I] [O] |\n";
        std::cout << "|   [A] [S] [D] [F] [G] [H] [J] [K]   |\n";
        std::cout << "| [P] [Y] [X] [C] [V] [B] [N] [M] [L] |\n";
        std::cout << " -------------------------------------\n";
        std::cout << '\n';
        std::cout << '\n';
        std::cout << "     |" << left.getRotorDiaplay() << "| " << middle.getRotorDiaplay() << "| " << right.getRotorDiaplay() << "| \n";
        std::cout << '\n';
        std::cout << "Plugboard : \n";
        Board.print();
        std::cout << '\n';
        std::cout << '\n';
        std::cout << "Type the action you'd like to perform : ";
    }

    void setPlugboard()
    {
        while (true)
        {
            system("CLS");
            std::cout << "Plugboard : \n";
            Board.print();
            std::cout << "Type the action you'd like to perform : ";
            std::string input{ InputValidation::getInput_String("Add new connection -> 'add'  Remove connection -> 'remove' Quit -> 'end'") };
            if (input == "add")
            {
                char x{ InputValidation::getInput_Engima_Char("Enter the first letter of the connection you wish to create :") };
                char y{ InputValidation::getInput_Engima_Char("Enter the second letter of the connection you wish to create :") };
                plug temp{ std::make_pair(x, y) };
                Board.add(temp);
            }
            else if (input == "remove")
            {
                char x{ InputValidation::getInput_Engima_Char("Enter the first letter of the connection you wish to remove :") };
                Board.remove(x);
            }
            else if (input == "end")
            {
                break;
            }
        }
    }

    void setRotorPosition();
    void setRotorNotch();
    void setRotorPattern();

    void setRotors()
    {
        while(true)
        {
            system("CLS");
            std::cout << "Left position : " << left.getRotorDiaplay() << " Middle position : " << middle.getRotorDiaplay() << " Right position : " << right.getRotorDiaplay() << '\n';
            std::cout << "Middle notch : " << middle.getRotorNotch() << " Right notch : " << right.getRotorNotch() << '\n';
            std::cout << "Left pattern : " << left.getPatternName() << " Middle pattern : " << middle.getPatternName() << " Right pattern : " << right.getPatternName() 
                <<" Reflector pattern : " << reflector.getPatternName() << '\n';
            std::cout << '\n';
            std::string input{ InputValidation::getInput_String("Change Rotor Position -> 'position'  Change Rotor Notch -> 'notch'  Change Rotor Pattern -> 'pattern'  Quit -> 'end'") };
            if(input == "position")
            {
                setRotorPosition();
            } 
            else if(input == "notch")
            {
                setRotorNotch();
            }
            else if(input == "pattern")
            {
                setRotorPattern();
            }
            else if(input == "end")
            {
                break;
            }
        }
    }
    void setRotorPosition()
    {
        while(true)
        {
            system("CLS");
            std::cout << "Choose rotor, you wish to change the position of\n";
            std::string input{ InputValidation::getInput_String("Left -> 'left'  Middle -> 'middle'  Right -> 'right'") };
            if (input == "left")
            {
                std::cout << "Current Rotor Posittion : " << left.getRotorDiaplay() << '\n';
                left.setRotorPosition(InputValidation::getInput_Enigma_Int("enter number between 1 and 26 : "));
                break;
            }
            else if (input == "middle")
            {
                std::cout << "Current Rotor Posittion : " << middle.getRotorDiaplay() << '\n';
                middle.setRotorPosition(InputValidation::getInput_Enigma_Int("enter number between 1 and 26 : "));
                break;
            }
            else if (input == "right")
            {
                std::cout << "Current Rotor Posittion : " << right.getRotorDiaplay() << '\n';
                right.setRotorPosition(InputValidation::getInput_Enigma_Int("enter number between 1 and 26 : "));
                break;
            }
        }
    }

    void printRotorPatterns()
    {
        std::cout << "Pattern IC    - 'D', 'M', 'T', 'W', 'S', 'I', 'L', 'R', 'U', 'Y', 'Q', 'N', 'K', 'F', 'E', 'J', 'C', 'A', 'Z', 'B', 'P', 'G', 'X', 'O', 'H', 'V'\n";
        std::cout << "Pattern IIC   - 'H', 'Q', 'Z', 'G', 'P', 'J', 'T', 'M', 'O', 'B', 'L', 'N', 'C', 'I', 'F', 'D', 'Y', 'A', 'W', 'V', 'E', 'U', 'S', 'R', 'K', 'X'\n";
        std::cout << "Pattern IIIC  - 'U', 'Q', 'N', 'T', 'L', 'S', 'Z', 'F', 'M', 'R', 'E', 'H', 'D', 'P', 'X', 'K', 'I', 'B', 'V', 'Y', 'G', 'J', 'C', 'W', 'O', 'A'\n";
        std::cout << '\n';
        std::cout << "Pattern I     - 'J', 'G', 'D', 'Q', 'O', 'X', 'U', 'S', 'C', 'A', 'M', 'I', 'F', 'R', 'V', 'T', 'P', 'N', 'E', 'W', 'K', 'B', 'L', 'Z', 'Y', 'H'\n";
        std::cout << "Pattern II    - 'N', 'T', 'Z', 'P', 'S', 'F', 'B', 'O', 'K', 'M', 'W', 'R', 'C', 'J', 'D', 'I', 'V', 'L', 'A', 'E', 'Y', 'U', 'X', 'H', 'G', 'Q'\n";
        std::cout << "Pattern III   - 'J', 'V', 'I', 'U', 'B', 'H', 'T', 'C', 'D', 'Y', 'A', 'K', 'E', 'Q', 'Z', 'P', 'O', 'S', 'G', 'X', 'N', 'R', 'M', 'W', 'F', 'L'\n";
        std::cout << '\n';
        std::cout << "Pattern I_K   - 'P', 'E', 'Z', 'U', 'O', 'H', 'X', 'S', 'C', 'V', 'F', 'M', 'T', 'B', 'G', 'L', 'R', 'I', 'N', 'Q', 'J', 'W', 'A', 'Y', 'D', 'K'\n";
        std::cout << "Pattern II_K  - 'Z', 'O', 'U', 'E', 'S', 'Y', 'D', 'K', 'F', 'W', 'P', 'C', 'I', 'Q', 'X', 'H', 'M', 'V', 'B', 'L', 'G', 'N', 'J', 'R', 'A', 'T'\n";
        std::cout << "Pattern III_K - 'E', 'H', 'R', 'V', 'X', 'G', 'A', 'O', 'B', 'Q', 'U', 'S', 'I', 'M', 'Z', 'F', 'L', 'Y', 'N', 'W', 'K', 'T', 'P', 'D', 'J', 'C'\n";
        std::cout << '\n';
        std::cout << "Pattern UKW   - 'Q', 'Y', 'H', 'O', 'G', 'N', 'E', 'C', 'V', 'P', 'U', 'Z', 'T', 'F', 'D', 'J', 'A', 'X', 'W', 'M', 'K', 'I', 'S', 'R', 'B', 'L'\n";
        std::cout << "Pattern ETW   - 'Q', 'W', 'E', 'R', 'T', 'Z', 'U', 'I', 'O', 'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'P', 'Y', 'X', 'C', 'V', 'B', 'N', 'M', 'L'\n";
        std::cout << '\n';
        std::cout << "Pattern UKW_K - 'I', 'M', 'E', 'T', 'C', 'G', 'F', 'R', 'A', 'Y', 'S', 'Q', 'B', 'Z', 'X', 'W', 'L', 'H', 'K', 'D', 'V', 'U', 'P', 'O', 'J', 'N'\n";
        std::cout << "Pattern ETW_K - 'Q', 'W', 'E', 'R', 'T', 'Z', 'U', 'I', 'O', 'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'P', 'Y', 'X', 'C', 'V', 'B', 'N', 'M', 'L'\n";
        std::cout << '\n';
    }
    connections switchOnPattern(const std::string_view &input)
    {
        for(const auto &x : patternNames)
        {
            if(x.second == input)
            {
                return x.first;
            }
        }
        std::cout << "No such pattern exists, please try again\n";
    }
    void setRotorPattern() 
    {
        while(true)
        {
            system("CLS");
            std::string input{ InputValidation::getInput_String("Choose rotor, you wish to change the pattern of : ") };
            if (input == "left")
            {
                printRotorPatterns();
                left.setRotorPattern(switchOnPattern(InputValidation::getInput_String("Enter valid pattern name :")));
                break;
            }
            else if (input == "middle")
            {
                printRotorPatterns();
                middle.setRotorPattern(switchOnPattern(InputValidation::getInput_String("Enter valid pattern name :")));
                break;
            }
            else if (input == "right")
            {
                printRotorPatterns();
                right.setRotorPattern(switchOnPattern(InputValidation::getInput_String("Enter valid pattern name :")));
                break;
            } 
            else if(input == "reflector")
            {
                printRotorPatterns();
                reflector.setReflectorPattern(switchOnPattern(InputValidation::getInput_String("Enter valid pattern name :")));
                break;
            }
        }
    }
    void setRotorNotch()
    {
        while (true)
        {
            system("CLS");
            std::cout << "Choose rotor, you wish to change the position of\n";
            std::string input{ InputValidation::getInput_String("Middle -> 'middle'  Right -> 'right'") };
            if (input == "middle")
            {
                std::cout << "Current Rotor Notch : " << middle.getRotorNotch() << '\n';
                middle.setRotorNotch(InputValidation::getInput_Enigma_Int("enter number between 1 and 26 : "));
                break;
            }
            else if (input == "right")
            {
                std::cout << "Current Rotor Notch : " << right.getRotorPosition() << '\n';
                right.setRotorNotch(InputValidation::getInput_Enigma_Int("enter number between 1 and 26 : "));
                break;
            }
        }
    }

    void encryption()
    {
        while(true)
        {
            system("CLS");
            userInteface_Enigma();
            const std::string input{ InputValidation::getInput_String("Begin -> 'start'   Quit -> 'end'   Enter Plugboard -> 'plugboard'  Enter Rotor Settings -> 'rotor' ") };
            if (input == "start")
            {
                std::cout << encrypt(InputValidation::getInput_Enigma_String("Type the phrase you want to encrypt : ")) << '\n';

                while(true)
                {
                    if (InputValidation::getInput_Enigma_Confirm("type 'Y' if you are ready to proceed : ") == 'Y')
                    {
                        break;
                    }
                }

            } else if (input == "end")
            {
                exit(0);
                break;

            } 
            else if (input == "plugboard")
            {
                setPlugboard();
            } 
            else if(input == "rotor")
            {
                setRotors();
            }
        }

    }

//Namespace "Enigma" ends here : 
} 