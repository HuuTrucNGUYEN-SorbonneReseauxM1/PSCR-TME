#ifndef SRC_TCPSERVER_H_
#define SRC_TCPSERVER_H_

#include <thread>
#include "ServerSocket.h"
#include "ConnectionHandler.h"
#include <vector>
#include <fstream>

namespace pr {

// un serveur TCP, la gestion des connections est déléguée
class TCPServer {
	ServerSocket * ss; // la socket d'attente si elle est instanciee
	//ConnectionHandler * handler; // le gestionnaire de session passe a la constru
	std::vector<std::thread> threads;
	// a completer
public :
	//TCPServer(ConnectionHandler * handler): ss(nullptr),handler(handler) {}
	// Tente de creer une socket d'attente sur le port donné
	std::vector listFile(std::string rep);
	bool uploadFile(std::string rep);
	bool downloadFile(std::string rep);
	bool startServer0(int port, std::string repertoire, int command);
	bool startServer1(int port);
	void handleClient(Socket scom, std::string rep, int command);
	// stoppe le serveur
	//void stopServer () ;
	~TCPServer();
};

} // ns pr

#endif /* SRC_TCPSERVER_H_ */
