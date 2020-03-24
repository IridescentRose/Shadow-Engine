#pragma once
#include <string>
#include <Graphics/Vertex.h>
#include <Graphics/Texture.h>
namespace Shadow
{
	namespace Graphics
	{

		/**
		* The 2D graphical sprite class
		*/
		class Sprite
		{
		public:
			/**
			Default Constructor (Invalid)
			*/
			Sprite();

			/**
			* Makes a sprite whose width and height are defined by the texture
			*/
			Sprite(const char* filename);

			/**
			* Makes a sprite with a texture, given the two x y positions and the size
			* @param startW - The starting X
			* @param startH - The starting Y
			* @param endW - The size on the X axis
			* @param endH - The size on the Y axis
			*/
			Sprite(const char* filename,int startW,int startH,int endW,int endH);

			/**
			* Makes a sprite whose width and height are defined by the texture
			*/
			Sprite(Texture* texture);

			/**
			* Makes a sprite with a texture, given the two x y positions and the size
			* @param startW - The starting X
			* @param startH - The starting Y
			* @param endW - The size on the X axis
			* @param endH - The size on the Y axis
			*/
			Sprite(Texture* texture, int startW, int startH, int endW, int endH);

			/**
			* Makes a sprite with a texture, given the two x y positions and the size
			* @param startW - The starting X
			* @param startH - The starting Y
			* @param endW - The size on the X axis
			* @param endH - The size on the Y axis
			*/
			Sprite(Texture* texture, int startW, int startH, int endW, int endH, bool obr);

			/**
			* Deletes the sprite data (not the texture)
			*/
			~Sprite();


			/**
			* Sets the position
			*/
			void SetPosition(float x,float y);


			/**
			* Sets the scale
			*/
			void Scale(float x,float y);


			/**
			* Sets the scale from the x to the right (loading bar)
			*/
			void NewScale(float x);

			/**
			* Deletes the texture
			*/
			void RemoveImage();


			/**
			* Draws the sprite
			*/
			void Draw();

			/**
			* Draws the sprite without modulation
			*/
			void DrawNoModSet();


			/**
			* Draws the sprite with forced linear filtering
			*/
			void DrawLinear();


			/**
			* Sets the alpha value (0-255)
			*/
			void Alpha(float _alpha);

			/**
			* Sets the RGB value (0-255)
			*/
			void RGB(float _red, float _green, float _blue);


			/**
			* Gets the X position
			*/
			float GetPositionX();

			/**
			* Gets the Y position
			*/
			float GetPositionY();

		private:
			Texture* tex;
			TexturedVertex *vertices;

			float scaleX,scaleY;
			float posX,posY;
			int width,height;
			int red, green, blue, alpha;
		};

	}

}