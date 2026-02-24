#include<iostream>
#include<cstring>
using namespace std;

int verify(char table[3][3])
{
    for(int i=0; i<3; i++)
        if(table[i][0]==table[i][1] && table[i][1]==table[i][2] && table[i][0]!='\0')
            return 1;

    for(int i=0; i<3; i++)
        if(table[0][i]==table[1][i] && table[1][i]==table[2][i] && table[0][i]!='\0')
            return 1;

    if(table[0][0]==table[1][1] && table[1][1]==table[2][2] && table[0][0]!='\0')
        return 1;

    if(table[0][2]==table[1][1] && table[1][1]==table[2][0] && table[0][2]!='\0')
        return 1;

    return 0;
}

void show_the_table(char table[3][3])
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout<<" "<<table[i][j]<<" ";
            if(j < 2)cout<<"|";
        }
        cout<<endl;
        if(i < 2)cout<<"---------"<<endl;
    }
}

int verify_if_the_coordonates_are_correct(char table[3][3], int *i, int *j)
{

    while((*i<0 || *i>=3) || (*j<0 || *j>=3))
    {
        cout<<endl;
        cout<<"The coordonares must be 1,2 or 3, not bigger or smaller!"<<endl;
        cout<<"The line coordonate is: ";
        cin>> *i;
        *i=*i-1;
        cout<<"The collumn coordonate is: ";
        cin>> *j;
        *j=*j-1;
    }

    if(table[*i][*j]!='\0')
    {
        return 0;
    }

    return 1;
}
int main()
{
    char table[3][3]= {'\0'};
    int i,j;
    for(int r=0; r<10; r++)
    {
        system("cls");
        show_the_table(table);

        if(r==9)
        {
        cout<<endl;
        cout<<"It's a draw!! Try again to see who is better";
        return 0;
        }

        if(r%2==0)
        {
            cout<<"Give the coordonates for X"<<endl;
            cout<<"The line coordonate is: ";
            cin>>i;
            i=i-1;
            cout<<"The collumn coordonate is: ";
            cin>>j;
            j=j-1;
            if(verify_if_the_coordonates_are_correct(table,&i,&j)==1)
                table[i][j]='X';
            else
            {
                while(verify_if_the_coordonates_are_correct(table,&i,&j)==0)
                {
                    cout<<"The coordonates are already used, please write another combination!"<<endl;
                    system("pause");
                    system("cls");
                    show_the_table(table);
                    cout<<"Give the coordonates for X"<<endl;
                    cout<<"The line coordonate is: ";
                    cin>>i;
                    i=i-1;
                    cout<<"The collumn coordonate is: ";
                    cin>>j;
                    j=j-1;
                    if(verify_if_the_coordonates_are_correct(table,&i,&j)==1)
                    {
                        table[i][j]='X';
                        break;
                    }
                }
            }
        }


        if(r%2==1)
        {
            cout<<"Give the coordonates for O"<<endl;
            cout<<"The line coordonate is: ";
            cin>>i;
            i=i-1;
            cout<<"The collumn coordonate is: ";
            cin>>j;
            j=j-1;
            if(verify_if_the_coordonates_are_correct(table,&i,&j)==1)
                table[i][j]='O';
            else
            {
                while(verify_if_the_coordonates_are_correct(table,&i,&j)==0)
                {
                    cout<<"The coordonates are already used, please write another combination!"<<endl;
                    system("pause");
                    system("cls");
                    show_the_table(table);
                    cout<<"Give the coordonates for O"<<endl;
                    cout<<"The line coordonate is: ";
                    cin>>i;
                    i=i-1;
                    cout<<"The collumn coordonate is: ";
                    cin>>j;
                    j=j-1;
                    if(verify_if_the_coordonates_are_correct(table,&i,&j)==1)
                    {
                        table[i][j]='O';
                        break;
                    }
                }
            }
        }

        if(verify(table)==1 && r%2==0)
        {
            system("cls");
            show_the_table(table);
            cout<<endl<<"Player 1 won!!";
            break;
        }
        if(verify(table)==1 && r%2==1)
        {
            system("cls");
            show_the_table(table);
            cout<<endl<<"Player 2 won!!";
            break;
        }
    }
    return 0;
}
