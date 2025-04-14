#include <iostream>
#include <iomanip>

using namespace std;

char user_input(unsigned int);
vector<int> user_score(const char*, const char*);
void print_score(vector<int>);

int main(){

    char answers[20] = { 'B', 'D', 'A', 'A', 'C', 'A', 'B', 'A', 'C', 'D', 'B', 'C', 'D', 'A', 'D', 'C', 'C', 'B', 'D', 'A' };
    char userAnswers[20];
    vector<int> userResults;
    unsigned int i;

    
    for(i = 0; i < 20; i++)
        userAnswers[i] = user_input(i);

    userResults = user_score(answers, userAnswers);
    
    print_score(userResults);

    return 0;
}

//Gets user input within A-D char range
char user_input(unsigned int i){
    char c;

    cout << "Enter A, B, C, or D for question " << i+1 << endl;
    cin >> c;

    //since the ascii of A and D are the range 65-68 it's easy to check like this
    while(int(c) < int('A') || int(c) > int('D')){
        cout << "\nMust be either A, B, C or D\n" << endl;
        cout << "Enter A, B, C, or D for question " << i+1 << endl;
        cin >> c;
    }

    return c;
}

//Takes in two char arrays as pointers, gets the score and returns list of incorrect problems with a vector
//the score is appeneded to the end to be popped off later.
//I was going to try to return another dynamic array with realloc but figured that we only needed to use arrays for the answers and user answers.
vector<int> user_score(const char* answers, const char* userAnswers){

    int score = 0;
    vector<int> incorrect;

    for(int i = 0; i < 20; i++){

        if(userAnswers[i] == answers[i])
            score++;
        else
            incorrect.push_back(i+1);
    }

    incorrect.push_back(score);

    return incorrect;
}

//Prints user tests results with incorrect problems
void print_score(vector<int> userResults){

    string passFail = (userResults.back() >= 15) ? "PASSED" : "FAILED";

    cout << "\n" << setw(20) << setfill('-') << "" << setfill(' ') << endl;
    cout << "    TEST RESULTS\n" << setw(20) << setfill('-') << "" << setfill(' ') << endl;
    cout << setw(11) << left << "GRADE " << ": " << passFail << endl;
    cout << setw(11) << left << "CORRECT " << ": " << userResults.back() << endl;
    cout << setw(11) << left << "INCORRECT " << ": " << 20-userResults.back() << endl;
    cout << setw(20) << setfill('-') << "" << setfill(' ') << endl;
    userResults.pop_back();

    if(userResults.size() > 0){
        cout << "\nProblems that were incorrect: \n| ";
        for(int i = 0; i < userResults.size(); i++)
            cout << userResults[i] << " | " << flush; 
        cout << endl << endl;
    }
    else
        cout << "\nAced test no incorrect problems to list\n" << endl;

}

