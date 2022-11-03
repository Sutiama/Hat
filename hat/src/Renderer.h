#pragma once
#include <string>
#include <glfw/glfw3.h>


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