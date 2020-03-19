#include <iostream>
#include <graphics.h>
#include <cstdlib>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

// global variables
int values[9];
int no_of_elements;
    int xBlockStarting[9];
    int yBlockStarting[9];
    int xBlockEnd[9];
    int yBlockEnd[9];
    int yBase=600;
    int color[9]={0,1,2,3,4,5,6,9,10};
    char value[2];

    // heights and width of blocks
    int height_of_block=50,width_of_block=60;

// function to take input for the array
void take_input()
{
    int i;
    cout<<endl<<"Enter the no of elements to sort: "<<endl;
    cin>>no_of_elements;
    cout<<endl<<"Enter the elements of the array to sort:"<<endl;
    for(i=0; i<no_of_elements; i++)
    {
        cin>>values[i];
    }
}

// function to display the rectangular blocks
void display_blocks(int values[])
{
    cleardevice();
    xBlockStarting[0]=400;

     for(int i=0; i<no_of_elements; i++)
    {
        yBlockEnd[i]=yBase;
            int k=i;
        yBlockStarting[i]=yBase-(50*values[i]);
        xBlockEnd[i]=xBlockStarting[i]+60;
        rectangle(xBlockStarting[i],yBlockStarting[i],xBlockEnd[i],yBlockEnd[i]);
        setfillstyle(1,color[i]);
            floodfill(xBlockStarting[i]+10,yBlockEnd[i]-10,15);
            // for spacing between the blocks we have choosen
            // the spacing betn the blocs as 10
            sprintf(value,"%d",values[i]);
            outtextxy(((xBlockStarting[i]+xBlockEnd[i])/2)-5,yBlockEnd[i]-30,value);
        xBlockStarting[k+1]=xBlockEnd[i]+10;
    }

}

// balancer code for bu
void taraju(int x)
{
    // displaying the balance variable
   line(xBlockStarting[x],yBase+5,xBlockStarting[x],yBase+20);
            line(xBlockEnd[x],yBase+5,xBlockEnd[x],yBase+20);
            line( ((xBlockStarting[x]+xBlockEnd[x])/2),yBase+20,((xBlockStarting[x]+xBlockEnd[x])/2),yBase+35 );
            line(xBlockEnd[x],yBase+20,xBlockStarting[x],yBase+20);

            // drawing the 2nd Block traxu
            line(xBlockStarting[x+1],yBase+5,xBlockStarting[x+1],yBase+20);
            line(xBlockEnd[x+1],yBase+5,xBlockEnd[x+1],yBase+20);
            line( ((xBlockStarting[x+1]+xBlockEnd[x+1])/2),yBase+20,((xBlockStarting[x+1]+xBlockEnd[x+1])/2),yBase+35 );
            line(xBlockEnd[x+1],yBase+20,xBlockStarting[x+1],yBase+20);

            line(((xBlockStarting[x+1]+xBlockEnd[x+1])/2),yBase+35,((xBlockStarting[x]+xBlockEnd[x])/2),yBase+35);
}


//swapping blocks function for all
// z is for taraju direction + go up -go down
 void swap_blocks(int x,int y,int z,int direction)
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
        yBlockEnd[i]=yBase-direction*move_block[i]*3*k;
            int j=i;
        yBlockStarting[i]=yBlockEnd[i]-(height_of_block*values[i]);
        xBlockEnd[i]=xBlockStarting[i]+width_of_block;
        rectangle(xBlockStarting[i],yBlockStarting[i],xBlockEnd[i],yBlockEnd[i]);
        setfillstyle(1,color[i]);
            floodfill(xBlockStarting[i]+10,yBlockEnd[i]-10,15);
            // for spacing between the blocks we have choosen
            // the spacing betn the blocs as 10
            sprintf(value,"%d",values[i]);
            outtextxy(((xBlockStarting[i]+xBlockEnd[i])/2)-5,yBlockEnd[i]-30,value);
        xBlockStarting[j+1]=xBlockEnd[i]+10;
    }
    // if z is 1 show taraju else not
    if(z==1)
    {
        taraju(x);
    }

    delay(150);
  }
}

int main()
{
    int choice,choice_of_sorting;
    initwindow(1380,1200,"visualizing algorithm");
    settextstyle(8,0,3);
    while(1)
    {
        system("CLS");
        cout<<"------------------------------------WELCOME TO THE WORLD OF VISUALIZING SORTING ALGORITHM-------------------------------"<<endl<<endl;
    cout<<"---------------------------------------------------------MENU-----------------------------------------------------------"<<endl<<endl;
    cout<<"------------------------------------PRESS 1 FOR VISUALIZING THE ALGORITHMS----------------------------------------------"<<endl<<endl;
    cout<<"------------------------------------PRESS 2 FOR BATTLE OF THE ALGORITHMS------------------------------------------------"<<endl<<endl;
    cout<<"----------------------------------------------ENTER YOUR CHOICE--------------------------------------------------------"<<endl<<endl;
    cin>>choice;
    // reseting the color after the sorting is done
    color[0]=0; color[1]=1; color[2]=2; color[3]=3; color[4]=4; color[5]=5; color[6]=6; color[7]=9; color[8]=10;
    switch(choice)
    {
        case 1:
        system("CLS");
    cout<<"-----------------------------------------LET'S VISUALIZE THE SORTING ALGORITHM-----------------------------------------"<<endl<<endl;
    cout<<"----------------------------------------------PRESS 1 FOR BUBBLE SORT--------------------------------------------------"<<endl<<endl;
    cout<<"----------------------------------------------PRESS 2 FOR SELECTION SORT-----------------------------------------------"<<endl<<endl;
    cout<<"----------------------------------------------PRESS 3 FOR INSERTION SORT------------------------------------------------"<<endl<<endl;
    cout<<"----------------------------------------------PRESS 4 FOR QUICK SORT----------------------------------------------------"<<endl<<endl;
    cout<<"----------------------------------------------ENTER YOUR CHOICE---------------------------------------------------------"<<endl<<endl;
    cin>>choice_of_sorting;

    switch(choice_of_sorting)
    {
        // if 1 doing the bubble sort
        case 1:
        take_input();
        display_blocks(values);
        // displaying the sorting name in the top
        getch();
        int temp;

            for(int i=0; i<no_of_elements; i++)
                {

                    for(int j=0; j<no_of_elements-1-i; j++)
                        {
                            if(values[j]>values[j+1])
                                {
                                //showing the animation of swap
                                    swap_blocks(j,j+1,1,1);
                                    // swapping the value of the array
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
                                display_blocks(values);
                                // drawing the 1st block traju
                                // drawing the line from the starting of 1st block to some narrow
                                taraju(j);
                                outtextxy((xBlockStarting[j+1]+xBlockEnd[j+1])/2,yBase+40,"Can't swap");
                                delay(2000);

                                }


                            }

                        // adding the grey color to the sorted blocks
                        color[no_of_elements-i-1]=8;
                           display_blocks(values);
                        }
                        outtextxy(xBlockStarting[0]+10,yBase+40,"SORTING COMPLETED");
                    break;

        // now sorting for the selection sort

        case 2:
            int minimum_number;
            int minimum_location;
            take_input();
        display_blocks(values);
        // taking enter before starting the sort
        getch();
        // now doing the sorting

        for(int i=0; i<no_of_elements-1; i++ )
    {
        minimum_number=values[i];
        minimum_location=i;
        // moving the blocks form ith block to minimum
        for(int j=i; j<no_of_elements; j++)
        {
            swap_blocks(j,no_of_elements,0,-1);
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
        // delayiing time showing and delaying before the swap
        delay(1500);

        if(minimum_location!=i)
        {
            swap_blocks(i,minimum_location,0,1);
        }
        display_blocks(values);

        int temp=values[i];
        values[i]=values[minimum_location];
        values[minimum_location]=temp;

        display_blocks(values);

        // adding the grey color to the sorted blocks
                        color[i]=8;
                           display_blocks(values);

    }
        // coloring the last element  with grey color
        color[no_of_elements-1]=8;
        display_blocks(values);
        outtextxy(xBlockStarting[0]+10,yBase+40,"SORTING COMPLETED");
        break;

    }// 2nd switch ending


}// 1st switch ending

    }// while loop 1 ending
return 0;
getch();
    }
