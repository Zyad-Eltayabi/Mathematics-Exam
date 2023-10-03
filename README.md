# Mathematics-Exam
Mathematics Exam using C++
<hr>

## Introduction
This project is a simple program that allows the user to take a mathematics exam. The program operates as follows:

1. **Program Start and User Selection:**
   - The user is asked to specify the number of questions they want to answer. This number must be a positive integer.
   - The user also chooses the difficulty level of the questions from available options (Easy, Medium, Hard, Mixed).
   - The user also chooses the type of mathematical operations they want to use (Addition, Subtraction, Multiplication, Division, Mixed).

2. **Preparing the Questions:**
   - Based on the user's choices, the program prepares a set of questions.
   - Random numbers used in the questions are generated based on the selected difficulty level. For example, if the level is Easy, the numbers will be between 1 and 10.
   - The type of mathematical operations is also determined based on the user's selection, and mixed operations may be included.

3. **Displaying Questions and Collecting Answers:**
   - Each question is displayed to the user and includes two numbers and a mathematical operation (e.g., 5 + 3).
   - The user is required to input their answer afterward.

4. **Calculating and Verifying Correct Answers:**
   - After the user enters their answer, the program calculates the correct answer for the question.
   - It checks whether the user's answer is correct by comparing it to the correct answer.

5. **Displaying Individual Results:**
   - After answering each question, the result of the answer is displayed individually. A message indicates whether the answer is correct or incorrect, along with the correct answer if the user's answer is incorrect.

6. **Displaying Final Results:**
   - After answering all questions, the final exam results are displayed.
   - This includes the total number of questions, the number of correct answers, the number of incorrect answers, a result title (related to the user's performance), the difficulty level of questions, and the type of mathematical operations.

7. **Play Again or Exit:**
   - The program allows the user to replay the exam if they wish.
   - If the user does not want to play again, they can exit the program.

### In summary, this program generates random math questions based on user choices and allows the user to answer them, displaying the final results at the end of the exam.
