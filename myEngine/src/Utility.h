#pragma once

#define START_GAME(className)\
int main() {\
	className _game;\
	_game.Run();\
	return 0;\
}



#ifdef ENGINE_MS_COMPILER
#ifdef ENGINE_LIB
	#define ENGINE_API __declspec(dllexport)
#else 
	#define ENGINE_API __declspec(dllimport)
#endif //ENGINE_LIB
#else
	#define ENGINE_API
#endif //ENGINE_MS_COMPILER 


#if ENGINE_DEBUG==2
	#define ENGINE_ERROR(x) std::cout << x << std::endl;
	#define ENGINE_LOG(x) std::cout << x << std::endl;

#elif ENGINE_DEBUG == 1
	#define ENGINE_ERROR(x) std::cout << x << std::endl;
	#define ENGINE_LOG(x) 
#else 
	#define ENGINE_ERROR(x)
	#define ENGINE_LOG(x)
#endif// Logging
