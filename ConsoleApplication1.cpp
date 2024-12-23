#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Gets the number of inputs from user:
int HowMany()
{
    cout << "How many numbers do you wanna enter? ";
    int size; cin >> size; return size;
}

// Inputs an array of integers:
vector<int> GetInts(int size = HowMany())
{
    vector<int> ints(size);
    (size == 1) ? cout << "Enter a number: " : cout << "Enter " << size << " numbers:\n";
    for (int i = 0; i < size; ++i)
        cin >> ints[i];
    return ints;
}

// Inputs an array of doubles:
vector<double> GetDoubles(int size = HowMany())
{
    vector<double> arr(size);

    (size == 1) ? cout << "Enter a number: " : cout << "Enter " << size << " numbers:\n";
    for (int i = 0; i < size; ++i)
        cin >> arr[i];
    return arr;
}

// Inputs a string:
string GetString()
{
    cout << "Enter a string: ";
    string s;
    cin.ignore(); getline(cin, s);
    return s;
}

// Minimum number:
double Min(vector<double> nums = GetDoubles())
{
    int iMin = 0;
    for (int i = 0; i < nums.size(); i++)
        if (nums[i] < nums[iMin])
            iMin = i;
    return nums[iMin];
}

// Maximum number:
double Max(vector<double> nums = GetDoubles())
{
    int iMax = 0;
    for (int i = 0; i < nums.size(); i++)
        if (nums[i] > nums[iMax])
            iMax = i;
    return nums[iMax];
}

// Sorts an array of doubles:
vector<double> Sort(vector<double> nums = GetDoubles())
{
    double iMin = 0;
    vector<double> arranged(nums.size());
    for (int j = 0; j < nums.size(); j++)
    {
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] < nums[iMin])
                iMin = i;
        arranged[j] = nums[iMin];
        nums[iMin] = INFINITY;
    }
    return arranged;
}

// Average:
double Average(vector<double> nums = GetDoubles())
{
    double sum = 0;
    for (int i = 0; i < nums.size(); i++)
        sum = sum + nums[i];
    return sum / nums.size();
}

// Factorial:
int Factorial(int n = GetInts(1)[0])
{
    if (n == 1)
        return 1;
    return n * Factorial(n - 1);
}

// Checks if the number is prime or not (true/false):
bool CheckPrime(int n = GetInts(1)[0])
{
    bool result = false;
    for (int i = 2; i < n; i++)
        if (n == i)
        {
            result = true;
            break;
        }
    return result;
}

// ب.م.م:
int BMM(vector<int> nums = GetInts(2))
{
    int BMM;
    for (int i = nums[1]; true; i--)
        if (nums[0] % i == 0 && nums[1] % i == 0)
        {
            BMM = i;
            break;
        }
    return BMM;
}

// Multiplication table:
void MultiplicationTable(int n = GetInts(1)[0])
{
    for (int j = 1; j <= n; j++)
    {
        for (int i = 1; i <= n; i++)
            cout << i * j << ",";
        cout << "\n";
    }
}

// Fibonacci:
int Fibonacci(int n = GetInts(1)[0])
{
    if (n < 3)
        return n - 1;
    return Fibonacci(n - 1) + Fibonacci(n - 2);
}

// Reverse the string:
string ReverseStr(string s = GetString())
{
    string r;
    for (int i = s.size() - 1; i >= 0; i--)
        r += s[i];
    return r;
}

// Outputs a list of prime numbers until n:
void PrimeList(int n = GetInts(1)[0])
{
    for (int i = 2; i <= n; i++)
    {
        int j = i;
        do
        {
            if (j == 2)
                cout << i << ",";
            j--;
        } while (i % j != 0 && j > 1);
    }
}

// If the number is even, *2 . otherwise /2 :
double CheckEO(int n = GetInts(1)[0])
{
    double result = (n % 2 == 0) ? n * 2 : static_cast<double>(n) / 2;
    return result;
}

//12. ++ + ...
void Plus(int n = GetInts(1)[0])
{
    for (int j = 1; j <= n; j++)
    {
        for (int i = 1; i <= j; i++)
            cout << "+";
        cout << "\n";
    }
}

// Gets the names and scores then shows the best and worst students:
void Scores()
{
    cout << "How many students? ";
    int n; cin >> n;
    int iMin = 0, iMax = 0;
    vector<double> scores(n);
    vector<string> names(n);
    for (int i = 0; i < n; i++)
    {
        cout << "Enter a name: ";
        cin >> names[i];
        cout << "Enter his score: ";
        cin >> scores[i];
        if (scores[i] < scores[iMin])
            iMin = i;
        if (scores[i] > scores[iMax])
            iMax = i;
    }
    cout << "\nThe best student: " << names[iMax] << " (" << scores[iMax] << ")\n";
    cout << "The worst: "          << names[iMin] << " (" << scores[iMin] << ")\n";
}

// Gets x and y, Shows the x^y :
int Power(vector<int> n = GetInts(2))
{
    if (y == n[1])
        return x;
    return n[0] * Power({n[0] , n[1] - 1});
}

int main()
{
    cout << "I can do these things for you. Choose the number of your option:\n\n";
    cout << "1. Find the minimum number\n";
    cout << "2. Find the maximum number\n";
    cout << "3. Sort numbers\n";
    cout << "4. Average\n";
    cout << "5. Factorial\n";
    cout << "6. Check if the number is prime or not\n";
    cout << "7. B.M.M of two numbers\n";
    cout << "8. Multiplication table with the n length and width\n";
    cout << "9. Shows the term n of Fibonacci\n";
    cout << "10. Reverse a string\n";
    cout << "11. List of prime numbers until n\n";
    cout << "12. If the number is even, *2 . otherwise /2\n";
    cout << "13. Show the shape below for n lines:\n+\n++\n+++ ...\n";
    cout << "14. Shows the best and the worst students\n";
    cout << "15. Gets x and y, Shows the x^y :\n";

    int option, options = 15;
    bool loop = true;
    while (loop)
    {
        loop = false;
        cout << "\nYour option: "; cin >> option;

        switch (option)
        {
        case 1:
            cout << "The minimum number: " << Min();
            break;
        case 2:
            cout << "The maximum number: " << Max();
            break;
        case 3:
        {
            vector<double> sorted(Sort());
            cout << "Sorted numbers: ";
            for (int i : sorted)
                cout << i << ",";
            break;
        }
        case 4:
            cout << "Average: " << Average();
            break;
        case 5:
            cout << "Factorial: " << Factorial();
            break;
        case 6:
            (CheckPrime()) ? cout << "It's Prime" : cout << "Not Prime";
            break;
        case 7:
            cout << "B.M.M : " << BMM();
            break;
        case 8:
            MultiplicationTable();
            break;
        case 9:
            cout << Fibonacci();
            break;
        case 10:
            cout << "Reversed string: " << ReverseStr();
            break;
        case 11:
            PrimeList();
            break;
        case 12:
            cout << "Result: " << CheckEO();
            break;
        case 13:
            Plus();
            break;
        case 14:
            Scores();
            break;
        case 15:
            cout << "x^y  = " << Power();
            break;
        default:
            cout << "invalid input!! Choose a numer from 1 to " << options << "\n";
            loop = true;
            break;
        }
    }
    return 0;
}
