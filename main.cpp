#include <iostream>
#include <graphics.h>
#include <stdio.h>
#include <windows.h>

using namespace std;

// global variables
int values[9];
int no_of_elements;
    int xBlockStarting[9];
    int yBlockStarting[9];
    int xBlockEnd[9];
    int yBlockEnd[9];
    int yBase=300;
    int color[9]={0,1,2,3,4,5,6,9,10};
    char value[2];

void display_blocks(int values[])
{
    cleardevice();
    xBlockStarting[0]=70;

     for(int i=0; i<no_of_elements; i++)
    {
        yBlockEnd[i]=yBase;
            int k=i;
        yBlockStarting[i]=yBase-(20*values[i]);
        xBlockEnd[i]=xBlockStarting[i]+40;
        rectangle(xBlockStarting[i],yBlockStarting[i],xBlockEnd[i],yBlockEnd[i]);
        setfillstyle(1,color[i]);
            floodfill(xBlockStarting[i]+10,yBlockEnd[i]-10,15);
            // for spacing between the blocks we have choosen
            // the spacing betn the blocs as 10
            sprintf(value,"%d",values[i]);
            outtextxy(xBlockStarting[i]+15,yBlockEnd[i]-20,value);
        xBlockStarting[k+1]=xBlockEnd[i]+10;
    }

}

void swap_blocks(int x,int y,int balance)
{
    int move_block[9];
    cleardevice();
    for (int inc=0; inc<9; inc++)
    {
        int temp=inc;
        if (temp==x || temp==y)
        {
            move_block[inc]=1;
        }

        else{
            move_block[inc]=0;
        }
    }
  for(int k=0; k<=15; k++)
  {
      cleardevice();
      for(int i=0; i<no_of_elements; i++)
    {
        yBlockEnd[i]=yBase-move_block[i]*3*k;
            int j=i;
        yBlockStarting[i]=yBlockEnd[i]-(20*values[i]);
        xBlockEnd[i]=xBlockStarting[i]+40;
        rectangle(xBlockStarting[i],yBlockStarting[i],xBlockEnd[i],yBlockEnd[i]);
        setfillstyle(1,color[i]);
            floodfill(xBlockStarting[i]+10,yBlockEnd[i]-10,15);
            // for spacing between the blocks we have choosen
            // the spacing betn the blocs as 10
            sprintf(value,"%d",values[i]);
            outtextxy(xBlockStarting[i]+15,yBlockEnd[i]-20-move_block[i]*i,value);
        xBlockStarting[j+1]=xBlockEnd[i]+10;
    }

    // displaying the balance variable
    line(xBlockStarting[balance],305,xBlockStarting[balance],320);
            line(xBlockEnd[balance],305,xBlockEnd[balance],320);
            line( ((xBlockStarting[balance]+xBlockEnd[balance])/2),320,((xBlockStarting[balance]+xBlockEnd[balance])/2),335 );
            line(xBlockEnd[balance],320,xBlockStarting[balance],320);

            // drawing the 2nd Block traju
            line(xBlockStarting[balance+1],305,xBlockStarting[balance+1],320);
            line(xBlockEnd[balance+1],305,xBlockEnd[balance+1],320);
            line( ((xBlockStarting[balance+1]+xBlockEnd[balance+1])/2),320,((xBlockStarting[balance+1]+xBlockEnd[balance+1])/2),335 );
            line(xBlockEnd[balance+1],320,xBlockStarting[balance+1],320);

            line(((xBlockStarting[balance+1]+xBlockEnd[balance+1])/2),335,((xBlockStarting[balance]+xBlockEnd[balance])/2),335);

    delay(150);
  }
}



int main()
{
    initwindow(1000,1000,"graphics");
    cout<<"Enter the no of elements in the array: ";
    cin>>no_of_elements;
    for(int i=0; i<no_of_elements; i++)
    {
        cin>>values[i];
    }
    display_blocks(values);

    delay(600);
    // performing the bubble sort
    int temp;
    for(int i=0; i<no_of_elements; i++)
    {
        for(int j=0; j<no_of_elements-1-i; j++)
        {
           if(values[j]>values[j+1])
           {
               // swapping the values of the array
               int calltemp=j;
               swap_blocks(calltemp,calltemp+1,j);
               temp=values[j];
               values[j]=values[j+1];
               values[j+1]=temp;
               // swapping the values of the color to maintain the color consistency
               int temp_color;
               temp_color=color[j];
               color[j]=color[j+1];
               color[j+1]=temp_color;
               display_blocks(values);
           }
           // if nothing to swap displaying the message
        else{
                // display the  rectangular blocks
    cleardevice();
    xBlockStarting[0]=70;

     for(int i=0; i<no_of_elements; i++)
    {
        yBlockEnd[i]=yBase;
            int k=i;
        yBlockStarting[i]=yBase-(20*values[i]);
        xBlockEnd[i]=xBlockStarting[i]+40;
        rectangle(xBlockStarting[i],yBlockStarting[i],xBlockEnd[i],yBlockEnd[i]);
        setfillstyle(1,color[i]);
            floodfill(xBlockStarting[i]+10,yBlockEnd[i]-10,15);
            // for spacing between the blocks we have choosen
            // the spacing betn the blocs as 10
            sprintf(value,"%d",values[i]);
            outtextxy(xBlockStarting[i]+15,yBlockEnd[i]-20,value);
        xBlockStarting[k+1]=xBlockEnd[i]+10;
    }
    // drawing the 1st block traju
            // drawing the line from the starting of 1st block to some narrow
            line(xBlockStarting[j],305,xBlockStarting[j],320);
            line(xBlockEnd[j],305,xBlockEnd[j],320);
            line( ((xBlockStarting[j]+xBlockEnd[j])/2),320,((xBlockStarting[j]+xBlockEnd[j])/2),335 );
            line(xBlockEnd[j],320,xBlockStarting[j],320);

            // drawing the 2nd Block traju
            line(xBlockStarting[j+1],305,xBlockStarting[j+1],320);
            line(xBlockEnd[j+1],305,xBlockEnd[j+1],320);
            line( ((xBlockStarting[j+1]+xBlockEnd[j+1])/2),320,((xBlockStarting[j+1]+xBlockEnd[j+1])/2),335 );
            line(xBlockEnd[j+1],320,xBlockStarting[j+1],320);

            line(((xBlockStarting[j+1]+xBlockEnd[j+1])/2),335,((xBlockStarting[j]+xBlockEnd[j])/2),335);
            outtextxy(200,340,"Can't swap");
            delay(2500);

        }
        }

        // adding the grey color to the sorted blocks
        color[no_of_elements-i-1]=8;
           display_blocks(values);
    }



getch();
    return 0;
}
