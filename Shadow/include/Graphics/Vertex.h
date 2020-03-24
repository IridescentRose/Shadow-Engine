#pragma once

namespace Shadow
{
	namespace Graphics
	{

		/**
		* Defines a vertex with vertex colors (modulated) and XYZ coordinates
		*/
		typedef struct
		{
			unsigned int color;
			float x,y,z;
		}__attribute__((packed)) ColoredVertex;

		/**
		* Defines a vertex with UV textures, vertex colors (modulated), and XYZ coordinates
		*/
		typedef struct
		{
			float u,v;
			unsigned int color;
			float x,y,z;
		}__attribute__((packed)) Vertex;

		/**
		* Defines a vertex with UV textures, vertex colors (modulated), and packed XYZ coordinates
		*/
		typedef struct
		{
			float u,v;
			unsigned int color;
			unsigned char x,y,z;
		}__attribute__((packed)) PackedVertex;

		/**
		* Defines a vertex with UV texture coordinates and XYZ coordinates
		*/
		typedef struct
		{
			float u,v;
			float x,y,z;
		}__attribute__((packed)) TexturedVertex;

	}
}
