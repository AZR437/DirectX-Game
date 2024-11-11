#pragma once
#include "string"

typedef std::string String;
class UIManager;
class AUIScreen
{
	public:
		String GetName();
		
	protected:
		typedef std::string String;
		AUIScreen(String name);
		~AUIScreen();
		
		virtual void DrawUI() = 0;
		

		String name;

		friend class UIManager;
};

