// given {
#include <iostream>
#include <string>
using namespace std;

/*
 * Given the index of a application applicationIndex,
 * displays the corresponding entry from arrays
 * titles, authors and prices.
 * If applicationIndex is larger than applicationCount,
 * it displays "No application found"
 */
void displayApplication(int applicationIndex, string titles[], string authors[], double prices[], int applicationCount);

/*
* Iterates over the array comparing each
* entry with the first parameter.
* If found, it returns the index where it was found
* Otherwise it returns -1
*/
int searchApplicationsByTitle(string title, string titles[], int applicationCount);

/*
 * Iterates over the array comparing each
 * entry with the first parameter.
 * If found, it returns the index where it was found
 * Otherwise it returns -1
 */
int searchApplicationsByAuthor(string author, string authors[], int applicationCount);

/*
 * Iterates over the array comparing each
 * entry with the first parameter.
 * If found, it returns the index where it was found
 * Otherwise it returns -1
 */
int searchApplicationsByPrice(double price, double prices[], int applicationCount);

const int APPLICATION_COUNT = 10;

void main()
{
	string titles[] =
	{
		"Maplets", "Sky Guide", "Gaia GPS",
		"National Geographics", "NOAA Radar Pro", "Camp & RV",
		"San Francisco Travel Guide", "WorldMate Gold", "Phaidon Arch Travel Guide",
		"Wander Wheel"
	};
	string authors[] =
	{
		"Zaia Design", "Fith Star Labs", "Trail Behind",
		"Natgeo", "NOAA", "All Stays LLC",
		"City Notes", "WorldMate Inc", "Phaidon Press",
		"Wander LLC"
	};
	double prices[] =
	{
		2.99, 1.99, 19.99,
		9.99, 1.99, 9.99,
		1.99, 9.99, 14.99,
		0.99
	};

	displayApplication(3, titles, authors, prices, APPLICATION_COUNT);

	int index = searchApplicationsByTitle("NOAA Radar Pro", titles, APPLICATION_COUNT);
	displayApplication(index, titles, authors, prices, APPLICATION_COUNT);

	index = searchApplicationsByAuthor("City Notes", authors, APPLICATION_COUNT);
	displayApplication(index, titles, authors, prices, APPLICATION_COUNT);

	index = searchApplicationsByPrice(14.99, prices, APPLICATION_COUNT);
	displayApplication(index, titles, authors, prices, APPLICATION_COUNT);
}
/*
	Output:

	National Geographics, Natgeo, $9.99
	NOAA Radar Pro, NOAA, $1.99
	San Francisco Travel Guide, City Notes, $1.99
	Phaidon Arch Travel Guide, Phaidon Press, $14.99

*/
// } given
