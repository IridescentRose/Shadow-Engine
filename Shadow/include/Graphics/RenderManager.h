#pragma once

#include <stdarg.h>
#include <Graphics/Vertex.h>
#include <Graphics/TextureUtil.h>

#include <intraFont.h>

//psp headers
#include <pspgu.h>
#include <pspgum.h>
#include <pspctrl.h>
#include <pspkernel.h>
#include <pspdisplay.h>
#include <pspdebug.h>
#include <psppower.h>
#include <psptypes.h>
#include <pspge.h>
#include <psputils.h>

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


#define BUF_WIDTH (512)
#define SCR_WIDTH (480)
#define SCR_HEIGHT (272)

/** \addtogroup renderer Graphics Library
 *  @{
 */

namespace Shadow
{
	namespace Graphics
	{
		/**
		* The main rendering utility and frame manager
		*/
		class RenderManager
		{
		public:
			
			/**
			* Initializes the sceGu library
			*/
			void Init();

			/**
			* Initializes and loads the font at "assets/font.pgf" alongside the PSP hardware backups.
			*/
			void InitDebugFont();
			
			/**
			* Sets the font style, including size, color, shadows (broken), and accepts intrafont arguments. Angle is no longer used.
			* @param size - The font size
			* @param color - The GU_COLOR for the font
			* @param shadowColor - The GU_COLOR for the font shadow (broken / corrupted)
			* @param options - INTRAFONT options
			* @param angle - Deprecated, set to 0.
			*/
			void SetFontStyle(float size, unsigned int color, unsigned int shadowColor, unsigned int options, float angle);

			/**
			* Equivalent to printf, but shows up graphically.
			* @param x - X position
			* @param y - Y position
			* @param message - Your formatted string
			* @param ... - Any other arguments
			*/
			void DebugPrint(int x,int y, const char *message, ...);

			/**
			* Clears the screen and buffers
			*/
			void CleanBuffers();

			/**
			* Begins a frame
			*/
			void StartFrame();

			/**
			* Ends a frame
			*/
			void EndFrame();


			/**
			* Begins a dialog frame
			*/
			void StartDialog();

			/**
			* Ends a dialog frame
			*/
			void EndDialog();

			/**
			* Sets the clear color of the screen
			*/
			void SetClearColor(float r,float g,float b,float a);

			/**
			* Sets to standard orthographic mode, with 0, 0 being the top left corner.
			*/
			void SetOrtho();

			/**
			* Used to set the perspective matrix
			*/
			void SetPerspective(float _fov,float _aspect,float _znear,float _zfar);
			
			/**
			* Render to texture (untested)
			*/
			void DrawToTexture(Texture* offscreenTexture );

			/**
			*	Sets clear color to the GU_COLOR
			*/
			void SetClearColour(unsigned int color);


			protected:
				



		private:
			unsigned int cleanColor;
			float fovv;

            void* _fbp0;
			void* _fbp1;
			void* _zbp;
			void* _frameBuffer;

			char list[0x20000] __attribute__((aligned(64)));//__attribute__((aligned(16))) list[262144]
			int listNum;

			bool mVerticalSync;

			ScePspFMatrix4 proj;
			ScePspFMatrix4 view;
			ScePspFMatrix4 projection_view_matrix;

			//debug font
			intraFont* debugFont;
			intraFont* numFont;
			intraFont* engFont;
			intraFont* rusFont;
			intraFont* jpn0;
			intraFont* kr0; 
			intraFont* arib;
			intraFont* chn; 
			intraFont* defFont; 
			float fontVerticalShift;
			int fontType;

			float fov,aspect,znear,zfar;

			int screenNumber;

		private:

			//cpu and gpu timing
			int g_vbl_count;	// previous vblank count
			int g_vbl_step;		// previous vblank step
			int g_vbl_time;		// previous vblank time
			int g_cpu_load;		// current cpu load
			int g_gpu_load;		// current gpu load
			int g_frame_count;
			bool performanceCounter;

		};

		/**
		* The global render manager instance
		*/
		extern RenderManager g_RenderManager;
	}

}

/** @} */