#include <iostream>
using namespace std;

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>



/*\
* Professor Daniel F. Vukelich, Sr.
* Operating Systems
* MCS554AH2
* Fall 2014
* Rivier University
\*/

// Fix me! //


void m_alloc(int arg, int *ptr) {


	// allocate storage for an integer
	ptr = (int *)malloc(sizeof(int));

	// assign the newly allocated space the parameter
	// passed in arg
	*ptr = arg;
}

void m_alloc2(int arg, int **ptr) {


	// allocate storage for an integer
	*ptr = (int *)malloc(sizeof(int));

	// assign the newly allocated space the parameter
	// passed in arg
	**ptr = arg;
}

int main(int argc, char *argv[]) {

	int * ip = NULL;

	cout << ip << endl;
	cout << &ip << endl;

//	m_alloc(3, ip);  // allocate and assign
	m_alloc2(3, &ip);  // allocate and assign
	printf("Allocated: %d\n", *ip);  // print it out

}

