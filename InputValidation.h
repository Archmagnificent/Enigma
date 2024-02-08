#pragma once
#include <iostream>
#include <limits>

namespace InputValidation 
{
    void ignoreLine()
    {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::string getInput_Enigma_String(std::string message) //Adding messgae as a parameter to inform the user of the kind of input they need to provide
    {
        while (true) // Loop until user enters a valid input
        {
            std::cout << message;
            std::string x{};
            std::getline(std::cin, x);

            // Check for failed extraction
            if (!std::cin) // if the previous extraction failed
            {
                if (std::cin.eof()) // if the stream was closed
                {
                    exit(0); // shut down the program now
                }

                // let's handle the failure
                std::cin.clear(); // put us back in 'normal' operation mode
                ignoreLine();     // and remove the bad input

                std::cout << "Oops, that input is invalid.  Please try again.\n";
            }
            else
            {
                for(auto c : x)
                {
                    if((c >= 'A') && (c <= 'Z'))
                    {
                        return x;
                    }
                    else 
                    {
                        std::cout << "Error : string must only contain capital letters\n";
                        break;
                    }
                }
            }
        }
    }

    char getInput_Engima_Char(std::string_view message)
    {
        while (true) // Loop until user enters a valid input
        {
            std::cout << message;
            char x{};
            std::cin >> x;

            // Check for failed extraction
            if (!std::cin) // if the previous extraction failed
            {
                if (std::cin.eof()) // if the stream was closed
                {
                    exit(0); // shut down the program now
                }

                // let's handle the failure
                std::cin.clear(); // put us back in 'normal' operation mode
                ignoreLine();     // and remove the bad input

                std::cout << "Oops, that input is invalid.  Please try again.\n";
            }
            else
            {
                ignoreLine(); // remove any extraneous input

                // Check whether the user entered a letter between A and Z
                if ((x >= 'A') && (x <= 'Z'))
                {
                    return x;
                }
                else { std::cout << "Incorrect letter"; }
            }
        }
    }


    std::string getInput_String(const std::string message) //Adding messgae as a parameter to inform the user of the kind of input they need to provide
    {
        while (true) // Loop until user enters a valid input
        {
            std::cout << message;
            std::string x{};
            std::cin >> x;

            // Check for failed extraction
            if (!std::cin) // if the previous extraction failed
            {
                if (std::cin.eof()) // if the stream was closed
                {
                    exit(0); // shut down the program now
                }

                // let's handle the failure
                std::cin.clear(); // put us back in 'normal' operation mode
                ignoreLine();     // and remove the bad input

                std::cout << "Oops, that input is invalid.  Please try again.\n";
            }
            else
            {
                ignoreLine(); // remove any extraneous input
                return x;
            }
        }
    }

    int getInput_Enigma_Int(std::string_view message)
    {
        while (true) // Loop until user enters a valid input
        {
            std::cout << message;
            int x{};
            std::cin >> x;

            // Check for failed extraction
            if (!std::cin) // if the previous extraction failed
            {
                if (std::cin.eof()) // if the stream was closed
                {
                    exit(0); // shut down the program now
                }

                // let's handle the failure
                std::cin.clear(); // put us back in 'normal' operation mode
                ignoreLine();     // and remove the bad input

                std::cout << "Oops, that input is invalid.  Please try again.\n";
            }
            else
            {
                ignoreLine(); // remove any extraneous input

                if ((x >= 1) && (x <= 26))
                {
                    return x;
                }
                else { std::cout << "incorrect rotor position, please try again"; }
            }
        }
    }



    char getInpuRowLetter(std::string_view message, int row)
    {
        while (true) // Loop until user enters a valid input
        {
            std::cout << message;
            char x{};
            std::cin >> x;

            // Check for failed extraction
            if (!std::cin) // if the previous extraction failed
            {
                if (std::cin.eof()) // if the stream was closed
                {
                    exit(0); // shut down the program now
                }

                // let's handle the failure
                std::cin.clear(); // put us back in 'normal' operation mode
                ignoreLine();     // and remove the bad input

                std::cout << "Oops, that input is invalid.  Please try again.\n";
            }
            else
            {
                ignoreLine(); // remove any extraneous input

                // Check whether the user entered a letter between A and a maximum number of rows
                if ((x >= 'A') && (x <= ('A' + (row - 1))))
                {
                    return x;
                }
                else { std::cout << "incorrect row index, please try again"; }
            }
        }
    }

    int getInpuColumnNumber(std::string_view message, int column)
    {
        while (true) // Loop until user enters a valid input
        {
            std::cout << message;
            int x{};
            std::cin >> x;

            // Check for failed extraction
            if (!std::cin) // if the previous extraction failed
            {
                if (std::cin.eof()) // if the stream was closed
                {
                    exit(0); // shut down the program now
                }

                // let's handle the failure
                std::cin.clear(); // put us back in 'normal' operation mode
                ignoreLine();     // and remove the bad input

                std::cout << "Oops, that input is invalid.  Please try again.\n";
            }
            else
            {
                ignoreLine(); // remove any extraneous input

                // Check whether the user entered a letter between A and a maximum number of rows
                if ((x >= 1) && (x <= column))
                {
                    return x;
                }
                else { std::cout << "incorrect column index, please try again"; }
            }
        }
    }


    char getInput_Enigma_Confirm(std::string_view message)
    {
        while (true) // Loop until user enters a valid input
        {
            std::cout << message;
            char x{};
            std::cin >> x;

            // Check for failed extraction
            if (!std::cin) // if the previous extraction failed
            {
                if (std::cin.eof()) // if the stream was closed
                {
                    exit(0); // shut down the program now
                }

                // let's handle the failure
                std::cin.clear(); // put us back in 'normal' operation mode
                ignoreLine();     // and remove the bad input

                std::cout << "Oops, that input is invalid.  Please try again.\n";
            }
            else
            {
                ignoreLine(); // remove any extraneous input

                // Check whether the user entered the correct letter
                if (x == 'Y')
                {
                    return x;
                }
                else { std::cout << "Type 'Y' if you are ready to proceed"; }
            }
        }
    }
}

