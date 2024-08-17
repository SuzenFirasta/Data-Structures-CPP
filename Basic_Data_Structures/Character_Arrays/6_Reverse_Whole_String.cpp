#include <iostream>

using namespace std;

// Function to reverse a portion of the string from index start to end
void reverse(char input[], int start, int end) {
    while (start < end) {
        // Swap the characters at start and end
        char temp = input[start];
        input[start] = input[end];
        input[end] = temp;
        start++;
        end--;
    }
}

void reverseStringWordWise(char input[]) {
    int length = 0;

    // Calculate the length of the input string
    while (input[length] != '\0') {
        length++;
    }

    // Step 1: Reverse the entire string
    reverse(input, 0, length - 1);

    // Step 2: Reverse each word in the reversed string
    int start = 0;
    for (int end = 0; end <= length; end++) {
        // When we reach a space or the end of the string
        if (input[end] == ' ' || input[end] == '\0') {
            // Reverse the current word
            reverse(input, start, end - 1);
            // Move the start to the next word
            start = end + 1;
        }
    }
}

int main() {
    char input[100];
    cout << "Enter a string: ";
    cin.getline(input, 100);

    reverseStringWordWise(input);

    cout << "Reversed word-wise string: " << input << endl;

    return 0;
}
