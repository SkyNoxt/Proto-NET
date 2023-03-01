
#pragma once

namespace IP
{
	unsigned short checksum(unsigned short* data, unsigned int length, unsigned short initial = 0xffff)
	{
		unsigned int sum = (length & 1) ? ((unsigned char*)data)[length - 1] : 0 + initial;
		length /= 2;
		while(length--)
			sum += *data++;
		return ~(sum += (sum >> 16));
	}

	const unsigned short protocol = 0x0800;

	class Packet
	{
	  public:
		class Header
		{
		  public:
			unsigned char header : 4, version : 4;
			unsigned char service;
			unsigned short length;
			unsigned short id;
			union
			{
				unsigned short fragmentOffset;
				struct
				{
					unsigned short offset : 13;
					unsigned short moreFragments : 1;
					unsigned short dontFragment : 1;
					unsigned short reserved : 1;
				};
			};
			unsigned char time;
			unsigned char protocol;
			unsigned short checksum;
			unsigned int source;
			unsigned int destination;
		} header;

		unsigned char data[0];

		unsigned short checksum()
		{
			return IP::checksum((unsigned short*)this, sizeof(Header));
		}
	};

	class PseudoHeader
	{
	  public:
		unsigned int source;
		unsigned int destination;
		unsigned short protocol;
		unsigned short length;
	};
}
