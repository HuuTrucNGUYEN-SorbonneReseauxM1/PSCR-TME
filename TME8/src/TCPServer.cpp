#include "TCPServer.h"
#include "Socket.h"
#include <iostream>
#include <unistd.h>
#include <cstring>
#include <vector>
#include <thread>
#include <dirent.h>
#include <sys/types.h>
#include <fstream>

namespace pr{
std::vector TCPServer::listFile(std::string rep){
	DIR *dir = opendir("rep");
	std::vector<std::string> vec;
	if(!dir){
		perror("opendir error");
		exit(EXIT_FAILURE);
	}
	struct dirent *dr;
	while((dr = readdir(dir))){
		std::cout << dr -> d_name << std::endl;
		vec.emplace_back(dr -> d_name);
	}
	return vec;
}

bool TCPServer::downloadFile(std::string rep){
	std::vector<std::string>filelist;
	filelist = TCPServer::listFile(rep);
	std::ofstream file; //user choice
	std::fstream fileStream(rep, std::ios::in);
	if(fileStream.is_open()){
		std::string na
		for(std::string f : filelist){
			if(f == )
		}
	}
}

void TCPServer::handleClient(Socket scom, std::string rep, int command){
	read(scom.getFD(), &rep, sizeof(rep));
	switch(command){
	case 1: listFile(rep);
	break;
	case 2: uploadFile();
	break;
	case 3: downloadFile();
	break;
	}
	scom.close();
	write(scom.getFD(), &rep, sizeof(rep));
	scom.close();
}

bool TCPServer::startServer0(int port, std::string rep, int command){
	ss = new ServerSocket(port);
	if(ss -> isOpen()){
		while(1){
			std::cout << "En attente sur le port " << port << std::endl;
			Socket sc = ss -> accept();
			if(sc.isOpen()){
				handleClient(sc, rep, command);
			}
		}
		return true;
	}
	return false;
}

bool TCPServer::startServer1(int port){
	ss = new ServerSocket(port);
	if(ss -> isOpen()){
		while(1){
			std::cout << "En attente sur le port " << port << std::endl;
			Socket sc = ss -> accept();
			if(sc.isOpen()){
				threads.emplace_back(&TCPServer::handleClient, this, sc);
			}
		}
		return true;
	}
	return false;
}

TCPServer::~TCPServer(){
	for(auto &t : threads){
		t.join();
	}
}
}
