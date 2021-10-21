#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <locale.h>
#include <wchar.h>
int charSort() {
        // TODO write code here
        char *locale = setlocale(LC_ALL, "en_US.utf8");
        wchar_t c;                                       //input character with more bytes
        char temp;                                       //temporary character for sorting
        wchar_t list[10000];                             //character array to store input characters
        int counter[10000];                              //integer array to store count of characters
        int found = 0;                                   //integer to show if next character is in array currently
        int sl = 0;                                      //integer to show the amount of characters in array
        int temp2;                                       //temporary integer for sorting
        FILE *in = fopen("input.txt", "r");               //systemcall to opent file
        //while ((c = fgetwc(in)) != WEOF) {
                //putwchar(c);                           //for loop to test input
        //}     
        while((c = fgetwc(in)) != WEOF) {                //while loop to loop through file
                 //if (scanf("%c", &c) == EOF){
                        //break;                         //old scanf attempt
                //}
                //putwchar(c);  
                if (sl > 0) {                            // if statement to see if array is empty. If not a for loop to find an
                        for (int i = 0; i < sl; ++i) {   // character that matches input is activated.
                                if (c == list[i]) {
                                        ++counter[i];
                                        found = 1;
                                        break;
                                }
                        }
                }
          if (sl == 0) {                                //if statement to see if the array is empty. If array is empty it initiates  
                        list[sl] = c;                   // the first array spot with input.
                        ++counter[sl];
                        ++sl;
                }
                else if (found == 0) {                  //If array is not empty, also checks to see if input character has been found.
                        list[sl] = c;                   //If input character was not found then it is added to the next available spot in array.
                        ++counter[sl];
                        ++sl;
                }
                found = 0;
        }
        fclose(in);
        for (int i = 0; i < (sl - 1); ++i) {            //for loop for sorting by number of character appearance from input
                if (counter[i] < counter[i + 1]) {
                        temp2 = counter[i];
                        counter[i] = counter[i + 1];
                        counter[i + 1] = temp2;
                        temp = list[i];
                        list[i] = list[i + 1];
                        list[i + 1] = temp;
                 }
        }
        for (int i = 0; i < sl; ++i) {                      //for loop for printing arrays
                wprintf(L"%c->%d\n", list[i], counter[i]);
        }
        return 0;
}
int main (int argc, char **argv) {
    int result;
    // Error Check
    if (argc > 1) {
        dprintf(STDERR_FILENO, "Usage: %s <n>\n", argv[0]);
        exit(0);
    }
    // Call the function to print out values
    result = charSort();
    return result; // Return program status
}
