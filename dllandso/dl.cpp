#include <stdio.h>

#ifdef unix

#include <dlfcn.h>
#define HANDLE void*
HANDLE open(const char* so){
	char buf[256];
	sprintf(buf, "%s.so", so);
	puts(buf);
	return dlopen(buf, RTLD_LAZY);
}
void* load(HANDLE handle, const char* func){
	return dlsym(handle, func);
}
void close(HANDLE handle){
	dlclose(handle);
}

#else

#include <windows.h>
#define HANDLE HINSTANCE
HANDLE open(const char* so){
	char buf[256];
	sprintf(buf, "%s.dll", so);
	return LoadLibrary(buf);
}
void* load(HANDLE handle, const char* func){
	return (void*)GetProcAddress(handle, func);
}
void close(HANDLE handle){
	FreeLibrary(handle);
}

#endif

//////////////////////////////////////////////////////////

int main(){
	int (*dl_sum)(int, int);
	HANDLE handle;

	handle = open("./sum");

	dl_sum = (int (*)(int, int))load(handle, "sum");
	printf("dl:%d\n", dl_sum(1,3));

	close(handle);
	return 0;
}
