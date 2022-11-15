#pragma once
#include <string>
//#include <glfw3.h>
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