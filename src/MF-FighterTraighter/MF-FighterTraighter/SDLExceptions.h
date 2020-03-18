#pragma once
#include <stdexcept>

namespace SDLExceptions 
{
	class SDLException : public std::logic_error 
	{
	public:
		SDLException(const std::string& what) : logic_error("SDL error: " + what) {}
		SDLException(const char* what) : logic_error("SDL error: " + std::string(what)) {}
		SDLException(const SDLException&) = delete;
		SDLException operator=(const SDLException&) = delete;
	};

	class TTFException : public std::logic_error
	{
	public:
		TTFException(const std::string& what) : logic_error("TTF error: " + what) {}
		TTFException(const char* what) : logic_error("TTF error: " + std::string(what)) {}
		TTFException(const TTFException&) = delete;
		TTFException operator=(const TTFException&) = delete;
	};
}