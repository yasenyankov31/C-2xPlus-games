#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <sstream>
#include <algorithm> // for std::find
#include <iterator> // for std::begin, std::end

using namespace std;

bool WhiteKingMoved=false;
bool LeftRook=false;
bool RightRook=false;
int checkFigureX=0;
int checkFigureY=0;

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
const string boxes[2]={" ◼ "," ◻ "};

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

void LeftRookMoved(string arr[10][10])
{
    for (int r = 0; r < 10; r++)
    {
        for (int c = 0; c < 10; c++)
        {
            if (arr[8][2] != " ♜ ")
            {
                LeftRook=true;
            }
            else
            {
                LeftRook=false;
            }
        }
    }

}

void RightRookMoved(string arr[10][10])
{
    for (int r = 0; r < 10; r++)
    {
        for (int c = 0; c < 10; c++)
        {
            if (arr[8][9] != " ♜ ")
            {
                RightRook=true;
            }
            else
            {
                RightRook=false;
            }
        }
    }
}

bool PawnChecks(string arr[10][10],int x,int y)
{
    bool a=false;
    if(y-1>0&&x+1<9)
    {
        if(arr[y-1][x+1]==" ♙ ")
        {
            checkFigureX=x+1;
            checkFigureY=y-1;
            a=true;
        }
    }
    else if(y-1>0&&x-1>1)
    {
        if(arr[y-1][x-1]==" ♙ ")
        {
            checkFigureX=x-1;
            checkFigureY=y-1;
            a=true;
        }
    }

    return a;

}

bool KnightChecks(string arr[10][10],int x,int y)
{
    bool a =false;
    int pos[8][2]={{y-2,x-1},{y-2,x+1},
                   {y-1,x-2},{y-1,x+2},
                   {y+2,x-1},{y+2,x+1},
                   {y+1,x-2},{y+1,x+2},
                   };

    for(int i=0;i<8;i++)
    {
        //cout<<arr[pos[i][0]][pos[i][1]]<<endl;
        //cout<<pos[i][0]<<" "<<pos[i][1]<<endl;
        if(pos[i][0]>0&&pos[i][0]<9&&pos[i][1]>1&&pos[i][1]<10&&arr[pos[i][0]][pos[i][1]]==" ♘ ")
        {
            checkFigureX=pos[i][1];
            checkFigureY=pos[i][0];
            a=true;      
        }
        
    }
    return a;
}

bool StraightChecks(string arr[10][10],int x,int y)
{
    //backward
    for(int i=y-1;i>0;i--)
    {
        if(arr[i][x]!=" ◻ "&& arr[i][x]!=" ◼ ")
        {
            if(arr[i][x]==" ♖ "||arr[i][x]==" ♕ ")
            {
                checkFigureX=x;
                checkFigureY=i;
                return true;
            }
            else if(find(begin(white),end(white),arr[i][x]) != end(white)||
            find(begin(black),end(black),arr[i][x]) != end(black))
            {
                break;
            }
        }
        //cout<<sub_arr[i]<<endl;
    }
    //forward
    for(int i=y+1;i<10;i++)
    {
        if(arr[i][x]!=" ◻ "&& arr[i][x]!=" ◼ ")
        {
            if(arr[i][x]==" ♖ "||arr[i][x]==" ♕ ")
            {
                checkFigureX=x;
                checkFigureY=i;
                return true;
            }
            else if(find(begin(white),end(white),arr[i][x]) != end(white)||
            find(begin(black),end(black),arr[i][x]) != end(black))
            {
                break;
            }
        }
        //cout<<sub_arr[i]<<endl;
    }
    //left
    for(int i=x-1;i>1;i--)
    {
        if(arr[y][i]!=" ◻ "&& arr[y][i]!=" ◼ ")
        { 
            if(arr[y][i]==" ♖ "||arr[y][i]==" ♕ ")
            {
                checkFigureX=i;
                checkFigureY=y;
                return true;
            }
            else if(find(begin(white),end(white),arr[y][i]) != end(white)||
            find(begin(black),end(black),arr[y][i]) != end(black))
            {
                break;
            }
            
        }
    }
    //right
    for(int i=x+1;i<10;i++)
    {
        if(arr[y][i]!=" ◻ "&& arr[y][i]!=" ◼ ")
        {  
            if(arr[y][i]==" ♖ "||arr[y][i]==" ♕ ")
            {
                checkFigureX=i;
                checkFigureY=y;
                return true;
            }
            else if(find(begin(white),end(white),arr[y][i]) != end(white)||
            find(begin(black),end(black),arr[y][i]) != end(black))
            {
                break;
            }
        }
    }

    return false;
}

bool DiagonalsChecks(string arr[10][10],int x,int y)
{
    int a =1;
    //backward right
    for(int i=y+1;i<9;i++)
    {
        if(arr[i][x+a]!=" ◻ "&& arr[i][x+a]!=" ◼ ")
        {

            if(arr[i][x+a]==" ♗ "||arr[i][x+a]==" ♕ ")
            {
                checkFigureX=x+a;
                checkFigureY=i;
                return true;
            }
            else if(find(begin(white),end(white),arr[i][x+a]) != end(white)||
            find(begin(black),end(black),arr[i][x+a]) != end(black))
            {
                break;
            } 
        }
        a++;
    }
    //reset
    a=1;
    //forward left
    for(int i=x-1;i>1;i--)
    {
        if(arr[y-a][i]!=" ◻ "&& arr[y-a][i]!=" ◼ ")
        {
            if(arr[y-a][i]==" ♗ "||arr[y-a][i]==" ♕ ")
            {    
                checkFigureX=i;
                checkFigureY=y-a;       
                return true;
            }
            else if(find(begin(white),end(white),arr[y-a][i]) != end(white)||
            find(begin(black),end(black),arr[y-a][i]) != end(black))
            {
                break;
            }
        }
        a++;
    }

    //reset
    a=1;
    //forward right
    for(int i=x+1;i<10;i++)
    {
        if(arr[y-a][i]!=" ◻ "&& arr[y-a][i]!=" ◼ ")
        {
            if(arr[y-a][i]==" ♗ "||arr[y-a][i]==" ♕ ")
            {
                //cout<<"check"<<endl;
                checkFigureX=i;
                checkFigureY=y-a;  
                return true;
            }
            else if(find(begin(white),end(white),arr[y-a][i]) != end(white)||
            find(begin(black),end(black),arr[y-a][i]) != end(black))
            {
                break;
            }
        }
        a++;
    }
    //reset
    a=1;
    //backward left
    for(int i=y+1;i<9;i++)
    {
        
        if(arr[i][x-a]!=" ◻ "&& arr[i][x-a]!=" ◼ ")
        {
            if(arr[i][x-a]==" ♗ "||arr[i][x-a]==" ♕ ")
            {
                checkFigureX=x-a;
                checkFigureY=i;  
                return true;
            }
            else if(find(begin(white),end(white),arr[i][x-a]) != end(white)||
            find(begin(black),end(black),arr[i][x-a]) != end(black))
            {
                break;
            }
        }
        a++;
    }

    return false;
}

bool CheckIfWhiteKingInCheck(string arr[10][10],int x,int y)
{
    if(KnightChecks(arr,x,y)||StraightChecks(arr,x,y)||DiagonalsChecks(arr,x,y)||PawnChecks(arr,x,y))
    {
        //cout<<"king check"<<endl;
        return true;
        
    }
    else
    {
        return false;
    }


}

void GetWhiteFigure(string arr[10][10],int y ,int x,int _x,int _y)
{
    auto figure=arr[y][x];
    if(figure==" ♜ ")
    {

        for(int i=x+1;i<10;i++)
        { 
            if(i==_x&&y==_y)
            {
                if((arr[_y][i]==" ◻ "||arr[_y][i]==" ◼ "))
                {
                    WhiteMovement(arr,y,x,_x,_y);
                }
                else if(find(begin(black),end(black),arr[y][i]) != end(black)
                    &&find(begin(black),end(black),arr[y][i-1]) == end(black))
                {
                    WhiteMovement(arr,y,x,_x,_y);        
                }
            }      
        }
        for(int i=x-1;i>1;i--)
        {
              if(i==_x&&y==_y)
            {
                if((arr[_y][i]==" ◻ "||arr[_y][i]==" ◼ "))
                {
                    WhiteMovement(arr,y,x,_x,_y);
                }
                else if(find(begin(black),end(black),arr[y][i]) != end(black)
                    &&find(begin(black),end(black),arr[y][i+1]) == end(black))
                {
                    WhiteMovement(arr,y,x,_x,_y);
                }       
            }      
        }
        for(int i=y+1;i<10;i++)
        {
             if(i==_y&&x==_x)
            {
                if((arr[i][x]==" ◻ "||arr[i][x]==" ◼ "))
                {
                    WhiteMovement(arr,y,x,_x,_y);
                }
                else if(find(begin(black),end(black),arr[i][x]) != end(black)
                    &&find(begin(black),end(black),arr[i-1][x]) == end(black))
                {
                    WhiteMovement(arr,y,x,_x,_y); 
                }      
            }      
        }
        for(int i=y-1;i>0;i--)
        {
            if(i==_y&&x==_x)
            {
                if((arr[i][x]==" ◻ "||arr[i][x]==" ◼ "))
                {
                   WhiteMovement(arr,y,x,_x,_y);
                }
                else if(find(begin(black),end(black),arr[i][x]) != end(black)
                    &&find(begin(black),end(black),arr[i+1][x]) == end(black))
                {
                    WhiteMovement(arr,y,x,_x,_y);

                }
            }          
        }
        //arr[y][x-1]=" X ";
        //arr[y-1][x]=" X ";
        //arr[y+1][x]=" X ";    

        cout<<"rook"<<endl;
    }
    else if(figure==" ♞ ")
    {
        if(y-2>=1&&x+1<=10&&x-1>=1)
        {
            if(y-2==_y&&x-1==_x)
            {
                if(find(begin(black),end(black),arr[_y][_x]) != end(black)
                ||find(begin(boxes),end(boxes),arr[_y][_x]) != end(boxes))
                {
                    WhiteMovement(arr,y,x,_x,_y);
                }
                //arr[y-2][x-1]=" X ";
                
            }
            else if(y-2==_y&&x+1==_x)
            {
                if(find(begin(black),end(black),arr[_y][_x]) != end(black)
                ||find(begin(boxes),end(boxes),arr[_y][_x]) != end(boxes))
                {
                    WhiteMovement(arr,y,x,_x,_y);
                }
                //arr[y-2][x+1]=" X ";
            }
                 
        }
        if(y+2<=10&&x+1<=10&&x-1>=1)
        {
            if(y+2==_y&&x+1==_x)
            {
                //arr[y+2][x+1]=" X ";
                if(find(begin(black),end(black),arr[_y][_x]) != end(black)
                ||find(begin(boxes),end(boxes),arr[_y][_x]) != end(boxes))
                {
                    WhiteMovement(arr,y,x,_x,_y);
                }
            }
            else if(y+2==_y&&x-1==_x)
            {
                //arr[y+2][x-1]=" X ";
                if(find(begin(black),end(black),arr[_y][_x]) != end(black)
                ||find(begin(boxes),end(boxes),arr[_y][_x]) != end(boxes))
                {
                    WhiteMovement(arr,y,x,_x,_y);
                }
            }
            
            
        }
        if(y+1<=10&&x-2>=1)
        {
            if(y+1==_y&&x+2==_x)
            {
                //arr[y+1][x+2]=" X ";
                if(find(begin(black),end(black),arr[_y][_x]) != end(black)
                ||find(begin(boxes),end(boxes),arr[_y][_x]) != end(boxes))
                {
                    WhiteMovement(arr,y,x,_x,_y);
                }
            }
            else if(y+1==_y&&x-2==_x)
            {
                //arr[y+1][x-2]=" X ";
                if(find(begin(black),end(black),arr[_y][_x]) != end(black)
                ||find(begin(boxes),end(boxes),arr[_y][_x]) != end(boxes))
                {
                    WhiteMovement(arr,y,x,_x,_y);
                }
            }
            
            
        }
        if(x+2<=10&&x-2>=1)
        {
            if(y-1==_y&&x-2==_x)
            {
                //arr[y-1][x-2]=" X ";
                if(find(begin(black),end(black),arr[_y][_x]) != end(black)
                ||find(begin(boxes),end(boxes),arr[_y][_x]) != end(boxes))
                {
                    WhiteMovement(arr,y,x,_x,_y);
                }
            }
            else if(y-1==_y&&x+2==_x)
            {
                //arr[y-1][x+2]=" X ";
                if(find(begin(black),end(black),arr[_y][_x]) != end(black)
                ||find(begin(boxes),end(boxes),arr[_y][_x]) != end(boxes))
                {
                    WhiteMovement(arr,y,x,_x,_y);
                }
            }            
            
            
        }

        cout<<"knight"<<endl;
    }
    else if(figure==" ♝ ")
    {
        for(int i =1;x+i<=9;i++)
        {  
            //arr[y-i][x+i]=" X ";
            if(y-i==_y&&x+i==_x)
            {
                if((arr[_y][_x]==" ◻ "||arr[_y][_x]==" ◼ "))
                {
                    WhiteMovement(arr,y,x,_x,_y);
                }
                else if(find(begin(black),end(black),arr[_y][_x]) != end(black)
                    &&find(begin(black),end(black),arr[_y+1][_x-1]) == end(black))
                {
                    WhiteMovement(arr,y,x,_x,_y);        
                }


            } 
        }
        for(int i =1;x+i<=9;i++)
        {
            //arr[y+i][x+i]=" X ";
            if(y+i==_y&&x+i==_x)
            {
                if((arr[_y][_x]==" ◻ "||arr[_y][_x]==" ◼ "))
                {
                    WhiteMovement(arr,y,x,_x,_y);
                }
                else if(find(begin(black),end(black),arr[_y][_x]) != end(black)
                    &&find(begin(black),end(black),arr[_y-1][_x-1]) == end(black))
                {
                    WhiteMovement(arr,y,x,_x,_y);        
                }


            }  
        }
        for(int i =1;i<x-1;i++)
        {
            //arr[y-i][x-i]=" X ";
            if(y-i==_y&&x-i==_x)
            {
                if((arr[_y][_x]==" ◻ "||arr[_y][_x]==" ◼ "))
                {
                    WhiteMovement(arr,y,x,_x,_y);
                }
                else if(find(begin(black),end(black),arr[_y][_x]) != end(black)
                    &&find(begin(black),end(black),arr[_y+1][_x+1]) == end(black))
                {
                    WhiteMovement(arr,y,x,_x,_y);        
                }


            }  
        }
        for(int i =1;i<x-1;i++)
        {
            //arr[y+i][x-i]=" X ";
            if(y+i==_y&&x-i==_x)
            {
                if((arr[_y][_x]==" ◻ "||arr[_y][_x]==" ◼ "))
                {
                    WhiteMovement(arr,y,x,_x,_y);
                }
                else if(find(begin(black),end(black),arr[_y][_x]) != end(black)
                    &&find(begin(black),end(black),arr[_y-1][_x+1]) == end(black))
                {
                    WhiteMovement(arr,y,x,_x,_y);        
                }


            }  
        }
        
        cout<<"bishop"<<endl;
    }
    else if(figure==" ♛ ")
    {
        
        for(int i=x+1;i<10;i++)
        { 
            if(i==_x&&y==_y)
            {
                if((arr[_y][i]==" ◻ "||arr[_y][i]==" ◼ "))
                {
                    WhiteMovement(arr,y,x,_x,_y);
                }
                else if(find(begin(black),end(black),arr[y][i]) != end(black)
                    &&find(begin(black),end(black),arr[y][i-1]) == end(black))
                {
                    WhiteMovement(arr,y,x,_x,_y);        
                }
            }      
        }
        for(int i=x-1;i>1;i--)
        {
              if(i==_x&&y==_y)
            {
                if((arr[_y][i]==" ◻ "||arr[_y][i]==" ◼ "))
                {
                    WhiteMovement(arr,y,x,_x,_y);
                }
                else if(find(begin(black),end(black),arr[y][i]) != end(black)
                    &&find(begin(black),end(black),arr[y][i+1]) == end(black))
                {
                    WhiteMovement(arr,y,x,_x,_y);
                }       
            }      
        }
        for(int i=y+1;i<10;i++)
        {
             if(i==_y&&x==_x)
            {
                if((arr[i][x]==" ◻ "||arr[i][x]==" ◼ "))
                {
                    WhiteMovement(arr,y,x,_x,_y);
                }
                else if(find(begin(black),end(black),arr[i][x]) != end(black)
                    &&find(begin(black),end(black),arr[i-1][x]) == end(black))
                {
                    WhiteMovement(arr,y,x,_x,_y); 
                }      
            }      
        }
        for(int i=y-1;i>0;i--)
        {
            if(i==_y&&x==_x)
            {
                if((arr[i][x]==" ◻ "||arr[i][x]==" ◼ "))
                {
                   WhiteMovement(arr,y,x,_x,_y);
                }
                else if(find(begin(black),end(black),arr[i][x]) != end(black)
                    &&find(begin(black),end(black),arr[i+1][x]) == end(black))
                {
                    WhiteMovement(arr,y,x,_x,_y);

                }
            }          
        }

        for(int i =1;x+i<=9;i++)
        {  
            //arr[y-i][x+i]=" X ";
            if(y-i==_y&&x+i==_x)
            {
                if((arr[_y][_x]==" ◻ "||arr[_y][_x]==" ◼ "))
                {
                    WhiteMovement(arr,y,x,_x,_y);
                }
                else if(find(begin(black),end(black),arr[_y][_x]) != end(black)
                    &&find(begin(black),end(black),arr[_y+1][_x-1]) == end(black))
                {
                    WhiteMovement(arr,y,x,_x,_y);        
                }


            } 
        }
        for(int i =1;x+i<=9;i++)
        {
            //arr[y+i][x+i]=" X ";
            if(y+i==_y&&x+i==_x)
            {
                if((arr[_y][_x]==" ◻ "||arr[_y][_x]==" ◼ "))
                {
                    WhiteMovement(arr,y,x,_x,_y);
                }
                else if(find(begin(black),end(black),arr[_y][_x]) != end(black)
                    &&find(begin(black),end(black),arr[_y-1][_x-1]) == end(black))
                {
                    WhiteMovement(arr,y,x,_x,_y);        
                }


            }  
        }
        for(int i =1;i<x-1;i++)
        {
            //arr[y-i][x-i]=" X ";
            if(y-i==_y&&x-i==_x)
            {
                if((arr[_y][_x]==" ◻ "||arr[_y][_x]==" ◼ "))
                {
                    WhiteMovement(arr,y,x,_x,_y);
                }
                else if(find(begin(black),end(black),arr[_y][_x]) != end(black)
                    &&find(begin(black),end(black),arr[_y+1][_x+1]) == end(black))
                {
                    WhiteMovement(arr,y,x,_x,_y);        
                }


            }  
        }
        for(int i =1;i<x-1;i++)
        {
            //arr[y+i][x-i]=" X ";
            if(y+i==_y&&x-i==_x)
            {
                if((arr[_y][_x]==" ◻ "||arr[_y][_x]==" ◼ "))
                {
                    WhiteMovement(arr,y,x,_x,_y);
                }
                else if(find(begin(black),end(black),arr[_y][_x]) != end(black)
                    &&find(begin(black),end(black),arr[_y-1][_x+1]) == end(black))
                {
                    WhiteMovement(arr,y,x,_x,_y);        
                }


            }  
        }
        
        cout<<"queen"<<endl;
    }
    else if(figure==" ♚ ")
    {
        
        if(y-1>=1&&x+1<10&&x-1>=1)
        {
            if(y-1==_y&&x+1==_x)
            {
                if((find(begin(black),end(black),arr[_y][_x]) != end(black)
                ||find(begin(boxes),end(boxes),arr[_y][_x]) != end(boxes))
                &&!CheckIfWhiteKingInCheck(arr,_x,_y))
                {
                    WhiteKingMoved=true;
                    WhiteMovement(arr,y,x,_x,_y);
                }
                //arr[y-1][x+1]=" X ";
                
            }
            else if(y-1==_y&&x-1==_x)
            {
                if((find(begin(black),end(black),arr[_y][_x]) != end(black)
                ||find(begin(boxes),end(boxes),arr[_y][_x]) != end(boxes))
                &&!CheckIfWhiteKingInCheck(arr,_x,_y))
                {
                    WhiteKingMoved=true;
                    WhiteMovement(arr,y,x,_x,_y);
                }
                //arr[y-1][x-1]=" X ";
            }
                 
        }
        
        if(x-1>=1&&y+1<10&&x-1>=1)
        {
            if(y+1==_y&&x+1==_x)
            {
                if((find(begin(black),end(black),arr[_y][_x]) != end(black)
                ||find(begin(boxes),end(boxes),arr[_y][_x]) != end(boxes))
                &&!CheckIfWhiteKingInCheck(arr,_x,_y))
                {
                    WhiteKingMoved=true;
                    WhiteMovement(arr,y,x,_x,_y);
                }
                //arr[y+1][x+1]=" X ";
                
            }
            else if(y+1==_y&&x-1==_x)
            {
                if((find(begin(black),end(black),arr[_y][_x]) != end(black)
                ||find(begin(boxes),end(boxes),arr[_y][_x]) != end(boxes))
                &&!CheckIfWhiteKingInCheck(arr,_x,_y))
                {
                    WhiteKingMoved=true;
                    WhiteMovement(arr,y,x,_x,_y);
                }
                //arr[y+1][x-1]=" X ";
            }
                 
        }

        if(x-1>=1&&x+1<10)
        {
            if(y==_y&&x+1==_x)
            {
                if((find(begin(black),end(black),arr[_y][_x]) != end(black)
                ||find(begin(boxes),end(boxes),arr[_y][_x]) != end(boxes))
                &&!CheckIfWhiteKingInCheck(arr,_x,_y))
                {
                    WhiteKingMoved=true;
                    WhiteMovement(arr,y,x,_x,_y);
                }
                //arr[y][x+1]=" X ";
                
            }
            else if(y==_y&&x-1==_x)
            {
                if((find(begin(black),end(black),arr[_y][_x]) != end(black)
                ||find(begin(boxes),end(boxes),arr[_y][_x]) != end(boxes))
                &&!CheckIfWhiteKingInCheck(arr,_x,_y))
                {
                    WhiteKingMoved=true;
                    WhiteMovement(arr,y,x,_x,_y);
                }
                //arr[y][x-1]=" X ";
            }
                 
        }

        if(y-1>=1&&y+1<10)
        {
            if(y-1==_y&&x==_x)
            {
                if((find(begin(black),end(black),arr[_y][_x]) != end(black)
                ||find(begin(boxes),end(boxes),arr[_y][_x]) != end(boxes))
                &&!CheckIfWhiteKingInCheck(arr,_x,_y))
                {
                    WhiteKingMoved=true;
                    WhiteMovement(arr,y,x,_x,_y);
                }
                //arr[y-1][x]=" X ";
                
            }
            else if(y+1==_y&&x==_x)
            {
                if((find(begin(black),end(black),arr[_y][_x]) != end(black)
                ||find(begin(boxes),end(boxes),arr[_y][_x]) != end(boxes))
                &&!CheckIfWhiteKingInCheck(arr,_x,_y))
                {
                    WhiteKingMoved=true;
                    WhiteMovement(arr,y,x,_x,_y);
                }
                //arr[y+1][x]=" X ";
            }
                 
        }

        //Rokada left side
        for(int i=x-1;i>1;i--)
        {
            if(CheckIfWhiteKingInCheck(arr,i,y))
            {
                break;
            }
            if(arr[y][i]!=" ◻ "&& arr[y][i]!=" ◼ ")
            {
                if(arr[y][i]==" ♜ ")
                {
                    if(!WhiteKingMoved&&!LeftRook&&_x==2&&_y==8)
                    {                   
                        arr[y][x-2]=arr[y][x];
                        arr[y][x-1]=arr[_y][_x];
                        arr[_y][_x]=squares[y][x];
                        arr[y][x]=squares[y][x];
                        WhiteKingMoved=true;    
                    }
                }
            } 
        }
        //Rokada right side
        for(int i=x+1;i<10;i++)
        {
            if(CheckIfWhiteKingInCheck(arr,i,y))
            {
                break;
            }
            if(arr[y][i]!=" ◻ "&& arr[y][i]!=" ◼ ")
            {
                if(arr[y][i]==" ♜ ")
                {
                    if(!WhiteKingMoved&&!RightRook&&_x==9&&_y==8)
                    {
                        arr[y][x+2]=arr[y][x];
                        arr[y][x+1]=arr[_y][_x];
                        arr[_y][_x]=squares[y][x];
                        arr[y][x]=squares[y][x];
                        WhiteKingMoved=true;   
                    }
                }
            } 
        }


        cout<<"king"<<endl;
    }
    else if(figure==" ♟︎ ")
    {
        if(_y==y-1)
        {
            if(x-1==_x||x+1==_x)
            {
                if(find(begin(black),end(black),arr[_y][_x]) != end(black))
                {   
                    WhiteMovement(arr,y,x,_x,_y);
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

bool CantMoveKing(string arr[10][10],int x,int y)    
{
    bool a=true;
    int pos[8][2]={{y+1,x},{y-1,x},
                   {y+1,x+1},{y-1,x+1},
                   {y+1,x-1},{y-1,x-1},
                   {y,x-1},{y,x+1},
                   };
    
    for(int i=0;i<8;i++)
    {
        if(pos[i][0]>0&&pos[i][0]<9&&pos[i][1]>1&&pos[i][1]<10)
        {  
            if(CheckIfWhiteKingInCheck(arr,pos[i][1],pos[i][0])==false)
            {               
                a=false;
                break;
            }

        }
        
    }
    return a;


}

void WhiteTurn(string arr[10][10])
{

    int x;
    int y;

    int _x;
    int _y;
    
    char str[100];

    string copyArr[10][10];
    //std::fill(begin( copyArr),end( copyArr ), 0 );
    copy(&arr[0][0], &arr[0][0]+10*10,&copyArr[0][0]);

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
        string  str_(words[0]);
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

    GetWhiteFigure(copyArr,y,x,_x,_y);

    LeftRookMoved(arr);
    RightRookMoved(arr);

    int x1=0;
    int y1=0;
    for (int r = 0; r < 10; r++)
    {
        for (int c = 0; c < 10; c++)
        {
            if (arr[r][c] == " ♚ ")
            {
                y1=r;
                x1=c;
            }
        }
    }

    if(CheckIfWhiteKingInCheck(copyArr,x1,y1))
    {  
        cout<<arr[checkFigureY][checkFigureX]<<endl; 
        if(CantMoveKing(arr,x1,y1))
        {
            cout<<"Checkmate black won!"<<endl;
        }
        else
        {
            //system("cls");
            cout<<"king in check"<<endl;
            RenderBoard(arr);
            WhiteTurn(arr);
        }

    }
    else
    {  
        //system("cls"); 
        RenderBoard(copyArr);
        copy(&copyArr[0][0], &copyArr[0][0]+10*10,&arr[0][0]);

    }
       
}


int main()
{
  string arr[10][10]={{"  ",""," A "," B "," C "," D "," E "," F "," G "," H "},
                    {"8"," "," ♖ "," ♘ "," ♗ "," ♕ "," ♔ "," ♗ "," ♘ "," ♖ "},
                    {"7"," "," ♙ "," ♙ "," ♙ "," ♙ "," ♙ "," ♙ "," ♙ "," ♙ "},
                    {"6"," "," ◼ "," ◻ "," ◼ "," ◻ "," ◼ "," ◻ "," ♗ "," ◻ "},
                    {"5"," "," ◻ "," ◼ "," ◻ "," ◼ "," ◻ "," ◼ "," ◻ "," ◼ "},
                    {"4"," "," ◼ "," ◻ "," ◼ "," ◻ "," ◼ "," ◻ "," ◼ "," ◻ "},
                    {"3"," "," ◻ "," ◼ "," ◻ "," ♚ "," ◻ "," ◼ "," ◻ "," ◼ "},
                    {"2"," "," ♟︎ "," ♟︎ "," ♟︎ "," ♟︎ "," ♟︎ "," ♟︎ "," ♟︎ "," ♟︎ "},
                    {"1"," "," ♜ "," ♞ "," ♝ "," ♛ "," ◻ "," ♝ "," ♞ "," ♜ "}};

    RenderBoard(arr);
    while(true)
    {
        WhiteTurn(arr);       
    }
    

}