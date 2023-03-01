
#pragma once

#include "NET.h"
#include "IP.h"

namespace TCP
{
	const unsigned short protocol = 0x06;

	class Packet
	{
	  public:
		class Header
		{
		  public:
			unsigned short source;
			unsigned short destination;
			unsigned int sequence;
			unsigned int acknowledgment;
			union
			{
				unsigned short flags;
				struct
				{
					unsigned short fin : 1;
					unsigned short syn : 1;
					unsigned short rst : 1;
					unsigned short psh : 1;
					unsigned short ack : 1;
					unsigned short urg : 1;
					unsigned short ece : 1;
					unsigned short cwr : 1;
					unsigned short res : 4;
					unsigned short dof : 4;
				};
			};
			unsigned short window;
			unsigned short checksum;
			unsigned short urgent;
		} header;

		unsigned char data[0];

		unsigned short checksum(const IP::Packet::Header& ip)
		{
			unsigned short length = NET::ntoh(ip.length) - sizeof(ip);
			IP::PseudoHeader pseudoHeader{ ip.source, ip.destination, NET::ntoh(protocol), NET::ntoh(length) };
			return IP::checksum((unsigned short*)&pseudoHeader, sizeof(IP::PseudoHeader), ~IP::checksum((unsigned short*)this, length));
		}
	};
}
