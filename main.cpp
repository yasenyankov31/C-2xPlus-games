#include <iostream>
#include <iterator>

using namespace std;
void RenderBoard(string arr[3][3])
{
  for(int i=0;i<3;i++)
  {
    for(int j=0;j<3;j++)
    {
      cout<<arr[i][j];
    }
    cout<<""<<endl;
  }
}

void RestartBoard(string arr[3][3],string arr_copy[3][3])
{
  system("pause");
  system("cls");
  for(int i=0;i<3;i++)
  {
     for(int j=0;j<3;j++)
    {
      arr[i][j]=arr_copy[i][j];
    }
  }
  RenderBoard(arr);
}

void X_Input(string arr[3][3],string arr_copy[3][3],int counter)
{
  system("cls");
  RenderBoard(arr);
  int x;
  cout<<"Player X turn:";
  cin>>x;
  if(x<4)
  {
    if(arr[0][x-1]=="| o |")
    {
      X_Input(arr,arr_copy,counter);
    }
    else
    {
      counter=counter+1;
      arr[0][x-1]="| x |";
      system("cls");
      RenderBoard(arr);
    }

  }
  else if(x<7)
  {
    if(arr[1][x-4]=="| o |")
    {
      X_Input(arr,arr_copy,counter);
    }
    else
    {
      counter=counter+1;
      arr[1][x-4]="| x |";
      system("cls");
      RenderBoard(arr);
    }
  }
  else
  {
    if(arr[2][x-7]=="| o |")
    {
      X_Input(arr,arr_copy,counter);
    }
    else
    {
      counter=counter+1;
      arr[2][x-7]="| x |";
      system("cls");
      RenderBoard(arr);
    }
  }
  for(int i=0;i<3;i++)
    {
      string textrow;
      string textcol;
      string diag_1;
      string diag_2;
      for(int j=0;j<3;j++)
      {
        textrow=textrow+arr[i][j];
        textcol=textcol+arr[j][i];
        diag_1=arr[0][0]+arr[1][1]+arr[2][2];
        diag_2=arr[0][2]+arr[1][1]+arr[2][0];
        if(textrow=="| x || x || x |"||textcol=="| x || x || x |"||diag_1=="| x || x || x |"||diag_2=="| x || x || x |")
        {
          counter=0;
          cout<<" X player wins! ";
          RestartBoard(arr,arr_copy);
        }
      }
      diag_1="";
      diag_2="";
      textcol="";  
      textrow="";
    }
}

void O_Input(string arr[3][3],string arr_copy[3][3],int counter)
{
  system("cls");
  RenderBoard(arr);
  int o;
  cout<<"Player O turn:";
  cin>>o;
  if(o<4)
  {
    if(arr[0][o-1]=="| x |")
    {
      O_Input(arr,arr_copy,counter);
    }
    else
    {
    counter=counter+1;
    arr[0][o-1]="| o |";
    system("cls");
    RenderBoard(arr);
    }
  }
  else if(o<7)
  {
    if(arr[1][o-4]=="| x |")
    {
      O_Input(arr,arr_copy,counter);
    }
    else
    {
      counter=counter+1;
      arr[1][o-4]="| o |";
      system("cls");
      RenderBoard(arr);
    }
  }
  else
  {
    if(arr[2][o-7]=="| x |")
    {
      O_Input(arr,arr_copy,counter);
    }
    else
    {
    counter=counter+1;
    arr[2][o-7]="| o |";
    system("cls");
    RenderBoard(arr);
    }
  }
  for(int i=0;i<3;i++)
    {
      string textrow;
      string textcol;
      string diag_1;
      string diag_2;
      for(int j=0;j<3;j++)
      {
        textrow=textrow+arr[i][j];
        textcol=textcol+arr[j][i];
        diag_1=arr[0][0]+arr[1][1]+arr[2][2];
        diag_2=arr[0][2]+arr[1][1]+arr[2][0];
        if (textrow=="| o || o || o |"||textcol=="| o || o || o |"||diag_1=="| o || o || o |"||diag_2=="| o || o || o |")
        {
          counter=0;
          cout<<" O player wins! ";
          RestartBoard(arr,arr_copy);
        }
      }  
      textrow="";
      textcol="";
      diag_1="";
      diag_2="";
    }

}


int main()
{
  string arr[3][3]={{"| 1 |", "| 2 |", "| 3 |"},{"| 4 |", "| 5 |", "| 6 |"},{"| 7 |", "| 8 |", "| 9 |"}};
  string arr_copy[3][3]={{"| 1 |", "| 2 |", "| 3 |"},{"| 4 |", "| 5 |", "| 6 |"},{"| 7 |", "| 8 |", "| 9 |"}};
  RenderBoard(arr);
  int counter=0;
  while (true)
  {
    X_Input(arr,arr_copy,counter);
    if (counter>=9)
    {
      cout<<" Draw! ";
      counter=0;
      RestartBoard(arr,arr_copy);
    }
    O_Input(arr,arr_copy,counter);
    if (counter>=9)
    {
      cout<<" Draw! ";
      counter=0;
      RestartBoard(arr,arr_copy);
    }
  }
  
}