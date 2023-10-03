#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>
using namespace std;

enum Level_Of_Questions { Easy = 1, Medium = 2, Hard = 3, Mix = 4 };

enum Operation_Type { Addition = 1, subtraction = 2, multiplication = 3, division = 4, Mixed = 5 };

struct Exam_Questions
{
	short NumberOfQuestions = 0;
	Level_Of_Questions LevelOfQuestions = Level_Of_Questions::Easy; // create a default value
	Operation_Type OperationType = Operation_Type::Addition; // create a default value
};

struct Questions_Details
{
	string OperationType;
	int NumberOne = 0;
	int NumberTwo = 0;
	int CorrectAnswer = 0;
	int UserAnswer = 0;
};

struct FinalResult
{
	short NumOfQuestions = 0;
	short RightAnswers = 0;
	short WrongAnswers = 0;
	string ResultTitle = "";
	string QuestionsLevel = "";
	string OperationType = "";

};

int RandomNumber(int From, int To)
{
	int RandomNumber = rand() % (To - From + 1) + From;
	return RandomNumber;
}

int ReadPositiveNumber(string Message)
{
	int Number = 0;

	do
	{
		cout << Message << endl;
		cin >> Number;

	} while (Number <= 0);

	return Number;
}

int HowManyQuestions()
{
	int HowManyQuestions = ReadPositiveNumber("How many questions do you want to answer ? ");

	return HowManyQuestions;
}

Level_Of_Questions ReadLevelOfQuestions()
{
	short LevelOfQuestions = 0;

	do
	{
		cout << "\nEnter Level Of Questions ? \n";
		cout << "\n[1] Easy\n";
		cout << "[2] Medium\n";
		cout << "[3] Hard\n";
		cout << "[4] Mix\n";
		cout << "Your choice : ";
		cin >> LevelOfQuestions;

	} while (LevelOfQuestions <= 0 || LevelOfQuestions >= 5);


	return (Level_Of_Questions)LevelOfQuestions;
}

Operation_Type ReadOperationType()
{
	short OperationType = 0;

	do
	{
		cout << "\nEnter Operation Type ? \n";
		cout << "\n[1] Addition  (+)\n";
		cout << "[2] subtraction  (-)\n";
		cout << "[3] multiplication  (x)\n";
		cout << "[4] division (/)\n";
		cout << "[5] Mixed  (Randome Operation)\n";
		cout << "Your choice : ";
		cin >> OperationType;

	} while (OperationType <= 0 || OperationType >= 6);


	return (Operation_Type)OperationType;
}

int GenerateNumbersForTheQuestion(Level_Of_Questions LevelOfQuestions)
{
	switch (LevelOfQuestions)
	{
	case Level_Of_Questions::Easy:
		return RandomNumber(1, 10);
	case Level_Of_Questions::Medium:
		return RandomNumber(11, 50);
	case Level_Of_Questions::Hard:
		return RandomNumber(51, 100);
	case Level_Of_Questions::Mix:
		return RandomNumber(1, 100);
		break;
	default:
		return RandomNumber(21, 50);
	}
}

string GenerateMixedOperationType()
{
	string MixedOperationType[4] = { "+", "-", "x" , "/" };
	return MixedOperationType[RandomNumber(0, 3)];

}

string GenerateOperationTypeForTheQuestion(Operation_Type OperationType)
{
	switch (OperationType)
	{
	case Operation_Type::Addition:
		return "+";
	case Operation_Type::subtraction:
		return "-";
	case Operation_Type::multiplication:
		return "x";
	case Operation_Type::division:
		return "/";
	case Operation_Type::Mixed:
		return GenerateMixedOperationType();
	}
}

int CalculateCorrectAnswer(int NumberOne, int NumberTwo, string OperationType)
{
	if (OperationType == "+")
		return NumberOne + NumberTwo;
	else if (OperationType == "-")
		return NumberOne - NumberTwo;
	else if (OperationType == "x")
		return NumberOne * NumberTwo;
	else
		return NumberOne / NumberTwo;
}

void PrintTheCorrectAnswer(int CorrectAnswer, int UserAnswer)
{
	if (CorrectAnswer == UserAnswer)
		cout << "\nRight Answer :-) " << endl;
	else
	{
		cout << "\a";
		cout << "\nWrong Answer :-(" << endl;
		cout << "The rigth answer = " << CorrectAnswer << endl;
	}
}

string GenerateOperationTypeInFinalResults(Operation_Type OperationType)
{
	switch (OperationType)
	{
	case Addition:
		return "Addition";
		break;
	case subtraction:
		return "subtraction";
		break;
	case multiplication:
		return "multiplication";
		break;
	case division:
		return "division";
		break;
	case Mixed:
		return "Mixed";
		break;
	}
}

string GenerateQuestionsLevelInFinalResults(Level_Of_Questions LevelOfQuestions)
{
	switch (LevelOfQuestions)
	{
	case Easy:
		return "Easy";
		break;
	case Medium:
		return "Medium";
		break;
	case Hard:
		return "Hard";
		break;
	case Mix:
		return "Mix";
		break;
	}
}

int GenerateNumberOfCorrectAnswers(int CorrectAnswer, int UserAnswer, short& NumberOfCorrectAnswers)
{
	if (CorrectAnswer == UserAnswer)
	{
		++NumberOfCorrectAnswers;
	}
	return NumberOfCorrectAnswers;
}

string ResultTitle(int RoundNumber, int CorrectAnswer)
{
	if (CorrectAnswer >= (RoundNumber - CorrectAnswer))
		return " Pass :-) ";
	else
	{
		return "Failed :-( ";
	}
}

FinalResult PrintQuestion()
{
	Exam_Questions ExamQuestions;

	ExamQuestions.NumberOfQuestions = HowManyQuestions();
	ExamQuestions.LevelOfQuestions = ReadLevelOfQuestions();
	ExamQuestions.OperationType = ReadOperationType();

	Questions_Details QuestionsDetails;
	FinalResult FinalResults;
	FinalResults.RightAnswers = 0;

	for (int counter = 1; counter <= ExamQuestions.NumberOfQuestions; counter++)
	{
		QuestionsDetails.NumberOne = GenerateNumbersForTheQuestion(ExamQuestions.LevelOfQuestions);
		QuestionsDetails.OperationType = GenerateOperationTypeForTheQuestion(ExamQuestions.OperationType);
		QuestionsDetails.NumberTwo = GenerateNumbersForTheQuestion(ExamQuestions.LevelOfQuestions);

		cout << "\n\nQuestion " << "[ " << counter << " / " << ExamQuestions.NumberOfQuestions << " ]" << endl;
		cout << endl;
		cout << QuestionsDetails.NumberOne << endl;
		cout << QuestionsDetails.OperationType << endl;
		cout << QuestionsDetails.NumberTwo << endl;
		cout << "__________________\n";
		cout << "Your answer = ";
		cin >> QuestionsDetails.UserAnswer;

		QuestionsDetails.CorrectAnswer = CalculateCorrectAnswer(QuestionsDetails.NumberOne,
			QuestionsDetails.NumberTwo, QuestionsDetails.OperationType);

		PrintTheCorrectAnswer(QuestionsDetails.CorrectAnswer, QuestionsDetails.UserAnswer);


		FinalResults.NumOfQuestions = ExamQuestions.NumberOfQuestions;
		FinalResults.OperationType = GenerateOperationTypeInFinalResults(ExamQuestions.OperationType);
		FinalResults.QuestionsLevel = GenerateQuestionsLevelInFinalResults(ExamQuestions.LevelOfQuestions);
		FinalResults.RightAnswers = GenerateNumberOfCorrectAnswers(QuestionsDetails.CorrectAnswer,
			QuestionsDetails.UserAnswer, FinalResults.RightAnswers);
		FinalResults.WrongAnswers = FinalResults.NumOfQuestions - FinalResults.RightAnswers;
	}
	return FinalResults;
}

void ChangeScreenColor(int CorrectAnswer, int WorngAnswer)
{
	if (CorrectAnswer >= WorngAnswer)
		system("color 2D");
	else
		system("color 4E");
}

void PrintFinalResults()
{
	FinalResult FinalResultOfExam;

	FinalResultOfExam = PrintQuestion();

	FinalResultOfExam.ResultTitle = ResultTitle(FinalResultOfExam.NumOfQuestions,
		FinalResultOfExam.RightAnswers);

	cout << "\n___________________________________\n";
	cout << "\n Final Result is " << FinalResultOfExam.ResultTitle << endl;
	cout << "___________________________________\n";

	//ChangeScreenColor(FinalResultOfExam.RightAnswers, FinalResultOfExam.WrongAnswers);
	cout << "\n";

	cout << "  Number of questions : " << FinalResultOfExam.NumOfQuestions << endl;
	cout << "  Questions Level     : " << FinalResultOfExam.QuestionsLevel << endl;
	cout << "  Operation Type      : " << FinalResultOfExam.OperationType << endl;
	cout << "  Right Answers       : " << FinalResultOfExam.RightAnswers << endl;
	cout << "  Wrong Answers       : " << FinalResultOfExam.WrongAnswers << endl;
	cout << "\n___________________________________\n";

}

void ResetScreen()
{
	system("color 07");
	system("cls");
}

void StartExam()
{
	char NewExam = 'Y';

	do
	{
		ResetScreen();

		PrintFinalResults();

		cout << "\n Do you want to play again? Y/N ?  ";
		cin >> NewExam;


	} while (NewExam == 'Y' || NewExam == 'y');
}

int main()
{
	//Generate a random number
	srand((unsigned)time(NULL));

	StartExam();
}