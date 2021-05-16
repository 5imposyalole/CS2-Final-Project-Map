#include "item.h"
#include <stdio.h>
#include <stdlib.h>


#define RESULT_PAGE "result.html"

/*A function to extract the coordinates of the found items*/

 int find_part(Item coordinate[], int num_parts, int i, int j)
{
    int a;
    for(a =0; a < num_parts; a++)
        if(coordinate[a].x == i && coordinate[a].y == j)
            return a;
    return -1;
}

/* a function to generate HTML file that contains query results */
void print_page_sample(Item result[], int size)
{
	FILE *f;
	int i,j,k;

	if( (f = fopen(RESULT_PAGE, "w")) == NULL) {
		printf("cannot open file %s.", RESULT_PAGE);
		return;
	}

	/* printing HTML header */
	fprintf(f, "<html>\n");
	fprintf(f, "<head>\n");
	fprintf(f, "<title>result page</title>\n");
	fprintf(f, "<style type=\"text/css\">\n");
	fprintf(f, "table { background-image: url(\"nagoya.gif\"); }\n");
	fprintf(f, "td { padding: 0px; border: 1px; width: 16px; height: 14px; font-size: 10px; text-aligh: center; color: #ff00ff; } \n");
	fprintf(f, "</style>\n");
	fprintf(f, "</head>\n");
	fprintf(f, "<body>\n");

	/* printing HTML table */
	fprintf(f, "<table>\n");
	for(i = 0; i < MAX_X_COORDINATE; i++){

		/* printing table row */
		fprintf(f, "<tr>\n");
		for(j = 0; j < MAX_Y_COORDINATE; j++){

			/* printing table column */
			fprintf(f,"<td>");

			/* printing item label corresponding to X=j, Y=i */

				/* PLEASE REPLACE HERE */
int s = find_part(result, size, j, i);
    if(s >= 0){
       fprintf(f, "%d", s+1);
    }
				/* PLEASE REPLACE HERE */

			fprintf(f,"</td>\n");
		}
		fprintf(f, "</tr>\n");
	}
	fprintf(f, "</table>\n");

	/* printing HTML list */
	fprintf(f, "<ul>\n");

	/* printing list items */

		/* PLEASE REPLACE HERE */
for(i=0;i<size;i++){
    fprintf(f, "<li>%d : %s</li>\n", i+1,result[i].name);
  } /* item1 */

		/* PLEASE REPLACE HERE */

	fprintf(f, "</ul>\n");


	fprintf(f, "</body>\n");
	fprintf(f, "</html>\n");

	fclose(f);

	printf("Please refer to the map found in the following file: %s.\n", RESULT_PAGE);
	return;
}



