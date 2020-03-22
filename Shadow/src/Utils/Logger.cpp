#include <Utils/Logger.h>

namespace Shadow{
	namespace Utils {
		Logger::Logger(std::string name, std::string path) {
			m_file = std::ofstream(path, std::ios::trunc);
			currentLevel = 0;
			m_name = name;
		}

		Logger::~Logger() {
			flushLog();
		}

		void Logger::flushLog() {
			m_file.flush();
		}

		void Logger::log(std::string message, LoggerLevel level) {
			if (level < currentLevel)
				return;

			m_file << "[" << m_name << "]";

			switch (level) {
			case LOGGER_LEVEL_TRACE: {
				m_file << "[TRACE]: ";
				break;
			}
			case LOGGER_LEVEL_DEBUG: {
				m_file << "[DEBUG]: ";
				break;
			}
			case LOGGER_LEVEL_INFO: {
				m_file << "[INFO]: ";
				break;
			}
			case LOGGER_LEVEL_WARN: {
				m_file << "[WARN]: ";
				break;
			}
			case LOGGER_LEVEL_ERROR: {
				m_file << "[ERROR]: ";
				break;
			}

			}

			m_file << message << std::endl;
		}
		Logger* g_Logger;
	}
}