
#pragma once

namespace ETH
{
	class Packet
	{
	  public:
		class Header
		{
		  public:
			unsigned char destination[6];
			unsigned char source[6];
			unsigned short protocol;
		} header;

		unsigned char data[0];
	};
}
