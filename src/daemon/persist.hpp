#pragma once

#include <unordered_map>

namespace change
{
	//! Handles the persistent storage part of the change transfer module
	class persistence
	{
	public:
		//! Constructs the persistent storage manager with root as its managed
		//! directory.
		persistence(const boost::filesystem::path& root);

		//! Checks if the given key exists
		bool exists(const std::string& key) const;

		//! Checks if the given version of the given key exists (also returns false if
		//! exists(key) returns false.
		bool exists(const std::string& key, const std::string& version) const;

		//! Retrieve the path to the given version of key, throwing if it does not
		//! exist.
		boost::filesystem::path operator()(const std::string& key, const std::string& version) const;

		//! Add the specified version to key, adding key if it did not exist.
		/*!
		 *  \returns The path to the new file, which does not exist until it is
		 *  written into.
		 */
		boost::filesystem::path add(const std::string& key, const std::string& version);

		boost::filesystem::path root() const;

	protected:
		//! Maps from the keys to the set of available versions
		std::unordered_multimap<std::string, std::string> versions_;

		//! Stores the managed directory
		boost::filesystem::path root_;

	};

}
