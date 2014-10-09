/*
===========================================================================

Copyright (c) 2010-2014 Darkstar Dev Teams

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see http://www.gnu.org/licenses/

This file is part of DarkStar-server source code.

===========================================================================
*/

#include "../common/socket.h"
#include "../common/sql.h"
#include <zmq.hpp>
#include "../common/cbasetypes.h"

class CBasicPacket;

namespace message
{
    enum MSGSERVTYPE : uint8
    {
        MSG_LOGIN,
        MSG_CHAT_TELL,
        MSG_CHAT_PARTY,
        MSG_CHAT_LINKSHELL,
        MSG_CHAT_YELL,
        MSG_CHAT_SERVMES,
        MSG_PT_INVITE,
        MSG_PT_INV_RES,
        MSG_PT_RELOAD,
        MSG_PT_DISBAND,
        MSG_DIRECT
    };

	extern zmq::context_t zContext;
	extern zmq::socket_t* zSocket;
	extern Sql_t* ChatSqlHandle;

	void init(const char* chatIp, uint16 chatPort);

	void listen();
    void parse(MSGSERVTYPE type, zmq::message_t* extra, zmq::message_t* packet);
    void send(MSGSERVTYPE type, void* data, size_t datalen, CBasicPacket* packet);
};