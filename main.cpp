#include <iostream>

int fibonnacciEvenSum() {

    int firstVal = 1;
    int secondVal = 1;
    int sum = 0;

    while (secondVal <= 4000000) {
        secondVal = secondVal + firstVal;
        firstVal = secondVal - firstVal;
        if (secondVal % 2 == 0) {
            sum += secondVal;
        }
    }

    return sum;
}

long double factorial(int num) {
    return ((num <= 1) ? 1 : (factorial(num - 1) * num));
}

long double latticePaths(int x, int y) {
    return factorial(x + y) / factorial(x) / factorial(y);
}

const unsigned int coins[] = { 1, 2, 5, 10, 20, 50, 100, 200 };

int coinCombinations(int amount, int size) {
 
    int count = 0;

    if (amount > 0) {
        if (size >= 0 && amount >= coins[size])
            count += coinCombinations(amount - coins[size], size);
        if (size > 0)
            count += coinCombinations(amount, size - 1);
    }
    else if (amount == 0)
        count++;
    
    return count;
}



int main() {

    int answer2 = fibonnacciEvenSum();
    std::cout << "The answer to Question 2: \n\"By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms.\"\n Is: " << answer2 << std::endl;

    long double answer15 = latticePaths(20, 20);
    std::cout << "\nThe answer to Question 15: \n\"How many such routes are there through a grid?\"\n Is: " << answer15 << std::endl;

    int totalAmount = 200, largestSize = 0;
    for (largestSize = 7; coins[largestSize] > totalAmount && largestSize >= 0; largestSize--);
    int answer31 = coinCombinations(totalAmount, largestSize);
    std::cout << "\nThe answer to Question 31: \n\"How many different ways can 2 Pounds be made using any number of coins?\"\n Is: " << answer31 << std::endl;




    return 0;
}
