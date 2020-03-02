#include <iostream>
#include <graphics.h>
#include <cstdlib>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

// global variables
int no_of_elements,arr[10],color_value[10];
void take_input()
{
    int i;
    cout<<"\n Enter the no of elements to sort: ";
    cin>>no_of_elements;
    cout<<"Enter the elements"<<endl;
    for(i=0; i<no_of_elements; i++)
    {
        cin>>arr[i];
    }
}

void display_array()
{
    int i;
    cout<<"\n The array elements are"<<endl;
    for (i=0; i<no_of_elements; i++)
    {
        cout<<arr[i];
    }
}

void display_blocks()
{
    cleardevice();
    char value[2];
 // drawing the blocks
    int xStarting=300,yStarting=400,xEnd=330,yEnd=430,spacing=10;
    for(int i=0; i<no_of_elements; i++)
    {
            // first the y starting point is minimized to draw the blocks
            // in our case 1-block has height of 30
            yStarting=yEnd-(arr[i]*25);
            // for the end point this is for width of our box
            // we have choosen to take the width of the box as 50
            xEnd=xStarting+40;
            // drawing the rectangle
            rectangle(xStarting,yStarting,xEnd,yEnd);
            // filling the color of the boxes
            color_value[i]=rand();
            setfillstyle(1,color_value[i]);
            floodfill(xStarting+10,yEnd-10,15);
            // for spacing between the blocks we have choosen
            // the spacing betn the blocs as 10
            sprintf(value,"%d",arr[i]);
            outtextxy(xStarting+15,yEnd-20,value);
            xStarting=xEnd+spacing;
    }
}



int main()
{
    initwindow(1380,1200,"visualizing algorithm");
    // taking the input for the array
    take_input();
    display_blocks();

    getch();

    return 0;
}
