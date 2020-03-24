#pragma once

#include <pspkernel.h>
#include <pspdebug.h>
#include <pspdisplay.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/select.h>
#include <string.h>
#include <pspnet.h>
#include <psputility.h>
#include <pspnet_inet.h>
#include <pspnet_apctl.h>
#include <pspnet_resolver.h>
#include <psphttp.h>
#include <pspsdk.h>
#include <pspwlan.h>
#include <sys/socket.h>
#include <unistd.h> 
#include <queue>

/** \addtogroup System Library
 *  @{
 */
namespace Shadow {
	namespace System {
		namespace Network {
			/**
			* Initializes libraries
			*/
			void Init();

			/**
			* Connects to your access point automatically
			*/
			bool autoConnect();

			/**
			* Connects to your access point with a GUI
			*/
			bool dialogConnect();

			/**
			* Cleans up libraries
			*/
			void Cleanup();
		}
	}
}
/** @} */