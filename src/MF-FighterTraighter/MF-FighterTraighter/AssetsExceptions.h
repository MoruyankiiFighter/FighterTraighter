#pragma once
#include <stdexcept>

namespace AssetsExceptions
{
	class TextureException : public std::runtime_error 
	{
	public:
		TextureException(const std::string& what, const std::string& textureFile) : runtime_error("Texture error: " + what + textureFile) {}
		TextureException(const char* what, const char* textureFile) : runtime_error("Texture error: " + std::string(what) + textureFile) {}
		TextureException(const TextureException&) = delete;
		TextureException operator=(const TextureException&) = delete;
	};

	class FontException : public std::runtime_error 
	{
	public:
		FontException(const std::string& what, const std::string& fontFile) : runtime_error("Font error: " + what + fontFile) {}
		FontException(const char* what, const char* fontFile) : runtime_error("Font error: " + std::string(what) + std::string(fontFile)) {}
		FontException(const FontException&) = delete;
		FontException operator=(const FontException&) = delete;
	};
};

