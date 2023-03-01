
#pragma once

#include "NET.h"
#include "IP.h"

namespace UDP
{
	const unsigned short protocol = 0x11;

	class Packet
	{
	  public:
		class Header
		{
		  public:
			unsigned short source;
			unsigned short destination;
			unsigned short length;
			unsigned short checksum;
		} header;

		unsigned char data[0];

		unsigned short checksum(const IP::Packet::Header& ip)
		{
			IP::PseudoHeader pseudoHeader{ ip.source, ip.destination, NET::ntoh(protocol), header.length };
			return IP::checksum((unsigned short*)&pseudoHeader, sizeof(IP::PseudoHeader), ~IP::checksum((unsigned short*)this, NET::ntoh(header.length)));
		}
	};
}
