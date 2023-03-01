
#pragma once

namespace VLAN
{
	const unsigned short protocol = 0x8100;

	class Packet
	{
	  public:
		class Header
		{
		  public:
			union
			{
				unsigned short TCI;
				struct
				{
					unsigned short identifier : 12;
					unsigned short format : 1;
					unsigned short priority : 3;
				};
			};
			unsigned short protocol;
		} header;

		unsigned char data[0];
	};
}
