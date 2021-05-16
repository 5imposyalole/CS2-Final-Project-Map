/*
 * main_menu.c : A Source file of main function
 */
#include <stdio.h>
#include "item.h"
#include "database.h"



/* main function */
int main(void)
{
    char code;
    for(;;) {

        printf("case 'i': Add new item to File.\n");
        printf("case 'p': Print contents of File.\n");
        printf("case 'l': Load File.\n");
        printf("case 's': Save File.\n");
        printf("case 'f': find items by name.\n");
        printf("case 'c': Find items by category.\n");
        printf("case 'r': Find items by range.\n");
        printf("case 'n': Find nearest neighbor.\n");
        printf("case 'e': Estimated travel time.\n");
        printf("case 'q': Quit the program.\n");
        printf("Enter operation code: \n");
        scanf(" %c", &code);
        while (getchar() != '\n')  /* skips to end of line */
            ;
        switch(code) {
            case 'i': insert();
                      break;
            case 'p': print();
                      break;
            case 'l': load_items();
                      break;
            case 's': save_items();
                      break;
            case 'f': find_items_by_name();
                      break;
            case 'c': find_items_by_category();
                      break;
            case 'r': find_items_by_range();
                      break;
            case 'e': time();
                      break;
            case 'n': find_nearest_neighbor();
                      break;
            case 'q': return 0;
            default:  printf("Illegal code\n");
        }
        printf("\n");
    }
}
