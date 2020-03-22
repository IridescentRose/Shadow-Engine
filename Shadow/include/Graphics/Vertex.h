#pragma once

namespace Shadow
{
	namespace Graphics
	{
		typedef struct
		{
			unsigned int color;
			float x,y,z;
		}__attribute__((packed)) ColoredVertex;

        typedef struct
		{
			float x,y,z;
		}__attribute__((packed)) ColoredVertex2;

		typedef struct
		{
			float u,v;
			unsigned int color;
			float x,y,z;
		}__attribute__((packed)) Vertex;

		typedef struct
		{
			float u,v;
			unsigned int color;
			unsigned char x,y,z;
		}__attribute__((packed)) PackedVertex;

		typedef struct
		{
			float u,v;
			float x,y,z;
		}__attribute__((packed)) TexturedVertex;

		typedef struct
		{
			unsigned short u, v;
			short x, y, z;
		}__attribute__((packed)) TexturedVertex16;

		typedef struct
		{
			unsigned char u, v;
			char x, y, z;
		}__attribute__((packed)) TexturedVertex8;

		struct MorphVertex
		{
			TexturedVertex v0;
			TexturedVertex v1;
		};
	}
}
