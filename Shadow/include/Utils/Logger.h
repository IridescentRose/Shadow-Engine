#pragma once
#include <string>
#include <fstream>
#include <sstream>

namespace std {
	template < typename T > std::string to_string(const T& n)
	{
		std::ostringstream stm;
		stm << n;
		return stm.str();
	}
}


namespace Shadow {
	namespace Utils {

		/**
		* Different logging levels
		*/
		enum LoggerLevel {
			LOGGER_LEVEL_TRACE = -2,
			LOGGER_LEVEL_DEBUG = -1,
			LOGGER_LEVEL_INFO = 0,
			LOGGER_LEVEL_WARN = 1,
			LOGGER_LEVEL_ERROR = 2,
		};

		/**
		* A simple logger class
		*/
		class Logger {
		public:
			/**
			* Creates a logger with the logger name and path
			* @param name - The name of the logger
			* @param path - The path of the output file (default is log.log)
			*/
			Logger(std::string name, std::string path = "log.log");

			/**
			* Destroys the object and flushes the log to a file.
			*/
			~Logger();

			/**
			* Moves log data from here to the disk.
			*/
			void flushLog();

			/**
			* Adds a message with a logger level. Default is info.
			* @param message - The Message to output
			* @param level - The logger level (defaults to info)
			*/
			void log(std::string message, LoggerLevel level = LOGGER_LEVEL_INFO);

			/**
			* Sets the current level. Starts at Info. Messages below this level will not appear.
			*/
			int currentLevel;
		private:
			std::ofstream m_file;
			std::string m_name;
		};

		extern Logger* g_Logger;
	}
}