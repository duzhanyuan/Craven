#pragma once

#include "../common/configure.hpp"

//!Class for the daemon's configuration.
class DaemonConfigure : public Configure
{
	static std::map<std::string, boost::log::trivial::severity_level> level_map;
public:
	//!Constructor for the daemon config class.
	/*!
	 * \param argc passed through to the base class.
	 * \param argv passed through to the base class.
	 */
	DaemonConfigure(int argc, char** argv);

	//! Returns true if a daemon has been requested.
	bool daemonise() const;

	boost::filesystem::path log_path() const;

	//! Enum specifying how much output goes to stdout.
	enum loudness {
		normal, //!< normal: warning and above
		quiet, //!< quiet: critical and above
		verbose, //!< verbose: info and above
		daemon, //!< nothing -- we're a daemon, so we don't have a console.
	};

	//! Get the desired loudness on stderr.
	loudness output_loudness() const;

	//! Returns the desired log level for the file log.
	boost::log::trivial::severity_level log_level() const;

protected:
	boost::log::trivial::severity_level log_level_;
};
