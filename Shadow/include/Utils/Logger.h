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

		enum LoggerLevel {
			LOGGER_LEVEL_TRACE = -2,
			LOGGER_LEVEL_DEBUG = -1,
			LOGGER_LEVEL_INFO = 0,
			LOGGER_LEVEL_WARN = 1,
			LOGGER_LEVEL_ERROR = 2,
		};

		class Logger {
		public:
			Logger(std::string name, std::string path = "log.log");
			~Logger();

			void flushLog();

			void log(std::string message, LoggerLevel level = LOGGER_LEVEL_INFO);

			int currentLevel;
		private:
			std::ofstream m_file;
			std::string m_name;
		};

		extern Logger* g_Logger;
	}
}