#include "pch.h"

class MemoryBuffer
{
public:
	bool Create(int width, int height, int depth)
	{
		if (depth!=32 || width <= 0 || height <= 0) //先只支持32位好了
			return false;
		if (depth % 4 != 0||width<=0||height<=0)
			return false;
		size = width*height*depth / 4;
		data = (char*)malloc(size);
		memset(data, 0, size);
	}
	void DrawTest()
	{	
		for (int j = 0; j < height;j++)
		{
			for (int i = 0; i < width; i++)
			{
				data[4 * i * j] = 0xFFFFFFFF;
			}
		}



	}
	void DrawLine(POINT a,POINT b,COLORREF color)
	{

	}
protected:
private:
	int size;
	int width;
	int height;
	char* data;
};