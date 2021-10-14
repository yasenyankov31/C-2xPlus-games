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




void StraightChecks(string arr[10][10],int x,int y)
{
    int a=0;
    string sub_arr[10];
    //backward
    for(int i=y-1;i>0;i--)
    {
        if(arr[i][x]!=" ◻ "&& arr[i][x]!=" ◼ ")
        {
            sub_arr[a]=arr[i][x];
            a++;
        }             
    }
    for(int i=0;i<10;i++)
    {
        if(sub_arr[0]==" ♖ "||sub_arr[0]==" ♕ ")
        {
            cout<<"king check"<<endl;
            break;
        }
        //cout<<sub_arr[i]<<endl;
    }
    fill(begin(sub_arr),end(sub_arr),0);
    a=0;
    //forward
    for(int i=y+1;i<10;i++)
    {
        if(arr[i][x]!=" ◻ "&& arr[i][x]!=" ◼ ")
        {
            sub_arr[a]=arr[i][x];
            a++;
        }             
    }
    for(int i=0;i<10;i++)
    {
        if(sub_arr[0]==" ♖ "||sub_arr[0]==" ♕ ")
        {
            cout<<"king check"<<endl;
            break;
        }
        //cout<<sub_arr[i]<<endl;
    }
    fill(begin(sub_arr),end(sub_arr),0);
    a=0;
    //left
    for(int i=x-1;i>1;i--)
    {
        if(arr[y][i]!=" ◻ "&& arr[y][i]!=" ◼ ")
        { 
            sub_arr[a]=arr[y][i];
            a++;
        }
          
    }
    for(int i=0;i<10;i++)
    {
        if(sub_arr[0]==" ♖ "||sub_arr[0]==" ♕ ")
        {
            cout<<"king check"<<endl;
            break;
        }
    }
    fill(begin(sub_arr),end(sub_arr),0);
    a=0;
    //right
    for(int i=x+1;i<10;i++)
    {
        if(arr[y][i]!=" ◻ "&& arr[y][i]!=" ◼ ")
        {  
            sub_arr[a]=arr[y][i];
            a++;
        }
          
    }
    for(int i=0;i<10;i++)
    {
        if(sub_arr[0]==" ♖ "||sub_arr[0]==" ♕ ")
        {
            cout<<"king check"<<endl;
            break;
        }
    }

}


void DiagonalsChecks(string arr[10][10],int x,int y)
{
    int a =1;
    int j =0;
    string sub_arr[10];
    for(int i=y+1;i<9;i++)
    {      
        if(arr[i][x+a]!=" ◻ "&& arr[i][x+a]!=" ◼ ")
        {
            sub_arr[j]=arr[i][x+a];
            j++; 
        }
        a++;
    }
    if(sub_arr[0]==" ♗ "||sub_arr[0]==" ♕ ")
    {
        cout<<"king check"<<endl;
    }
    //reset
    a=1;
    j=0;
    fill(begin(sub_arr),end(sub_arr),0);
    for(int i=y-1;i>1;i--)
    {      
        if(arr[i][x+a]!=" ◻ "&& arr[i][x+a]!=" ◼ ")
        {
            arr[i][x+a]=" X ";
            j++; 
        }
        a++;
    }
}

void CheckIfWhiteKingInCheck(string arr[10][10])
{
    int x =0;
    int y =0;
    
    for (int r = 0; r < 10; r++)
    {
        for (int c = 0; c < 10; c++)
        {
            if (arr[r][c] == " ♚ ")
            {
                y=r;
                x=c;
            }
        }
    }

    if(arr[y-2][x-1]==" ♘ "||arr[y-2][x+1]==" ♘ "||arr[y-1][x-2]==" ♘ "||arr[y-1][x+2]==" ♘ "||
    arr[y+2][x-1]==" ♘ "||arr[y+2][x+1]==" ♘ "||arr[y+1][x-2]==" ♘ "||arr[y+1][x+2]==" ♘ ")
    {
        cout<<"king check"<<endl;
    }
    StraightChecks(arr,x,y);
    DiagonalsChecks(arr,x,y);


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
                if(find(begin(black),end(black),arr[_y][_x]) != end(black)
                ||find(begin(boxes),end(boxes),arr[_y][_x]) != end(boxes))
                {
                    WhiteMovement(arr,y,x,_x,_y);
                }
                //arr[y-1][x+1]=" X ";
                
            }
            else if(y-1==_y&&x-1==_x)
            {
                if(find(begin(black),end(black),arr[_y][_x]) != end(black)
                ||find(begin(boxes),end(boxes),arr[_y][_x]) != end(boxes))
                {
                    WhiteMovement(arr,y,x,_x,_y);
                }
                //arr[y-1][x-1]=" X ";
            }
                 
        }
        
        if(x-1>=1&&y+1<10&&x-1>=1)
        {
            if(y+1==_y&&x+1==_x)
            {
                if(find(begin(black),end(black),arr[_y][_x]) != end(black)
                ||find(begin(boxes),end(boxes),arr[_y][_x]) != end(boxes))
                {
                    WhiteMovement(arr,y,x,_x,_y);
                }
                //arr[y+1][x+1]=" X ";
                
            }
            else if(y+1==_y&&x-1==_x)
            {
                if(find(begin(black),end(black),arr[_y][_x]) != end(black)
                ||find(begin(boxes),end(boxes),arr[_y][_x]) != end(boxes))
                {
                    WhiteMovement(arr,y,x,_x,_y);
                }
                //arr[y+1][x-1]=" X ";
            }
                 
        }

        if(x-1>=1&&x+1<10)
        {
            if(y==_y&&x+1==_x)
            {
                if(find(begin(black),end(black),arr[_y][_x]) != end(black)
                ||find(begin(boxes),end(boxes),arr[_y][_x]) != end(boxes))
                {
                    WhiteMovement(arr,y,x,_x,_y);
                }
                //arr[y][x+1]=" X ";
                
            }
            else if(y==_y&&x-1==_x)
            {
                if(find(begin(black),end(black),arr[_y][_x]) != end(black)
                ||find(begin(boxes),end(boxes),arr[_y][_x]) != end(boxes))
                {
                    WhiteMovement(arr,y,x,_x,_y);
                }
                //arr[y][x-1]=" X ";
            }
                 
        }

        if(y-1>=1&&y+1<10)
        {
            if(y-1==_y&&x==_x)
            {
                if(find(begin(black),end(black),arr[_y][_x]) != end(black)
                ||find(begin(boxes),end(boxes),arr[_y][_x]) != end(boxes))
                {
                    WhiteMovement(arr,y,x,_x,_y);
                }
                //arr[y-1][x]=" X ";
                
            }
            else if(y+1==_y&&x==_x)
            {
                if(find(begin(black),end(black),arr[_y][_x]) != end(black)
                ||find(begin(boxes),end(boxes),arr[_y][_x]) != end(boxes))
                {
                    WhiteMovement(arr,y,x,_x,_y);
                }
                //arr[y+1][x]=" X ";
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
                    {"6"," "," ◼ "," ♚ "," ◼ "," ◻ "," ◼ "," ◻ "," ◼ "," ◻ "},
                    {"5"," "," ◻ "," ◼ "," ◻ "," ◼ "," ◻ "," ◼ "," ◻ "," ◼ "},
                    {"4"," "," ◼ "," ◻ "," ◼ "," ◻ "," ◼ "," ◻ "," ◼ "," ◻ "},
                    {"3"," "," ◻ "," ◼ "," ◻ "," ◼ "," ♕ "," ◼ "," ◻ "," ◼ "},
                    {"2"," "," ♟︎ "," ♟︎ "," ♟︎ "," ♟︎ "," ♟︎ "," ♟︎ "," ♟︎ "," ♟︎ "},
                    {"1"," "," ♜ "," ♞ "," ♝ "," ♛ "," ◻ "," ♝ "," ♞ "," ♜ "}};
    RenderBoard(arr);
    while(true)
    {
    CheckIfWhiteKingInCheck(arr);
    WhiteTurn(arr);
    }
    

}