//R.Prithikasri CODSOFT Task1:Number Guessing Game
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int main()
{
    srand(static_cast<unsigned int>(time(0)));
    int randomNum = rand() % 100 + 1;
    int guess = 0;
    int attempts = 0;
    cout<<"Welcome to Number Guessing Name!"<<endl;
    cout<<"I've chosen a number between 1 to 100. Can you guess it?"<<endl;
    while(guess != randomNum)
    {
        cout<<"Enter your guess : "<<endl;
        cin>>guess;
        attempts++;
        if(guess > randomNum)
        {
            cout<<"Too high! Try again."<<endl;
        }else if (guess < randomNum) 
        {
            cout<<"Too low! Try again."<<endl;
        }else {
            cout<<"Congratulations! You've guessed the correct number in "<<attempts<<" attempts."<<endl;
        }
    }
    return 0;
}