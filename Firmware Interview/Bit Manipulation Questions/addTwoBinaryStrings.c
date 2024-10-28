#
// Given two binary strings a and b, return their sum as a binary string.

// Example 1:

// Input: a = "11", b = "1"
// Output: "100"
// Example 2:

// Input: a = "1010", b = "1011"
// Output: "10101"

char* addBinary(char* a, char* b) {
    int input = atoi(*a) + atoi(*b);
    int count = 0; 
    int output_num = 0;
    char *ouput[strlen(a) + 1];
    int quotient; 

    while( quotient!=  0){
        quotient = input / 2; 
        int bit = input % 2;
        output_num |= (bit << count); 
    }

    return itoa(output, out);
}