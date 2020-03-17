// selection sort animation try

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

// function to display the blocks inttially
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


void swap_blocks(int x,int y)
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
    // loop for animating that swapping two blocks is moving
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
    delay(150);
  }
}

void move_block(int block_no,int direction)
{
    int move_block[9];
    cleardevice();
    for (int inc=0; inc<9; inc++)
    {
        int temp=inc;
        if (temp==block_no)
        {
            move_block[inc]=1;
        }

        else{
            move_block[inc]=0;
        }
    }
    // loop for animating that swapping two blocks is moving
  for(int k=0; k<=20; k++)
  {
      cleardevice();
      for(int i=0; i<no_of_elements; i++)
    {
        yBlockEnd[i]=yBase+move_block[i]*3*k*direction;
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
    delay(60);
  }
}



int main()
{
     int gd=DETECT,gm;
     initgraph(&gd,&gm,"C:TURBOC3\\BGI");
     int page=0;


     int minimum_number,minimum_location;
    cout<<"Enter the no of elements in the array: ";
    cin>>no_of_elements;
    for(int i=0; i<no_of_elements; i++)
    {
        cin>>values[i];
    }
    while(1)
    {
        setactivepage(page);
        setvisualpage(1-page);
        cleardevice();

        display_blocks(values);

    // now doing the sort
    for(int i=0; i<no_of_elements-1; i++ )
    {
        minimum_number=values[i];
        minimum_location=i;
        // moving the blocks form ith block to minimum
        for(int j=i; j<no_of_elements; j++)
        {
            move_block(j,1);
        }

        // checking the minimum
        for(int inner=i; inner<no_of_elements; inner++)
        {
            if( values[inner]< minimum_number )
            {
                minimum_number=values[inner];
                minimum_location=inner;
            }
        }

        // displaying the minimum

        display_blocks(values);
        outtextxy( xBlockStarting[minimum_location],yBlockEnd[minimum_location]+5,"MIN");
                  getch();

        if(minimum_location!=i)
        {
            swap_blocks(i,minimum_location);
        }
        display_blocks(values);

        int temp=values[i];
        values[i]=values[minimum_location];
        values[minimum_location]=temp;

        display_blocks(values);

        page=1-page;
    }

    }

    getch();
    return 0;
}
