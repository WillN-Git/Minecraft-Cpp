#ifndef MINECRAFT_SERVER_H
#define MINECRAFT_SERVER_H
#include "core.h"

typedef struct _ENetPacket ENetPacket;
typedef struct _ENetPeer ENetPeer;

namespace Minecraft
{
	namespace Server
	{
		void init();

		void update();

		void broadcast(ENetPacket* packet);

		void sendClient(ENetPeer* peer, ENetPacket* packet);

		void free();

		constexpr uint16 listeningPort = 7317;
		extern uint64 serverGameTime;
	}
}

#endif