/*
#	IPRechner
#   main.c
#	Copyright (c) 2019 j-bill
#   github.com/j-bill
#	This file is part of "IPRechner" which is released under the MIT license.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

void header()
{
    system("@cls||clear");
    printf("|tolle markierung ascii codes und so|\n");
    printf("|IP RECHNER|\n");
    printf("|tolle markierung ascii codes und so|\n");
    printf("copyright: Julian Billinger\n");
}

int main()
{
    int IP1, IP2, IP3, IP4, CIDR;
    int bcIP1, bcIP2, bcIP3, bcIP4;
    int IPeingabe = 0;
    int CIDReingabe = 0;
    double aHosts;

   header();
    //Begrüßerung
    printf("erklären was programm macht");

    //IP EINGABE
    while (IPeingabe == 0)
    {
           header();
        printf("\nBitte IP im Format XXX.XXX.XXX.XXX eingeben: ");
        scanf("%i.%i.%i.%i", &IP1, &IP2, &IP3, &IP4);
        //Prüfung ob IP Sinn macht
        if (IP1 > 255|| IP2 > 255 || IP3 > 255 || IP4 > 255 || IP1 == 127 || IP1 == 255 || IP1 < 1 || IP2 < 0 || IP3 < 0 || IP4 < 0)
        {
               header();
            printf("Fehler: du bist dumm. Fix das Format von der IP");
            printf("\npress se button to continue");
            getch();
        }
        else
            IPeingabe = 1;

    }

    //CIDR EINGABE
    while (CIDReingabe == 0)
    {
           header();
        printf("\nBitte CIDR eingeben: ");
        scanf("%i", &CIDR);
        //Prüfung ob CIDR Sinn macht
        if (CIDR < 0  || CIDR > 30)
        {
               header();
            printf("\nare you okay?");
            printf("\npress se button to continue");
            getch();
        }
        else if (CIDR <= 7 && CIDR >= 0)
        {
               header();
            printf("Adressbereiche der Gr\224\341e /0 bis /7 werden in der Praxis nicht\nals einzelnes Subnetz verwendet, sondern in mehrere Subnetze unterteilt.");
            printf("\npress se button to continue");
            getch();
        }
        else
            CIDReingabe = 1;


    }

    //Anzahl Hosts berechnen. fuck you inan :)
    int i = 32 - CIDR;
    aHosts = pow(2, i) - 2;

    //Netzadresse und Broadcast Berechenung
    if (CIDR == 30)
    {
        while (IP4 % 4 != 0)
            IP4--;
        bcIP1 = IP1;
        bcIP2 = IP2;
        bcIP3 = IP3;
        bcIP4 = IP4 + 3;
    }
    else if (CIDR == 29)
    {
        while (IP4 % 8 != 0)
            IP4--;
        bcIP1 = IP1;
        bcIP2 = IP2;
        bcIP3 = IP3;
        bcIP4 = IP4 + 7;
    }
    else if (CIDR == 28)
    {
        while (IP4 % 16 != 0)
            IP4--;
        bcIP1 = IP1;
        bcIP2 = IP2;
        bcIP3 = IP3;
        bcIP4 = IP4 + 15;
    }
    else if (CIDR == 27)
    {
        while (IP4 % 32 != 0)
            IP4--;
        bcIP1 = IP1;
        bcIP2 = IP2;
        bcIP3 = IP3;
        bcIP4 = IP4 + 31;
    }
    else if (CIDR == 26)
    {
        while (IP4 % 64 != 0)
            IP4--;
        bcIP1 = IP1;
        bcIP2 = IP2;
        bcIP3 = IP3;
        bcIP4 = IP4 + 63;
    }
    else if (CIDR == 25)
    {
        while (IP4 % 128 != 0)
            IP4--;
        bcIP1 = IP1;
        bcIP2 = IP2;
        bcIP3 = IP3;
        bcIP4 = IP4 + 127;
    }
    else if (CIDR == 24)
    {
        IP4 = 0;
        bcIP1 = IP1;
        bcIP2 = IP2;
        bcIP3 = IP3;
        bcIP4 = 255;
    }
    else if (CIDR == 23)
    {
        while (IP3 % 2 != 0)
            IP3--;
        IP4 = 0;
        bcIP1 = IP1;
        bcIP2 = IP2;
        bcIP3 = IP3+1;
        bcIP4 = 255;
    }
    else if (CIDR == 22)
    {
        while (IP3 % 4 != 0)
            IP3--;
        IP4 = 0;
        bcIP1 = IP1;
        bcIP2 = IP2;
        bcIP3 = IP3+3;
        bcIP4 = 255;
    }
    else if (CIDR == 21)
    {
        while (IP3 % 8 != 0)
            IP3--;
        IP4 = 0;
        bcIP1 = IP1;
        bcIP2 = IP2;
        bcIP3 = IP3+7;
        bcIP4 = 255;
    }
    else if (CIDR == 20)
    {
        while (IP3 % 16 != 0)
            IP3--;
        IP4 = 0;
        bcIP1 = IP1;
        bcIP2 = IP2;
        bcIP3 = IP3+15;
        bcIP4 = 255;
    }
    else if (CIDR == 19)
    {
        while (IP3 % 32 != 0)
            IP3--;
        IP4 = 0;
        bcIP1 = IP1;
        bcIP2 = IP2;
        bcIP3 = IP3+31;
        bcIP4 = 255;
    }
    else if (CIDR == 18)
    {
        while (IP3 % 64 != 0)
            IP3--;
        IP4 = 0;
        bcIP1 = IP1;
        bcIP2 = IP2;
        bcIP3 = IP3+63;
        bcIP4 = 255;
    }
    else if (CIDR == 17)
    {
        while (IP3 % 128 != 0)
            IP3--;
        IP4 = 0;
        bcIP1 = IP1;
        bcIP2 = IP2;
        bcIP3 = IP3+127;
        bcIP4 = 255;
    }
    else if (CIDR == 16)
    {
        IP3 = 0;
        IP4 = 0;
        bcIP1 = IP1;
        bcIP2 = IP2;
        bcIP3 = 255;
        bcIP4 = 255;
    }
    else if (CIDR == 15)
    {
        while (IP2 % 2 != 0)
            IP2--;
        IP3 = 0;
        IP4 = 0;
        bcIP1 = IP1;
        bcIP2 = IP2+1;
        bcIP3 = 255;
        bcIP4 = 255;
    }
    else if (CIDR == 14)
    {
        while (IP2 % 4 != 0)
            IP2--;
        IP3 = 0;
        IP4 = 0;
        bcIP1 = IP1;
        bcIP2 = IP2+3;
        bcIP3 = 255;
        bcIP4 = 255;
    }
    else if (CIDR == 13)
    {
        while (IP2 % 8 != 0)
            IP2--;
        IP3 = 0;
        IP4 = 0;
        bcIP1 = IP1;
        bcIP2 = IP2+7;
        bcIP3 = 255;
        bcIP4 = 255;
    }
    else if (CIDR == 12)
    {
        while (IP2 % 16 != 0)
            IP2--;
        IP3 = 0;
        IP4 = 0;
        bcIP1 = IP1;
        bcIP2 = IP2+15;
        bcIP3 = 255;
        bcIP4 = 255;
    }
    else if (CIDR == 11)
    {
        while (IP2 % 32 != 0)
            IP2--;
        IP3 = 0;
        IP4 = 0;
        bcIP1 = IP1;
        bcIP2 = IP2+31;
        bcIP3 = 255;
        bcIP4 = 255;
    }
    else if (CIDR == 10)
    {
        while (IP2 % 64 != 0)
            IP2--;
        IP3 = 0;
        IP4 = 0;
        bcIP1 = IP1;
        bcIP2 = IP2+63;
        bcIP3 = 255;
        bcIP4 = 255;
    }
    else if (CIDR == 9)
    {
        while (IP2 % 128 != 0)
            IP2--;
        IP3 = 0;
        IP4 = 0;
        bcIP1 = IP1;
        bcIP2 = IP2+127;
        bcIP3 = 255;
        bcIP4 = 255;
    }
    else if (CIDR == 8)
    {
        IP2 = 0;
        IP3 = 0;
        IP4 = 0;
        bcIP1 = IP1;
        bcIP2 = 255;
        bcIP3 = 255;
        bcIP4 = 255;
    }

    //Gewünschter Output
       header();
    printf("\nAnzahl Hosts = %0.f", aHosts); //DONE
    printf("\nNetzadresse = %i.%i.%i.%i", IP1, IP2, IP3, IP4); //DONE
    printf("\nBroadcast IP = %i.%i.%i.%i", bcIP1, bcIP2, bcIP3, bcIP4); //DONE
    printf("\nHost IP von = %i.%i.%i.%i", IP1, IP2, IP3, IP4+1); //DONE
    printf("\nHost IP bis = %i.%i.%i.%i", bcIP1, bcIP2, bcIP3, bcIP4-1); //DONE
    printf("\n\n\n\n\n");

    return 0;
}
