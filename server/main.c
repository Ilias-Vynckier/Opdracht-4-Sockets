/*************************************************************************\
*                  Copyright (C) Michael Kerrisk, 2020.                   *
*                                                                         *
* This program is free software. You may use, modify, and redistribute it *
* under the terms of the GNU General Public License as published by the   *
* Free Software Foundation, either version 3 or (at your option) any      *
* later version. This program is distributed without any warranty.  See   *
* the file COPYING.gpl-v3 for details.                                    *
\*************************************************************************/

/* Listing 57-6 */

/* ud_ucase_sv.c

   A server that uses a UNIX domain datagram socket to receive datagrams,
   convert their contents to uppercase, and then return them to the senders.

   See also ud_ucase_cl.c.
*/
#include "ud_ucase.h"
#include <gpiod.h>
#include <time.h>

char IOtog(int test)
{

    printf("IOtog %s\r\n", test);

    int gpig, sped, vlag, freq;

    gpig = strtok(test, " "); // Splits string
    sped = strtok(NULL, " ");
    freq = atoi(sped);
    printf("dink %d\r\n", freq);

    const char *chipname = "gpiochip0";
    struct gpiod_chip *chip;
    struct gpiod_line *gpio26; // GPIO 19

    // Open GPIO chip
    chip = gpiod_chip_open_by_name(chipname);

    // Open GPIO lines
    gpio26 = gpiod_chip_get_line(chip, 26);

    // Open switch line for input
    gpiod_line_request_output(gpio26, "gpio26", NULL);

    time_t interval;
    clock_t prevClock;
    prevClock = clock();
    

    if (strcmp(gpig, "26") == 0)
    {
        while (1)
        {
            while (((clock() - prevClock)  / CLOCKS_PER_SEC) < freq)
            {
            };
            prevClock = clock();
            if (vlag == 1)
            {
                printf("on\n\r");
                gpiod_line_set_value(gpio26, 1);
            }
            if (vlag == 0)
            {
                printf("off\n\r");
                gpiod_line_set_value(gpio26, 0);
            }
            vlag = !vlag;
        }

        gpiod_line_release(gpio26);
    }
}

int main(int argc, char *argv[])
{
    struct sockaddr_un svaddr, claddr;
    int sfd, j;
    ssize_t numBytes;
    socklen_t len;
    char buf[BUF_SIZE];

    sfd = socket(AF_UNIX, SOCK_DGRAM, 0); /* Create server socket */
    if (sfd == -1)
        errExit("socket");

    /* Construct well-known address and bind server socket to it */

    /* For an explanation of the following check, see the erratum note for
       page 1168 at http://www.man7.org/tlpi/errata/. */

    if (strlen(SV_SOCK_PATH) > sizeof(svaddr.sun_path) - 1)
        fatal("Server socket path too long: %s", SV_SOCK_PATH);

    if (remove(SV_SOCK_PATH) == -1 && errno != ENOENT)
        errExit("remove-%s", SV_SOCK_PATH);

    memset(&svaddr, 0, sizeof(struct sockaddr_un));
    svaddr.sun_family = AF_UNIX;
    strncpy(svaddr.sun_path, SV_SOCK_PATH, sizeof(svaddr.sun_path) - 1);

    if (bind(sfd, (struct sockaddr *)&svaddr, sizeof(struct sockaddr_un)) == -1)
        errExit("bind");

    /* Receive messages, convert to uppercase, and return to client */

    printf("buf %c\r\n", buf[2]);

    for (;;)
    {
        len = sizeof(struct sockaddr_un);
        numBytes = recvfrom(sfd, buf, BUF_SIZE, 0,
                            (struct sockaddr *)&claddr, &len);
        if (numBytes == -1)
            errExit("recvfrom");

        IOtog(buf);

        printf("Server received %s bytes from %s\n", buf, //
               claddr.sun_path);

        /*FIXME: above: should use %zd here, and remove (long) cast */

        /*for (j = 0; j < numBytes; j++)
            buf[j] = toupper((unsigned char)buf[j]);

        if (sendto(sfd, buf, numBytes, 0, (struct sockaddr *)&claddr, len) !=
            numBytes)
            fatal("sendto");*/

        //bzero(buf, strlen(buf));// clears buff
        memset(buf, 0, sizeof(buf));
    }
}
