#ifndef AUTH_HPP
#define AUTH_HPP

#include <iostream>
#include <vector>
#include <fstream>

// Удалено #include <Windows.h>, так как на Android его нет

namespace KeyAuth {
	class api {
	public:

		std::string name, ownerid, secret, version, url;

		api(std::string name, std::string ownerid, std::string secret, std::string version, std::string url) : name(name), ownerid(ownerid), secret(secret), version(version), url(url) {}

		void ban(std::string reason = "");
		void init();
		void check();
		void log(std::string msg);
		void license(std::string key);
		std::string var(std::string varid);
		std::string webhook(std::string id, std::string params);
		void setvar(std::string var, std::string vardata);
		std::string getvar(std::string var);
		bool checkblack();
		void upgrade(std::string username, std::string key);
		void login(std::string username, std::string password);
		void web_login();
		void button(std::string value);
		std::vector<unsigned char> download(std::string fileid);
		void regstr(std::string username, std::string password, std::string key);

		class data_class {
		public:
			// app data
			std::string numUsers;
			std::string numOnlineUsers;
			std::string numKeys;
			std::string version;
			std::string customerPanelLink;
			// user data
			std::string username;
			std::string ip;
			std::string hwid;
			std::string createdate;
			std::string lastlogin;
			std::string subscription;
			std::string expiry;
			bool success;
			std::string message;
		};

		data_class data;

	private:
		// Внутренние функции для работы с сетью на Android (curl)
		static size_t write_callback(void* contents, size_t size, size_t nmemb, void* userp);
		std::string req(std::string post_data);
	};
}

#endif // AUTH_HPP
