#ifndef __FUNCTIONS__ /* Include guard */
#define __FUNCTIONS__

int idokezeles();

int FindPID();

void BMPcreator(int *Values, int NumValues);

int Measurement(int **Values);

void SendViaFile(int *Values, int NumValues);

void ReceiveViaFile(int sig);

void SendViaSocket(int *Values, int NumValues);

void ReceiveViaSocket();

#endif // FOO_H_
