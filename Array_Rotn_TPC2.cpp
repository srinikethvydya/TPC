#include <conio.h>
#include <stdio.h>
#include <iostream>
using namespace std;

/**
 * @brief when we left rotate a list by 'r' then 
 *          in the resulting list the first 'n-r' elements ('n'
 *          is size) elements will be perfect but the next 'r'
 *          elements will be left rotated by 'n-r', so rotate
 *          only these elements to fix the disorder
 *          (recursively).
 */

/**
* consider a list of size 'n', if we left rotate it by 'r' then 
*   we need to rotate the resulting list 'n-r' left
*   to bring it to original form.
*	
*   If we have to rotate left/right a list by 'r' then we can
*   conversly rotate it right/left by 'n-r'.
*
*/
void LeftShift(int pArr[], int pSize, int pRotSize)
{
		int i=0, temp;

	for (i=pRotSize;i<pSize;i++){

		temp = pArr[i];
		pArr[i] = pArr[i-pRotSize];
		pArr[i-pRotSize] = temp;
	}
}

void RotateArr(int pArr[], int pSize, int pRotSize)
{
	if (pRotSize % pSize == 0)
        return;
    LeftShift(pArr, pSize, pRotSize);
    RotateArr(pArr+pSize-pRotSize, pRotSize, pRotSize - (pSize-pRotSize) % pRotSize);
}

void PrintArray(int pArr[], int pSize)
{
	for (int i=0; i<pSize; i++)
		cout<<pArr[i]<<"->";

	cout<<"\b\b  \n";
}

int main()
{
        int *   arr;
        int     size;
        int     rotsize;
        char    l;
    /**
     * @expected input form 
     *  
     * n[size of arrary] r[rotationsize] l/r [or L/R for left/right] 
     * a1 a2 a3 .. an [array] 
     *  
     * @output 
     * The Rotated array is : [new line]
     * ar .. an a1 a2 a3 
     */
    cin>>size;

    if (size <= 0) {

        return 0;
    }
    cin>>rotsize;
    cin>>l;

    arr = new int[size];

    for (int i=0; i<size; i++) {

        cin>>arr[i];
    }

    if (l == 'L' || l == 'l') {
        RotateArr(arr, size, rotsize % size);
    } else{
        RotateArr(arr, size, size - size % rotsize);
    }

    cout<<"the Rotated array is :\n";

	PrintArray(arr, size);

	getch();

    delete []arr;

    return 0;
}
