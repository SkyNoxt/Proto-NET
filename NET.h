
#pragma once

namespace NET
{
	unsigned short ntoh(unsigned short net)
	{
		unsigned char* data = (unsigned char*)&net;
		return data[1] << 0 | data[0] << 8;
	}

	unsigned int ntoh(unsigned int net)
	{
		unsigned char* data = (unsigned char*)&net;
		return data[3] << 0 | data[2] << 8 | data[1] << 16 | data[0] << 24;
	}
}
