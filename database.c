/*Lolelanji Simposya
 * database.h : A header file to share function prototype for database accesses
 */
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include "readline.h"
#include "item.h"
#include "database.h"
#include "page.h"
#define MAX_PARTS 100

/*
 * the definition of array variable to store items
 */
 Item items[MAX_PARTS];

/*
 * Integer variable to store the number of stored items
 */

int num_parts = 0;  /* the number of parts currently stored */

/*
 * Functions
 */

void insert(void);
void print(void);


int read_line(char str[], int n)
{
    int ch, i = 0;

    while(isspace(ch = getchar()))
        ;
    while(ch != '\n' && ch != EOF) {
        if(i < n)
            str[i++] = ch;
        ch = getchar();
    }
    str[i] = '\0';
    return i;
}


/* function for insertion of a new data item */

void insert(void)
{


    printf("Enter the name of item: ");
    read_line(items[num_parts].name, MAX_NAME_LENGTH);
    printf("Enter the category of item: ");
    read_line(items[num_parts].category, MAX_CATEGORY_LENGTH);
    printf("Enter x coordinate: ");
    scanf("%d", &items[num_parts].x);
    printf("Enter y coordinate: ");
    scanf("%d", &items[num_parts].y);
    num_parts++;
}



/* function for printing all data items */
void print(void)
{
    int i;
printf("Name                    Category            Position\n");
printf("===========================================================\n");
for(i=0; i<num_parts; i++)
  printf("%-30s %-20s(%2d,%2d)\n", items[i].name, items[i].category, items[i].x, items[i].y);
}




/* function for loading items from a file */
void load_items()
{
FILE *fp;
int x, y, i;
char name[512], category[512];
char file[512];
printf("Enter a file name:\n");
scanf("%s", file);
if( (fp = fopen(file, "r")) == NULL) {
printf("Can't open %s\n", file);
exit(EXIT_FAILURE);
}

while ( fscanf(fp, "%[^,],%[^,],%d,%d\n", &items[num_parts].name, &items[num_parts].category, &items[num_parts].x, &items[num_parts].y) == 4){
num_parts++;

}



fclose(fp);

printf("Successfully loaded %s\n", file);


}

/* function for saving items into a file */
   void save_items()
   {
      FILE *fp;
      int i;
      char file[512];
      printf("Please enter a file name:\n");
      scanf("%s", file);

      fp = fopen(file, "w");
      if (fp == NULL) {
         printf("Error.\n");
      }

      /* write to the file */
      for (i=0; i<num_parts; i++){
    fprintf(fp, "%s,%s,%d,%d\n", items[i].name, items[i].category, items[i].x, items[i].y);

      }
      printf("Successfully copied.\n");
      /* close the file */
      fclose(fp);

   }

/* function for finding items based on name */

void find_items_by_name(){

 char item_name[512];
 int num_result = 0;
 int i;
 Item found_part[num_parts];
 printf("Please enter the name of the item: ");
 read_line(item_name, 512);

 for(i=0;i<num_parts;i++){

    if(strcmp(items[i].name, item_name)==0){
      strcpy(found_part[num_result].category,items[i].category);
      strcpy(found_part[num_result].name,items[i].name);
      found_part[num_result].x=items[i].x;
      found_part[num_result].y=items[i].y;
      num_result++;
    }



    }
printf("Successfully found the %s\n", item_name);
print_page_sample(found_part, num_result);
}
/* function for finding items based on category */

void find_items_by_category(){

 char category_name[512];
 int num_result = 0;
 int i;
 Item found_part[num_parts];
 printf("Please enter the category of the item: ");
 read_line(category_name, 512);

 for(i=0;i<num_parts;i++){
    if(strcmp(items[i].category,category_name)==0){
      strcpy(found_part[num_result].category,items[i].category);
      strcpy(found_part[num_result].name,items[i].name);
      found_part[num_result].x=items[i].x;
      found_part[num_result].y=items[i].y;
      num_result++;
    }



    }

print_page_sample(found_part, num_result);
}



/* function for finding items based on range */

void find_items_by_range(){

 int num_result = 0;
 int i;
 int x;
 int y;
 int threshold;
 Item found_part[num_parts];
 printf("This function will allow you to find the distance between your position and a given location on campus.\n");
 printf("Please enter your current location.\n");
 printf("Enter the x coordinate (max 32): \n");
 scanf("%d", &x);
  if(x > MAX_X_COORDINATE){

     printf("Error! Please input a valid position.\n");

 };

 printf("Enter the y coordinate (max 32): \n");
 scanf("%d", &y);
 if(y > MAX_X_COORDINATE){

     printf("Error! Please input a valid position.\n");

 };
 printf("Your position is currently:(%d,%d) \n", x,y);
 printf("Enter the distance threshold (m): \n");
 scanf("%d", &threshold);

 for(i=0;i<num_parts;i++){

    if(40*sqrt(pow(items[i].x-x,2)+pow(items[i].y-y,2))<=threshold){
      strcpy(found_part[num_result].category,items[i].category);
      strcpy(found_part[num_result].name,items[i].name);
      found_part[num_result].x=items[i].x;
      found_part[num_result].y=items[i].y;
      num_result++;
    }

    }

print_page_sample(found_part, num_result);

}

/* function for nearest neighbor items */

void find_nearest_neighbor(){

 int num_result = 0;
 int i;
 int x;
 int y;
 int j;
 int n;
 int smallest;
 int d1 = 40*(sqrt(pow(items[i].x-x,2)+pow(items[i].y-y,2)));
 int A[512];
 Item found_part[num_parts];
 printf("This function will allow you to find the closest item to your location.\n");
 printf("Please enter your current location.\n");
 printf("Enter the x coordinate (max 32): \n");
 scanf("%d", &x);
  if(x > MAX_X_COORDINATE){

     printf("Error! Please input a valid position.\n");

 };

 printf("Enter the y coordinate (max 32): \n");
 scanf("%d", &y);
 if(y > MAX_X_COORDINATE){

     printf("Error! Please input a valid position.\n");
 };

 printf("Your position is currently:(%d,%d) \n", x,y);



 for(i=0;i<num_parts;i++){

 A[i] = 40*(sqrt(pow(items[i].x-x,2)+pow(items[i].y-y,2)));


    }

      smallest = A[0];

   for (i = 0; i < num_parts; i++) {
      if (A[i] < smallest) {
         smallest = A[i];
      }
   }


 for(i=0;i<num_parts;i++){

    if(40*sqrt(pow(items[i].x-x,2)+pow(items[i].y-y,2)) == smallest){
      strcpy(found_part[num_result].category,items[i].category);
      strcpy(found_part[num_result].name,items[i].name);
      found_part[num_result].x=items[i].x;
      found_part[num_result].y=items[i].y;
      num_result++;
    }

    }

printf("\nNearest item is : %s.\n",found_part[0].name);
print_page_sample(found_part, num_result);

}

/* function for finding the estimated time taken */
void time() {
 float t1;
 float t2;
 char item_name[512];
 int num_result = 0;
 int i;
 int x;
 int y;
 float k;
 float l;
 Item found_part[num_parts];
 float speed1 = 1.38889;
 float speed2 = 4.305556;
 printf("This function will allow you to find the estimated time it will take you to get to your destination on campus, assuming you are walking or riding a bicycle.\n");

 printf("Please enter your current location.\n");
 printf("Enter the x coordinate (max 32): \n");
 scanf("%d", &x);
  if(x > MAX_X_COORDINATE){

     printf("Error! Please input a valid position.\n");

 };

 printf("Enter the y coordinate (max 32): \n");
 scanf("%d", &y);
 if(y > MAX_X_COORDINATE){

     printf("Error! Please input a valid position.\n");

 };
 printf("Your position is currently:(%d,%d) \n", x,y);

 printf("Enter the name of the item you wish to travel to: \n");
 read_line(item_name, 512);
 for(i=0;i<num_parts;i++){

    if(strcmp(items[i].name, item_name)==0){
      strcpy(found_part[num_result].category,items[i].category);
      strcpy(found_part[num_result].name,items[i].name);
      found_part[num_result].x=items[i].x;
      found_part[num_result].y=items[i].y;
      num_result++;
    }


    }

printf("Successfully found the %s\n", found_part[0].name);
float distance = 40*(sqrt(pow(found_part[0].x-x,2)+pow(found_part[0].y-y,2)));
t1 = (distance / speed1);
t2 = (distance / speed2);
k = t1 / 60;
l = t2 / 60;

printf("It will take you approximately %f minutes walking and %f minutes by bicycle.\n", k,l);

};






