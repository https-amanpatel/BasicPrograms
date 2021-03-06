#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<fstream.h>
#include<conio.h>

using namespace std;

char un[20];
class Admin
{
    char name[20];
    int totsub;
    char subject[10][10];
    char mobile[15], mail[50], fname[20];
    char passwd[20], rpasswd[20];

    public:
    char rollno[15];

    /* This function is used to get the student data entry from the ADMIN portal.....all the records entries
    are made by this method */
    
    void getstdata()
    {
        cout<<"\nEnter the student Name : ";
        gets(name);
        cout<<"\nEnter the student ID/Roll No. : ";
        cin>>rollno;
        cout<<"\nEnter the student Father's Name : ";
        gets(fname);
        cout<<"\nEnter the Mobile Number : ";
        gets(mobile);
        cout<<"\nEnter the E-Mail ID : ";
        gets(mail);
        cout<<"\nEnter the Total Subjects : ";
        cin>>totsub;
        for(int i = 0; i < totsub; i++)
        {
            cout<<"\nEnter the Subject "<<i+1<<" Name : ";
            cin>>subject[i];
        } 
        cout<<"\nCreate Your Login password : ";
        cin>>passwd;
        cout<<"\nEnter the Unique keyword to Recover password : ";
        cin>>rpasswd;
        cout<<"\n\nPlease note your UserName is ID/Roll no.\n";
    } 
    /* This function authenticate the login of both the students & faculties.
    With their reference to their unique ID/PASSWORD login is provided */

    int login()
    {
        if((strcmp(::un, rollno))==0)
        {
            cout<<"\nEnter the Login Password : ";
            int len = 0;
            len = strlen(passwd);
            char inputpasswd[20];
            for(int i = 0; i < len; i++)
            {
                inputpasswd[i]=getch();
                cout<<"#";
            }
            inputpasswd[i]=NULL;
            
            // Cout<<"\nThe Entered password is "<<inputpasswd;

            if((strcmp(::un, rollno)==0)&&(strcmp(passwd, inputpasswd)==0))
            return 1;
            else
            return 0;
        }
        else 
        return 0;
    }

    /* This function help both the students & faculties to recover the password with the help of unique keyword provided 
    by the Admin */

    int recover()
    {
        //cout<<"\nThe Input Username is "<<::un;

        char key[20];
        if(strcmp(::un, rollno)==0)
        {
            cout<<"\nEnter the Unique keyword ( provided by Admin ) : ";
            cin>>key;
            if(strcmp(key, rpasswd)==0)
            {
                cout<<"\nYou are a Valid user.";
                cout<<"\nYour Password is "<<passwd;
                cout<<"\nPlease Exit To Login Again ";
                return 1;
            }
            else
            return 0;
        }
        else
        return 0;
    }

    // This function displays the faculty profile to the faculty at their respective portals

    int faprofile()
    {
        if((strcmp(::un, rollno)==0))
        {
            cout<<"\nFaculty Name          : "<<name;
            cout<<"\nFaculty Father's Name : "<<fname;
            cout<<"\nFaculty Mobile No.    : "<<mobile;
            cout<<"\nFaculty E-Mail ID     : "<<mail;
            return 1;
        }
        else
        return 0;
    }

    // This function displays the different subjects of the faculty at their respective portals

    int knowfasub()
    {
        if((strcmp(::un, rollno)==0))
        {
            cout<<"\nFaculty Total Subjects :- "<<totsub;
            for(int i = 0; i<totsub; i++)
            {
                cout<<"\n\tSubject "<<i+1<<" : "<<subject[i];
            }
            return 1;
        }
        else
        return 0;
    }

    // This function helps a faculty to add a subject in their module.

    void addfasub()
    {
        if((strcmp(::un, rollno)==0))
        {
            cout<<"\nEnter the New Subject : ";
            cin>>subject[totsub];
            totsub++;
            cout<<"\n\nNew Subject Added Successfully...";
        }
    }

    // This function helps a faculty to delete a subject from their module.

    void delfasub()
    {
        knowfasub();
        int de=0;
        if((strcmp(::un, rollno)==0))
        {
            if(totsub==0||totsub<0)
            {
                totsub=0;
                cout<<"\nNone Subjects Exists...";
                getch();
                exit(0);
            }
            cout<<"\nEnter the subject No. to be Deleted : ";
            cin>>de;
            if(de==totsub)
            {
                totsub--;
                strcpy(subject[totsub], " ");
            }
            else if(totsub==1)
            {
                totsub=0;
                strcpy(subject[totsub], " ");
            }
            else
            {
                de--;
                strcpy(subject[totsub], " ");
                for(int p=de; p<totsub; p++)
                {
                    strcpy(subject[p], subject[p+1]);
                }
                totsub--;
            }
            cout<<"\nRecords Updated Successfully...";
        }
    }

    // This function helps a faculty to modify his personal profile

    
}
