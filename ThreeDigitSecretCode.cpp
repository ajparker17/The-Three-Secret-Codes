#include<iostream>
#include<ctime>

void InputManager();

bool PlayGame(int LevelDifficulty)
{
    srand(time(NULL));

    int InitialDifficulty = LevelDifficulty;
    int MaxDifficulty = LevelDifficulty + 4;
    int RoomNumber = 1;

    std::cout<<"\nYou are now in Room number "<<RoomNumber;

    do
    {
        int EncryptedA = rand() % LevelDifficulty + 1;
        int EncryptedB = rand() % LevelDifficulty + 1;
        int EncryptedC = rand() % LevelDifficulty + 1;
    
        int EncryptedSum = EncryptedA + EncryptedB + EncryptedC;
        int EncryptedProduct = EncryptedA * EncryptedB * EncryptedC;

        //std::cout<<"Only for devs/// "<<EncryptedA<<std::endl<<EncryptedB<<std::endl<<EncryptedC<<std::endl;

        std::cout<<"\n\nYou need find three Encrypted number for Room Number "<<RoomNumber;
        std::cout<<"\nSum of three encrypted numbers = "<<EncryptedSum;
        std::cout<<"\nProduct of three encrypted numbers = "<<EncryptedProduct<<std::endl;

        //user guess
        int GuessA;
        int GuessB;
        int GuessC;
        std::cout<<"\nNow enter number to save yourself:"<<std::endl;
        std::cin>>GuessA>>GuessB>>GuessC;
        int GuessSum = GuessA + GuessB + GuessC;
        int GuessProduct = GuessA * GuessB * GuessC;
        if(GuessSum == EncryptedSum && GuessProduct == EncryptedProduct)
        {
            std::cout<<"\nCorrect!! ";
            ++LevelDifficulty;
            if(RoomNumber == 5)
            {
                std::cout<<"\n\nCongradulations you've completed the game try other difficulty modes";
                return true;
                InputManager();
            }
            else
            {
                ++RoomNumber;
                 std::cout<<"\nProceeding to Room Number "<<RoomNumber;
            }
        }
        else
        {
            std::cout<<"Wrong Codes, Restarting game";
            return true;
        }
    }while(LevelDifficulty <= MaxDifficulty);
}

void InputManager()
{

    std::cout<<"\n\nPlease Select the difficulty:\n1.Easy\n2.Normal\n3.Hard\n"<<std::endl;

    int Difficulty;
    std::cin>>Difficulty;

    if(Difficulty < 1 || Difficulty > 3)
    {
        std::cout<<"\nPlease Enter Valid Difficulty"<<std::endl;
        InputManager();
    }else
    {
        switch (Difficulty)
        {
        case 1: std::cout<<"\nMode: EASY";
            PlayGame(Difficulty * 8);
            break;
        case 2: std::cout<<"\nMode: NORMAL";
            PlayGame(Difficulty * 16);
            break;
        case 3: std::cout<<"\nMode: HARD";
            PlayGame(Difficulty * 32);
            break;        
        
        default:
            break;
        }
    }
}

int main()
{
    std::cout<<"\nWelcome to Three Digit Secret Code Game!!!";
    InputManager();
    return 0;
}