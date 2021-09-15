#include<bits/stdc++.h>

#include <stdio.h> // standard input and output library
#include <stdlib.h> // this includes functions regarding memory allocation
#include <string.h> // contains string functions
#include <errno.h> //It defines macros for reporting and retrieving error conditions through error codes
#include <time.h> //contains various functions for manipulating date and time
#include <unistd.h> //contains various constants
#include <sys/types.h> //contains a number of basic derived types that should be used whenever appropriate
//#include <arpa/inet.h> // defines in_addr structure
//#include <sys/socket.h> // for socket creation
// #include <netinet/in.h> //contains constants and structures needed for internet domain addresses

using namespace std;



typedef long long ll;
typedef long double ld;
typedef double db;
typedef string str;

typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<db, db> pd;

typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ll> vl;
typedef vector<db> vd;
typedef vector<str> vs;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<pd> vpd;

#define mp make_pair
#define f first
#define s second
#define sz(x) (int) (x).size()
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sor(x) sort(all(x))
#define rsz resize
#define resz resize
#define ins insert
#define ft front()
#define bk back()
#define pf push_front
#define pb push_back
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound

#define loop(i, a, b) for(int i = (a); i < (b); ++i)
#define loop0(i, a) loop(i, 0, a)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define F0R(i, a) FOR(i,0,a)
#define ROF(i, a, b) for (int i = (b) - 1; i >= (a); --i)
#define R0F(i, a) ROF(i, 0, a)
#define trav(a, x) for (auto& a : x)

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output1.txt","w",stdout);
	#endif

    time_t clock;
char dataSending[1025]; // Actually this is called packet in Network Communication, which contain data and send through.
int clintListn = 0, clintConnt = 0;
struct sockaddr_in ipOfServer;
clintListn = socket(AF_INET, SOCK_STREAM, 0); // creating socket
memset(&ipOfServer, '0', sizeof(ipOfServer));
memset(dataSending, '0', sizeof(dataSending));
ipOfServer.sin_family = AF_INET;
ipOfServer.sin_addr.s_addr = htonl(INADDR_ANY);
ipOfServer.sin_port = htons(2017); // this is the port number of running server
bind(clintListn, (struct sockaddr*)&ipOfServer , sizeof(ipOfServer));
listen(clintListn , 20);
 
while(1)
{
printf("\n\nHi,Iam running server.Some Client hit me\n"); // whenever a request from client came. It will be processed here.
clintConnt = accept(clintListn, (struct sockaddr*)NULL, NULL);
 
clock = time(NULL);
snprintf(dataSending, sizeof(dataSending), "%.24s\r\n", ctime(&clock)); // Printing successful message
write(clintConnt, dataSending, strlen(dataSending));
 
        close(clintConnt);
        sleep(1);
     }
 
     return 0;
}