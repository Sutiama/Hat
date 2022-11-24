#pragma once
#include <string>

//#include <glad.h>


class Renderer
{
	public:

		static void init();
		static void release();
	private:

};

class ConsoleRenderer
{
	public:

		void Draw2D(const std::string& map);
	private:
};