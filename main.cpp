#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <string>
#include <time.h>
#include <windows.h>
#include <fstream>

using namespace std;

struct date_time
{
    int _sec, _min, _hour, _mday, _mon, _year,  _wday;
    int _meri;  //  0=am and 1=pm
};

void num_to_text(int num, char* text)
{
    //char text[50];
    int temp=num;

    int hun=temp/10;
    int unit=temp%10;

    if(hun==0)
    {
        switch(unit)
        {
        case 0: strcpy(text, "");   break;
        case 1: strcpy(text, "One");    break;
        case 2: strcpy(text, "Two");    break;
        case 3: strcpy(text, "Three");  break;
        case 4: strcpy(text, "Four");   break;
        case 5: strcpy(text, "Five");   break;
        case 6: strcpy(text, "Six");    break;
        case 7: strcpy(text, "Seven");  break;
        case 8: strcpy(text, "Eight");  break;
        case 9: strcpy(text, "Nine");   break;
        }
        return;
        //return text;
    }

    else if(hun==1)
    {
        switch(unit)
        {
        case 0: strcpy(text, "Ten");    break;
        case 1: strcpy(text, "Eleven"); break;
        case 2: strcpy(text, "Twelve"); break;
        case 3: strcpy(text, "Thirteen");   break;
        case 4: strcpy(text, "Fourteen");   break;
        case 5: strcpy(text, "Fivteen");    break;
        case 6: strcpy(text, "Sixteen");    break;
        case 7: strcpy(text, "Seventeen");  break;
        case 8: strcpy(text, "Eighteen");   break;
        case 9: strcpy(text, "Ninteen");    break;
        }
        return;
        //return text;
    }

    switch(hun)
    {
    case 2: strcpy(text, "Twen");   break;
    case 3: strcpy(text, "Thir");   break;
    case 4: strcpy(text, "For");    break;
    case 5: strcpy(text, "Fif");    break;
    case 6: strcpy(text, "Six");    break;
    }

    switch(unit)
    {
    case 0: strcat(text, "ty"); break;
    case 1: strcat(text, "ty-one"); break;
    case 2: strcat(text, "ty-two"); break;
    case 3: strcat(text, "ty-three");   break;
    case 4: strcat(text, "ty-four");    break;
    case 5: strcat(text, "ty-five");    break;
    case 6: strcat(text, "ty-six"); break;
    case 7: strcat(text, "ty-seven");   break;
    case 8: strcat(text, "ty-eight");   break;
    case 9: strcat(text, "ty-nine");    break;
    }
    return;
    //return text;
}

void num_to_voice(int num)
{
    fstream f;
    f.open("clock.txt", ios::in);

    char clock[50];
    f>>clock;

    char text[100];
    char comm[100];
    int temp=num;

    int hun=temp/10;
    int unit=temp%10;

    if(hun==0)
    {
        strcpy(text, clock);
        switch(unit)
        {
        case 0: strcat(text, "00.wav");   break;
        case 1: strcat(text, "1.wav");    break;
        case 2: strcat(text, "2.wav");    break;
        case 3: strcat(text, "3.wav");  break;
        case 4: strcat(text, "4.wav");   break;
        case 5: strcat(text, "5.wav");   break;
        case 6: strcat(text, "6.wav");    break;
        case 7: strcat(text, "7.wav");  break;
        case 8: strcat(text, "8.wav");  break;
        case 9: strcat(text, "9.wav");   break;
        }
        strcpy(comm, "sounder ");
        strcat(comm, text);
        system(comm);
        return;
        //return text;
    }

    else if(hun==1)
    {
        strcpy(text, clock);
        switch(unit)
        {
        case 0: strcat(text, "10.wav");    break;
        case 1: strcat(text, "11.wav"); break;
        case 2: strcat(text, "12.wav"); break;
        case 3: strcat(text, "thir.wav");   break;
        case 4: strcat(text, "for.wav");   break;
        case 5: strcat(text, "fif.wav");    break;
        case 6: strcat(text, "six.wav");    break;
        case 7: strcat(text, "seven.wav");  break;
        case 8: strcat(text, "eight.wav");   break;
        case 9: strcat(text, "nine.wav");    break;
        }
        strcpy(comm, "sounder ");
        strcat(comm, text);
        system(comm);

        if(unit>2)
        {
            strcpy(comm, "sounder ");
            strcat(comm, clock);
            strcat(comm, "teen.wav");
            system(comm);
        }

        return;
        //return text;
    }

    else
    {
        strcpy(text, clock);
        switch(hun)
        {
        case 2: strcat(text, "twen.wav");   break;
        case 3: strcat(text, "thir.wav");   break;
        case 4: strcat(text, "for.wav");    break;
        case 5: strcat(text, "fif.wav");    break;
        case 6: strcat(text, "six.wav");    break;
        }
        strcpy(comm, "sounder ");
        strcat(comm, text);
        system(comm);

        strcpy(text, clock);
        switch(unit)
        {
        case 0: strcat(text, "ty.wav"); break;
        case 1: strcat(text, "ty1.wav"); break;
        case 2: strcat(text, "ty2.wav"); break;
        case 3: strcat(text, "ty3.wav");   break;
        case 4: strcat(text, "ty4.wav");    break;
        case 5: strcat(text, "ty5.wav");    break;
        case 6: strcat(text, "ty6.wav"); break;
        case 7: strcat(text, "ty7.wav");   break;
        case 8: strcat(text, "ty8.wav");   break;
        case 9: strcat(text, "ty9.wav");    break;
        }
        strcpy(comm, "sounder ");
        strcat(comm, text);
        system(comm);

        return;
        //return text;
    }
}

void get_time(date_time &dt)
{
    time_t t = time(0);   // get time now
    tm* now = localtime(&t);
    dt._sec=now->tm_sec;
    dt._min=now->tm_min;
    dt._hour=now->tm_hour;
    dt._mday=now->tm_mday;
    dt._mon=now->tm_mon;
    dt._year=now->tm_year + 1900;
    dt._wday=now->tm_wday;
    dt._meri=0;

    if(dt._hour>12)
    {
        dt._hour=dt._hour-12;
        dt._meri=1;
    }

    else if(dt._hour==0)
        dt._hour=12;
}

int main()
{
	system("cls");

	fstream f;
    f.open("clock.txt", ios::in);

    char clock[50];
    f>>clock;

	char speak_clock[100];
	char comm[100];
	char h[50], m[50];

	date_time dt;
	get_time(dt);

	num_to_text(dt._hour, h);
	//dt._min=0;
	num_to_text(dt._min, m);

	strcpy(speak_clock, "It's ");
	strcat(speak_clock, h);
	if(dt._min != 0)
        strcat(speak_clock, " ");
    else
        strcat(speak_clock, " o'clock");
	strcat(speak_clock, m);

	if(dt._meri==0)
        strcat(speak_clock, " am");
    else if(dt._meri==1)
        strcat(speak_clock, " pm");

    cout<<speak_clock;

    //_getch();

    strcpy(comm, "sounder ");
    strcat(comm, clock);
    strcat(comm, "HOUR1.wav");
    system(comm);
    //Sleep(1000);

    strcpy(comm, "sounder ");
    strcat(comm, clock);
    strcat(comm, "its.wav");
    system(comm);

    num_to_voice(dt._hour);
	//dt._min=23;
	num_to_voice(dt._min);

	strcpy(comm, "sounder ");
    strcat(comm, clock);
	if(dt._meri==0)
    {
        strcat(comm, "am.wav");
        system(comm);
    }
    else if(dt._meri==1)
    {
        strcat(comm, "pm.wav");
        system(comm);
    }


    //Sleep(1000);
    strcpy(comm, "sounder ");
    strcat(comm, clock);
    strcat(comm, "hour2.wav");
    system(comm);

	return 0;
}
