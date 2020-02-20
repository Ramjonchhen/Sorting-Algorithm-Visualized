#include <iostream>
#include <graphics.h>
#include <cstdlib>
#include <vector>
using namespace std;



int main()
{
    initwindow(1380,1200,"visualizing algorithm");

    // array for inputing numbers
    int n;
    cout<<"Enter how many elements you want to sort";
    cin>>n;
    vector <int> arr(n);
    cout<<"Enter the elements"<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    // points for the rectangel to draw
    int xStarting=300,yStarting=400,xEnd=330,yEnd=430,spacing=10;
    for(int i=0; arr[i]!='\0'; i++)
    {
            // first the y starting point is minimized to draw the blocks
            // in our case 1-block has height of 30
            yStarting=yEnd-(arr[i]*30);
            // for the end point this is for width of our box
            // we have choosen to take the width of the box as 50
            xEnd=xStarting+50;
            // drawing the rectangle
            rectangle(xStarting,yStarting,xEnd,yEnd);
            // filling the color of the boxes
            setfillstyle(1,rand());
            floodfill(xStarting+10,yEnd-10,15);
            // for spacing between the blocks we have choosen
            // the spacing betn the blocs as 10
            xStarting=xEnd+spacing;
    }
    getch();
    return 0;
}
