#ifndef __FUNCTIONS__ /* Include guard */
#define __FUNCTIONS__

void Mod_handling(int argc, char **argv, int **modes);

int idokezeles();

int FindPID();

void BMPcreator(int *Values, int NumValues);

int Measurement(int **Values);

void SendViaFile(int *Values, int NumValues);

void ReceiveViaFile(int sig);

void SendViaSocket(int *Values, int NumValues);

void ReceiveViaSocket();

void SignalHandler(int sig);

#endif // FOO_H_
