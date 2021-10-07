#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <sstream>
#include <algorithm> // for std::find
#include <iterator> // for std::begin, std::end

using namespace std;

const  string squares[10][10]={{"  ",""," A "," B "," C "," D "," E "," F "," G "," H "},
                    {"8"," "," ◼ "," ◻ "," ◼ "," ◻ "," ◼ "," ◻ "," ◼ "," ◻ "},
                    {"7"," "," ◻ "," ◼ "," ◻ "," ◼ "," ◻ "," ◼ "," ◻ "," ◼ "},
                    {"6"," "," ◼ "," ◻ "," ◼ "," ◻ "," ◼ "," ◻ "," ◼ "," ◻ "},
                    {"5"," "," ◻ "," ◼ "," ◻ "," ◼ "," ◻ "," ◼ "," ◻ "," ◼ "},
                    {"4"," "," ◼ "," ◻ "," ◼ "," ◻ "," ◼ "," ◻ "," ◼ "," ◻ "},
                    {"3"," "," ◻ "," ◼ "," ◻ "," ◼ "," ◻ "," ◼ "," ◻ "," ◼ "},
                    {"2"," "," ◼ "," ◻ "," ◼ "," ◻ "," ◼ "," ◻ "," ◼ "," ◻ "},
                    {"1"," "," ◻ "," ◼ "," ◻ "," ◼ "," ◻ "," ◼ "," ◻ "," ◼ "}};
const string black[5]={" ♙ "," ♘ "," ♖ "," ♗ "," ♕ "};
const string white[5]={" ♟︎ "," ♞ "," ♜ "," ♝ "," ♛ "};
void RenderBoard(string arr[10][10])
{
  int arr_length =sizeof(arr[0]) / sizeof(string);
  for(int i=0;i<arr_length;i++)
  {
    for(int j=0;j<arr_length;j++)
    { 
        SetConsoleOutputCP(CP_UTF8);
        cout<<arr[i][j];  
    }
    cout<<""<<endl;
  }
}
void WhiteMovement(string arr[10][10],int y,int x,int _x,int _y)
{
    auto figure=arr[y][x];
    arr[_y][_x]=figure;
    arr[y][x]=squares[y][x];   
}

void GetWhiteFigure(string arr[10][10],int y ,int x,int _x,int _y)
{
    
    auto figure=arr[y][x];
    if(figure==" ♜ ")
    {
        for(int i=x+1;i<10;i++)
        { 
            arr[y][i]=" X ";
        }
        for(int i=x-1;i>1;i--)
        {
            arr[y][i]=" X ";
        }
        for(int i=y+1;i<10;i++)
        {
            arr[y][i]=" X ";
        }
        for(int i=y-1;i>0;i--)
        {
            if(i==_y&&x==_x)
            {
                if((arr[i][x]==" ◻ "||arr[i][x]==" ◼ "))
                {
                    arr[i][x]=" X ";
                }
                else
                {
                    if(find(begin(black),end(black),arr[i][x]) == end(black)
                    &&find(begin(black),end(black),arr[i+1][x]) != end(black))
                    {
                        arr[i][x]=" X ";        
                    }
                    
                }
            }
            
           
            
        }
        //arr[y][x-1]=" X ";
        //arr[y-1][x]=" X ";
        //arr[y+1][x]=" X ";    

        cout<<"rook";
    }
    else if(figure==" ♞ ")
    {
        cout<<"knight";
    }
    else if(figure==" ♝ ")
    {
        if(arr[y-1][x+1]==" ◼ "||arr[y-1][x+1]==" ◻ ")
        {
            for(int i =1;i<10;i++)
            {
                if(x+i<=9)
                {
                    if(y-i==_y&&x+i==_x)
                    {
                        WhiteMovement(arr,y,x,_x,_y);
                    }
                    //arr[y-i][x+i]=" X "; 
                }
            }

        }
        if(arr[y-1][x-1]==" ◼ "||arr[y-1][x-1]==" ◻ ")
        {
            for(int i =10;i>0;i--)
            {
                if(x-i>=2)
                {
                    if(y-i==_y&&x-i==_x)
                    {
                        WhiteMovement(arr,y,x,_x,_y);
                    }
                    //arr[y-i][x-i]=" X ";
                }
            }

        }
        if(arr[y+1][x-1]==" ◼ "||arr[y+1][x-1]==" ◻ ")
        {
            for(int i =10;i>0;i--)
            {
                if(x-i>=2)
                {
                    if(y+i==_y&&x-i==_x)
                    {
                        WhiteMovement(arr,y,x,_x,_y);
                    }
                    //arr[y-i][x-i]=" X ";
                }
            }

        }
        if(arr[y+1][x+1]==" ◼ "||arr[y+1][x+1]==" ◻ ")
        {
            for(int i =1;i<10;i++)
            {
                if(x+i<=9)
                {
                    if(y+i==_y&&x+i==_x)
                    {
                        WhiteMovement(arr,y,x,_x,_y);
                    }
                    //arr[y-i][x+i]=" X "; 
                }
            }

        }
             
        cout<<"bishop"<<endl;
    }
    else if(figure==" ♛ ")
    {
        cout<<"queen";
    }
    else if(figure==" ♚ ")
    {
    cout<<"king";
    }
    else if(figure==" ♟︎ ")
    {
        if(_y==y-1)
        {
            if(x-1==_x||x+1==_x)
            {
                for(int a=0;a<5;a++)
                {
                    if( arr[_y][_x]==black[a])
                    {   
                        WhiteMovement(arr,y,x,_x,_y);
                    }
                }
            }
            if(arr[y-1][x]==" ◻ "|| arr[y-1][x]==" ◼ ")
            {
                WhiteMovement(arr,y,x,_x,_y);
            }
            
        }
        else if (_y==y-2&&y==7)
        {
            WhiteMovement(arr,y,x,_x,_y);
        }
        
        cout<<"pawn"<<endl;
    }

}
void WhiteTurn(string arr[10][10])
{
    int x;
    int y;
    int _x;
    int _y;
    char str[100];   
    cout << " Enter a position of figure: " <<endl;  
    cin.getline(str, 100); 
      
    char *ptr;
    ptr = strtok(str, " ");
    char* words[5];
    int i=0;
    while (ptr != NULL)  //read inputs
    { 
        words[i]=ptr;
        ptr = strtok (NULL, " , ");
        i++; 
    }
    for(int a=0;a<10;a++)
    {
        string str_(words[0]);
        str_=' '+str_+' '; 
        if(arr[0][a]==str_)
        {
            x=a;
        }
        str_="";
    }
    for(int k=0;k<10;k++)
    {   
        string str_(words[1]);
        if(arr[k][0]==str_)
        {
            y=k;
        }
        str_="";
    }
    for(int a=0;a<10;a++)
    {
        string str_(words[2]);
        str_=' '+str_+' '; 
        if(arr[0][a]==str_)
        {
            _x=a;
        }
        str_="";
    }
    for(int k=0;k<10;k++)
    {   
        string string_(words[3]);
        if(arr[k][0]==string_)
        {
            _y=k;
        }
        string_="";
    }
    //cout<<_x<<endl;
    //cout<<_y<<endl;
    //pos=atoi(words[2]);// char to int 
    GetWhiteFigure(arr,y,x,_x,_y);
    //system("cls");
    RenderBoard(arr);

       
}

int main()
{
    
  string arr[10][10]={{"  ",""," A "," B "," C "," D "," E "," F "," G "," H "},
                    {"8"," "," ♖ "," ♘ "," ♗ "," ♕ "," ♔ "," ♗ "," ♘ "," ♖ "},
                    {"7"," "," ♙ "," ♙ "," ♙ "," ♙ "," ♙ "," ♙ "," ♙ "," ♙ "},
                    {"6"," "," ◼ "," ◻ "," ◼ "," ◻ "," ◼ "," ◻ "," ◼ "," ◻ "},
                    {"5"," "," ◻ "," ◼ "," ◻ "," ◼ "," ◻ "," ◼ "," ◻ "," ◼ "},
                    {"4"," "," ◼ "," ◻ "," ◼ "," ♜ "," ◼ "," ◻ "," ◼ "," ◻ "},
                    {"3"," "," ◻ "," ◼ "," ◻ "," ◼ "," ◻ "," ◼ "," ◻ "," ◼ "},
                    {"2"," "," ♟︎ "," ♟︎ "," ♟︎ "," ♟︎ "," ♟︎ "," ♟︎ "," ♟︎ "," ♟︎ "},
                    {"1"," "," ♜ "," ♞ "," ♝ "," ♛ "," ♚ "," ♝ "," ♞ "," ♜ "}};
    RenderBoard(arr);
    while(true)
    {
    WhiteTurn(arr);
    }
    

}