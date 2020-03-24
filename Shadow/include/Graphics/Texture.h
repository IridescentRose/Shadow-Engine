#pragma once
#include <string>
#include <stdlib.h>
#include <malloc.h>
#include <png.h>
#include <pspdebug.h>
#include <pspgu.h>
#include <pspgum.h>
#include <psputils.h>
#include <pspdisplay.h>
#include <math.h>

/**
* The "texture object" class
*/
class Texture {
public:
	int width, height, pWidth, pHeight, ramSpace, colorMode, swizzled;

	unsigned int texID;

	std::string fileName;

	unsigned short* data; //32 bit pixel data in (likely) 8888 RGBA

	/**
	* Binds a texture into RAM with the given filters and modulation. Textures are clamped.
	* @param minFilter - The min filter, default is NEAREST
	* @param magFilter - The mag filter, default is NEAREST
	* @param modulate - Whether to interpolate with vertex color
	*/
	inline void bindTexture(int minFilter = GU_NEAREST, int maxFilter = GU_NEAREST, bool modulate = false) {
		if (modulate) {
			sceGuTexMode(colorMode, 0, 0, swizzled);
			sceGuTexFunc(GU_TFX_MODULATE, GU_TCC_RGBA);
			sceGuTexFilter(minFilter, maxFilter);
			sceGuTexOffset(0.0f, 0.0f);
			sceGuTexWrap(GU_CLAMP, GU_CLAMP);
			sceGuTexImage(0, pWidth, pHeight, pWidth, data);
		}
		else {
			sceGuTexMode(colorMode, 0, 0, 1);
			sceGuTexFunc(GU_TFX_REPLACE, GU_TCC_RGBA);
			sceGuTexFilter(minFilter, maxFilter);
			sceGuTexOffset(0.0f, 0.0f);
			sceGuTexWrap(GU_CLAMP, GU_CLAMP);
			sceGuTexImage(0, pWidth, pHeight, pWidth, data);
		}
	}

	/**
	* Binds a texture into RAM with the given filters and modulation. Textures repeat.
	* @param minFilter - The min filter, default is NEAREST
	* @param magFilter - The mag filter, default is NEAREST
	* @param modulate - Whether to interpolate with vertex color
	*/
	inline void bindTextureRepeat(int minFilter = GU_NEAREST, int maxFilter = GU_NEAREST, bool modulate = false) {
		if (modulate) {
			sceGuTexMode(colorMode, 0, 0, swizzled);
			sceGuTexFunc(GU_TFX_MODULATE, GU_TCC_RGBA);
			sceGuTexFilter(minFilter, maxFilter);
			sceGuTexOffset(0.0f, 0.0f);
			sceGuTexWrap(GU_REPEAT, GU_REPEAT);
			sceGuTexImage(0, pWidth, pHeight, pWidth, data);
		}
		else {
			sceGuTexMode(colorMode, 0, 0, 1);
			sceGuTexFunc(GU_TFX_REPLACE, GU_TCC_RGBA);
			sceGuTexFilter(minFilter, maxFilter);
			sceGuTexOffset(0.0f, 0.0f);
			sceGuTexWrap(GU_REPEAT, GU_REPEAT);
			sceGuTexImage(0, pWidth, pHeight, pWidth, data);
		}
	}

	/**
	* Binds mipmaps.
	* @param mipmap - The mipmap texture
	*/
	inline void bindMipMaps(Texture* mipmap) {
		sceGuTexMode(colorMode, 2, 0, swizzled);
		sceGuTexFunc(GU_TFX_MODULATE, GU_TCC_RGBA);
		sceGuTexOffset(0.0f, 0.0f);
		sceGuTexWrap(GU_CLAMP, GU_CLAMP);
		sceGuTexLevelMode(GU_TEXTURE_AUTO, 0.0f);
		sceGuTexFilter(GU_NEAREST_MIPMAP_NEAREST, GU_NEAREST);

		sceGuTexImage(0, pWidth, pHeight, pWidth, data);
		sceGuTexImage(1, pWidth, pHeight, pWidth, data);
		sceGuTexImage(2, mipmap->pWidth, mipmap->pHeight, mipmap->pWidth, mipmap->data);
	}

	/**
	* Gets the alpha value at position X, Y
	* @param x - The X position
	* @param y - The Y position
	*/
	inline int getAlpha(int x, int y) {
		float box_width = width / (width * 4 / 16);
		float box_height = height / (height / 8);
		float box_num = width / box_width;

		/// box width = 4
		/// box height = 8
		/// strip = 64
		/// strip number = 4096
		/// box number  = 64

		float box_x = x / box_width;
		box_x = (int)box_x;
		float box_y = y / box_height;
		box_y = (int)box_y;

		int box_number = box_x + (box_y * box_num);
		int box_first_index = box_number * box_width * box_height * 2;

		int x_in_box = x - (box_x * box_width);
		int y_in_box = y - (box_y * box_height);

		int end_index = box_first_index + ((x_in_box * 2) + (y_in_box * box_width * 2));

		return data[end_index + 1] >> 8;
	}
	/**
	* Gets the green value at position X, Y
	* @param x - The X position
	* @param y - The Y position
	*/
	inline int getGreen(int x, int y) {
		float box_width = width / (width * 4 / 16);
		float box_height = height / (height / 8);
		float box_num = width / box_width;

		/// box width = 4
		/// box height = 8
		/// strip = 64
		/// strip number = 4096
		/// box number  = 64

		float box_x = x / box_width;
		box_x = (int)box_x;
		float box_y = y / box_height;
		box_y = (int)box_y;

		int box_number = box_x + (box_y * box_num);
		int box_first_index = box_number * box_width * box_height * 2;

		int x_in_box = x - (box_x * box_width);
		int y_in_box = y - (box_y * 8);

		int end_index = box_first_index + ((x_in_box * 2) + (y_in_box * box_width * 2));

		return data[end_index] >> 8;
	}
	/**
	* Gets the red value at position X, Y
	* @param x - The X position
	* @param y - The Y position
	*/
	inline int getRed(int x, int y) {
		float box_width = width / (width * 4 / 16);
		float box_height = height / (height / 8);
		float box_num = width / box_width;


		float box_x = x / box_width;
		box_x = (int)box_x;
		float box_y = y / box_height;
		box_y = (int)box_y;

		int box_number = box_x + (box_y * box_num);
		int box_first_index = box_number * box_width * box_height * 2;

		int x_in_box = x - (box_x * box_width);
		int y_in_box = y - (box_y * box_height);

		int end_index = box_first_index + ((x_in_box * 2) + (y_in_box * box_width * 2));

		return data[end_index];
	}
	/**
	* Gets the blue value at position X, Y
	* @param x - The X position
	* @param y - The Y position
	*/
	inline int getBlue(int x, int y) {
		float box_width = width / (width * 4 / 16);
		float box_height = height / (height / 8);
		float box_num = width / box_width;

		/// box width = 4
		/// box height = 8
		/// strip = 64
		/// strip number = 4096
		/// box number  = 64

		float box_x = x / box_width;
		box_x = (int)box_x;
		float box_y = y / box_height;
		box_y = (int)box_y;

		int box_number = box_x + (box_y * box_num);
		int box_first_index = box_number * box_width * box_height * 2;

		int x_in_box = x - (box_x * box_width);
		int y_in_box = y - (box_y * box_height);

		int end_index = box_first_index + ((x_in_box * 2) + (y_in_box * box_width * 2));

		return data[end_index + 1];
	}
	/**
	* Sets the color, specified, at position X, Y
	* @param x - The X position
	* @param y - The Y position
	* @param red - The red value from 0-255
	* @param green - The green value from 0-255
	* @param blue - The blue value from 0-255
	* @param alpha - The alpha value from 0-255
	*/
	inline void setColour(int x, int y, unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha) {
		float box_width = width / (width * 4 / 16);
		float box_height = height / (height / 8);
		float box_num = width / box_width;

		/// box width = 4
		/// box height = 8
		/// strip = 64
		/// strip number = 4096
		/// box number  = 64

		float box_x = x / box_width;
		box_x = (int)box_x;
		float box_y = y / box_height;
		box_y = (int)box_y;

		int box_number = box_x + (box_y * box_num);
		int box_first_index = box_number * box_width * box_height * 2;

		int x_in_box = x - (box_x * box_width);
		int y_in_box = y - (box_y * box_height);

		int end_index = box_first_index + ((x_in_box * 2) + (y_in_box * box_width * 2));

		data[end_index] = (red) | (green << 8);
		data[end_index + 1] = (blue) | (alpha << 8);
	}
	/**
	* Binds with 3 levels of mip mapping
	* @param mip1 - First (large) level
	* @param mip2 - Second (medium) level
	* @param mip3 - Third (small) level
	*/
	inline void bindMipMaps(Texture* mip1, Texture* mip2, Texture* mip3) {
		sceGuTexMode(colorMode, 0, 0, swizzled);
		sceGuTexFunc(GU_TFX_MODULATE, GU_TCC_RGBA);
		sceGuTexFilter(GU_NEAREST, GU_NEAREST);
		sceGuTexOffset(0.0f, 0.0f);
		sceGuTexWrap(GU_CLAMP, GU_CLAMP);

		sceGuTexImage(0, pWidth, pHeight, pWidth, data);
		sceGuTexImage(1, mip1->pWidth, mip1->pHeight, mip1->pWidth, mip1->data);
		sceGuTexImage(2, mip2->pWidth, mip2->pHeight, mip2->pWidth, mip2->data);
		sceGuTexImage(3, mip3->pWidth, mip3->pHeight, mip3->pWidth, mip3->data);
	}

	/**
	Frees the data
	*/
	~Texture()
	{
		if (data != NULL)
			free(data);
	}
};
