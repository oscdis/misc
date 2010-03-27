#ifdef unix
#define EXPORT
#else
#define EXPORT __declspec(dllexport)
#endif

extern "C" EXPORT int sum(int a, int b){
	return a+b;
}
